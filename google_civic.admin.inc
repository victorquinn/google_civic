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

  $form['google_civic_election_id'] = array(
    '#type' => 'textfield',
    '#title' => t('Google Civic Election ID'),
    '#default_value' => variable_get('google_civic_election_id', ''),
    '#description' => t('Enter the Google Civic election ID to use '
                      . 'when issuing Google Civic requests.'),
  );

  $form['google_civic_election_date'] = array(
    '#type' => 'date_select',
    '#title' => t('Election Day'),
    '#default_value' => variable_get('google_civic_election_year', ''),
    '#description' => t('Enter the election date (for display).'),
  );

  return system_settings_form($form);
}

