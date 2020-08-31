/**
 * @file trie.h
 * @author Lochemem Bruno Michael (lochbm@gmail.com)
 * @brief header file containing extension's core Trie routines
 * @version 0.1.0
 * 
 * @copyright Copyright (c) 1999-2019 The PHP Group
 * 
 */

#ifndef TRIE_H
#define TRIE_H

#include <unordered_map>
#include <utility>
#include <cstddef>
#include <string>
#include <hat-trie/include/tsl/htrie_map.h>

namespace trie
{
  struct NodeVal
  {
    enum
    {
      isString,
      isBool,
      isLong,
      isFloat,
      isNull,
      isUndefined
    } type;
    union
    {
      const char *strv;
      bool bv;
      long lv;
      float fv;
      std::nullptr_t nullv;
    };
  };

  struct TrieNode
  {
    std::unordered_map<char, TrieNode *> children;
    NodeVal val;
    bool isLeaf;
    // might be controversial
    std::string history;
  };

  // trie map type alias
  typedef std::unordered_map<std::string, NodeVal> triemap;

  /**
     * @brief creates new trie
     *
     * @return TrieNode*
     */
  TrieNode *newTrie()
  {
    auto trie = new TrieNode;
    trie->isLeaf = false;

    return trie;
  }

  /**
     * @brief inserts item into trie
     *
     * @param trie
     * @param key
     * @param val
     */
  void insertItem(TrieNode *&trie, const char *key, NodeVal val)
  {
    if (trie == nullptr)
    {
      trie = newTrie();
    }

    TrieNode *current = trie;
    std::string history;
    while (*key)
    {
      if (current->children.find(*key) == current->children.end())
      {
        current->children[*key] = newTrie();
      }
      history.push_back(*key);

      current = current->children[*key];

      key++;
    }
    history.shrink_to_fit(); // reduce memory usage

    current->val = val;
    current->history = history;
    current->isLeaf = true;
  }

  /**
     * @brief checks if key exists in trie
     *
     * @param trie
     * @param key
     * @return true
     * @return false
     */
  bool keyExists(TrieNode *&trie, const char *key)
  {
    if (trie == nullptr)
    {
      return false;
    }

    TrieNode *current = trie;
    while (*key)
    {
      current = current->children[*key];

      if (current == nullptr)
      {
        return false;
      }

      key++;
    }

    return current->isLeaf;
  }

  /**
     * @brief returns a trie value that corresponds to a specified key
     *
     * @param trie
     * @param key
     * @return NodeVal
     */
  NodeVal fetchByKey(TrieNode *&trie, const char *key)
  {
    NodeVal ret;
    ret.type = NodeVal::isNull;
    ret.nullv = nullptr;

    if (trie == nullptr)
    {
      return ret;
    }

    TrieNode *current = trie;
    while (*key)
    {
      current = current->children[*key];

      if (current == nullptr)
      {
        return ret;
      }

      key++;
    }

    return current->val;
  }

  /**
     * @brief deletes item from trie
     *
     * @param trie
     * @param key
     * @return true
     * @return false
     */
  bool deleteItem(TrieNode *&trie, const char *key)
  {
    TrieNode *current = trie;
    while (*key)
    {
      TrieNode *next = current->children[*key];

      if (next != nullptr)
      {
        current->children.erase(*key);
      }

      current = next;

      key++;
    }

    return true;
  }

  /**
     * @brief checks if a trie node has children
     * 
     * @param trie 
     * @return true 
     * @return false 
     */
  bool hasChildren(TrieNode *&trie)
  {
    for (auto idx : trie->children)
    {
      if (idx.second != nullptr)
      {
        return true;
      }
    }

    return false;
  }

  /**
   * @brief extracts the trie's branches into key-value pairs
   * 
   * @param trie 
   * @return triemap 
   */
  triemap getPairs(TrieNode *&trie)
  {
    triemap res;

    TrieNode *current = trie;
    for (auto idx : current->children)
    {
      if (idx.second != nullptr)
      {
        std::string history = idx.second->history;
        history.shrink_to_fit();

        NodeVal val = idx.second->val;

        if (val.type != NodeVal::isUndefined)
        {
          // for the root node
          if (history.size() != 0)
          {
            res[history] = val;
          }
        }

        if (!hasChildren(idx.second))
        {
          res[history] = val;
        }
        else
        {
          auto other = getPairs(idx.second);
          res.insert(other.begin(), other.end());
        }
      }
    }

    return res;
  }

