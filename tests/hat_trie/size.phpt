--TEST--
size outputs the HAT Trie element count
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