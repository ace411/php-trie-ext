/**
 * @file php_trie.cpp
 * @author Lochemem Bruno Michael (lochbm@gmail.com)
 * @brief php_trie extension core file
 * @version 0.1.0
 * 
 * @copyright Copyright (c) 1999-2019 The PHP Group
 * 
 */
#include "common.cpp"

/* {{{ proto Trie::__construct()
 */
PHP_METHOD(Trie, __construct)
{
  trieConstruct(INTERNAL_FUNCTION_PARAM_PASSTHRU, IS_TRIE);
}
/* }}} */

/* {{{ proto bool Trie::insert(string key, mixed entry)
 */
PHP_METHOD(Trie, insert)
{
  trieInsert(INTERNAL_FUNCTION_PARAM_PASSTHRU, IS_TRIE);
}
/* }}} */

/* {{{ proto bool Trie::keyExists(string key)
 */
PHP_METHOD(Trie, keyExists)
{
  trieKeyExists(INTERNAL_FUNCTION_PARAM_PASSTHRU, IS_TRIE);
}
/* }}} */

/* {{{ proto static Trie::fromArray(array entries)
 */
PHP_METHOD(Trie, fromArray)
{
  trieFromArray(INTERNAL_FUNCTION_PARAM_PASSTHRU, IS_TRIE);
}
/* }}} */

/* {{{ proto mixed Trie::search(string key)
 */
PHP_METHOD(Trie, search)
{
  trieSearch(INTERNAL_FUNCTION_PARAM_PASSTHRU, IS_TRIE);
}
/* }}} */

/* {{{ proto void Trie::erase(string key)
 */
PHP_METHOD(Trie, erase)
{
  trieKeyDelete(INTERNAL_FUNCTION_PARAM_PASSTHRU, IS_TRIE);
}
/* }}} */

/* {{{ proto bool Trie::offsetSet(string key, mixed entry)
 */
PHP_METHOD(Trie, offsetSet)
{
  trieInsert(INTERNAL_FUNCTION_PARAM_PASSTHRU, IS_TRIE);
}
/* }}} */

/* {{{ proto mixed Trie::offsetGet(string key)
 */
PHP_METHOD(Trie, offsetGet)
{
  trieSearch(INTERNAL_FUNCTION_PARAM_PASSTHRU, IS_TRIE);
}
/* }}} */

/* {{{ proto int Trie::size()
 */
PHP_METHOD(Trie, size)
{
  trieCount(INTERNAL_FUNCTION_PARAM_PASSTHRU, IS_TRIE);
}
/* }}} */

/* {{{ proto bool Trie::offsetExists(string key)
 */
PHP_METHOD(Trie, offsetExists)
{
  trieKeyExists(INTERNAL_FUNCTION_PARAM_PASSTHRU, IS_TRIE);
}
/* }}} */

/* {{{ proto void Trie::offsetUnset(string key)
 */
PHP_METHOD(Trie, offsetUnset)
{
  trieKeyDelete(INTERNAL_FUNCTION_PARAM_PASSTHRU, IS_TRIE);
}
/* }}} */

/* {{{ proto array Trie::toArray()
 */
PHP_METHOD(Trie, toArray)
{
  trieToArray(INTERNAL_FUNCTION_PARAM_PASSTHRU);
}
/* }}} */

PHP_METHOD(Trie, jsonSerialize)
{
  trieToArray(INTERNAL_FUNCTION_PARAM_PASSTHRU);
}

/* ---- HatTrie methods ----- */

/* {{{ proto HatTrie::__construct()
 */
PHP_METHOD(HatTrie, __construct)
{
  trieConstruct(INTERNAL_FUNCTION_PARAM_PASSTHRU, IS_HATTRIE);
}
/* }}} */

/* {{{ proto bool HatTrie::insert(string key, mixed value)
 */
PHP_METHOD(HatTrie, insert)
{
  trieInsert(INTERNAL_FUNCTION_PARAM_PASSTHRU, IS_HATTRIE);
}
/* }}} */

/* {{{ proto mixed HatTrie::search(string key)
 */
PHP_METHOD(HatTrie, search)
{
  trieSearch(INTERNAL_FUNCTION_PARAM_PASSTHRU, IS_HATTRIE);
}
/* }}} */

/* {{{ proto HatTrie HatTrie::prefixSearch(string prefix)
 */
PHP_METHOD(HatTrie, prefixSearch)
{
  hatPrefixSearch(INTERNAL_FUNCTION_PARAM_PASSTHRU);
}
/* }}} */

/* proto HatTrie HatTrie::map(callable func)
 */
PHP_METHOD(HatTrie, map)
{
  hatMap(INTERNAL_FUNCTION_PARAM_PASSTHRU);
}
/* }}} */

/* {{{ proto bool HatTrie::keyExists(string key)
 */
