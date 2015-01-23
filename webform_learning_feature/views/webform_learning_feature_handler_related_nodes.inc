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
class webform_learning_feature_handler_related_nodes extends views_handler_field {

  /**
   * Class constructor.
   */
  public function construct() {
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
    $options['webform_related_cp'] = array('default' => NULL);
    $options['webform_related_cp_fields'] = array('default' => NULL);
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

    $nid = (int) $this->options['webform_nid'];
    $cid = (int) $this->options['webform_cid'];

    // Helper function provides webform_nid and webform_cid options.
    _webform_views_options_form($form, $form_state, $nid, $cid);

    // Content types list.
    $content_type_list = $this->getContentTypeList();
    $form['webform_related_cp'] = array(
      '#title' => t('Related Content Type'),
      '#type' => 'select',
      '#options' => $content_type_list,
      '#default_value' => $this->options['webform_related_cp'],
      '#description' => t('Content Type, related to webform.'),
      '#submit' => array('views_ui_config_item_form_submit_temporary'),
      '#executes_submit_callback' => TRUE,
    );

    // Content type field list.
    $content_type_fields = $this->getContentTypeFields($this->options['webform_related_cp']);
    $form['webform_related_cp_fields'] = array(
      '#title' => t('Field for rendering'),
      '#type' => 'select',
      '#options' => $content_type_fields,
      '#access' => count($content_type_fields),
      '#default_value' => $this->options['webform_related_cp_fields'],
      '#description' => t('Select field to display.'),
    );
  }

  /**
   * Return Content Type Fields List.
   *
   * @param string $content_type
   *   Neddle content type.
   *
   * @return array
   *   Field list for content type.
   */
  public function getContentTypeFields($content_type = '') {
    $options = array();

    $fields = field_info_instances('node', $content_type);
    if (!empty($fields)) {
      $options['title'] = 'Title';
      foreach ($fields['fields'] as $key => $item) {
        $options[$key] = $item['label'];
        dsm($key, $item);
      }
    }

    return $options;
  }

  /**
   * Return Content Type List.
   *
   * @return array
   *   Image fields list.
   */
  public function getContentTypeList() {
    $options = array();

    $query = db_select('node_type', 'n');
    $query->fields('n', array('type', 'name'));
    $query->condition('n.module', 'node');
    $query->orderBy('n.name', 'ASC');
    $result = $query->execute();

    foreach ($result as $row) {
      $options[$row->type] = $row->name;
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
    _webform_views_options_validate($form, $form_state);
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
    _webform_views_options_submit($form, $form_state);
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
