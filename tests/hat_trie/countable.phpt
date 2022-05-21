--TEST--
HAT trie implements Countable interface
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
  'bar' => 'bar',
]);

echo (float)phpversion() < 8 ? count($trie) : $trie->size();
?>
--EXPECT--
2