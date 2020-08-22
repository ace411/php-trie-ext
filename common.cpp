/**
 * @file common.cpp
 * @author Lochemem Bruno Michael (lochbm@gmail.com)
 * @brief file containing C++ implementations of PHP userland-destined functions
 * @version 0.1.0
 * 
 * @copyright Copyright (c) 1999-2019 The PHP Group
 * 
 */

#include "php_trie_ext.h"
#include "trie.h"

using namespace trie;

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#ifdef HAVE_SPL
#include "ext/spl/spl_exceptions.h"
#endif

/* For compatibility with older PHP versions */
#ifndef ZEND_PARSE_PARAMETERS_NONE
#define ZEND_PARSE_PARAMETERS_NONE() \
  ZEND_PARSE_PARAMETERS_START(0, 0)  \
  ZEND_PARSE_PARAMETERS_END()
#endif

zend_object_handlers phptrie_object_handlers;
zend_object_handlers phphattrie_object_handlers;

/* phptrie object instantiation */
zend_class_entry *phptrie_ce;
zend_class_entry *phphattrie_ce; // HAT Trie class
zend_class_entry *phptrie_exception_ce;

/* phptrie object struct */
typedef struct _phptrie_object
{
  Trie *trie;
  zend_object std;
} phptrie_object;

/* phphattrie object */
typedef struct _phphattrie_object
{
  HatTrie *hat;
  zend_object std;
} phphattrie_object;

