--TEST--
inserting items into Trie is doable
--FILE--
<?php
$trie = new Trie;

$x = $trie->insert("chemem", 12);
$trie["mike"] = "foo";
$y = $trie->insert("foo", false);

var_dump($x, $trie->keyExists("mike"), $y);
?>
--EXPECT--
bool(true)
bool(true)
bool(true)