--TEST--
erasure works on HAT trie
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
$trie = HatTrie::fromArray([
  'foo' => 'foo',
  'bar' => 'bar',
  'baz' => 'baz'
]);

$trie->erase('bar');
unset($trie['baz']);

var_dump(isset($trie['bar'], $trie['baz']));
?>
--EXPECT--
bool(false)