<?php

/**
 * @file Google Civic settings
 * Responsible for the Google Civic Drupal admin interface.
 */

/**
 * Creates the admin form.
 *
 * @return Form
 *   An array containing form items to place on the module settings page.
 */
function google_civic_settings_form() {
  $form = array();

  $form['google_civic_key'] = array(
    '#type' => 'textfield',
    '#title' => t('Google Civic API Key'),
    '#default_value' => variable_get('google_civic_key', ''),
    '#description' => t('Enter your Google Civic API Key.'),
  );

  return system_settings_form($form);
}

