 Drupal composer classloader
===========================

## Overview

A simple module enables [composer autoloading](http://getcomposer.org) for drupal modules.

## Installation

This project can be checked out with [composer](http://getcomposer.org).

```json
{
  "require": {
    "janschumann/classloader_composer": "*"
  }
}
```

## Confguration

Usually no configuration is necessary.

Only if you have changed the ```vendor-dir``` configuration option in your ```composer.json``` file, the absolute path to this directory has to be made available to drupal:

**Via shell script:**

```sh
$ drush vset composer_vendor_dir <path/to/vendor/dir>
```

**Via php:**

```php
variable_set('composer_vendor_dir', '<path/to/vendor/dir>');
```

## Usage

After this module is required in your project´s ```composer.json``` file, composer will autoload all classes added to the ```composer.json``` autoload section:

```json
{
    "autoload": {
        "psr-0": {
            "My\\Namespace\\": "src"
        }
    }
}
```
