--TEST--
Trie implements Countable interface
--FILE--
<?php
$trie = Trie::fromArray([
  'foo' => 'foo',
  'bar' => 'bar',
]);

echo count($trie);
?>
--EXPECT--
2