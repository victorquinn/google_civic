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
    '#type' => 'textarea',
    '#title' => t('Address'),
    '#description' => t('Enter your address to find your polling place.'),
  );

  $form['google_civic_address']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Submit'),
  );

  $form['#submit'][] = 'google_civic_address_form_submit';

  return $form;
}

/**
 * Implements Drupal's hook_form_ID_submit().
 */
function _google_civic_address_form_submit($form, &$form_state) {
  $query = array('address' => $form_state['values']['address_field'],);
  drupal_goto('google_civic/where-do-I-vote', $query);
}