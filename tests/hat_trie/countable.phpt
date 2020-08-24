--TEST--
HAT trie implements Countable interface
--FILE--
<?php
$trie = HatTrie::fromArray([
  'foo' => 'foo',
  'bar' => 'bar',
]);

echo count($trie);
?>
--EXPECT--
2