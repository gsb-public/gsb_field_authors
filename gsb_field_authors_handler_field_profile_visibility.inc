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
   * The entity that contains this field.
   *
   * @var object
   */
  protected $gsb_field_authors_entity;

  /**
   * The entity ID of the entity that contains this field.
   *
   * @var int|string
   */
  protected $gsb_field_authors_entity_id;

  /**
   * The entity type of the entity that contains this field.
   *
   * @var string
   */
  protected $gsb_field_authors_entity_type;

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
    if (!$this->options['use_form_element']) {
      return parent::render_item($count, $item);
    }

    return array(
      '#type' => 'select',
      '#title' => t('Visibility'),
      '#title_display' => 'invisible',
      '#options' => list_allowed_values($this->field_info, NULL, $this->gsb_field_authors_entity_type, $this->gsb_field_authors_entity),
      '#attributes' => array(
        'class' => array(
          'gsb-field-authors-visibility',
          'gsb-form-message-optout',
        ),
        'data-gsb-field-authors-entity-type' => $this->gsb_field_authors_entity_type,
        'data-gsb-field-authors-entity-id' => $this->gsb_field_authors_entity_id,
      ),
      // Use #value instead of #default_value since this is a render array,
      // not a true form.
      '#value' => $item['raw']['value'],
      '#attached' => array(
        'js' => array(
          ctools_attach_js('gsb_field_authors', 'gsb_field_authors'),
        ),
      ),
    );
  }

  /**
   * {@inheritdoc}
   */
  function render_items($items) {
    if (!$this->options['use_form_element']) {
      return parent::render_items($items);
    }

    return implode('', $items);
  }

  /**
   * {@inheritdoc}
   */
  function advanced_render($values) {
    // Store the entity type and ID so the field can output it.
    $this->gsb_field_authors_entity_type = $values->_field_data[$this->field_alias]['entity_type'];
    $this->gsb_field_authors_entity = clone $values->_field_data[$this->field_alias]['entity'];
    list($entity_id) = entity_extract_ids($this->gsb_field_authors_entity_type, $this->gsb_field_authors_entity);
    $this->gsb_field_authors_entity_id = $entity_id;

    return parent::advanced_render($values);
  }

}
