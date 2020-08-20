--TEST--
size outputs the Trie element count
--FILE--
<?php
$trie = new Trie;

$trie['foo'] = 'foo';
$trie['bar'] = 'bar';

echo $trie->size();
?>
--EXPECT--
2