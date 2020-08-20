--TEST--
insert throws TrieException when invalid entry data type is detected
--FILE--
<?php
$trie = new Trie();

try {
  $trie->insert('chemem', new StdClass(['foo' => 'bar']));
} catch (TrieException $exp) {
  echo $exp->getMessage();
}
?>
--EXPECT--
Everything but resources, objects, and callables are storable