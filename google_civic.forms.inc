<?php

/**
 * @file Google Civic Drupal form handling.
 */

/**
 * Sets the Google Civic Address Form structure--used to build the form.
 *
 * @param string $style
 *  The style of form to display: either 'page' or 'block'
 * @return Array
 *   The Google Civic Address Form structure.
 */
function _google_civic_address_form($style) {
  $form = array();

  $form['google_civic_address']['intro'] = array(
    '#type' => 'item',
    '#value' => ('Find voter information for the address below:'),
    '#weight' => 0,
  );

  $form['google_civic_address']['address_field'] = array(
    '#type' => 'textfield',
    '#title' => t('Home Address'),
    '#required' => TRUE,
    '#size' => 35,
    '#description' =>
      t('Enter your street address to find your polling location'),
  );

  $form['google_civic_address']['style'] = array(
    '#type' => 'value',
    '#value' => $style,
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Submit'),
    '#weight' => 100,
  );

  $form['#action'] = url('google_civic/voterinfo');
  $form['#redirect'] = FALSE;
  $form['#attributes']['class'] .= ' google-civic-address-form ';

  return $form;
}

