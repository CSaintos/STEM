/**
 * @file stem/inc/front/Definer.hpp
 * @author Christian Santos
 * @version 1.0.0
 * @date 9/7/2024
 */

#pragma once

#include <memory>
#include <vector>
#include <stack>
#include <unordered_map>

#include "Node.hpp"
#include "NodeType.hpp"
#include "BinOpNode.hpp"
#include "UnaOpNode.hpp"
#include "ValueNode.hpp"
#include "TokenType.hpp"
#include "NameTrie.hpp"
#include "TrieNode.hpp"

namespace stem
{
  class Definer
  {
  private:
    std::vector<std::unique_ptr<stem::Node>>* parse_trees;
    std::stack<stem::Node*> analyze_nodes;
    std::unordered_map<std::string, stem::Node*> name_table;
    NameTrie name_trie;
    //TrieNode* curr;

    bool let_stmt;

    void init();
    void searchOneNode(stem::Node* node);
    void analyzeTree(stem::Node* root);
  public:
    Definer();
    /*
     * @brief analyzes parse trees to append to symbol table and modify tree accordingly
     *
     * @param root node of parse tree to analyze
     */
    void define(std::vector<std::unique_ptr<stem::Node>>* parse_trees);
    void getSymbolTable();
  };
}