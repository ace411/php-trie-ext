--TEST--
prefixSearch creates new trie containing entries whose keys have a common arbitrary prefix
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
$trie = HatTrie::fromArray([
  'foo'   => 'foo',
  'bar'   => 'bar',
  'food'  => 'fish'
]);

var_dump($trie->prefixSearch('foo')->toArray());
?>
--EXPECT--
array(2) {
  ["food"]=>
  string(4) "fish"
  ["foo"]=>
  string(3) "foo"
}