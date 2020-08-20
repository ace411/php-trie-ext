--TEST--
search outputs the value that corresponds to a key stored in a HAT trie
--FILE--
<?php
$trie = HatTrie::fromArray([
  'foo' => 'foo',
  'bar' => 'bar'
]);

echo $trie->search('foo') . ': ' . $trie['bar'];
?>
--EXPECT--
foo: bar