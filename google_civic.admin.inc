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

  $form['google_civic_election_year'] = array(
    '#type' => 'textfield',
    '#title' => t('Election Year'),
    '#default_value' => variable_get('google_civic_election_year', ''),
    '#description' => t('Enter the four-digit election year to use for '
                      . 'Google Civic requests.'),
  );

  return system_settings_form($form);
}

/**
 * Implements Drupal's hook_form_ID_validate().
 */
function google_civic_settings_form_validate($form, &$form_state) {
  $election_year = (int) $form_state['values']['google_civic_election_year'];
  if (strlen((string) $election_year) != 4) {
    form_set_error('text', t('You must enter a four-digit election year.'));
  }
}
