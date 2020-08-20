--TEST--
erasure works on Trie
--FILE--
<?php
$trie = new Trie;

$trie['chemem'] = 12;
$trie['mike'] = 'foo';
$trie['chef'] = true;

unset($trie['chemem']);
$trie->erase('mike');

var_dump($trie->keyExists('chemem'));
var_dump(isset($trie['mike']));
?>
--EXPECT--
bool(false)
bool(false)