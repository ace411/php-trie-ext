<?php

if (!extension_loaded('php_trie')) {
  exit();
}

$trie = HatTrie::fromArray([
  'foo'   => 'foo',
  'bar'   => 'bar',
  'fooz'  => 'fooz',
]);

echo json_encode(
  $trie
    ->map('strtoupper')
    ->filter(function (string $val) {
      return mb_strlen($val, 'utf-8') < 4;
    })
);
