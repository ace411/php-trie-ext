--TEST--
merging two HAT tries works
--FILE--
<?php
$fst = HatTrie::fromArray([
  'foo' => 'foo',
  'bar' => 'bar',
]);

$snd = new HatTrie;
$snd['baz'] = 12;

$thd = new HatTrie;
$thd['baff'] = false;

var_dump($fst->merge($snd, $thd)->toArray());
?>
--EXPECT--
array(4) {
  ["baz"]=>
  int(12)
  ["baff"]=>
  bool(false)
  ["foo"]=>
  string(3) "foo"
  ["bar"]=>
  string(3) "bar"
}