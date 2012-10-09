<?php

/**
 * Renders the Google Civic voterinfo view.
 * endpoint: google_civic/where-do-I-vote
 *
 * @return string
 *   The voterinfo view rendered as HTML.
 */
function google_civic_voterinfo() {
  $election_year = _google_civic_get_election_year();
  $address = check_plain($_GET['address']);

  $response = google_civic_request_voterinfo($election_year, $address);
  $title = count($response->pollingLocations) == 1 ? 'Polling Location' :
                                                     'Polling Locations';

  $locations = google_civic_locations_response_massage(
                                          $response->pollingLocations);

  $election_info_link = google_civic_voterinfo_response_get_link($response);
  $election_date = _google_civic_get_election_date_string();

  module_load_include('inc', 'google_civic', 'google_civic.map');
  $map = google_civic_map($address, $locations);

  return theme('google_civic-voterinfo', $title, $locations, $map,
               $election_info_link, $election_date);
}

/**
 * @see GoogleCivicAPI::request_voterinfo (google_civic.google.php)
 */
function google_civic_request_voterinfo($election_year, $address) {
  module_load_include('inc', 'google_civic', 'google_civic.google');
  $api = google_civic_get_api();
  $response = $api->request_voterinfo($election_year, $address);
  return $response;
}

/**
 * Massages the pollingLocations of the voterinfo response to include
 * a Google Map as part of the location.
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

  module_load_include('inc', 'google_civic', 'google_civic.google');
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
  return $poll_times;
}

/**
 * Gets the admin-set election year.
 *
 * @return int
 *   The admin-set election year.
 */
function _google_civic_get_election_year() {
  $election_date = variable_get('google_civic_election_date',
                                '2012-11-06 00:00:00');
  $year = substr($election_date, 0, 4);
  return (int) $year;
}

/**
 * Gets the admin-set election date as a formatted string for display.
 *
 * @return string
 *   The admin-set election date--formatted for display.
 */
function _google_civic_get_election_date_string() {
  $election_date = variable_get('google_civic_election_date',
                                '2012-11-06 00:00:00');
  $election_time = strtotime($election_date);
  $election_date = strftime('%B %e', $election_time);
  return $election_date;
}

