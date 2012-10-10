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

  /**
   * coderev-google_civic
   * Can you add a #size to these things so that they don't stick out of the
   * block on a standard accelerator site?
   * Also, let's get rid of the #description thing.
   */
  $form['google_civic_address']['address_field'] = array(
    '#type' => 'textfield',
    '#title' => t('Home Address'),
    '#description' => t('Enter your address to find your polling place.'),
    '#required' => TRUE,
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Submit'),
    '#weight' => 100,
  );

  $form['#action'] = url('google_civic/wheredoivote');
  $form['#redirect'] = FALSE;

  return $form;
}

