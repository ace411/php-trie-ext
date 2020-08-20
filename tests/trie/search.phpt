--TEST--
search outputs the value that corresponds to a key stored in a trie
--FILE--
<?php
$trie = new Trie;

$trie["fox"] = 12;
$trie["foxy"] = "foo";

echo $trie["foxy"] . ' = ' . $trie->search("fox");
?>
--EXPECT--
foo = 12