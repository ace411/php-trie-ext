--TEST--
HAT trie map operation works
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
$trie = new HatTrie;

$trie->insert('foo', 12);
$trie['bar'] = null;
$trie['baz'] = 3;

var_dump(
  $trie
    ->map(function ($x): int {
      return $x ** 2;
    })
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