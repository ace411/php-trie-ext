/*
   +----------------------------------------------------------------------+
   | Copyright (c) The PHP Group                                          |
   +----------------------------------------------------------------------+
   | This source file is subject to version 3.01 of the PHP license,      |
   | that is bundled with this package in the file LICENSE, and is        |
   | available through the world-wide-web at the following url:           |
   | https://www.php.net/license/3_01.txt                                 |
   | If you did not receive a copy of the PHP license and are unable to   |
   | obtain it through the world-wide-web, please send a note to          |
   | license@php.net so we can mail you a copy immediately.               |
   +----------------------------------------------------------------------+
   | Author: Lochemem Bruno Michael                                       |
   +----------------------------------------------------------------------+
*/

#include "common.cpp"

/* {{{ proto Trie::__construct()
 */
PHP_METHOD(Trie, __construct)
{
  trieConstruct(INTERNAL_FUNCTION_PARAM_PASSTHRU);
}
/* }}} */

/* {{{ proto bool Trie::insert( string key [, mixed entry ] )
 */
PHP_METHOD(Trie, insert)
{
  insert(INTERNAL_FUNCTION_PARAM_PASSTHRU, IS_TRIE);
}
/* }}} */

/* {{{ proto bool Trie::keyExists( string key )
 */
PHP_METHOD(Trie, keyExists)
{
  keyExists(INTERNAL_FUNCTION_PARAM_PASSTHRU, IS_TRIE);
}
/* }}} */

/* {{{ proto static Trie::fromArray( array entries )
 */
PHP_METHOD(Trie, fromArray)
{
  trieFromArray(INTERNAL_FUNCTION_PARAM_PASSTHRU);
}
/* }}} */

/* {{{ proto mixed Trie::search( string key )
 */
PHP_METHOD(Trie, search)
{
  search(INTERNAL_FUNCTION_PARAM_PASSTHRU, IS_TRIE);
}
/* }}} */

/* {{{ proto void Trie::erase( string key )
 */
PHP_METHOD(Trie, erase)
{
  keyDelete(INTERNAL_FUNCTION_PARAM_PASSTHRU, IS_TRIE);
}
/* }}} */

/* {{{ proto bool Trie::offsetSet( string key [, mixed entry ] )
 */
PHP_METHOD(Trie, offsetSet)
{
  insert(INTERNAL_FUNCTION_PARAM_PASSTHRU, IS_TRIE);
}
/* }}} */

/* {{{ proto mixed Trie::offsetGet( string key )
 */
PHP_METHOD(Trie, offsetGet)
{
  search(INTERNAL_FUNCTION_PARAM_PASSTHRU, IS_TRIE);
}
/* }}} */

/* {{{ proto int Trie::size()
 */
PHP_METHOD(Trie, size)
{
  count(INTERNAL_FUNCTION_PARAM_PASSTHRU, IS_TRIE);
}
/* }}} */

/* {{{ proto bool Trie::offsetExists( string key )
 */
PHP_METHOD(Trie, offsetExists)
{
  keyExists(INTERNAL_FUNCTION_PARAM_PASSTHRU, IS_TRIE);
}
/* }}} */

/* {{{ proto void Trie::offsetUnset( string key )
 */
PHP_METHOD(Trie, offsetUnset)
{
  keyDelete(INTERNAL_FUNCTION_PARAM_PASSTHRU, IS_TRIE);
}
/* }}} */

/* {{{ proto array Trie::toArray()
 */
PHP_METHOD(Trie, toArray)
{
  trieToArray(INTERNAL_FUNCTION_PARAM_PASSTHRU);
}
/* }}} */

/* {{{ proto Trie Trie::jsonSerialize()
 */
PHP_METHOD(Trie, jsonSerialize)
{
  trieToArray(INTERNAL_FUNCTION_PARAM_PASSTHRU);
}
/* }}} */

/* {{{ proto Trie Trie::prefixSearch( string prefix )
 */
PHP_METHOD(Trie, prefixSearch)
{
  triePrefixSearch(INTERNAL_FUNCTION_PARAM_PASSTHRU);
}
/* }}} */

