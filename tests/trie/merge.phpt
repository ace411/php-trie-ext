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

$res = $fst->merge($snd, $thd)->toArray();
ksort($res);
var_dump($res);
?>
--EXPECT--
array(4) {
  ["baff"]=>
  bool(false)
  ["bar"]=>
  string(3) "bar"
  ["baz"]=>
  int(12)
  ["foo"]=>
  string(3) "foo"
}