PHP_METHOD(HatTrie, keyExists)
{
  trieKeyExists(INTERNAL_FUNCTION_PARAM_PASSTHRU, IS_HATTRIE);
}
/* }}} */

/* {{{ proto static HatTrie::fromArray(array entry)
 */
PHP_METHOD(HatTrie, fromArray)
{
  trieFromArray(INTERNAL_FUNCTION_PARAM_PASSTHRU, IS_HATTRIE);
}
/* }}} */

/* {{{ proto array HatTrie::toArray()
 */
PHP_METHOD(HatTrie, toArray)
{
  hatToArray(INTERNAL_FUNCTION_PARAM_PASSTHRU);
}
/* }}} */

/* {{{ proto HatTrie HatTrie::prefixErase(string prefix)
 */
PHP_METHOD(HatTrie, prefixErase)
{
  hatPrefixErase(INTERNAL_FUNCTION_PARAM_PASSTHRU);
}
/* }}} */

/* {{{ proto void HatTrie::erase(string key)
 */
PHP_METHOD(HatTrie, erase)
{
  trieKeyDelete(INTERNAL_FUNCTION_PARAM_PASSTHRU, IS_HATTRIE);
}
/* }}} */

/* {{{ proto HatTrie HatTrie::fold(callable function [, mixed accumulator ])
 */
PHP_METHOD(HatTrie, fold)
{
  hatFold(INTERNAL_FUNCTION_PARAM_PASSTHRU);
}
/* }}} */

/* {{{ proto HatTrie HatTrie::filter(callable function)
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

/* {{{ proto mixed HatTrie::offsetGet(string key)
 */
PHP_METHOD(HatTrie, offsetGet)
{
  trieSearch(INTERNAL_FUNCTION_PARAM_PASSTHRU, IS_HATTRIE);
}
/* }}} */

/* {{{ proto bool HatTrie::offsetSet(string key, mixed value)
 */
PHP_METHOD(HatTrie, offsetSet)
{
  trieInsert(INTERNAL_FUNCTION_PARAM_PASSTHRU, IS_HATTRIE);
}
/* }}} */

/* {{{ proto void HatTrie::offsetUnset(string key)
 */
PHP_METHOD(HatTrie, offsetUnset)
{
  trieKeyDelete(INTERNAL_FUNCTION_PARAM_PASSTHRU, IS_HATTRIE);
}
/* }}} */

/* {{{ proto bool HatTrie::offsetExists(string key)
 */
PHP_METHOD(HatTrie, offsetExists)
{
  trieKeyExists(INTERNAL_FUNCTION_PARAM_PASSTHRU, IS_HATTRIE);
}
/* }}} */

PHP_METHOD(HatTrie, size)
{
  trieCount(INTERNAL_FUNCTION_PARAM_PASSTHRU, IS_HATTRIE);
}

ZEND_BEGIN_ARG_INFO_EX(arginfo_insert, 0, 0, 2)
ZEND_ARG_INFO(0, key)
ZEND_ARG_INFO(0, entry)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arginfo_onlykey, 0, 0, 1)
ZEND_ARG_INFO(0, key)
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

static const zend_function_entry hattrie_methods[] = {
    PHP_ME(HatTrie, __construct, NULL, ZEND_ACC_PUBLIC | ZEND_ACC_CTOR)
        PHP_ME(HatTrie, fromArray, arginfo_onlyhash, ZEND_ACC_PUBLIC | ZEND_ACC_STATIC)
            PHP_ME(HatTrie, fold, arginfo_fold, ZEND_ACC_PUBLIC)
                PHP_ME(HatTrie, size, NULL, ZEND_ACC_PUBLIC)
                    PHP_ME(HatTrie, filter, arginfo_onlycallable, ZEND_ACC_PUBLIC)
                        PHP_ME(HatTrie, insert, arginfo_insert, ZEND_ACC_PUBLIC)
                            PHP_ME(HatTrie, keyExists, arginfo_onlykey, ZEND_ACC_PUBLIC)
                                PHP_ME(HatTrie, search, arginfo_onlykey, ZEND_ACC_PUBLIC)
                                    PHP_ME(HatTrie, erase, arginfo_onlykey, ZEND_ACC_PUBLIC)
                                        PHP_ME(HatTrie, prefixSearch, arginfo_onlykey, ZEND_ACC_PUBLIC)
                                            PHP_ME(HatTrie, prefixErase, arginfo_onlykey, ZEND_ACC_PUBLIC)
                                                PHP_ME(HatTrie, map, arginfo_onlycallable, ZEND_ACC_PUBLIC)
                                                    PHP_ME(HatTrie, offsetSet, arginfo_insert, ZEND_ACC_PUBLIC)
                                                        PHP_ME(HatTrie, offsetGet, arginfo_onlykey, ZEND_ACC_PUBLIC)
                                                            PHP_ME(HatTrie, offsetExists, arginfo_onlykey, ZEND_ACC_PUBLIC)
                                                                PHP_ME(HatTrie, offsetUnset, arginfo_onlykey, ZEND_ACC_PUBLIC)
                                                                    PHP_ME(HatTrie, toArray, NULL, ZEND_ACC_PUBLIC)
                                                                        PHP_ME(HatTrie, jsonSerialize, NULL, ZEND_ACC_PUBLIC)
                                                                            PHP_FE_END};