/* {{{ proto Trie Trie::map( callable func )
 */
PHP_METHOD(Trie, map)
{
  trieMap(INTERNAL_FUNCTION_PARAM_PASSTHRU);
}
/* }}} */

/* {{{ proto Trie Trie::filter( callable func )
 */
PHP_METHOD(Trie, filter)
{
  trieFilter(INTERNAL_FUNCTION_PARAM_PASSTHRU);
}
/* }}} */

/* {{{ proto Trie Trie::merge([ Trie trie... ])
 */
PHP_METHOD(Trie, merge)
{
  trieMerge(INTERNAL_FUNCTION_PARAM_PASSTHRU, IS_TRIE);
}
/* }}} */

/* ---- HatTrie methods ----- */

/* {{{ proto HatTrie::__construct( int burstThreshold [, double loadFactor [, bool shrink ]] )
 */
PHP_METHOD(HatTrie, __construct)
{
  hatConstruct(INTERNAL_FUNCTION_PARAM_PASSTHRU);
}
/* }}} */

/* {{{ proto bool HatTrie::insert( string key [, mixed value ] )
 */
PHP_METHOD(HatTrie, insert)
{
  insert(INTERNAL_FUNCTION_PARAM_PASSTHRU, IS_HATTRIE);
}
/* }}} */

/* {{{ proto mixed HatTrie::search( string key )
 */
PHP_METHOD(HatTrie, search)
{
  search(INTERNAL_FUNCTION_PARAM_PASSTHRU, IS_HATTRIE);
}
/* }}} */

/* {{{ proto HatTrie HatTrie::prefixSearch( string prefix )
 */
PHP_METHOD(HatTrie, prefixSearch)
{
  hatPrefixSearch(INTERNAL_FUNCTION_PARAM_PASSTHRU);
}
/* }}} */

/* proto HatTrie HatTrie::map( callable func )
 */
PHP_METHOD(HatTrie, map)
{
  hatMap(INTERNAL_FUNCTION_PARAM_PASSTHRU);
}
/* }}} */

/* {{{ proto bool HatTrie::keyExists( string key )
 */
PHP_METHOD(HatTrie, keyExists)
{
  keyExists(INTERNAL_FUNCTION_PARAM_PASSTHRU, IS_HATTRIE);
}
/* }}} */

/* {{{ proto static HatTrie::fromArray( array entry [, int burstThreshold [, double loadFactor [, bool shrink ]]] )
 */
PHP_METHOD(HatTrie, fromArray)
{
  hatFromArray(INTERNAL_FUNCTION_PARAM_PASSTHRU);
}
/* }}} */

/* {{{ proto array HatTrie::toArray()
 */
PHP_METHOD(HatTrie, toArray)
{
  hatToArray(INTERNAL_FUNCTION_PARAM_PASSTHRU);
}
/* }}} */

/* {{{ proto HatTrie HatTrie::prefixErase( string prefix )
 */
PHP_METHOD(HatTrie, prefixErase)
{
  hatPrefixErase(INTERNAL_FUNCTION_PARAM_PASSTHRU);
}
/* }}} */

/* {{{ proto void HatTrie::erase( string key )
 */
PHP_METHOD(HatTrie, erase)
{
  keyDelete(INTERNAL_FUNCTION_PARAM_PASSTHRU, IS_HATTRIE);
}
/* }}} */

/* {{{ proto HatTrie HatTrie::fold( callable function [, mixed accumulator ] )
 */
PHP_METHOD(HatTrie, fold)
{
  hatFold(INTERNAL_FUNCTION_PARAM_PASSTHRU);
}
/* }}} */

/* {{{ proto HatTrie HatTrie::filter( callable function )
 */
PHP_METHOD(HatTrie, filter)
{
  hatFilter(INTERNAL_FUNCTION_PARAM_PASSTHRU);
}
/* }}} */

/* {{{ proto array HatTrie::jsonSerialize()
 */
