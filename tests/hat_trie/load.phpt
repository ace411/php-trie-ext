--TEST--
HAT trie is usable
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

echo gettype($trie);
?>
--EXPECT--
object