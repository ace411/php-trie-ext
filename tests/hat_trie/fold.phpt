--TEST--
HAT trie fold operation works
--FILE--
<?php
$trie = HatTrie::fromArray([
  'foo' => 2,
  'bar' => 9,
  'baz' => 13,
]);

echo $trie->fold(function ($acc, $val): int {
  return $val + $acc;
}, 0)
?>
--EXPECT--
24