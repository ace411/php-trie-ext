--TEST--
toArray converts trie to PHP hashtable
--FILE--
<?php
$trie = Trie::fromArray([
  'foo' => 'foo',
  'bar' => 'bar'
]);

var_dump($trie->toArray());
?>
--EXPECT--
array(2) {
  ["foo"]=>
  string(3) "foo"
  ["bar"]=>
  string(3) "bar"
}