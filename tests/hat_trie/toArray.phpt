--TEST--
toArray converts HAT trie to PHP hashtable
--SKIPIF--
<?php
try {
  $trie = new HatTrie;
} catch (TrieException $exp) {
  echo $exp->getMessage();
}
?>
--FILE--
<?php
$trie = new HatTrie;

$trie['foo'] = 'foo';
$trie['bar'] = 2;

var_dump($trie->toArray());
?>
--EXPECT--
array(2) {
  ["foo"]=>
  string(3) "foo"
  ["bar"]=>
  int(2)
}