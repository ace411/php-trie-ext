--TEST--
fromArray throws TrieException when array destined for HAT trie is empty 
--FILE--
<?php
try {
  $trie = HatTrie::fromArray([]);
} catch (TrieException $exp) {
  echo $exp->getMessage();
}
?>
--EXPECT--
Array cannot be empty