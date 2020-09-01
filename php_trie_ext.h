/**
 * @file trie.h
 * @author Lochemem Bruno Michael (lochbm@gmail.com)
 * @brief header file containing essential module bindings and C-file preprocessor inclusions
 * @version 0.1.0
 * 
 * @copyright Copyright (c) 1999-2019 The PHP Group
 * 
 */

#ifndef PHP_TRIE_EXT_H
#define PHP_TRIE_EXT_H

#define PHP_TRIE_EXT_EXTNAME "php_trie"
#define PHP_TRIE_EXT_EXTVER "0.1.0"

#define IS_HATTRIE 1
#define IS_TRIE 2

#define ZEND_API_PHP74 20190902 
#define ZEND_API_PHP73 20180731

const long DEFAULT_BURST_THRESHOLD = 16384;
const float DEFAULT_LOAD_FACTOR = 8.0f;

#ifndef HAVE_CONFIG_H
#include "config.h"
#endif

extern "C"
{
#include "php.h"
#include "zend_interfaces.h"
#include "zend_exceptions.h"
#include "ext/standard/info.h"
#include "ext/json/php_json.h"
#include "ext/standard/php_var.h"
#include "ext/standard/php_array.h"
}

extern zend_module_entry php_trie_module_entry;
#define phptrie_ext_ptr &php_trie_module_entry;

#endif // PHP_TRIE_EXT_H
