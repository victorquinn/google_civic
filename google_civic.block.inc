<?php

/**
 * @file Google Civic Block File
 * This file is responsible for displaying Drupal blocks for the
 * Google Civic module.
 */


/**
 * @todo Please document this function.
 * @see http://drupal.org/node/1354
 */
function google_civic_block_address() {
  $address_form = drupal_get_form('google_civic_address_form', 'block');
  return $address_form;
}
