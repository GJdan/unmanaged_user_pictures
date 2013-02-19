<?php

/**
 * @file
 * Definition of views_handler_field_unmanaged_user_picture.
 */

/**
 * Override views_handler_field_user_picture to support picture_unmanaged.
 *
 * @ingroup views_field_handlers
 */
class views_handler_field_unmanaged_user_picture extends views_handler_field_user_picture {
  function construct() {
    parent::construct();
    $this->additional_fields['picture_unmanaged'] = 'picture_unmanaged';
  }

  function render($values) {
    if ($this->options['image_style'] && module_exists('image')) {
      if ($picture_unmanaged_path = $this->get_value($values, 'picture_unmanaged')) {
				$picture_filepath = $picture_unmanaged_path;
			}
      else if (($picture_fid = $this->get_value($values)) && $picture = file_load($picture_fid)) {
        $picture_filepath = $picture->uri;
      }
      else {
        $picture_filepath = variable_get('user_picture_default', '');
      }
      if (file_valid_uri($picture_filepath)) {
        $output = theme('image_style', array('style_name' => $this->options['image_style'], 'path' => $picture_filepath));
        if ($this->options['link_photo_to_profile'] && user_access('access user profiles')) {
          $uid = $this->get_value($values, 'uid');
          $output = l($output, "user/$uid", array('html' => TRUE));
        }
      }
      else {
        $output = '';
      }
    }
    else {
      // Fake an account object.
      $account = new stdClass();
      if ($this->options['link_photo_to_profile']) {
        // Prevent template_preprocess_user_picture from adding a link
        // by not setting the uid.
        $account->uid = $this->get_value($values, 'uid');
      }
      $account->name = $this->get_value($values, 'name');
      $account->mail = $this->get_value($values, 'mail');
      $account->picture = $this->get_value($values);
      $output = theme('user_picture', array('account' => $account));
    }

    return $output;
  }
}
