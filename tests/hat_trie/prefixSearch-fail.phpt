--TEST--
prefixSearch throws TrieException when empty string is detected
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
  'foo'   => 'foo',
  'food'  => 'fish',
]);

try {
  $trie->prefixSearch('');
} catch (TrieException $exp) {
  echo $exp->getMessage();
}
?>
--EXPECT--
Prefix cannot be empty