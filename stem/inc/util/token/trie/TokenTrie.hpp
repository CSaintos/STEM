/**
 * @file stem/inc/util/token/trie/TokenTrie.hpp
 * @author Christian Santos
 * @version 1.0.0
 * @date 8/11/2024
 */

#pragma once

#include <string>
#include <list>

#include "TrieNode.hpp"
#include "TokenUtils.hpp"

namespace stem
{
  class TokenTrie
  {
  private:
    static TokenTrie instance;
    TrieNode root;
    static bool isInstanciated;
    TokenTrie();
  public:
    static TokenTrie* getInstance();
    TrieNode* getTrie();
  };
}