PHP_METHOD(HatTrie, jsonSerialize)
{
  hatToArray(INTERNAL_FUNCTION_PARAM_PASSTHRU);
}
/* }}} */

/* {{{ proto mixed HatTrie::offsetGet( string key )
 */
PHP_METHOD(HatTrie, offsetGet)
{
  search(INTERNAL_FUNCTION_PARAM_PASSTHRU, IS_HATTRIE);
}
/* }}} */

/* {{{ proto bool HatTrie::offsetSet( string key [, mixed value ] )
 */
PHP_METHOD(HatTrie, offsetSet)
{
  insert(INTERNAL_FUNCTION_PARAM_PASSTHRU, IS_HATTRIE);
}
/* }}} */

/* {{{ proto void HatTrie::offsetUnset( string key )
 */
PHP_METHOD(HatTrie, offsetUnset)
{
  keyDelete(INTERNAL_FUNCTION_PARAM_PASSTHRU, IS_HATTRIE);
}
/* }}} */

/* {{{ proto bool HatTrie::offsetExists( string key )
 */
PHP_METHOD(HatTrie, offsetExists)
{
  keyExists(INTERNAL_FUNCTION_PARAM_PASSTHRU, IS_HATTRIE);
}
/* }}} */

/* {{{ proto int HatTrie::size()
 */
PHP_METHOD(HatTrie, size)
{
  count(INTERNAL_FUNCTION_PARAM_PASSTHRU, IS_HATTRIE);
}
/* }}} */

/* {{{ proto array longestPrefix( string prefix )
 */
PHP_METHOD(HatTrie, longestPrefix)
{
  hatLongestPrefix(INTERNAL_FUNCTION_PARAM_PASSTHRU);
}
/* }}} */

/* {{{ proto HatTrie HatTrie::merge([ HatTrie trie... ])
 */
PHP_METHOD(HatTrie, merge)
{
  trieMerge(INTERNAL_FUNCTION_PARAM_PASSTHRU, IS_HATTRIE);
}
/* }}} */

ZEND_BEGIN_ARG_INFO_EX(arginfo_trieconstruct, 0, 0, 0)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arginfo_hatconstruct, 0, 0, 3)
ZEND_ARG_INFO(0, burstThreshold)
ZEND_ARG_INFO(0, loadFactor)
ZEND_ARG_INFO(0, shrink)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arginfo_hatfromarray, 0, 0, 4)
ZEND_ARG_ARRAY_INFO(0, array, 0)
ZEND_ARG_INFO(0, burstThreshold)
ZEND_ARG_INFO(0, loadFactor)
ZEND_ARG_INFO(0, shrink)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_to_array, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO();

#if ZEND_MODULE_API_NO >= ZEND_API_PHP80
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_insert, 0, 2, IS_VOID, 0)
ZEND_ARG_TYPE_INFO(0, key, IS_MIXED, 0)
ZEND_ARG_TYPE_INFO(0, entry, IS_MIXED, 0)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_get, 0, 1, IS_MIXED, 0)
ZEND_ARG_TYPE_INFO(0, key, IS_MIXED, 0)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_check, 0, 1, _IS_BOOL, 0)
ZEND_ARG_TYPE_INFO(0, key, IS_MIXED, 0)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_del, 0, 1, IS_VOID, 0)
ZEND_ARG_TYPE_INFO(0, key, IS_MIXED, 0)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_json_serialize, 0, 0, IS_MIXED, 0)
ZEND_END_ARG_INFO();
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_insert, 0, 0, 2)
ZEND_ARG_INFO(0, key)
ZEND_ARG_INFO(0, entry)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arginfo_get, 0, 0, 1)
ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO();
#endif

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_count, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arginfo_onlyhash, 0, 0, 1)
ZEND_ARG_ARRAY_INFO(0, array, 0)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arginfo_onlycallable, 0, 0, 1)
ZEND_ARG_TYPE_INFO(0, func, IS_CALLABLE, 0)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arginfo_fold, 0, 0, 2)
ZEND_ARG_TYPE_INFO(0, func, IS_CALLABLE, 0)
ZEND_ARG_INFO(0, accumulator)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arginfo_onlyprefix, 0, 0, 1)
ZEND_ARG_INFO(0, prefix)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_merge, 0, 0, IS_ARRAY, 0)
ZEND_ARG_VARIADIC_TYPE_INFO(0, tries, IS_OBJECT, 0)
ZEND_END_ARG_INFO();

