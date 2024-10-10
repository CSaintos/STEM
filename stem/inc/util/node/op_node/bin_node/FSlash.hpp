/*
 * @file stem/inc/util/node/op_node/bin_node/FSlash.hpp
 * @author Christian Santos
 * @version 1.0.0
 * @date 10/3/2024
 */

#pragma once

#include <memory>
#include <iostream>
#include <numeric>

#include "Token.hpp"
#include "TokenType.hpp"
#include "Node.hpp"
#include "BinOpNode.hpp"
#include "ValueNode.hpp"
#include "NodeUtils.hpp"
#include "NumberUtils.hpp"

namespace stem
{
  struct FSlash : public BinOpNode
  {
    FSlash(Token &tok_op);
    FSlash(std::unique_ptr<Node> &node_left, std::unique_ptr<Node> &node_op, std::unique_ptr<Node> &node_right);
    FSlash(std::unique_ptr<Node> &node_left, Token &tok_op, std::unique_ptr<Node> &node_right);
    bool interpret() override;
  };
}