--TEST--
fromArray creates Trie from PHP array
--FILE--
<?php
$trie = Trie::fromArray([
  'foo' => 'foo',
  'bar' => 12,
  'baz' => true,
]); 

var_dump(isset($trie['foo'], $trie['bar'], $trie['baz']));
?>
--EXPECT--
bool(true)