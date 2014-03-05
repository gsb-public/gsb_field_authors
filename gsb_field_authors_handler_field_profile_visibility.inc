<?php

/**
 * @file
 * Contains gsb_field_authors_handler_field_profile_visibility.
 */

/**
 * Allows the visibility field to be output as a form element.
 */
class gsb_field_authors_handler_field_profile_visibility extends views_handler_field_field {

  /**
   * {@inheritdoc}
   */
  function option_definition() {
    $options = parent::option_definition();
    $options['use_form_element'] = array(
      'default' => FALSE,
      'bool' => TRUE,
    );
    return $options;
  }

  /**
   * {@inheritdoc}
   */
  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
    $form['use_form_element'] = array(
      '#type' => 'checkbox',
      '#title' => t('Display as a form element'),
      '#default_value' => $this->options['use_form_element'],
    );
    return $form;
  }

  /**
   * {@inheritdoc}
   */
  function render_item($count, $item) {
    $rendered_item = parent::render_item($count, $item);
    if ($this->options['use_form_element']) {
      // @todo.
    }
    return $rendered_item;
  }

  /**
   * {@inheritdoc}
   */
  function render_items($items) {
    $rendered_items = parent::render_items($items);
    if ($this->options['use_form_element']) {
      // @todo.
    }
    return $rendered_items;
  }

}
