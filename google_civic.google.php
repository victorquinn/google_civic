<?php

/**
 * @file Google Civic API class
 */

define('GOOGLE_CIVIC_API', "https://www.googleapis.com/civicinfo/us_v1");

/**
 * Consumes the Google Civic REST API.
 */
class GoogleCivicAPI {
  private $_api_key;

  /**
   * Constructor...
   *
   * @param string $api_key
   *   The Google API key under which requests via this API will be issued.
   */
  public function __construct($api_key) {
    $this->_api_key = $api_key;
  }

  /**
   * Attaches $this API's Google API key to a URL.
   *
   * @param string $url
   *   A URL to a Google Civic REST endpoint.
   */
  private function attach_key(&$url) {
    if ($this->_api_key) {
      $url .= sprintf("?key=%s", $this->_api_key);
    }
  }

  /**
   * Issues a request to the Google Civic REST API.
   *
   * @param string $url
   *   A URL (the Google Civic JSON endpoint to request).
   * @param Array $payload
   *   An ASSOCIATIVE array (of data to attach to the request).
   *
   * @return Object
   *   The response (decoded as an object) from Google Civic's API.
   */
  private function request($url, $payload) {
    $this->attach_key($url);

    $headers = array('Content-Type: application/json');

    $ch = curl_init();

    curl_setopt($ch, CURLOPT_URL, $url);
    curl_setopt($ch, CURLOPT_HTTPHEADER, $headers);
    curl_setopt($ch, CURLOPT_RETURNTRANSFER, TRUE);

    if ($payload) {
      curl_setopt($ch, CURLOPT_POSTFIELDS, json_encode($payload));
    }

    $resp = curl_exec($ch);
    curl_close($ch);

    return json_decode($resp);
  }

  /**
   * Requests voterinfo for an address for a given year.
   *
   * @param int $year
   *   A year (for which to request voter information).
   * @param string $address
   *   An address (for which to request voter information).
   *
   * @return Object|NULL
   *   The voter information reponse from Google Civic for the requested
   *   year and address--or NULL in case of failure.
   */
  public function request_voterinfo($year, $address) {
    if (!is_int($year)) {
      return NULL;
    }

    if (strlen($year) != 4) {
      return NULL;
    }

    $url = sprintf("%s/voterinfo/%d/lookup", GOOGLE_CIVIC_API, $year);
    $payload = array('address' => $address,);

    return $this->request($url, $payload);
  }
}

