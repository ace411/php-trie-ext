--TEST--
merging two tries works
--FILE--
<?php
$fst = Trie::fromArray([
  'foo' => 'foo',
  'bar' => 'bar',
]);

$snd = new Trie;
$snd['baz'] = 12;

$thd = new Trie;
$thd['baff'] = false;

var_dump($fst->merge($snd, $thd)->toArray());
?>
--EXPECT--
array(4) {
  ["foo"]=>
  string(3) "foo"
  ["baz"]=>
  int(12)
  ["bar"]=>
  string(3) "bar"
  ["baff"]=>
  bool(false)
}
