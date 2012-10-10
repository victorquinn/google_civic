<?php

/**
 * @file API Documentation file
 * This file contains API documentation for the Google Civic module.
 * Note that this code is exemplary; it is never executed when
 * the Google Civic module.
 */

/**
 * Hook to consume the voterinfo response.
 *
 * @param Object $response
 *   A voterinfo response from Google Civic.
 *
 * @see GoogleCivicAPI::request_voterinfo (google_civic.google.php).
 */
function hook_google_civic_voterinfo($response) {
  $voter_postal_code = $response->normalizedInput->zip;
}

/**
 * Hook to add additional data to the bottom of the voterinfo page.
 *
 * @return string
 *   HTML
 */
function hook_google_civic_voterinfo_extra_data() {
  return theme('___');
}

