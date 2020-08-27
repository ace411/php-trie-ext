--TEST--
prefixSearch throws TrieException when empty string is detected
--FILE--
<?php
$trie = Trie::fromArray([
  'foo'   => 'foo',
  'food'  => 'fish'
]);

try {
  $trie->prefixSearch('');
} catch (TrieException $exp) {
  echo $exp->getMessage();
}
?>
--EXPECT--
Prefix cannot be empty