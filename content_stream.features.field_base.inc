<?php
/**
 * @file
 * content_stream.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function content_stream_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_view_content_type'
  $field_bases['field_view_content_type'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_view_content_type',
    'foreign keys' => array(),
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        'all' => 'All',
        'article' => 'Article',
        'page' => 'Page',
        'video' => 'Video',
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => 0,
    'type' => 'list_text',
  );

  return $field_bases;
}
