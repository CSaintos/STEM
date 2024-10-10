/*
 * @file stem/inc/util/node/op_node/bin_node/Caret.hpp
 * @author Christian Santos
 * @version 1.0.0
 * @date 10/2/2024
 */
#pragma once

#include <memory>
#include <iostream>
#include <cmath>

#include "Token.hpp"
#include "TokenType.hpp"
#include "Node.hpp"
#include "BinOpNode.hpp"
#include "ValueNode.hpp"
#include "NodeUtils.hpp"
#include "NumberUtils.hpp"

namespace stem
{
  struct Caret : public BinOpNode
  {
    Caret(Token &tok_op);
    Caret(std::unique_ptr<Node> &node_left, std::unique_ptr<Node> &node_op, std::unique_ptr<Node> &node_right);
    Caret(std::unique_ptr<Node> &node_left, Token &tok_op, std::unique_ptr<Node> &node_right);
    bool interpret() override;
  };
}