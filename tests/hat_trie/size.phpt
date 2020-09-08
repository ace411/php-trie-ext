--TEST--
size outputs the HAT Trie element count
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
  'foo' => 12,
  'bar' => 'bar'
]);

echo $trie->size();
?>
--EXPECT--
2