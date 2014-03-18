<?php
/**
 * @file
 * content_stream.features.inc
 */

/**
 * Implements hook_views_api().
 */
function content_stream_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function content_stream_node_info() {
  $items = array(
    'content_stream' => array(
      'name' => t('Content Stream'),
      'base' => 'node_content',
      'description' => t('Create a stream of content based on content type and tags. '),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}

/*
function content_stream_preprocess_node(&$variables) {
  if ($variables['type'] == 'content_stream') {
    $view_type=(isset($variables['field_view_content_type'][0]['value']) ? $variables['field_view_content_type'][0]['value'] : 'all' );
    $view_tags=(isset($variables['field_tags'][0]['tid']) ? $variables['field_tags'][0]['tid'] : null);
    $view=views_embed_view('content', 'default', $view_type, $view_tags);
    $variables['content']['body'][0]['#markup']=$view;
    dpm($variables);
  }
}
*/
function content_stream_node_view($node, $view_mode, $langcode) {
  if ('content_stream' == $node->type) {
    $view_type=(isset($node->content['field_view_content_type']['#items'][0]['value']) ? $node->content['field_view_content_type']['#items'][0]['value'] : 'all' );
    $view_tags=(isset($node->content['field_tags']['#items'][0]['tid']) ? $node->content['field_tags']['#items'][0]['tid'] : null);
    $view=views_embed_view('content', 'default', $view_type, $view_tags);
    $node->content['field_content_stream'] = array(
      '#markup' => $view,
      '#weight' => 1000,
    );
    unset($node->content['field_view_content_type']);
    unset($node->content['field_tags']);
  }
}