#define TRIEOBJ_INIT(type, object) \
  return (type##_object *)((char *)(object)-XtOffsetOf(type##_object, std));

static inline phptrie_object *phptrie_obj_from_obj(zend_object *obj)
{
  TRIEOBJ_INIT(phptrie, obj);
}

static inline phphattrie_object *phphattrie_obj_from_obj(zend_object *obj)
{
  TRIEOBJ_INIT(phphattrie, obj);
}

#define Z_TRIEOBJ_P(zv) phptrie_obj_from_obj(Z_OBJ_P((zv)))
#define Z_HATOBJ_P(zv) phphattrie_obj_from_obj(Z_OBJ_P((zv)))

// macro to throw TrieException
#define TRIE_THROW(msg)                                         \
  zend_throw_exception(phptrie_exception_ce, msg, 0 TSRMLS_CC); \
  RETURN_NULL();

// macro to create a Trie object
#define TRIE_OBJECT_CREATE(type, entry)                                                                            \
  type##_object *intern = (type##_object *)ecalloc(1, sizeof(type##_object) + zend_object_properties_size(entry)); \
  zend_object_std_init(&intern->std, entry TSRMLS_CC);                                                             \
  object_properties_init(&intern->std, entry);                                                                     \
  intern->std.handlers = &type##_object_handlers;                                                                  \
  return &intern->std;

// macro to destroy a Trie object
#define TRIE_OBJECT_DESTROY(type, object)                                   \
  type##_object *obj;                                                       \
  obj = (type##_object *)((char *)object - XtOffsetOf(type##_object, std)); \
  zend_objects_destroy_object(object);

// macro to free a Trie object
#define TRIE_OBJECT_FREE(name, type, object)                                \
  type##_object *obj;                                                       \
  obj = (type##_object *)((char *)object - XtOffsetOf(type##_object, std)); \
  delete obj->name;                                                         \
  zend_object_std_dtor(object);

/**
 * @brief creates new phptrie object
 * 
 * @param ce  
 * @return zend_object* 
 */
zend_object *phptrie_object_new(zend_class_entry *ce TSRMLS_DC)
{
  TRIE_OBJECT_CREATE(phptrie, ce);
}

/**
 * @brief creates new phphattrie object
 * 
 * @param ce  
 * @return zend_object* 
 */
zend_object *phphattrie_object_new(zend_class_entry *ce TSRMLS_DC)
{
  TRIE_OBJECT_CREATE(phphattrie, ce);
}

/**
 * @brief destroys phptrie object
 * 
 * @param object 
 */
static void phptrie_object_destroy(zend_object *object)
{
  TRIE_OBJECT_DESTROY(phptrie, object);
}

/**
 * @brief destroys phphattrie object
 * 
 * @param object 
 */
static void phphattrie_object_destroy(zend_object *object)
{
  TRIE_OBJECT_DESTROY(phphattrie, object);
}

/**
 * @brief releases the memory allocated to phptrie object
 * 
 * @param object 
 */
static void phptrie_object_free(zend_object *object)
{
  TRIE_OBJECT_FREE(trie, phptrie, object);
}

/**
 * @brief releases the memory allocated to phphattrie object
 * 
 * @param object 
 */
static void phphattrie_object_free(zend_object *object)
{
  TRIE_OBJECT_FREE(hat, phphattrie, object);
}

/* ---- common routines ----- */

/**
 * @brief PHP trie/HAT trie object constructor
 * 
 * @param type 
 */
static void trieConstruct(INTERNAL_FUNCTION_PARAMETERS, long type)
{
  zval *obj = getThis();
  phptrie_object *trie;
  phphattrie_object *hat;

  ZEND_PARSE_PARAMETERS_NONE();

  switch (type)
  {
  case IS_HATTRIE:
    hat = Z_HATOBJ_P(obj);
    break;

  case IS_TRIE:
    trie = Z_TRIEOBJ_P(obj);
    break;
  }

  if (trie != NULL || hat != NULL)
  {
    switch (type)
    {
    case IS_HATTRIE:
#ifndef TSL_HTRIE_MAP_H
      zend_throw_exception(phptrie_exception_ce,
                           "You do not have Tessil/hat-trie installed",
                           0 TSRMLS_CC);
#endif
      hat->hat = new HatTrie();
      break;

    case IS_TRIE:
      trie->trie = new Trie();
      break;
    }
  }
}

/**
 * @brief PHP trie/HAT trie insert function
 * 
 * @param type 
 */
static void trieInsert(INTERNAL_FUNCTION_PARAMETERS, long type)
{
  zend_string *key;
  zval *entry;

  zval *obj = getThis();
  phptrie_object *trie;
  phphattrie_object *hat;

  ZEND_PARSE_PARAMETERS_START(2, 2)
  Z_PARAM_STR(key)
  Z_PARAM_ZVAL(entry)
  ZEND_PARSE_PARAMETERS_END();

  if (ZSTR_LEN(key) == 0)
  {
    TRIE_THROW("Key cannot be empty");
  }

  switch (type)
  {
  case IS_HATTRIE:
    hat = Z_HATOBJ_P(obj);
    break;

  case IS_TRIE:
    trie = Z_TRIEOBJ_P(obj);
    break;
  }

  if (trie != NULL || hat != NULL)
  {
    NodeVal ins;
    auto ret = false;

    switch (Z_TYPE_P(entry))
    {
    case IS_STRING:
      ins.type = NodeVal::isString;
      ins.strv = Z_STRVAL_P(entry);
      break;

    case IS_DOUBLE:
      ins.type = NodeVal::isFloat;
      ins.fv = Z_DVAL_P(entry);
      break;

    case IS_LONG:
      ins.type = NodeVal::isLong;
      ins.lv = Z_LVAL_P(entry);
      break;

    case IS_NULL:
      ins.type = NodeVal::isNull;
      ins.nullv = nullptr;
      break;

    case IS_TRUE:
      ins.type = NodeVal::isBool;
      ins.bv = true;
      break;

    case IS_FALSE:
      ins.type = NodeVal::isBool;
      ins.bv = false;
      break;

    default:
      TRIE_THROW("Everything but resources, objects, and callables are storable");
      break;
    }

    switch (type)
    {
    case IS_HATTRIE:
      ret = hat->hat->insert(ZSTR_VAL(key), ins);
      break;

    case IS_TRIE:
      ret = trie->trie->insert(ZSTR_VAL(key), ins);
      break;
    }

    RETURN_BOOL(ret);
  }

  zend_string_release(key);
}

/**
 * @brief PHP trie/HAT trie keyExists function
 * 
 * @param type 
 */
static void trieKeyExists(INTERNAL_FUNCTION_PARAMETERS, long type)
{
  zend_string *key;

  zval *obj = getThis();
  phptrie_object *trie;
  phphattrie_object *hat;

  ZEND_PARSE_PARAMETERS_START(1, 1)
  Z_PARAM_STR(key)
  ZEND_PARSE_PARAMETERS_END();

  if (ZSTR_LEN(key) == 0)
  {
    TRIE_THROW("Sorry, key length cannot be zero");
  }

  switch (type)
  {
  case IS_HATTRIE:
    hat = Z_HATOBJ_P(obj);
    break;

  case IS_TRIE:
    trie = Z_TRIEOBJ_P(obj);
    break;
  }

  if (trie != NULL || hat != NULL)
  {
    bool ret;
    switch (type)
    {
    case IS_HATTRIE:
      ret = hat->hat->check(ZSTR_VAL(key));
      break;

    case IS_TRIE:
      ret = trie->trie->check(ZSTR_VAL(key));
      break;
    }
    RETURN_BOOL(ret);
  }

  zend_string_release(key);
}

/**
 * @brief PHP trie/HAT trie search function
 * 
 * @param type 
 */
static void trieSearch(INTERNAL_FUNCTION_PARAMETERS, long type)
{
  zend_string *key;

  zval *obj = getThis();
  phptrie_object *trie;
  phphattrie_object *hat;

  ZEND_PARSE_PARAMETERS_START(1, 1)
  Z_PARAM_STR(key)
  ZEND_PARSE_PARAMETERS_END();

  // trie = Z_TRIEOBJ_P(obj);
  switch (type)
  {
  case IS_HATTRIE:
    hat = Z_HATOBJ_P(obj);
    break;

  case IS_TRIE:
    trie = Z_TRIEOBJ_P(obj);
    break;
  }

  if (trie != NULL || hat != NULL)
  {
    NodeVal val;
    switch (type)
    {
    case IS_HATTRIE:
      // if key does not exist, then throw exception
      try
      {
        val = hat->hat->extract(ZSTR_VAL(key));
      }
      catch (const std::exception &exp)
      {
        TRIE_THROW(exp.what());
      }
      break;

    case IS_TRIE:
      val = trie->trie->extract(ZSTR_VAL(key));
      break;
    }

    switch (val.type)
    {
    case NodeVal::isNull:
      RETURN_NULL();
      break;

    case NodeVal::isBool:
      RETURN_BOOL(val.bv);
      break;

    case NodeVal::isLong:
      RETURN_LONG(val.lv);
      break;

    case NodeVal::isString:
      RETURN_STRING(val.strv);
      break;

    case NodeVal::isFloat:
      RETURN_DOUBLE(val.fv);
      break;
    }
  }

  zend_string_release(key);
}

/**
 * @brief PHP trie/HAT trie delete function
 * 
 * @param type 
 */
static void trieKeyDelete(INTERNAL_FUNCTION_PARAMETERS, long type)
{
  zend_string *key;

  zval *obj = getThis();
  phptrie_object *trie;
  phphattrie_object *hat;

  ZEND_PARSE_PARAMETERS_START(1, 1)
  Z_PARAM_STR(key)
  ZEND_PARSE_PARAMETERS_END();

  // trie = Z_TRIEOBJ_P(obj);
  switch (type)
  {
  case IS_HATTRIE:
    hat = Z_HATOBJ_P(obj);
    break;

  case IS_TRIE:
    trie = Z_TRIEOBJ_P(obj);
    break;
  }

  if (trie != NULL || hat != NULL)
  {
    bool deleted;
    switch (type)
    {
    case IS_HATTRIE:
      deleted = hat->hat->remove(ZSTR_VAL(key));
      break;

    case IS_TRIE:
      deleted = trie->trie->remove(ZSTR_VAL(key));
      break;
    }

    if (!deleted)
    {
      zend_throw_exception(phptrie_exception_ce,
                           "Cannot delete key",
                           0 TSRMLS_CC);
    }
  }
}

/**
 * @brief PHP trie/HAT trie size function
 * 
 * @param type 
 */
static void trieCount(INTERNAL_FUNCTION_PARAMETERS, long type)
{
  zval *obj = getThis();
  phptrie_object *trie;
  phphattrie_object *hat;

  ZEND_PARSE_PARAMETERS_NONE();

  switch (type)
  {
  case IS_HATTRIE:
    hat = Z_HATOBJ_P(obj);
    break;

  case IS_TRIE:
    trie = Z_TRIEOBJ_P(obj);
    break;
  }

  if (trie != NULL || hat != NULL)
  {
    switch (type)
    {
    case IS_HATTRIE:
      RETURN_LONG(hat->hat->size());
      break;

    case IS_TRIE:
      RETURN_LONG(trie->trie->size());
      break;
    }
  }
}

/**
 * @brief PHP trie/HAT trie fromArray static function
 * 
 * @param type 
 */
static void trieFromArray(INTERNAL_FUNCTION_PARAMETERS, long type)
{
  zval *array, *hashVal;
  zend_string *hashKey;

  phphattrie_object *hat;
  phptrie_object *trie;

  HatTrie *initHat;
  Trie *initTrie;

  ZEND_PARSE_PARAMETERS_START(1, 1)
  Z_PARAM_ARRAY(array)
  ZEND_PARSE_PARAMETERS_END();

  if (zend_hash_num_elements(Z_ARRVAL_P(array)) == 0)
  {
    TRIE_THROW("Sorry, array cannot be empty");
  }

  switch (type)
  {
  case IS_HATTRIE:
#ifndef TSL_HTRIE_MAP_H
    TRIE_THROW("You do not have Tessil/hat-trie installed");
#endif
    initHat = new HatTrie();
    break;

  case IS_TRIE:
    initTrie = new Trie();
    break;
  }

  ZEND_HASH_FOREACH_STR_KEY_VAL(Z_ARRVAL_P(array), hashKey, hashVal)
  {
    NodeVal ins;

    zval dup;
    ZVAL_COPY(&dup, hashVal);

    switch (Z_TYPE(dup))
    {
    case IS_STRING:
      ins.type = NodeVal::isString;
      ins.strv = Z_STRVAL(dup);
      break;

    case IS_LONG:
      ins.type = NodeVal::isLong;
      ins.lv = Z_LVAL(dup);
      break;

    case IS_DOUBLE:
      ins.type = NodeVal::isFloat;
      ins.fv = Z_DVAL(dup);
      break;

    case IS_NULL:
      ins.type = NodeVal::isNull;
      ins.nullv = nullptr;
      break;

    case IS_TRUE:
      ins.type = NodeVal::isBool;
      ins.bv = true;
      break;

    case IS_FALSE:
      ins.type = NodeVal::isBool;
      ins.bv = false;
      break;

    // skip over everything else
    default:
      continue;
    }

    switch (type)
    {
    case IS_HATTRIE:
      initHat->insert(ZSTR_VAL(hashKey), ins);
      break;

    case IS_TRIE:
      initTrie->insert(ZSTR_VAL(hashKey), ins);
      break;
    }
  }
  ZEND_HASH_FOREACH_END();

  switch (type)
  {
  case IS_HATTRIE:
    object_init_ex(return_value, phphattrie_ce);

    hat = Z_HATOBJ_P(return_value);
    hat->hat = initHat;
    break;

  case IS_TRIE:
    object_init_ex(return_value, phptrie_ce);

    trie = Z_TRIEOBJ_P(return_value);
    trie->trie = initTrie;
    break;
  }
}

/* ---- Trie routines ----- */

/**
 * @brief PHP trie toArray function
 * 
 */
static void trieToArray(INTERNAL_FUNCTION_PARAMETERS)
{
  zval *obj = getThis();
  phptrie_object *trie;

  triemap data;

  ZEND_PARSE_PARAMETERS_NONE();

  trie = Z_TRIEOBJ_P(obj);
  if (trie != NULL)
  {
    zval retval;
    array_init(&retval);

    data = trie->trie->all();
    for (auto idx : data)
    {
      switch (idx.second.type)
      {
      case NodeVal::isString:
        add_assoc_string(&retval, idx.first.c_str(), idx.second.strv);
        break;

      case NodeVal::isBool:
        add_assoc_bool(&retval, idx.first.c_str(), idx.second.bv);
        break;

      case NodeVal::isLong:
        add_assoc_long(&retval, idx.first.c_str(), idx.second.lv);
        break;

      case NodeVal::isFloat:
        add_assoc_double(&retval, idx.first.c_str(), idx.second.fv);
        break;

      case NodeVal::isNull:
        add_assoc_null(&retval, idx.first.c_str());
        break;
      }
    }

    RETURN_ZVAL(&retval, 1, 0);
  }
}

/* ---- HAT trie routines ----- */

/**
 * @brief PHP HAT trie prefixSearch function
 * 
 */
static void hatPrefixSearch(INTERNAL_FUNCTION_PARAMETERS)
{
  zend_string *prefix;

  zval *obj = getThis();
  phphattrie_object *hat;

  Htrie data;
  HatTrie *hattrie;

  ZEND_PARSE_PARAMETERS_START(1, 1)
  Z_PARAM_STR(prefix)
  ZEND_PARSE_PARAMETERS_END();

  // throw exception if prefix is empty
  if (ZSTR_LEN(prefix) == 0)
  {
    TRIE_THROW("Prefix cannot be empty");
  }

  hat = Z_HATOBJ_P(obj);
  if (hat != NULL)
  {
    hattrie = new HatTrie;
    data = hat->hat->all();
    auto results = data.equal_prefix_range(ZSTR_VAL(prefix));

    for (auto idx = results.first; idx != results.second; ++idx)
    {
      hattrie->insert(idx.key().c_str(), idx.value());
    }

    hat->hat = hattrie;
    RETURN_OBJ(Z_OBJ_P(obj));
  }

  zend_string_release(prefix);
}

/**
 * @brief PHP HAT trie toArray function
 * 
 */
static void hatToArray(INTERNAL_FUNCTION_PARAMETERS)
{
  zval *obj = getThis();
  phphattrie_object *hat;

  Htrie data;

  ZEND_PARSE_PARAMETERS_NONE();

  hat = Z_HATOBJ_P(obj);
  if (hat != NULL)
  {
    zval retval;
    array_init(&retval);

    data = hat->hat->all();
    std::string buffer;
    for (auto idx = data.begin(); idx != data.end(); ++idx)
    {
      idx.key(buffer);
      switch (idx.value().type)
      {
      case NodeVal::isString:
        add_assoc_string(&retval, buffer.c_str(), idx.value().strv);
        break;

      case NodeVal::isBool:
        add_assoc_bool(&retval, buffer.c_str(), idx.value().bv);
        break;

      case NodeVal::isLong:
        add_assoc_long(&retval, buffer.c_str(), idx.value().lv);
        break;

      case NodeVal::isFloat:
        add_assoc_double(&retval, buffer.c_str(), idx.value().fv);
        break;

      case NodeVal::isNull:
        add_assoc_null(&retval, buffer.c_str());
        break;
      }
    }

    RETURN_ZVAL(&retval, 1, 0);
  }
}

/**
 * @brief PHP HAT trie prefixErase function
 * 
 */
static void hatPrefixErase(INTERNAL_FUNCTION_PARAMETERS)
{
  zend_string *prefix;

  zval *obj = getThis();
  phphattrie_object *hat;

  ZEND_PARSE_PARAMETERS_START(1, 1)
  Z_PARAM_STR(prefix)
  ZEND_PARSE_PARAMETERS_END();

  if (ZSTR_LEN(prefix) == 0)
  {
    TRIE_THROW("Prefix cannot be empty");
  }

  hat = Z_HATOBJ_P(obj);
  if (hat != NULL)
  {
    hat->hat->prefixDelete(ZSTR_VAL(prefix));

    RETURN_OBJ(Z_OBJ_P(obj));
  }

  zend_string_release(prefix);
}

/**
 * @brief PHP HAT trie fold function
 * 
 */
static void hatFold(INTERNAL_FUNCTION_PARAMETERS)
{
  zval *acc; // accumulator

  zval result, args[2]; // function return value and arguments
  zend_fcall_info fci;
  zend_fcall_info_cache fci_cache = empty_fcall_info_cache;

  zval *obj = getThis();
  phphattrie_object *hat;

  Htrie data;

  ZEND_PARSE_PARAMETERS_START(2, 2)
  Z_PARAM_FUNC(fci, fci_cache)
  Z_PARAM_ZVAL(acc)
  ZEND_PARSE_PARAMETERS_END();

  hat = Z_HATOBJ_P(obj);
  if (hat != NULL)
  {
    fci.retval = &result;
    fci.param_count = 2;

    data = hat->hat->all();
    // std::string buffer;

    if (hat->hat->size() == 0)
    {
      ZVAL_COPY_VALUE(return_value, acc);
    }

    for (auto idx = data.begin(); idx != data.end(); ++idx)
    {
      // idx.key(buffer);
      zval temp;
      switch (idx.value().type)
      {
      case NodeVal::isString:
        ZVAL_STRING(&temp, idx.value().strv);
        break;

      case NodeVal::isLong:
        ZVAL_LONG(&temp, idx.value().lv);
        break;

      case NodeVal::isBool:
        ZVAL_BOOL(&temp, idx.value().bv);
        break;

      case NodeVal::isFloat:
        ZVAL_DOUBLE(&temp, idx.value().fv);
        break;

      case NodeVal::isNull:
        ZVAL_NULL(&temp);
        break;
      }

      ZVAL_COPY_VALUE(&args[0], return_value);
      ZVAL_COPY(&args[1], &temp);
      fci.params = args;

      // i_zval_ptr_dtor(&temp);

      if (zend_call_function(&fci, &fci_cache) == FAILURE ||
          Z_TYPE(result) == IS_UNDEF)
      {
        zval_ptr_dtor(&args[0]);
        zval_ptr_dtor(&args[1]);
        RETURN_NULL();
      }

      zval_ptr_dtor(&args[0]);
      zval_ptr_dtor(&args[1]);
      ZVAL_COPY_VALUE(return_value, &result);
    }

    zend_release_fcall_info_cache(&fci_cache);
  }
}

/**
 * @brief PHP HAT trie map function
 * 
 */
static void hatMap(INTERNAL_FUNCTION_PARAMETERS)
{
  zval result, arg;
  zend_fcall_info fci = empty_fcall_info;
  zend_fcall_info_cache fci_cache = empty_fcall_info_cache;

  zval *obj = getThis();
  phphattrie_object *hat;

  Htrie htrie;
  HatTrie *hattrie;

  ZEND_PARSE_PARAMETERS_START(1, 1)
  Z_PARAM_FUNC(fci, fci_cache)
  ZEND_PARSE_PARAMETERS_END();

  hat = Z_HATOBJ_P(obj);
  if (hat != NULL)
  {
    htrie = hat->hat->all();
    hattrie = new HatTrie;

    std::string buffer;

    for (auto idx = htrie.begin(); idx != htrie.end(); ++idx)
    {
      idx.key(buffer);
      NodeVal ins;

      // bind NodeVal to zval stored in temp variable
      zval temp;
      switch (idx.value().type)
      {
      case NodeVal::isString:
        ZVAL_STRING(&temp, idx.value().strv);
        break;

      case NodeVal::isLong:
        ZVAL_LONG(&temp, idx.value().lv);
        break;

      case NodeVal::isBool:
        ZVAL_BOOL(&temp, idx.value().bv);
        break;

      case NodeVal::isFloat:
        ZVAL_DOUBLE(&temp, idx.value().fv);
        break;

      case NodeVal::isNull:
        ZVAL_NULL(&temp);
        break;
      }

      fci.retval = &result;
      fci.param_count = 1;
      fci.params = &arg;

      ZVAL_COPY(&arg, &temp);
      if (zend_call_function(&fci, &fci_cache) == FAILURE ||
          Z_TYPE(result) == IS_UNDEF)
      {
        TRIE_THROW("map operation failure");
      }

      i_zval_ptr_dtor(&arg);
      // i_zval_ptr_dtor(&temp);

      switch (Z_TYPE(result))
      {
      case IS_STRING:
        ins.type = NodeVal::isString;
        ins.strv = Z_STRVAL(result);
        break;

      case IS_LONG:
        ins.type = NodeVal::isLong;
        ins.lv = Z_LVAL(result);
        break;

      case IS_DOUBLE:
        ins.type = NodeVal::isFloat;
        ins.fv = Z_DVAL(result);
        break;

      case IS_NULL:
        ins.type = NodeVal::isNull;
        ins.nullv = nullptr;
        break;

      case IS_TRUE:
        ins.type = NodeVal::isBool;
        ins.bv = true;
        break;

      case IS_FALSE:
        ins.type = NodeVal::isBool;
        ins.bv = false;
        break;
      }

      hattrie->insert(buffer.c_str(), ins);
    }
    zend_release_fcall_info_cache(&fci_cache);

    hat->hat = hattrie;
    RETURN_OBJ(Z_OBJ_P(obj));
  }
}

/**
 * @brief PHP HAT trie filter function
 * 
 */
static void hatFilter(INTERNAL_FUNCTION_PARAMETERS)
{
  zval result, arg;
  zend_fcall_info fci = empty_fcall_info;
  zend_fcall_info_cache fci_cache = empty_fcall_info_cache;

  zval *obj = getThis();
  phphattrie_object *hat;

  Htrie htrie;

  ZEND_PARSE_PARAMETERS_START(1, 1)
  Z_PARAM_FUNC(fci, fci_cache)
  ZEND_PARSE_PARAMETERS_END();

  hat = Z_HATOBJ_P(obj);
  if (hat != NULL)
  {
    htrie = hat->hat->all();

    std::string buffer;
    for (auto idx = htrie.begin(); idx != htrie.end(); ++idx)
    {
      idx.key(buffer);

      zval temp;
      switch (idx.value().type)
      {
      case NodeVal::isString:
        ZVAL_STRING(&temp, idx.value().strv);
        break;

      case NodeVal::isLong:
        ZVAL_LONG(&temp, idx.value().lv);
        break;

      case NodeVal::isBool:
        ZVAL_BOOL(&temp, idx.value().bv);
        break;

      case NodeVal::isFloat:
        ZVAL_DOUBLE(&temp, idx.value().fv);
        break;

      case NodeVal::isNull:
        ZVAL_NULL(&temp);
        break;
      }

      fci.retval = &result;
      fci.param_count = 1;
      fci.params = &arg;

      ZVAL_COPY(&arg, &temp);
      if (zend_call_function(&fci, &fci_cache) == FAILURE ||
          Z_TYPE(result) == IS_UNDEF)
      {
        TRIE_THROW("Filter operation failure");
      }

      i_zval_ptr_dtor(&arg);

      // purge entry if the result is false
      if (Z_TYPE(result) == IS_FALSE)
      {
        hat->hat->remove(buffer.c_str());
      }
      else if (Z_TYPE(result) == IS_TRUE)
      {
        // move on to next iteration if the result is true
        continue;
      }
      else
      {
        TRIE_THROW("Only boolean results are acceptable");
      }
    }
    zend_release_fcall_info_cache(&fci_cache);

    RETURN_OBJ(Z_OBJ_P(obj));
  }
}

/**
 * @brief PHP HAT trie longestPrefix function
 * 
 */
static void hatLongestPrefix(INTERNAL_FUNCTION_PARAMETERS)
{
  zend_string *prefix;

  zval *obj = getThis();
  phphattrie_object *hat;

  ZEND_PARSE_PARAMETERS_START(1, 1)
  Z_PARAM_STR(prefix)
  ZEND_PARSE_PARAMETERS_END();

  if (ZSTR_LEN(prefix) == 0)
  {
    TRIE_THROW("Prefix cannot be empty");
  }

  hat = Z_HATOBJ_P(obj);
  if (hat != NULL)
  {
    zval retval;
    array_init(&retval);

    auto longest = hat->hat->longestPrefix(ZSTR_VAL(prefix));
    if (longest != hat->hat->all().end())
    {
      switch (longest.value().type)
      {
      case NodeVal::isString:
        add_assoc_string(&retval, longest.key().c_str(), longest.value().strv);
        break;

      case NodeVal::isBool:
        add_assoc_bool(&retval, longest.key().c_str(), longest.value().bv);
        break;

      case NodeVal::isLong:
        add_assoc_long(&retval, longest.key().c_str(), longest.value().lv);
        break;

      case NodeVal::isFloat:
        add_assoc_double(&retval, longest.key().c_str(), longest.value().fv);
        break;

      case NodeVal::isNull:
        add_assoc_null(&retval, longest.key().c_str());
        break;
      }
    }
    RETURN_ZVAL(&retval, 1, 0);
  }

  zend_string_release(prefix);
}
