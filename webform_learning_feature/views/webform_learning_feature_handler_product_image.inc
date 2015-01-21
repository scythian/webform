<?php

/**
 * @file
 * Views handler to display data value of a webform submission component.
 */

/**
 * Field handler to show submission data.
 *
 * @ingroup views_field_handlers
 */
class webform_learning_feature_handler_product_image extends views_handler_field {

  /**
   * Class constructor.
   */
  public function construct() {
    // We need to set this property before calling the construct() chain
    // as we use it in the option_definintion() call.
    $this->webform_expand = $this->definition['webform_expand'];
    parent::construct();
  }

  /**
   * Handler option definition.
   *
   * @return array
   *   Options list.
   */
  public function option_definition() {
    $options = parent::option_definition();
    $options['custom_label'] = array('default' => 'default');
    $options['webform_nid'] = array('default' => NULL);
    $options['webform_cid'] = array('default' => NULL);
    $options['webform_if'] = array('default' => NULL);
    return $options;
  }

  /**
   * Options form.
   *
   * @param array $form
   *   The form parameters array.
   * @param array $form_state
   *   The form state array.
   */
  public function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
    form_load_include($form_state, 'inc', 'webform', 'views/webform.views');

    $form['custom_label']['#type'] = 'radios';
    $form['custom_label']['#options'] = array(
      'default' => t('Use component label'),
      'custom' => t('Custom label'),
      'none' => t('No label'),
    );
    $form['custom_label']['#default_value'] = $this->options['custom_label'];
    $form['label']['#dependency'] = array('radio:options[custom_label]' => array('custom'));

    if (!$this->webform_expand) {
      $nid = (int) $this->options['webform_nid'];
      $cid = (int) $this->options['webform_cid'];

      // Helper function provides webform_nid and webform_cid options.
      _webform_views_options_form($form, $form_state, $nid, $cid);
    }

    $options = $this->getImageFieldsList();
    $form['webform_if'] = array(
      '#title' => t('Image field name'),
      '#type' => 'select',
      '#options' => $options,
      '#default_value' => $this->options['webform_if'],
      '#description' => t('Related node image machine name.'),
    );

  }

  /**
   * Return image fields list.
   *
   * @return array
   *   Image fields list.
   */
  public function getImageFieldsList() {
    $options = array();

    $query = db_select('field_config', 'f');
    $query->fields('f', array('id', 'field_name'));
    $query->condition('f.type', 'image');
    $query->orderBy('f.field_name', 'ASC');
    $result = $query->execute();

    foreach ($result as $row) {
      $options[$row->id] = $row->field_name;
    }

    return $options;
  }

  /**
   * Custom options validate handler.
   *
   * @param array $form
   *   The form parameters array.
   * @param array $form_state
   *   The form state array.
   */
  function options_validate(&$form, &$form_state) {
    parent::options_validate($form, $form_state);
    if (!$this->webform_expand) {
      _webform_views_options_validate($form, $form_state);
      // Just store the checked components of the selected type.
      if (empty($form_state['values']['options']['webform_if'])) {
        form_error($form['webform_if'], t('Image field name is required.'));
      }
    }
  }

  /**
   * Custom options submit handler.
   *
   * @param array $form
   *   The form parameters array.
   * @param array $form_state
   *   The form state array.
   */
  function options_submit(&$form, &$form_state) {
    parent::options_submit($form, $form_state);
    if (!$this->webform_expand) {
      _webform_views_options_submit($form, $form_state);
    }
  }

  /**
   * Load the node and submissions needed for this components values.
   *
   * @param array $values
   *   Submitted values array.
   */
  public function pre_render(&$values) {
    $nid = $this->options['webform_nid'];
    $this->webform_node = node_load($nid);
    // Load all the submissions needed for this page. This is stored at the
    // view level to ensure it's available between fields so we don't load
    // them twice.
    if (!isset($this->view->_webform_submissions[$nid])) {
      module_load_include('inc', 'webform', 'includes/webform.submissions');
      $this->view->_webform_submissions[$nid] = array();
      $sids = array();
      foreach ($values as $value) {
        $sids[] = $value->{$this->field_alias};
      }
      if ($sids) {
        $this->view->_webform_submissions[$nid] = webform_get_submissions(array('sid' => $sids));
      }
    }
  }

  /**
   * Render the field using the loaded submissions from pre_render().
   */
  public function render($row) {
    $output = array();
    $sid = $this->get_value($row);
    $nid = $this->options['webform_nid'];
    $cid = $this->options['webform_cid'];
    $image_field = $this->options['webform_if'];

    $webform = $this->webform_node;
    if (isset($sid) && isset($webform->webform['components'][$cid])) {
      $submission = $this->view->_webform_submissions[$nid][$sid];

      if (!empty($submission->data[$cid][0])) {
        $node = node_load($submission->data[$cid][0]);
        $image = field_get_items('node', $node, $image_field);
        $output = field_view_value('node', $node, $image_field, $image[0], array(
          'type' => 'image',
          'settings' => array(
            'image_style' => 'thumbnail',
            'image_link' => 'content',
          ),
        ));
      }
    }

    return render($output);
  }
}
