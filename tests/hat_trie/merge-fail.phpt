--TEST--
merge operation fails when non-Hat trie objects are encountered
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
$fst = HatTrie::fromArray(['foo' => 'foo', 'bar' => 'bar']);

try {
  $fst->merge(new StdClass(2), [], 'foo');
} catch (TrieException $exp) {
  echo $exp->getMessage();
}
?>
--EXPECT--
Only trie elements are allowed