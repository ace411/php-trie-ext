--TEST--
fromArray creates HAT trie from PHP array
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
  'bar' => false
]);

var_dump($trie instanceof HatTrie);
?>
--EXPECT--
bool(true)