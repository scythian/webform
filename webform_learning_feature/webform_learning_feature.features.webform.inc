<?php
/**
 * @file
 * webform_learning_feature.features.webform.inc
 */

/**
 * Implements hook_webform_defaults().
 */
function webform_learning_feature_webform_defaults() {
$webforms = array();
  $webforms['test_quiz'] = array(
  'title' => 'Test 	quiz',
  'log' => '',
  'status' => 1,
  'comment' => 1,
  'promote' => 1,
  'sticky' => 0,
  'type' => 'webform',
  'language' => 'und',
  'tnid' => 0,
  'translate' => 0,
  'rdf_mapping' => array(
    'rdftype' => array(
      0 => 'sioc:Item',
      1 => 'foaf:Document',
    ),
    'title' => array(
      'predicates' => array(
        0 => 'dc:title',
      ),
    ),
    'created' => array(
      'predicates' => array(
        0 => 'dc:date',
        1 => 'dc:created',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
    'changed' => array(
      'predicates' => array(
        0 => 'dc:modified',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
    'body' => array(
      'predicates' => array(
        0 => 'content:encoded',
      ),
    ),
    'uid' => array(
      'predicates' => array(
        0 => 'sioc:has_creator',
      ),
      'type' => 'rel',
    ),
    'name' => array(
      'predicates' => array(
        0 => 'foaf:name',
      ),
    ),
    'comment_count' => array(
      'predicates' => array(
        0 => 'sioc:num_replies',
      ),
      'datatype' => 'xsd:integer',
    ),
    'last_activity' => array(
      'predicates' => array(
        0 => 'sioc:last_activity_date',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
  ),
  'webform' => array(
    'next_serial' => 3,
    'confirmation' => 'Vivamus in erat ut urna cursus vestibulum. Proin faucibus arcu quis ante. Aliquam lobortis. Aenean commodo ligula eget dolor. Morbi mollis tellus ac sapien.',
    'confirmation_format' => 'filtered_html',
    'redirect_url' => '<confirmation>',
    'status' => 1,
    'block' => 1,
    'allow_draft' => 1,
    'auto_save' => 1,
    'submit_notice' => 1,
    'submit_text' => '',
    'submit_limit' => -1,
    'submit_interval' => -1,
    'total_submit_limit' => -1,
    'total_submit_interval' => -1,
    'progressbar_bar' => 0,
    'progressbar_page_number' => 0,
    'progressbar_percent' => 0,
    'progressbar_pagebreak_labels' => 0,
    'progressbar_include_confirmation' => 0,
    'progressbar_label_first' => 'Start',
    'progressbar_label_confirmation' => 'Complete',
    'preview' => 0,
    'preview_next_button_label' => '',
    'preview_prev_button_label' => '',
    'preview_title' => '',
    'preview_message' => '',
    'preview_message_format' => 'filtered_html',
    'preview_excluded_components' => array(),
    'machine_name' => 'test_quiz',
    'record_exists' => TRUE,
    'roles' => array(
      0 => 1,
      1 => 2,
    ),
    'emails' => array(
      0 => array(
        'email' => 'alex.vodyanoy@blinkreaction.com',
        'subject' => 'default',
        'from_name' => 'default',
        'from_address' => 'default',
        'template' => 'default',
        'excluded_components' => array(),
        'html' => 0,
        'attachments' => 0,
        'extra' => FALSE,
        'components_machine_names' => array(
          'email' => FALSE,
          'subject' => FALSE,
          'from_name' => FALSE,
          'from_address' => FALSE,
        ),
      ),
    ),
    'components' => array(
      'test_quiz__first_name' => array(
        'form_key' => 'first_name',
        'name' => 'First Name',
        'type' => 'textfield',
        'value' => '',
        'extra' => array(
          'title_display' => 'none',
          'private' => 0,
          'wrapper_classes' => '',
          'css_classes' => '',
          'placeholder' => 'Name',
          'width' => '',
          'maxlength' => '',
          'field_prefix' => '',
          'field_suffix' => '',
          'disabled' => 0,
          'unique' => 0,
          'description' => '',
          'attributes' => array(),
          'analysis' => FALSE,
        ),
        'required' => 1,
        'weight' => 0,
        'machine_name' => 'test_quiz__first_name',
        'page_num' => 1,
      ),
      'test_quiz__last_name' => array(
        'form_key' => 'last_name',
        'name' => 'Last Name',
        'type' => 'textfield',
        'value' => '',
        'extra' => array(
          'title_display' => 'none',
          'private' => 0,
          'wrapper_classes' => '',
          'css_classes' => '',
          'placeholder' => 'Last Name',
          'width' => '',
          'maxlength' => '',
          'field_prefix' => '',
          'field_suffix' => '',
          'disabled' => 0,
          'unique' => 0,
          'description' => '',
          'attributes' => array(),
          'analysis' => FALSE,
        ),
        'required' => 1,
        'weight' => 1,
        'machine_name' => 'test_quiz__last_name',
        'page_num' => 1,
      ),
      'test_quiz__sex' => array(
        'form_key' => 'sex',
        'name' => 'Sex',
        'type' => 'select',
        'value' => '',
        'extra' => array(
          'items' => '0|male
1|female',
          'multiple' => 0,
          'title_display' => 'before',
          'private' => 0,
          'wrapper_classes' => '',
          'css_classes' => '',
          'aslist' => 0,
          'optrand' => 0,
          'other_option' => NULL,
          'other_text' => 'Other...',
          'description' => '',
          'custom_keys' => FALSE,
          'options_source' => '',
          'analysis' => TRUE,
        ),
        'required' => 1,
        'weight' => 2,
        'machine_name' => 'test_quiz__sex',
        'page_num' => 1,
      ),
      'test_quiz__dob' => array(
        'form_key' => 'dob',
        'name' => 'DOB',
        'type' => 'date',
        'value' => '',
        'extra' => array(
          'title_display' => 'before',
          'private' => 0,
          'wrapper_classes' => '',
          'start_date' => '-60 years',
          'end_date' => '-16 years',
          'timezone' => 'user',
          'year_textfield' => 0,
          'datepicker' => 1,
          'description' => '',
          'analysis' => FALSE,
        ),
        'required' => 1,
        'weight' => 3,
        'machine_name' => 'test_quiz__dob',
        'page_num' => 1,
      ),
      'test_quiz__email' => array(
        'form_key' => 'email',
        'name' => 'Email',
        'type' => 'email',
        'value' => '',
        'extra' => array(
          'title_display' => 'none',
          'private' => 0,
          'wrapper_classes' => '',
          'css_classes' => '',
          'placeholder' => 'Email',
          'width' => '',
          'unique' => 0,
          'disabled' => 0,
          'description' => '',
          'attributes' => array(),
          'analysis' => FALSE,
        ),
        'required' => 1,
        'weight' => 4,
        'machine_name' => 'test_quiz__email',
        'page_num' => 1,
      ),
      'test_quiz__address' => array(
        'form_key' => 'address',
        'name' => 'Address',
        'type' => 'pagebreak',
        'value' => '',
        'extra' => array(
          'private' => 0,
          'next_page_label' => '',
          'prev_page_label' => '',
        ),
        'required' => 0,
        'weight' => 5,
        'machine_name' => 'test_quiz__address',
        'page_num' => 2,
      ),
      'test_quiz__street_address' => array(
        'form_key' => 'street_address',
        'name' => 'Street Address',
        'type' => 'textarea',
        'value' => '',
        'extra' => array(
          'title_display' => 'none',
          'private' => 0,
          'wrapper_classes' => '',
          'css_classes' => '',
          'placeholder' => 'Street Address',
          'cols' => '',
          'rows' => '',
          'resizable' => 1,
          'disabled' => 0,
          'description' => '',
          'attributes' => array(),
          'analysis' => FALSE,
        ),
        'required' => 1,
        'weight' => 6,
        'machine_name' => 'test_quiz__street_address',
        'page_num' => 2,
      ),
      'test_quiz__address_additional' => array(
        'form_key' => 'address_additional',
        'name' => 'Address Additional',
        'type' => 'textarea',
        'value' => '',
        'extra' => array(
          'title_display' => 'none',
          'private' => 0,
          'wrapper_classes' => '',
          'css_classes' => '',
          'placeholder' => 'Address Additional',
          'cols' => '',
          'rows' => '',
          'resizable' => 1,
          'disabled' => 0,
          'description' => '',
          'attributes' => array(),
          'analysis' => FALSE,
        ),
        'required' => 0,
        'weight' => 7,
        'machine_name' => 'test_quiz__address_additional',
        'page_num' => 2,
      ),
      'test_quiz__city' => array(
        'form_key' => 'city',
        'name' => 'City',
        'type' => 'textfield',
        'value' => '',
        'extra' => array(
          'title_display' => 'none',
          'private' => 0,
          'wrapper_classes' => '',
          'css_classes' => '',
          'placeholder' => 'City',
          'width' => '',
          'maxlength' => '',
          'field_prefix' => '',
          'field_suffix' => '',
          'disabled' => 0,
          'unique' => 0,
          'description' => '',
          'attributes' => array(),
          'analysis' => FALSE,
        ),
        'required' => 1,
        'weight' => 8,
        'machine_name' => 'test_quiz__city',
        'page_num' => 2,
      ),
      'test_quiz__state' => array(
        'form_key' => 'state',
        'name' => 'State',
        'type' => 'select',
        'value' => '',
        'extra' => array(
          'items' => 'AL|Alabama
AK|Alaska
AS|American Samoa
AZ|Arizona
AR|Arkansas
CA|California
CO|Colorado
CT|Connecticut
DE|Delaware
DC|District of Columbia
FL|Florida
GA|Georgia
GU|Guam
HI|Hawaii
ID|Idaho
IL|Illinois
IN|Indiana
IA|Iowa
KS|Kansas
KY|Kentucky
LA|Louisiana
ME|Maine
MH|Marshall Islands
MD|Maryland
MA|Massachusetts
MI|Michigan
MN|Minnesota
MS|Mississippi
MO|Missouri
MT|Montana
NE|Nebraska
NV|Nevada
NH|New Hampshire
NJ|New Jersey
NM|New Mexico
NY|New York
NC|North Carolina
ND|North Dakota
MP|Northern Marianas Islands
OH|Ohio
OK|Oklahoma
OR|Oregon
PW|Palau
PA|Pennsylvania
PR|Puerto Rico
RI|Rhode Island
SC|South Carolina
SD|South Dakota
TN|Tennessee
TX|Texas
UT|Utah
VT|Vermont
VI|Virgin Islands
VA|Virginia
WA|Washington
WV|West Virginia
WI|Wisconsin
WY|Wyoming
',
          'options_source' => 'united_states',
          'multiple' => 0,
          'title_display' => 'before',
          'private' => 0,
          'wrapper_classes' => '',
          'css_classes' => '',
          'aslist' => 1,
          'optrand' => 0,
          'other_option' => NULL,
          'other_text' => 'Other...',
          'description' => '',
          'custom_keys' => FALSE,
          'analysis' => TRUE,
        ),
        'required' => 1,
        'weight' => 9,
        'machine_name' => 'test_quiz__state',
        'page_num' => 2,
      ),
      'test_quiz__zip' => array(
        'form_key' => 'zip',
        'name' => 'ZIP',
        'type' => 'textfield',
        'value' => '',
        'extra' => array(
          'title_display' => 'none',
          'private' => 0,
          'wrapper_classes' => '',
          'css_classes' => '',
          'placeholder' => 'ZIP',
          'width' => '',
          'maxlength' => '',
          'field_prefix' => '',
          'field_suffix' => '',
          'disabled' => 0,
          'unique' => 0,
          'description' => '',
          'attributes' => array(),
          'analysis' => FALSE,
        ),
        'required' => 1,
        'weight' => 10,
        'machine_name' => 'test_quiz__zip',
        'page_num' => 2,
      ),
      'test_quiz__additional' => array(
        'form_key' => 'additional',
        'name' => 'Personal Date',
        'type' => 'pagebreak',
        'value' => '',
        'extra' => array(
          'private' => 0,
          'next_page_label' => '',
          'prev_page_label' => '',
        ),
        'required' => 0,
        'weight' => 11,
        'machine_name' => 'test_quiz__additional',
        'page_num' => 3,
      ),
      'test_quiz__comments' => array(
        'form_key' => 'comments',
        'name' => 'Comments',
        'type' => 'textarea',
        'value' => '',
        'extra' => array(
          'title_display' => 'none',
          'private' => 0,
          'wrapper_classes' => '',
          'css_classes' => '',
          'placeholder' => 'Comments',
          'cols' => '',
          'rows' => '',
          'resizable' => 1,
          'disabled' => 0,
          'description' => '',
          'attributes' => array(),
          'analysis' => FALSE,
        ),
        'required' => 0,
        'weight' => 12,
        'machine_name' => 'test_quiz__comments',
        'page_num' => 3,
      ),
      'test_quiz__im_agree_to_receive_email_notifi' => array(
        'form_key' => 'im_agree_to_receive_email_notification',
        'name' => 'I\'m agree to receive email notification',
        'type' => 'select',
        'value' => '',
        'extra' => array(
          'items' => '1|I\'m agree to receive email notification',
          'multiple' => 1,
          'title_display' => 'none',
          'private' => 0,
          'wrapper_classes' => '',
          'css_classes' => '',
          'aslist' => 0,
          'optrand' => 0,
          'other_option' => NULL,
          'other_text' => 'Other...',
          'description' => '',
          'custom_keys' => FALSE,
          'options_source' => '',
          'analysis' => TRUE,
        ),
        'required' => 1,
        'weight' => 13,
        'machine_name' => 'test_quiz__im_agree_to_receive_email_notifi',
        'page_num' => 3,
      ),
      'test_quiz__agreement' => array(
        'form_key' => 'agreement',
        'name' => 'I\'m agree with Privacy Policy',
        'type' => 'select',
        'value' => '',
        'extra' => array(
          'items' => '1|I\'m agree with Privacy Policy',
          'multiple' => 1,
          'title_display' => 'none',
          'private' => 0,
          'wrapper_classes' => '',
          'css_classes' => '',
          'aslist' => 0,
          'optrand' => 0,
          'other_option' => NULL,
          'other_text' => 'Other...',
          'description' => '',
          'custom_keys' => FALSE,
          'options_source' => '',
          'analysis' => TRUE,
        ),
        'required' => 1,
        'weight' => 14,
        'machine_name' => 'test_quiz__agreement',
        'page_num' => 3,
      ),
    ),
    'conditionals' => array(),
  ),
  'cid' => 0,
  'last_comment_name' => NULL,
  'last_comment_uid' => 1,
  'comment_count' => 0,
  'name' => 'admin',
  'picture' => 0,
  'data' => 'b:0;',
  'webform_features_author' => 'admin',
  'webform_features_revision_author' => 'admin',
);
return $webforms;
}
