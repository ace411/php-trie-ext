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
        if (idx.second->val.type != NodeVal::isUndefined)
        {
          // for the root node
          if (idx.second->history.size() != 0)
          {
            res[idx.second->history] = idx.second->val;
          }
        }

        if (!hasChildren(idx.second))
        {
          res[idx.second->history] = idx.second->val;
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

  class Trie
  {
  private:
    TrieNode *trie = nullptr;

  public:
    Trie() {}
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
  };

  // HAT trie type alias
  typedef tsl::htrie_map<char, NodeVal> Htrie;
  class HatTrie
  {
  private:
    Htrie hatTrie;

  public:
    HatTrie() {}
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
  };

}; // namespace trie

#endif // TRIE_H
