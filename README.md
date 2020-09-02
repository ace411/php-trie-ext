# php_trie

[![Build Status](https://travis-ci.org/ace411/php-trie-ext.svg?branch=master)](https://travis-ci.org/ace411/php-trie-ext)

Trie and HAT trie data structures for PHP.

## Requirements

- C++ 11
- PHP 7.3 or greater
- [HAT Trie library](https://github.com/Tessil/hat-trie) (optional)

## Installation

To install the extension, type the following in a console of your choosing:

```sh
git clone https://github.com/ace411/php_trie.git <directory>
cd <directory>
phpize
./configure --enable-php_trie
make && sudo make install
```

If you intend to use the HAT trie component of the module, you are going to need to install the HAT trie C++ library. The installation directives, with the said library installed become:

```sh
git clone https://github.com/Tessil/hat-trie.git <lib-dir>
git clone https://github.com/ace411/php_trie.git <directory>
cd <directory>
phpize
./configure --enable-php_trie --with-hattrie=<lib-dir>/include/tsl
make && sudo make install
```

Running the tests in the `tests` directory is doable by running the following directive.

```sh
make test
```

> Do not forget to enable the extension by adding `extension=php_trie` to your `php.ini` file.

## Usage

Shown below is an example of Trie-specific creation, insertion, and deletion operations - akin to those performable on arrays.

```php
$trie = Trie::fromArray([
  'foo' => 'foo',
  'bar' => 12,
  'baz' => null,
]);

if (!isset($trie['boom'])) {
  $trie['boom'] = 'explode';
}

unset($trie['bar']);
```

> Please check out the [examples](https://github.com/ace411/php-trie-ext/tree/master/examples) directory for more sample material

## API

### Trie object

```php
class Trie implements Countable, ArrayAccess, JsonSerializable {

  /* Methods */
  public __construct();
  public static fromArray( array $array ) : Trie;
  public insert|offsetSet( string $key [, mixed $entry ] ) : bool;
  public erase|offsetUnset( string $key ) : void;
  public keyExists|offsetExists( string $key ) : bool;
  public search|offsetGet( string $key ) : mixed;
  public prefixSearch( string $prefix ) : Trie;
  public filter( callable $predicate ) : Trie;
  public map( callable $function ) : Trie;
  public merge([ Trie $tries... ]) : Trie;
  public size() : int;
  public toArray() : array;
}
```

**`Trie::fromArray`** - Creates a new trie from a PHP hashtable

**`Trie::insert`** - Inserts a value in a trie

**`Trie::erase`** - Deletes a value from a trie

**`Trie::keyExists`** - Checks if a specified key exists in a trie

**`Trie::search`** - Returns the value that corresponds to the specified key

**`Trie::prefixSearch`** - Returns a new HAT trie containing values that have a common arbitrary prefix

**`Trie::filter`** - Returns trie containing entries that conform to a specified predicate

**`Trie::map`** - Applies a transformation function to each entry in a trie

**`Trie::merge`** - Merges multiple tries into a single one

**`Trie::size`** - Outputs the size of a trie

**`Trie::toArray`** - Outputs a trie as an array

### HatTrie object

```php
class HatTrie implements Countable, ArrayAccess, JsonSerializable {

  /* Constants */
  const bool SHRINK = true;
  const bool NO_SHRINK = false;
  const double DEFAULT_LOAD_FACTOR = 8.0;
  const int DEFAULT_BURST_THRESHOLD = 16384;

  /* Methods */
  public __construct( int $burstThreshold = HatTrie::DEFAULT_BURST_THRESHOLD [, double $loadFactor = HatTrie::DEFAULT_LOAD_FACTOR [, bool $shrink = HatTrie::NO_SHRINK ]] );
  public static fromArray( array $array [, int $burstThreshold = HatTrie::DEFAULT_BURST_THRESHOLD [, double $loadFactor = HatTrie::DEFAULT_LOAD_FACTOR [, bool $shrink = HatTrie::NO_SHRINK ]]] ) : HatTrie;
  public insert|offsetSet( string $key [, mixed $entry ] ) : bool;
  public erase|offsetUnset( string $key ) : void;
  public keyExists|offsetExists( string $key ) : bool;
  public search|offsetGet( string $key ) : mixed;
  public prefixSearch( string $prefix ) : HatTrie;
  public longestPrefix( string $prefix ) : array;
  public prefixErase( string $prefix ) : HatTrie;
  public map( callable $function ) : HatTrie;
  public filter( callable $predicate ) : HatTrie;
  public fold( callable $function [, mixed $accumulator ] ) : mixed;
  public merge([ HatTrie $tries... ]) : HatTrie;
  public size() : int;
  public toArray() : array;
}
```

> This class is unusable without the HAT trie library.

**`HatTrie::fold`** - Transforms trie into a single value

**`HatTrie::prefixErase`** - Erases all entries whose keys have a common arbitrary prefix

**`HatTrie::longestPrefix`** - Computes the longest match prefix and outputs the result as a hashtable

### Important concepts

**Load factor** - A measure of the balance between speed and memory usage (lower load factor means greater iteration speed and a higher one means lower memory consumption)

**Burst threshold** - The maximum size of a bucket hash node before a burst (spawning of new node-parented trie buckets) occurs

## Contributing

Consider buying me a coffee if you appreciate the offerings of the project and/or would like to provide more impetus for me to continue working on it.

<a href="https://www.buymeacoffee.com/agiroLoki" target="_blank"><img src="https://cdn.buymeacoffee.com/buttons/lato-white.png" alt="Buy Me A Coffee" style="height: 51px !important;width: 217px !important;" ></a>
