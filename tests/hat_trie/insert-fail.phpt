--TEST--
inserting invalid data type into HatTrie throws TrieException 
--FILE--
<?php
$trie = new HatTrie;

try {
  $trie->insert('foo', function (int $x): int {
    return $x ** 2;
  });
} catch (TrieException $exp) {
  echo $exp->getMessage();
}
?>
--EXPECT--
Everything but resources, objects, and callables are storable