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

