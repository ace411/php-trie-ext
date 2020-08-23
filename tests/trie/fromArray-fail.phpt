--TEST--
fromArray throws TrieException when array is empty
--FILE--
<?php
try {
  $trie = Trie::fromArray([]);
} catch (TrieException $exp) {
  echo $exp->getMessage();
}
?>
--EXPECT--
Array cannot be empty