<?php

/**
 * Renders the Google Civic voterinfo view.
 * endpoint: google_civic/where-do-I-vote
 *
 * @return string
 *   The voterinfo view rendered as HTML.
 */
function google_civic_voterinfo() {
  $address_form = drupal_get_form('google_civic_address_form');

  if (!$_POST) {
    return $address_form;
  }

  drupal_add_css(drupal_get_path('module', 'google_civic')
                  . '/css/google_civic.css');

  $election_id = (int) variable_get('google_civic_election_id', '');

  $address = check_plain($_POST['address_field']);

  $response = google_civic_request_voterinfo($election_id, $address);
  module_invoke_all('google_civic_voterinfo', $response);

  $election_date = _google_civic_format_election_date();
  $headline = format_plural(count($response->pollingLocations),
        'Your Polling Location for the !election_date Election:',
        'Your Polling Locations for the !election_date Election:',
        array('!election_date' => $election_date,));

  $locations = google_civic_locations_response_massage(
                                          $response->pollingLocations);
  $early_locations = google_civic_locations_response_massage(
                                          $response->earlyVoteSites);

  module_load_include('inc', 'google_civic', 'google_civic.map');
  $map = google_civic_map($address, array_merge($locations, $early_locations));

  $locations = google_civic_locations_render($locations, 'poll');
  $early_locations = google_civic_locations_render($early_locations,
                                                   'early-poll');

  $election_info_link = google_civic_voterinfo_response_get_link($response);

  return theme('google_civic_voterinfo', $headline, $locations,
               $early_locations, $map, $election_info_link, $address_form);
}

/**
 * @see GoogleCivicAPI::request_voterinfo (google_civic.google.php)
 */
function google_civic_request_voterinfo($election_id, $address) {
  module_load_include('inc', 'google_civic', 'google_civic.google');
  $api = google_civic_get_api();
  $response = $api->request_voterinfo($election_id, $address);
  return $response;
}

/**
 * Massages the pollingLocations of the voterinfo response to include
 * a Google Map as part of the location and extracts opening / closing
 * times.
 *
 * @param Array $locations_response
 *   A pollingLocations array from a voterinfo response.
 *
 * @return Array
 *   The pollingLocations--massaged to include a Google Map of the
 *   polling location.
 */
function google_civic_locations_response_massage($locations_response) {
  $locations = array();
  if (!$locations_response) {
    return $locations;
  }

  module_load_include('inc', 'google_civic', 'google_civic.map');

  foreach($locations_response as &$location) {
    $location->marker = google_civic_location_marker($location);
    list($start_time, $end_time) = google_civic_location_poll_time($location);

    $location->opening_time = $start_time;
    $location->closing_time = $end_time;

    $locations[] = $location;
  }
  return $locations;
}

/**
 * Gets the electionInfoUrl from the voterinfo_response
 *
 * @param Array $voterinfo_response
 *   A voterinfo response.
 *
 * @return string
 *   The electionInfoUrl--rendered as an HTML anchor.
 */
function google_civic_voterinfo_response_get_link($voterinfo_response) {
  if (!count($voterinfo_response)) {
    return NULL;
  }

  $election_info_url = $voterinfo_response->state[0]->local_jurisdiction->
                        electionAdministrationBody->electionInfoUrl;

  if (!$election_info_url) {
    return NULL;
  }

  $election_info_link = l($election_info_url, $election_info_url);
  return $election_info_link;
}

/**
 * Gets a GMap-style map marker for a Google Civic location.
 *
 * @param Object $location
 *   A Google Civic location (from a voterinfo response).
 *
 * @return Array
 *   A GMap-style map marker.
 */
function google_civic_location_marker($location) {
  module_load_include('inc', 'google_civic', 'google_civic.google');

  $address = google_civic_translate_address_response($location->address);
  $marker = google_civic_address_marker($address);
  return $marker;
}

/**
 * Gets the opening / closing times for a Google Civic polling location.
 *
 * @param Object $location
 *   A Google Civic polling location (from a voterinfo response).
 *
 * @return Array
 *   Two strings--the opening / closing times.
 */
function google_civic_location_poll_time($location) {
  $polling_hours = explode('-', $location->pollingHours);

  if (count($polling_hours) != 2) {
    return NULL;
  }

  $poll_times = array();
  $poll_times[] = trim($polling_hours[0]);
  $poll_times[] = trim($polling_hours[1]);

  if (!$poll_times[0] || !$poll_times[1]) {
    return NULL;
  }

  return $poll_times;
}

/**
 * Gets the admin-set election date as a formatted string for display.
 *
 * @return string
 *   The admin-set election date--formatted for display.
 */
function _google_civic_format_election_date() {
  $election_date = variable_get('google_civic_election_date',
                                '2012-11-06 00:00:00');
  $election_time = strtotime($election_date);
  $election_date = strftime('%B %e', $election_time);
  return $election_date;
}

/**
 * Renders a list of Google Civic locations as HTML.
 *
 * @param Array $locations
 *   A list of Google Civic locations.
 * @param string $class_name
 *   An identifier for the type of Google Civic location being rendered.
 *
 * @return string
 *   The $locations--rendered as HTML.
 */
function google_civic_locations_render($locations, $class_name) {
  $class_prefix = 'google-civic-voterinfo-' . $class_name;
  return theme('google_civic_locations', $locations, $class_prefix);
}

