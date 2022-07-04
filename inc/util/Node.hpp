/**
 * @brief This file is part of {{ stem.inc.util }}
 * 
 * @file node.hpp
 * @author Christian Santos
 * @version 1.0.3 7/3/2022
 */

#pragma once

#include <iostream>
#include <memory>

#include "Token.hpp"

namespace stem
{
  /**
   * @pure @struct Node
   * @brief Specifies generic node
   */
  struct Node
  {
    Token *m_tok; ///< Default represented token

    /**
     * @brief Returns node as string representation
     * 
     * @return string node representation
     */
    virtual std::string to_string() = 0;
    /**
     * @return true if node is a leaf,
     * false otherwise.
     */
    virtual bool is_leaf() = 0;
    /**
     * @return true if node has grandchildren,
     * false otherwise.
     */
    virtual bool has_grandchildren() = 0;
  };

  /**
   * @pure @struct ValueNode
   * @brief Specifies generic value node
   * - Used for Digits and Identifiers
   */
  struct ValueNode : virtual public Node
  {
    Token m_tok_value; ///< token value

    /**
     * @return true because a value node is a leaf
     * ? Is it though?
     */
    inline bool is_leaf() override { return true; }

    /**
     * @return false because value node has no grandchildren
     * ? Does it though?
     */
    inline bool has_grandchildren() override { return false; }
  };

  /**
   * @pure @struct OpNode
   * @brief Specifies generic operator node
   * - Used for Operators
   */
  struct OpNode : virtual public Node
  {
    Token m_tok_op; ///< token operator

    /**
     * @return false because an operator node is not a leaf
     * ? Is it though?
     */
    inline bool is_leaf() override { return false; }
  };

  /**
   * @struct DigitNode
   * @brief node specifying digits
   */
  struct DigitNode final : virtual public ValueNode
  {
  public:
    /**
     * @brief DigitNode(tok) constructor
     */
    DigitNode(Token &tok_digit);
    /**
     * @brief ~DigitNode() destructor
     */
    ~DigitNode();

    /**
     * @brief Returns node as string representation
     * 
     * @return string node representation
     */
    std::string to_string() override;
  };

  /**
   * @struct IdentifierNode
   * @brief node specifying identifiers
   */
  struct IdentifierNode final : virtual public ValueNode
  {
  public:
    /**
     * @brief IdentifierNode(tok) constructor
     */
    IdentifierNode(Token &tok_identifier);
    /**
     * @brief ~IdentifierNode() destructor
     */
    ~IdentifierNode();

    /**
     * @brief Returns node as string representation
     * 
     * @return string node representation
     */
    std::string to_string() override;
  };

  /**
   * @struct BinOpNode
   * @brief node specifying binary operators
   */
  struct BinOpNode final : virtual public OpNode
  {
  public:
    std::unique_ptr<Node> m_node_left; ///< left operand
    std::unique_ptr<Node> m_node_right; ///< right operand
    
    /**
     * @brief BinOpNode(tok_op)
     */
    BinOpNode(Token &tok_op);
    /**
     * @brief BinOpNode(node_left, tok_op, node_right) constructor
     */
    BinOpNode(std::unique_ptr<Node> &node_left, std::unique_ptr<Node> &node_op, std::unique_ptr<Node> &node_right);
    /**
     * @brief ~BinOpNode() destructor
     */
    ~BinOpNode();

    /**
     * @brief Returns node as string representation
     * 
     * @return string node representation
     */
    std::string to_string() override;

    /**
     * @return true if node has grandchildren,
     * false otherwise.
     */
    bool has_grandchildren() override;
  };

  /**
   * @struct UnaOpNode
   * @brief node specifying unary operators
   */
  struct UnaOpNode final : virtual public OpNode
  {
    std::unique_ptr<Node> m_node; ///< left operand

    /**
     * @brief UnaOpNode(tok_op)
     */
    UnaOpNode(Token &tok_op);
    /**
     * @brief UnaOpNode(tok_op, node)
     */
    UnaOpNode(std::unique_ptr<Node> &node_op, std::unique_ptr<Node> &node);
    /**
     * @brief ~UnaOpNode() destructor
     */
    ~UnaOpNode();

    /**
     * @brief Returns node as string representation
     * 
     * @return string node representation
     */
    std::string to_string() override;

    /**
     * @return true if node has grandchildren,
     * false otherwise.
     */
    bool has_grandchildren() override;
  };
}