static const zend_function_entry hattrie_methods[] = {
    PHP_ME(HatTrie, __construct, arginfo_hatconstruct, ZEND_ACC_PUBLIC | ZEND_ACC_CTOR)
        PHP_ME(HatTrie, fromArray, arginfo_hatfromarray, ZEND_ACC_PUBLIC | ZEND_ACC_STATIC)
            PHP_ME(HatTrie, fold, arginfo_fold, ZEND_ACC_PUBLIC)
#if ZEND_MODULE_API_NO >= ZEND_API_PHP80
                PHP_ME(HatTrie, size, arginfo_count, ZEND_ACC_PUBLIC)
                    PHP_ME(HatTrie, toArray, arginfo_to_array, ZEND_ACC_PUBLIC)
                        PHP_ME(HatTrie, jsonSerialize, arginfo_json_serialize, ZEND_ACC_PUBLIC)
                            PHP_ME(HatTrie, keyExists, arginfo_check, ZEND_ACC_PUBLIC)
                                PHP_ME(HatTrie, offsetExists, arginfo_check, ZEND_ACC_PUBLIC)
                                    PHP_ME(HatTrie, offsetUnset, arginfo_del, ZEND_ACC_PUBLIC)
                                        PHP_ME(HatTrie, erase, arginfo_del, ZEND_ACC_PUBLIC)
#else
                PHP_ME(HatTrie, size, NULL, ZEND_ACC_PUBLIC)
                    PHP_ME(HatTrie, toArray, NULL, ZEND_ACC_PUBLIC)
                        PHP_ME(HatTrie, jsonSerialize, NULL, ZEND_ACC_PUBLIC)
                            PHP_ME(HatTrie, erase, arginfo_get, ZEND_ACC_PUBLIC)
                                PHP_ME(HatTrie, keyExists, arginfo_get, ZEND_ACC_PUBLIC)
                                    PHP_ME(HatTrie, offsetExists, arginfo_get, ZEND_ACC_PUBLIC)
                                        PHP_ME(HatTrie, offsetUnset, arginfo_get, ZEND_ACC_PUBLIC)
#endif
                                            PHP_ME(HatTrie, filter, arginfo_onlycallable, ZEND_ACC_PUBLIC)
                                                PHP_ME(HatTrie, search, arginfo_get, ZEND_ACC_PUBLIC)
                                                    PHP_ME(HatTrie, prefixSearch, arginfo_onlyprefix, ZEND_ACC_PUBLIC)
                                                        PHP_ME(HatTrie, prefixErase, arginfo_onlyprefix, ZEND_ACC_PUBLIC)
                                                            PHP_ME(HatTrie, longestPrefix, arginfo_onlyprefix, ZEND_ACC_PUBLIC)
                                                                PHP_ME(HatTrie, map, arginfo_onlycallable, ZEND_ACC_PUBLIC)
                                                                    PHP_ME(HatTrie, insert, arginfo_insert, ZEND_ACC_PUBLIC)
                                                                        PHP_ME(HatTrie, offsetSet, arginfo_insert, ZEND_ACC_PUBLIC)
                                                                            PHP_ME(HatTrie, offsetGet, arginfo_get, ZEND_ACC_PUBLIC)
                                                                                PHP_ME(HatTrie, merge, arginfo_merge, ZEND_ACC_PUBLIC)
                                                                                    PHP_FE_END};

