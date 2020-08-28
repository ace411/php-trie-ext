--TEST--
Trie map operation works
--FILE--
<?php
$trie = new Trie;
$trie['foo'] = 'FOO';
$trie['bar'] = 'BAR';
$trie['baz'] = 'BAZ';

var_dump(
  $trie
    ->map('strtolower')
    ->map('ucfirst')
    ->toArray()
);
?>
--EXPECT--
array(3) {
  ["foo"]=>
  string(3) "Foo"
  ["bar"]=>
  string(3) "Bar"
  ["baz"]=>
  string(3) "Baz"
}