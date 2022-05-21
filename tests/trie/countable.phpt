--TEST--
Trie implements Countable interface
--FILE--
<?php
$trie = Trie::fromArray([
  'foo' => 'foo',
  'bar' => 'bar',
]);

echo (float)phpversion() < 8 ? count($trie) : $trie->size();;
?>
--EXPECT--
2