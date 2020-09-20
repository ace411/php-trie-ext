--TEST--
prefixSearch produces precise results for varied keys
--FILE--
<?php
$trie = new Trie;
$trie['kylo-ren'] = 2;
$trie['leia'] = 'foo';
$trie['luke'] = false;

var_dump($trie->prefixSearch('l')->toArray());
?>
--EXPECT--
array(2) {
  ["leia"]=>
  string(3) "foo"
  ["luke"]=>
  bool(false)
}