--TEST--
HAT trie map operation works
--FILE--
<?php
$trie = new HatTrie;

$trie->insert('foo', 12);
$trie['bar'] = null;
$trie['baz'] = 3;

var_dump(
  $trie
    ->map(fn ($x): int => $x ** 2)
    ->toArray()
);
?>
--EXPECT--
array(3) {
  ["baz"]=>
  int(9)
  ["foo"]=>
  int(144)
  ["bar"]=>
  int(0)
}