--TEST--
Trie filter operation works
--FILE--
<?php
$trie = Trie::fromArray([
  'foo' => 'foo',
  'bar' => 12,
  'baz' => false
]);

var_dump($trie->filter('is_bool')->toArray());
?>
--EXPECT--
array(1) {
  ["baz"]=>
  bool(false)
}