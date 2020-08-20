--TEST--
fromArray creates HAT trie from PHP array
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