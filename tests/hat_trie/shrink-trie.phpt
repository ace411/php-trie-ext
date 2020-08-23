--TEST--
Setting the shrink flag shrinks trie nodes
--FILE--
<?php
$trie = new HatTrie(HatTrie::DEFAULT_LOAD_FACTOR, HatTrie::SHRINK);

$trie['foo'] = json_encode(range(1, 250000));
$trie['bar'] = json_encode(range(1, 150000));
$trie['baz'] = json_encode(range(1, 750000));
$trie['fooz'] = json_encode(range(1, 20000));

$begin = hrtime(true);
$trie->prefixSearch('fo');
var_dump(((hrtime(true) - $begin) / 1000000000) < 0.1);
?>
--EXPECT--
bool(true)