static const zend_function_entry trie_methods[] = {
    PHP_ME(Trie, __construct, arginfo_trieconstruct, ZEND_ACC_PUBLIC | ZEND_ACC_CTOR)
        PHP_ME(Trie, fromArray, arginfo_onlyhash, ZEND_ACC_PUBLIC | ZEND_ACC_STATIC)
            PHP_ME(Trie, insert, arginfo_insert, ZEND_ACC_PUBLIC)
                PHP_ME(Trie, search, arginfo_get, ZEND_ACC_PUBLIC)
#if ZEND_MODULE_API_NO >= ZEND_API_PHP80
                    PHP_ME(Trie, size, arginfo_count, ZEND_ACC_PUBLIC)
                        PHP_ME(Trie, toArray, arginfo_to_array, ZEND_ACC_PUBLIC)
                            PHP_ME(Trie, jsonSerialize, arginfo_json_serialize, ZEND_ACC_PUBLIC)
                                PHP_ME(Trie, keyExists, arginfo_check, ZEND_ACC_PUBLIC)
                                    PHP_ME(Trie, offsetExists, arginfo_check, ZEND_ACC_PUBLIC)
                                        PHP_ME(Trie, offsetUnset, arginfo_del, ZEND_ACC_PUBLIC)
                                            PHP_ME(Trie, erase, arginfo_del, ZEND_ACC_PUBLIC)
#else
                    PHP_ME(Trie, size, NULL, ZEND_ACC_PUBLIC)
                        PHP_ME(Trie, toArray, NULL, ZEND_ACC_PUBLIC)
                            PHP_ME(Trie, jsonSerialize, NULL, ZEND_ACC_PUBLIC)
                                PHP_ME(Trie, keyExists, arginfo_get, ZEND_ACC_PUBLIC)
                                    PHP_ME(Trie, offsetExists, arginfo_get, ZEND_ACC_PUBLIC)
                                        PHP_ME(Trie, offsetUnset, arginfo_get, ZEND_ACC_PUBLIC)
                                            PHP_ME(Trie, erase, arginfo_get, ZEND_ACC_PUBLIC)
#endif
                                                PHP_ME(Trie, offsetSet, arginfo_insert, ZEND_ACC_PUBLIC)
                                                    PHP_ME(Trie, offsetGet, arginfo_get, ZEND_ACC_PUBLIC)
                                                        PHP_ME(Trie, prefixSearch, arginfo_onlyprefix, ZEND_ACC_PUBLIC)
                                                            PHP_ME(Trie, map, arginfo_onlycallable, ZEND_ACC_PUBLIC)
                                                                PHP_ME(Trie, filter, arginfo_onlycallable, ZEND_ACC_PUBLIC)
                                                                    PHP_ME(Trie, merge, arginfo_merge, ZEND_ACC_PUBLIC)
                                                                        PHP_FE_END};

/* {{{ PHP_RINIT_FUNCTION
 */
PHP_RINIT_FUNCTION(php_trie)
{
#if defined(ZTS) && defined(COMPILE_DL_PHP_TRIE)
  ZEND_TSRMLS_CACHE_UPDATE();
#endif

  return SUCCESS;
}
/* }}} */

/**
 * @brief check if HAT trie library is available
 *
 * @return const char*
 */
static const char *hatTrieCheck()
{
#ifndef TSL_HTRIE_MAP_H
  return "no";
#else
  return "yes";
#endif
}

/* {{{ PHP_MINFO_FUNCTION
 */
PHP_MINFO_FUNCTION(php_trie)
{
  php_info_print_table_start();
  php_info_print_table_header(2, "php_trie support", "enabled");
  php_info_print_table_header(2, "php_trie version", PHP_TRIE_EXT_EXTVER);
  php_info_print_table_header(2, "php_trie author", "Lochemem Bruno Michael <lochbm@gmail.com>");
  php_info_print_table_header(2, "Trie available", "yes");
  php_info_print_table_header(2, "Hat Trie available", hatTrieCheck());
  php_info_print_table_end();
}
/* }}} */

/* {{{ PHP_MINIT_FUNCTION
 */
