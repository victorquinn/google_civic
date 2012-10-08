<?php

/**
 * @file Google Civic API Drupal-specific helper functions.
 */

/**
 * Creates a GoogleCivicAPI instance.
 *
 * @param string $api_key
 *   A Google Civic API Key string.
 *
 * @return GoogleCivicAPI
 *   A GoogleCivicAPI instantiated with $api_key.
 */
function google_civic_get_api($api_key = NULL) {
  module_load_include('php', 'google_civic', 'google_civic.google');
  $api_key = $api_key ? $api_key : variable_get('google_civic_key', '');
  return new GoogleCivicAPI($api_key);
}

/**
 * Translates an address response object into an address string.
 *
 * @param Object $address_response
 *   An address object from the Google Civic API.
 *
 * @return string
 *   The address object as an address string.
 */
function google_civic_translate_address_response($address_response) {
  $address_array[] = $address_response->locationName;
  $address_array[] = $address_response->line1;
  $address_array[] = $address_response->line2;
  $address_array[] = $address_response->line3;
  $address_array[] = $address_response->city;
  $address_array[] = $address_response->state;
  $address_array[] = $address_response->zip;
  $address = join(' ', $address_array);
  return $address;
}

/**
 * Gets a Google Map for a Google Civic location.
 *
 * @param Object $location_response
 *   A location object from the Google Civic API.
 *
 * @return GMap
 *   A Simple GMap--corresponding to the $location_response.
 */
function google_civic_map_location_response($location_response) {
  $address = google_civic_translate_address_response(
                                       $location_resposne->address);

  $geocode_data = gmap_geocode($address);
  $map = gmap_simple_map($geocode_data['latitude'],
                         $geocode_data['longitude']);

  return $map;
}