static const zend_function_entry trie_methods[] = {
    PHP_ME(Trie, __construct, NULL, ZEND_ACC_PUBLIC | ZEND_ACC_CTOR)
        PHP_ME(Trie, fromArray, arginfo_onlyhash, ZEND_ACC_PUBLIC | ZEND_ACC_STATIC)
            PHP_ME(Trie, insert, arginfo_insert, ZEND_ACC_PUBLIC)
                PHP_ME(Trie, keyExists, arginfo_onlykey, ZEND_ACC_PUBLIC)
                    PHP_ME(Trie, search, arginfo_onlykey, ZEND_ACC_PUBLIC)
                        PHP_ME(Trie, erase, arginfo_onlykey, ZEND_ACC_PUBLIC)
                            PHP_ME(Trie, size, NULL, ZEND_ACC_PUBLIC)
                                PHP_ME(Trie, offsetSet, arginfo_insert, ZEND_ACC_PUBLIC)
                                    PHP_ME(Trie, offsetGet, arginfo_onlykey, ZEND_ACC_PUBLIC)
                                        PHP_ME(Trie, offsetExists, arginfo_onlykey, ZEND_ACC_PUBLIC)
                                            PHP_ME(Trie, offsetUnset, arginfo_onlykey, ZEND_ACC_PUBLIC)
                                                PHP_ME(Trie, toArray, NULL, ZEND_ACC_PUBLIC)
                                                    PHP_ME(Trie, jsonSerialize, NULL, ZEND_ACC_PUBLIC)
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

/* {{{ PHP_MINFO_FUNCTION
 */
PHP_MINFO_FUNCTION(php_trie)
{
  php_info_print_table_start();
  php_info_print_table_header(2, "php_trie support", "enabled");
  php_info_print_table_header(2, "php_trie version", PHP_TRIE_EXT_EXTVER);
  php_info_print_table_header(2, "php_trie author", "Lochemem Bruno Michael <lochbm@gmail.com>");
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
  type##_ce = zend_register_internal_class(&entry TSRMLS_CC);                                      \
  type##_ce->create_object = type##_object_new;                                                    \
  memcpy(&type##_object_handlers, zend_get_std_object_handlers(), sizeof(type##_object_handlers)); \
  type##_object_handlers.free_obj = type##_object_free;                                            \
  type##_object_handlers.dtor_obj = type##_object_destroy;                                         \
  type##_object_handlers.offset = XtOffsetOf(type##_object, std);

  TRIE_OBJECT_REGISTER(phptrie, ce);
  TRIE_OBJECT_REGISTER(phphattrie, hat_ce);

#ifdef HAVE_SPL
  phptrie_exception_ce = zend_register_internal_class_ex(
      &exception_ce, spl_ce_RuntimeException);
#else
  phptrie_exception_ce = zend_register_internal_class_ex(
      &exception_ce, zend_exception_get_default(TSRMLS_C));
#endif

#define TRIE_IMPLEMENTS(type) \
  zend_class_implements(type##_ce TSRMLS_CC, 2, zend_ce_arrayaccess, php_json_serializable_ce);

  TRIE_IMPLEMENTS(phptrie);
  TRIE_IMPLEMENTS(phphattrie);

  return SUCCESS;
}
/* }}} */

/* {{{ php_trie_module_entry
 */
zend_module_entry php_trie_module_entry = {
    STANDARD_MODULE_HEADER,
    "php_trie",                    /* Extension name */
    trie_methods,                  /* zend_function_entry */
    PHP_MINIT(php_trie),           /* PHP_MINIT - Module initialization */
    NULL,                          /* PHP_MSHUTDOWN - Module shutdown */
    PHP_RINIT(php_trie),           /* PHP_RINIT - Request initialization */
    NULL,                          /* PHP_RSHUTDOWN - Request shutdown */
    PHP_MINFO(php_trie),           /* PHP_MINFO - Module info */
#if ZEND_MODULE_API_NO >= 20181206 // PHP >= 7.3.0
    PHP_TRIE_EXT_EXTVER,           /* Version */
#endif
    STANDARD_MODULE_PROPERTIES};
/* }}} */

#ifdef COMPILE_DL_PHP_TRIE
#ifdef ZTS
ZEND_TSRMLS_CACHE_DEFINE()
#endif
ZEND_GET_MODULE(php_trie)
#endif
