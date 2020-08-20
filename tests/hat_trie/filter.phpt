--TEST--
HAT trie filter operation works
--FILE--
<?php
$trie = HatTrie::fromArray([
  'foo' => 'foo',
  'bar' => 12,
  'baz' => false,
]);

var_dump($trie->filter('is_bool')->toArray());
?>
--EXPECT--
array(1) {
  ["baz"]=>
  bool(false)
}