--TEST--
prefixErase purges items whose keys match an arbitrary prefix
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
$trie['che'] = 'South America';
$trie['chef'] = 'Ramsay';
$trie['sport'] = 'Basketball';

var_dump($trie->prefixErase('che')->toArray());
?>
--EXPECT--
array(1) {
  ["sport"]=>
  string(10) "Basketball"
}