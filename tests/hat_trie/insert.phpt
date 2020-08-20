--TEST--
inserting items into HAT trie is doable
--FILE--
<?php
$trie = new HatTrie;

$trie->insert('foo', 'foo');
$trie['bar'] = false;

var_dump(isset($trie['foo'], $trie['bar']));
?>
--EXPECT--
bool(true)