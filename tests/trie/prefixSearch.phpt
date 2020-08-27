--TEST--
prefixSearch works on Trie
--FILE--
<?php
$trie = Trie::fromArray([
  'foo' => 'foo',
  'bar' => 'bar',
  'baz' => 'baz'
]);

var_dump(
  $trie
    ->prefixSearch('ba')
    ->toArray()
);
?>
--EXPECT--
array(2) {
  ["bar"]=>
  string(3) "bar"
  ["baz"]=>
  string(3) "baz"
}