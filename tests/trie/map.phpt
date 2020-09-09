--TEST--
Trie map operation works
--FILE--
<?php
$trie = new Trie;
$trie['foo'] = 'FOO';
$trie['bar'] = 'BAR';
$trie['baz'] = 'BAZ';

$res = $trie
    ->map('strtolower')
    ->map('ucfirst')
    ->toArray();
ksort($res);
var_dump($res);
?>
--EXPECT--
array(3) {
  ["bar"]=>
  string(3) "Bar"
  ["baz"]=>
  string(3) "Baz"
  ["foo"]=>
  string(3) "Foo"
}
