--TEST--
merge operation fails when non-Trie objects are encountered
--FILE--
<?php
$fst = Trie::fromArray(['foo' => 'foo', 'bar' => 'bar']);

try {
  $fst->merge(new StdClass(2), 'foo', 12);
} catch (TrieException $exp) {
  echo $exp->getMessage();
}
?>
--EXPECT--
Only trie elements are allowed