/**
 * @file stem/inc/util/node/op_node/PlusNode.hpp
 * @author Christian Santos
 * @version 1.0.0
 * @date 09/21/2024
 */

#pragma once

#include <memory>
#include <iostream>

#include "TokenType.hpp"
#include "Node.hpp"
#include "ValueNode.hpp"
#include "BinOpNode.hpp"
#include "UnaOpNode.hpp"

namespace stem
{
  struct BinPlus : public BinOpNode
  {
    BinPlus(Token &tok_op);
    BinPlus(std::unique_ptr<Node> &node_left, std::unique_ptr<Node> &node_op, std::unique_ptr<Node> &node_right);
    BinPlus(std::unique_ptr<Node> &node_left, Token &tok_op, std::unique_ptr<Node> &node_right);
    void interpret() override;
  };
}
