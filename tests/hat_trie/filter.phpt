--TEST--
HAT trie filter operation works
--SKIPIF--
<?php
try {
  $trie = new HatTrie;
} catch (TrieException $exp) {
  echo $exp->getMessage();
}
?>
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