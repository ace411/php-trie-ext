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
Sorry, array cannot be empty