<?php

if (!extension_loaded('php_trie')) {
  exit();
}

$trie = new Trie;

$trie['foo'] = 'foo';
$trie['bar'] = 12;
$trie['baz'] = null;

if (isset($trie['bar']))
{
  unset($trie['bar']);
}

echo json_encode($trie);
