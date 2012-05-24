
------------------------
CONTENTS OF THIS FILE

* Introduction
* Requirements
* Installation


INTRODUCTION
------------------------

This is a small drupal module for D7 with the very specific purpose of making user pictures sharable on sites with a shared users table.


REQUIREMENTS
------------------------

This module currently requires a multi-site (shared code-base) install with a shared user table.  This is accomplished by using table prefixes.  See http://drupal.org/documentation/install/multi-site for more information.


INSTALLATION
------------------------

 - Create directory, sites/all/files, and give it open permissions
   - $ mkdir /path/to/drupal/sites/all/files
   - $ chmod 777 /path/to/drupal/sites/all/files
 - Pick one site to be the main site (generally this should be the site who's database houses the main users table) and install both unmanaged_user_pictures and unmanaged_user_pictures_main.  All other sites reqire only unmanaged_user_pictures.
 - Enable unmanaged_user_pictures in all other subsites you wish to share user pictures.

------------------------
MORE TO COME
------------------------