  /**
   * @brief checks if a string exists inside another
   * 
   * @param needle 
   * @param haystack 
   * @return true 
   * @return false 
   */
  bool strExists(std::string needle, std::string haystack)
  {
    std::string::size_type size = haystack.find(needle);

    return size == std::string::npos ? false : true;
  }

  /**
   * @brief searches trie for entries that match a specified prefix
   * 
   * @param trie 
   * @param prefix 
   * @return triemap 
   */
  triemap prefixLookup(TrieNode *&trie, std::string prefix)
  {
    triemap res; // TrieNode *res = newTrie();
    TrieNode *current = trie;

    for (auto idx : current->children)
    {
      if (idx.second != nullptr)
      {
        NodeVal val = idx.second->val;
        std::string history = idx.second->history;
        history.shrink_to_fit();

        bool prefixCheck = strExists(prefix, history);

        if (val.type != NodeVal::isUndefined && prefixCheck)
        {
          if (history.size() != 0)
          {
            res[history] = val;
          }
        }

        if (!hasChildren(idx.second) && prefixCheck)
        {
          res[history] = val;
        }
        else
        {
          auto other = prefixLookup(idx.second, prefix);
          res.insert(other.begin(), other.end());
        }
      }
    }

    return res;
  }

  class Trie
  {
  private:
    TrieNode *trie = nullptr;

  public:
    Trie() {}
    Trie(triemap trmap)
    {
      trie = newTrie();

      // secondary iteration might be costly
      for (auto idx : trmap)
      {
        insertItem(trie, idx.first.c_str(), idx.second);
      }
    }
    Trie(TrieNode *obj) : trie(obj) {}
    ~Trie() { trie = nullptr; }

    bool insert(const char *key, NodeVal val)
    {
      insertItem(trie, key, val);

      return keyExists(trie, key);
    }

    bool check(const char *key)
    {
      return keyExists(trie, key);
    }

    NodeVal extract(const char *key)
    {
      return fetchByKey(trie, key);
    }

    bool remove(const char *key)
    {
      return deleteItem(trie, key);
    }

    triemap all()
    {
      return getPairs(trie);
    }

    int size()
    {
      return getPairs(trie).size();
    }

    triemap prefixSearch(std::string prefix)
    {
      return prefixLookup(trie, prefix);
    }

    Trie *merge(triemap other)
    {
      for (auto idx = other.begin(); idx != other.end(); ++idx)
      {
        insertItem(trie, idx->first.c_str(), idx->second);
      }

      return new Trie(trie);
    }
  };

  // HAT trie type alias
  typedef tsl::htrie_map<char, NodeVal> Htrie;
  class HatTrie
  {
  private:
    Htrie hatTrie;

  public:
    // HatTrie() {}
    HatTrie(float factor = 8.0f, size_t threshold = 16384)
    {
      hatTrie.max_load_factor(factor);
      hatTrie.burst_threshold(threshold);
    }
    HatTrie(Htrie hat) : hatTrie(hat) {}
    ~HatTrie()
    {
      hatTrie.clear();
    }

    bool check(const char *key)
    {
      return hatTrie.find(key) != hatTrie.end();
    }

    bool insert(const char *key, NodeVal val)
    {
      hatTrie[key] = val;

      return check(key);
    }

    NodeVal extract(const char *key)
    {
      return hatTrie.at(key);
    }

    bool remove(const char *key)
    {
      hatTrie.erase(key);

      return check(key) ? false : true;
    }

    int size()
    {
      return hatTrie.size();
    }

    Htrie all()
    {
      return hatTrie;
    }

    int prefixDelete(std::string prefix)
    {
      return hatTrie.erase_prefix(prefix);
    }

    Htrie::iterator longestPrefix(const char *prefix)
    {
      return hatTrie.longest_prefix(prefix);
    }

    void shrinkTrie()
    {
      hatTrie.shrink_to_fit();
    }

    void adjustLoadFactor(float factor = 8.0f)
    {
      hatTrie.max_load_factor(factor);
    }

    void adjustBurstThreshold(size_t threshold = 16384)
    {
      hatTrie.burst_threshold(threshold);
    }

    HatTrie *merge(Htrie map)
    {
      std::string buffer;
      for (auto idx = map.begin(); idx != map.end(); ++idx)
      {
        idx.key(buffer);
        hatTrie[buffer] = idx.value();
      }

      return new HatTrie(hatTrie);
    }
  };
}; // namespace trie

#endif // TRIE_H
