#include "FSlash.hpp"

using namespace std;
using namespace mua;

FSlash::FSlash(Token &tok_op)
  : BinOpNode(tok_op)
{}

FSlash::FSlash(unique_ptr<Node> &node_left, unique_ptr<Node> &node_op, unique_ptr<Node> &node_right)
  : BinOpNode(node_left, node_op, node_right)
{}

FSlash::FSlash(unique_ptr<Node> &node_left, Token &tok_op, unique_ptr<Node> &node_right)
  : BinOpNode(node_left, tok_op, node_right)
{}

string FSlash::to_repr()
{
  if (node_left == nullptr || node_right == nullptr)
  {
    return "/";
  }
  return node_left->to_repr() + "/" + node_right->to_repr();
}

bool FSlash::interpret(const unordered_set<InterpretType> &flags)
{
  bool left_change = false;
  bool right_change = false;
  bool change = false;
  bool is_left_leaf = true;
  bool is_right_leaf = true;

  if (!node_left->isLeaf()) 
  {
    left_change = node_left->interpret(flags);
    change = left_change || change;
    is_left_leaf = false;
  }
  if (!node_right->isLeaf())
  {
    right_change = node_right->interpret(flags);
    change = right_change || change;
    is_right_leaf = false;
  }
  if (change)
  {
    return change;
  }

  unique_ptr<Node> lhs_node;
  unique_ptr<Node> rhs_node;
  unique_ptr<Node> left_numerator;
  unique_ptr<Node> left_denominator;
  unique_ptr<Node> right_numerator;
  unique_ptr<Node> right_denominator;
  bool is_left_minus = false;
  bool is_right_minus = false;
  bool is_minus = false;
  bool removable_right_paren = false;

  if (!is_left_leaf)
  {
    if (node_left->tok.type == TokenType::MINUS)
    {
      UnaOpNode* una_op_node = static_cast<UnaOpNode*>(node_left.get());
      is_left_minus = true;

      if (una_op_node->node->tok.type == TokenType::DIGIT)
      {
        lhs_node = NumberUtils::fractionalize(una_op_node->node->to_repr());
      }
    }
    else if (node_left->tok.type == TokenType::FSLASH)
    {
      BinOpNode* bin_op_node = static_cast<BinOpNode*>(node_left.get());
      UnaOpNode* una_op_node;

      if (bin_op_node->node_left->tok.type == TokenType::MINUS)
      {
        is_left_minus = !is_left_minus;
        una_op_node = static_cast<UnaOpNode*>(bin_op_node->node_left.get());
        left_numerator = std::move(una_op_node->node);
      }
      else if (bin_op_node->node_left->tok.type == TokenType::DIGIT)
      {
        left_numerator = std::move(bin_op_node->node_left);
      }
      else
      {
        cout << "Not implemented yet (3)" << endl;
      }
      if (bin_op_node->node_right->tok.type == TokenType::MINUS)
      {
        is_left_minus = !is_left_minus;
        una_op_node = static_cast<UnaOpNode*>(bin_op_node->node_right.get());
        left_denominator = std::move(una_op_node->node);
      }
      else if (bin_op_node->node_right->tok.type == TokenType::DIGIT)
      {
        left_denominator = std::move(bin_op_node->node_right);
      }
      else
      {
        cout << "Not implemented yet (3)" << endl;
      }
    }
    else if (node_left->tok.type == TokenType::LPAREN)
    {
      UnaOpNode* una_op_node = static_cast<UnaOpNode*>(node_left.get());

      if (una_op_node->node->tok.type == TokenType::MINUS)
      {
        is_left_minus = true;
        una_op_node = static_cast<UnaOpNode*>(una_op_node->node.get());
      }
      if (una_op_node->node->tok.type == TokenType::DIGIT)
      {
//        removable_left_paren = true;
        lhs_node = NumberUtils::fractionalize(una_op_node->node->to_repr());
      }
      if (una_op_node->node->tok.type == TokenType::FSLASH)
      {
        BinOpNode* bin_op_node = static_cast<BinOpNode*>(una_op_node->node.get());

        if (bin_op_node->node_left->tok.type == TokenType::MINUS)
        {
          is_left_minus = !is_left_minus;
          una_op_node = static_cast<UnaOpNode*>(bin_op_node->node_left.get());
          left_numerator = std::move(una_op_node->node);
        }
        else if (bin_op_node->node_left->tok.type == TokenType::DIGIT)
        {
          left_numerator = std::move(bin_op_node->node_left);
        }
        else
        {
          cout << "Not implemented yet (3)" << endl;
        }
        if (bin_op_node->node_right->tok.type == TokenType::MINUS)
        {
          is_left_minus = !is_left_minus;
          una_op_node = static_cast<UnaOpNode*>(bin_op_node->node_right.get());
          left_denominator = std::move(una_op_node->node);
        }
        else if (bin_op_node->node_right->tok.type == TokenType::DIGIT)
        {
          left_denominator = std::move(bin_op_node->node_right);
        }
        else
        {
          cout << "Not implemented yet (3)" << endl;
        }
      }
    }
    else
    {
      cout << "Not implemented yet (2)" << endl;
    }
  }
  else
  {
    if (node_left->tok.type == TokenType::DIGIT)
    {
      lhs_node = NumberUtils::fractionalize(node_left->to_repr());
    }
  }

  if (!is_right_leaf)
  {
    if (node_right->tok.type == TokenType::MINUS)
    {
      UnaOpNode* una_op_node = static_cast<UnaOpNode*>(node_right.get());
      is_right_minus = true;

      if (una_op_node->node->tok.type == TokenType::DIGIT)
      {
        rhs_node = NumberUtils::fractionalize(una_op_node->node->to_repr());
      }
    }
    else if (node_right->tok.type == TokenType::FSLASH)
    {
      cout << "Not implemented yet (1)" << endl;
    }
    else if (node_right->tok.type == TokenType::LPAREN)
    {
      UnaOpNode* una_op_node = static_cast<UnaOpNode*>(node_right.get());
          
      if (una_op_node->node->tok.type == TokenType::MINUS)
      {
        is_right_minus = true;
        una_op_node = static_cast<UnaOpNode*>(una_op_node->node.get());
      }
      if (una_op_node->node->tok.type == TokenType::DIGIT)
      {
        removable_right_paren = true;
        rhs_node = NumberUtils::fractionalize(una_op_node->node->to_repr());
      }
      if (una_op_node->node->tok.type == TokenType::FSLASH)
      {
        BinOpNode* bin_op_node = static_cast<BinOpNode*>(una_op_node->node.get());

        if (bin_op_node->node_left->tok.type == TokenType::MINUS)
        {
          is_right_minus = !is_right_minus;
          una_op_node = static_cast<UnaOpNode*>(bin_op_node->node_left.get());
          right_numerator = std::move(una_op_node->node);
        }
        else if (bin_op_node->node_left->tok.type == TokenType::DIGIT)
        {
          right_numerator = std::move(bin_op_node->node_left);
        }
        else
        {
          cout << "Not implemented yet (3)" << endl;
        }
        if (bin_op_node->node_right->tok.type == TokenType::MINUS)
        {
          is_right_minus = !is_right_minus;
          una_op_node = static_cast<UnaOpNode*>(bin_op_node->node_right.get());
          right_denominator = std::move(una_op_node->node);
        }
        else if (bin_op_node->node_right->tok.type == TokenType::DIGIT)
        {
          right_denominator = std::move(bin_op_node->node_right);
        }
        else
        {
          cout << "Not implemented yet (3)" << endl;
        }
      }
    }
    else
    {
      cout << "Not implemented yet (2)" << endl;
    }
  }
  else
  {
    if (node_right->tok.type == TokenType::DIGIT)
    {
      rhs_node = NumberUtils::fractionalize(node_right->to_repr());
    }
  }
      
  is_minus = (
    (is_left_minus || 
    is_right_minus) &&
    !(is_left_minus &&
    is_right_minus)
  );
  if (lhs_node != nullptr && rhs_node != nullptr)
  {
    if (lhs_node->isLeaf() && rhs_node->isLeaf())
    {
      int lhs = std::stod(lhs_node->to_repr());
      int rhs = std::stod(rhs_node->to_repr());
      int gcd = std::gcd(lhs, rhs);

      if (gcd == 1)
      {
        if (flags.count(InterpretType::DECIMALIZE) > 0)
        {
          double result = double(lhs) / double(rhs);
          string result_str = NumberUtils::stripTrailingZeros(std::to_string(result));
          Token res_tok;
          res_tok.type = TokenType::DIGIT;
          res_tok.lexemes = result_str;
          lhs_node = std::make_unique<ValueNode>(res_tok);
          if (is_minus)
          {
            Token minus_tok;
            minus_tok.type = TokenType::MINUS;
            lhs_node = std::make_unique<UnaMinus>(minus_tok, lhs_node);
          }
          NodeUtils::replaceNode(this, lhs_node);
          change = true;
        }
        else if (rhs == 1)
        {
          if (is_minus)
          {
            Token minus_tok;
            minus_tok.type = TokenType::MINUS;
            lhs_node = std::make_unique<UnaMinus>(minus_tok, lhs_node);
          }
          NodeUtils::replaceNode(this, lhs_node);
          change = true;
        }
        else if (removable_right_paren)
        {
          if (is_right_minus)
          {
            Token minus_tok;
            minus_tok.type = TokenType::MINUS;
            rhs_node = std::make_unique<UnaMinus>(minus_tok, rhs_node);
          }
          NodeUtils::replaceNode(node_right.get(), rhs_node);
          change = true;
        }
      }
      else
      {
        lhs = lhs / gcd;
        rhs = rhs / gcd;
        lhs_node->tok.lexemes = std::to_string(lhs);
        if (is_minus)
        {
          Token minus_tok;
          minus_tok.type = TokenType::MINUS;
          lhs_node = std::make_unique<UnaMinus>(minus_tok, lhs_node);
        }
        if (rhs != 1)
        {
          rhs_node->tok.lexemes = std::to_string(rhs);
          NodeUtils::replaceNode(node_left.get(), lhs_node);
          NodeUtils::replaceNode(node_right.get(), rhs_node);
        }
        else
        {
          NodeUtils::replaceNode(this, lhs_node);
        }
        change = true;
      }
    }
    else
    {
      if (!lhs_node->isLeaf())
      {
        if (is_left_minus)
        {
          Token minus_tok;
          minus_tok.type = TokenType::MINUS;
          if (lhs_node->getType() == NodeType::BINARY_OPERATOR)
          {
            BinOpNode* bin_op_node = static_cast<BinOpNode*>(lhs_node.get());
            unique_ptr<Node> left_numerator = std::move(bin_op_node->node_left);
            left_numerator = std::make_unique<UnaMinus>(minus_tok, left_numerator);
            bin_op_node->node_left = std::move(left_numerator);
            bin_op_node->node_left->parent = bin_op_node;
          }
        }
        NodeUtils::replaceNode(node_left.get(), lhs_node);
      }
      if (!rhs_node->isLeaf())
      {
        if (is_right_minus)
        {
          Token minus_tok;
          minus_tok.type = TokenType::MINUS;
          if (rhs_node->getType() == NodeType::BINARY_OPERATOR)
          {
            BinOpNode* bin_op_node = static_cast<BinOpNode*>(rhs_node.get());
            unique_ptr<Node> right_numerator = std::move(bin_op_node->node_left);
            right_numerator = std::make_unique<UnaMinus>(minus_tok, right_numerator);
            bin_op_node->node_left = std::move(right_numerator);
            bin_op_node->node_left->parent = bin_op_node;
          }
        }
        if (rhs_node->tok.type == TokenType::FSLASH)
        {
          Token paren_tok;
          paren_tok.type = TokenType::LPAREN;
          rhs_node = std::make_unique<Paren>(paren_tok, rhs_node);
        }
        NodeUtils::replaceNode(node_right.get(), rhs_node);
      }
      change = true;
    }
  }
  else if (left_numerator != nullptr && left_denominator != nullptr && rhs_node != nullptr)
  {
    Token tok_op;
    tok_op.type = TokenType::ASTERISK;
    unique_ptr<Node> denominator = std::make_unique<Asterisk>(left_denominator, tok_op, rhs_node);
    Token tok_paren;
    tok_paren.type = TokenType::LPAREN;
    unique_ptr<Node> paren = std::make_unique<Paren>(tok_paren, denominator);
    if (is_minus)
    {
      Token tok_minus;
      tok_minus.type = TokenType::MINUS;
      left_numerator = std::make_unique<UnaMinus>(tok_minus, left_numerator);
    }
    NodeUtils::replaceNode(node_left.get(), left_numerator);
    NodeUtils::replaceNode(node_right.get(), paren);
    change = true;
  }
  else if (right_numerator != nullptr && right_denominator != nullptr && lhs_node != nullptr)
  {
    Token tok_op;
    tok_op.type = TokenType::ASTERISK;
    unique_ptr<Node> numerator = std::make_unique<Asterisk>(lhs_node, tok_op, right_denominator);
    if (is_minus)
    {
      Token tok_paren;
      tok_paren.type = TokenType::LPAREN;
      numerator = std::make_unique<Paren>(tok_paren, numerator);
      Token tok_minus;
      tok_minus.type = TokenType::MINUS;
      numerator = std::make_unique<UnaMinus>(tok_minus, numerator);
    }

    NodeUtils::replaceNode(node_left.get(), numerator);
    NodeUtils::replaceNode(node_right.get(), right_numerator);
    change = true;
  }
  else if (left_numerator != nullptr && left_denominator != nullptr && right_numerator != nullptr && right_denominator != nullptr)
  {
    Token tok_asterisk;
    tok_asterisk.type = TokenType::ASTERISK;
    Token tok_paren;
    tok_paren.type = TokenType::LPAREN;
    unique_ptr<Node> numerator = std::make_unique<Asterisk>(left_numerator, tok_asterisk, right_denominator);
    numerator = std::make_unique<Paren>(tok_paren, numerator);
    if (is_minus)
    {
      Token tok_minus;
      tok_minus.type = TokenType::MINUS;
      numerator = std::make_unique<UnaMinus>(tok_minus, numerator);
    }
    unique_ptr<Node> denominator = std::make_unique<Asterisk>(left_denominator, tok_asterisk, right_numerator);
    denominator = std::make_unique<Paren>(tok_paren, denominator);
    
    NodeUtils::replaceNode(node_left.get(), numerator);
    NodeUtils::replaceNode(node_right.get(), denominator);
    change = true;
  }

  return change;
}

unique_ptr<Node> FSlash::copy()
{
  unique_ptr<Node> lhs_node = node_left->copy();
  unique_ptr<Node> rhs_node = node_right->copy();
  return std::make_unique<FSlash>(lhs_node, tok, rhs_node);
}