PHP_MINIT_FUNCTION(php_trie)
{
  zend_class_entry ce;
  zend_class_entry hat_ce;
  zend_class_entry exception_ce;

  INIT_CLASS_ENTRY(ce, "Trie", trie_methods);
  INIT_CLASS_ENTRY(hat_ce, "HatTrie", hattrie_methods);
  INIT_CLASS_ENTRY(exception_ce, "TrieException", NULL);

#define TRIE_OBJECT_REGISTER(type, entry)                                                          \
  type##_ce = zend_register_internal_class(&entry);                                                \
  type##_ce->create_object = type##_object_new;                                                    \
  memcpy(&type##_object_handlers, zend_get_std_object_handlers(), sizeof(type##_object_handlers)); \
  type##_object_handlers.free_obj = type##_object_free;                                            \
  type##_object_handlers.dtor_obj = type##_object_destroy;                                         \
  type##_object_handlers.offset = XtOffsetOf(type##_object, std);

  TRIE_OBJECT_REGISTER(phptrie, ce);
  TRIE_OBJECT_REGISTER(phphattrie, hat_ce);

#if ZEND_MODULE_API_NO < ZEND_API_PHP80
  phptrie_object_handlers.count_elements = phptrie_count_elements;
  phphattrie_object_handlers.count_elements = phphattrie_count_elements;
#endif

  zend_declare_class_constant_bool(phphattrie_ce, "SHRINK", sizeof("SHRINK") - 1, 1);
  zend_declare_class_constant_bool(phphattrie_ce, "NO_SHRINK", sizeof("NO_SHRINK") - 1, 0);
  zend_declare_class_constant_double(phphattrie_ce,
                                     "DEFAULT_LOAD_FACTOR",
                                     sizeof("DEFAULT_LOAD_FACTOR") - 1,
                                     DEFAULT_LOAD_FACTOR);
  zend_declare_class_constant_long(phphattrie_ce,
                                   "DEFAULT_BURST_THRESHOLD",
                                   sizeof("DEFAULT_BURST_THRESHOLD") - 1,
                                   DEFAULT_BURST_THRESHOLD);

#ifdef HAVE_SPL
  phptrie_exception_ce = zend_register_internal_class_ex(
      &exception_ce, spl_ce_RuntimeException);
#else
  phptrie_exception_ce = zend_register_internal_class_ex(
      &exception_ce, zend_exception_get_default());
#endif

  // #define TRIE_IMPLEMENTS(type) zend_class_implements(type##_ce, 2, zend_ce_arrayaccess, php_json_serializable_ce);

  zend_class_implements(phphattrie_ce, 2, zend_ce_arrayaccess, php_json_serializable_ce);
  zend_class_implements(phptrie_ce, 2, zend_ce_arrayaccess, php_json_serializable_ce);
  // TRIE_IMPLEMENTS(phptrie);
  // TRIE_IMPLEMENTS(phphattrie);

  return SUCCESS;
}
/* }}} */

static zend_module_dep php_trie_deps[] = {
    ZEND_MOD_REQUIRED("json")
        ZEND_MOD_END};

/* {{{ php_trie_module_entry
 */
zend_module_entry php_trie_module_entry = {
    STANDARD_MODULE_HEADER_EX,
    NULL,
    php_trie_deps,
    "php_trie",                          /* Extension name */
    trie_methods,                        /* zend_function_entry */
    PHP_MINIT(php_trie),                 /* PHP_MINIT - Module initialization */
    NULL,                                /* PHP_MSHUTDOWN - Module shutdown */
    PHP_RINIT(php_trie),                 /* PHP_RINIT - Request initialization */
    NULL,                                /* PHP_RSHUTDOWN - Request shutdown */
    PHP_MINFO(php_trie),                 /* PHP_MINFO - Module info */
#if ZEND_MODULE_API_NO >= ZEND_API_PHP73 // PHP >= 7.3.0
    PHP_TRIE_EXT_EXTVER,                 /* Version */
#endif
    STANDARD_MODULE_PROPERTIES};
/* }}} */

#ifdef COMPILE_DL_PHP_TRIE
#ifdef ZTS
ZEND_TSRMLS_CACHE_DEFINE()
#endif
ZEND_GET_MODULE(php_trie)
#endif
