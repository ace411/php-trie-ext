dnl config.m4 for extension php_trie

PHP_ARG_ENABLE(php_trie, whether to enable php_trie support,
[  --enable-php_trie          Enable php_trie support], no)

PHP_ARG_WITH(hattrie, whether to add hattrie library path,
[  --with-hattrie=[=DIR]      Ignore hattrie library path check ])

if test "$PHP_PHP_TRIE" != "no"; then
  HEADER_INSTALL_DIRS="/usr/local /usr /usr/local/opt"
  HATTRIE_CPP_DIR="/include/hat-trie/include/tsl"
  HATTRIE_HEADER="htrie_map.h"

  dnl check if hat-trie library is installed
  AC_MSG_CHECKING([for Tessil/hat-trie library])
  if test -s $PHP_HATTRIE/$HATTRIE_HEADER; then
    AC_MSG_RESULT(found $HATTRIE_HEADER)
    HATTRIE_LIB=$PHP_HATTRIE
  else
    for iter in $HEADER_INSTALL_DIRS; do
      if test -s $iter/$HATTRIE_CPP_DIR/$HATTRIE_CPP_HEADER; then
        AC_MSG_RESULT(found $HATTRIE_HEADER)
        HATTRIE_LIB=$iter/$HATTRIE_CPP_DIR
      fi
    done
  fi

  if test -z "$HATTRIE_LIB"; then
    AC_MSG_RESULT(hattrie lib is not properly installed. You will not be able to use the HAT trie)
    AC_MSG_ERROR(Please install the hattrie library)
  fi

  dnl add support for C++
  PHP_REQUIRE_CXX()
  PHP_ADD_INCLUDE($HATTRIE_LIB)

  
  dnl add C++11 standard library
  AC_DEFINE(HAVE_PHP_TRIE, 1, [ Have php_trie support ])
  
  PHP_NEW_EXTENSION(php_trie, php_trie.cpp, $ext_shared,, -std=c++11, cxx)
fi
