--TEST--
longestPrefix computes the longest possible matching prefix and outputs the result as an array
--FILE--
<?php
$trie = HatTrie::fromArray([
  'foo'     => 'foo',
  'food'    => 'fish',
  'person'  => 'eddie'
]);

var_dump($trie->longestPrefix('food is delicious'));
?>
--EXPECT--
array(1) {
  ["food"]=>
  string(4) "fish"
}