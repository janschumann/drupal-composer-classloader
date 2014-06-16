<?php

/**
 * Classloader settings form
 *
 * @see hook_menu()
 *
 * @return array
 */
function classloader_composer_admin_settings_form() {
  $form = array();

  $form['composer_vendor_dir'] = array(
    '#type' => 'textfield',
    '#title' => t('Composer vendor directory'),
    '#default_value' => variable_get('composer_vendor_dir', DRUPAL_ROOT . '/../vendor'),
    '#description' => t('The absolute path to composer vendor directory.'),
    '#required' => true,
  );
  if (extension_loaded('apc')) {
    $form['composer_use_apc'] = array(
      '#type' => 'radios',
      '#title' => t('Use APC class loader'),
      '#default_value' => variable_get('composer_use_apc', 0),
      '#options' => array(0 => t('false'), 1 => t('true')),
      '#required' => true,
    );
  }
  $form['actions'] = array('#type' => 'actions');
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
  );

  return $form;
}

/**
 * Submit handler for dic settings
 *
 * @param $form
 * @param $form_state
 */
function classloader_composer_admin_settings_form_submit($form, $form_state) {
  // save form values
  foreach ($form_state['values'] as $key => $value) {
    if (strpos($key, 'composer_') === 0) {
      variable_set($key, $value);
    }
  }
  
  drupal_set_message(t('Settings have been saved.'));  
}
