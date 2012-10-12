<?php

/**
 * @file Google Civic Block File
 * This file is responsible for displaying Drupal blocks for the
 * Google Civic module.
 */

/**
 * Lists the Google Civic Drupal blocks.
 *
 * @return Array
 *   The list of Google Civic Drupal blocks.
 */
function google_civic_block_list() {
  $blocks['google_civic_address']['info'] = t('Google Civic Address Block');
  return $blocks;
}

/**
 * Renders the correct block view.
 *
 * @param string $delta
 *   A Drupal block name.
 *
 * @return string
 *   The block (corresponding to $delta) rendered as HTML.
 */
function google_civic_block_view($delta) {
  if ($delta == 'google_civic_address') {
    $block['content'] = google_civic_block_address();
  }
  return $block;
}

function google_civic_block_address() {
  $address_form = drupal_get_form('google_civic_address_form', 'block');
  return $address_form;
}

