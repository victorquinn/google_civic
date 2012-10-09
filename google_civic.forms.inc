<?php

/**
 * @file Google Civic Drupal form handling.
 */

/**
 * Sets the Google Civic Address Form structure--used to build the form.
 *
 * @return Array
 *   The Google Civic Address Form structure.
 */
function _google_civic_address_form() {
  $form = array();

  $form['google_civic_address']['address_field'] = array(
    '#type' => 'textfield',
    '#title' => t('Street Address'),
    '#description' => t('Enter your address to find your polling place.'),
    '#required' => TRUE,
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Submit'),
    '#weight' => 100,
  );

  $form['#submit'][] = 'google_civic_address_form_submit';

  return $form;
}

/**
 * Implements Drupal's hook_form_ID_submit().
 */
function _google_civic_address_form_submit($form, &$form_state) {
  $query = array('address' => $form_state['values']['address_field'],);
  drupal_goto('google_civic/wheredoivote', $query);
}

