--TEST--
php_trie module loads into PHP
--SKIPIF--
<?php
if (!extension_loaded('php_trie')) {
  echo 'skip';
} 
?>
--FILE--
<?php
$trie = new Trie;

echo gettype($trie);
?>
--EXPECT--
object