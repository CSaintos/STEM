#include "Let.hpp"

using namespace std;
using namespace mua;

Let::Let(Token &tok_op)
  : UnaOpNode(tok_op)
{}

Let::Let(unique_ptr<Node> &node_op, unique_ptr<Node> &node)
  : UnaOpNode(node_op, node)
{}

Let::Let(Token &tok_op, unique_ptr<Node> &node)
  : UnaOpNode(tok_op, node)
{}

string Let::to_repr()
{
  return "let " + node->to_repr();
}

bool Let::interpret(const unordered_set<InterpretType> &flags)
{
  bool change = false;
  return change;
}

unique_ptr<Node> Let::copy()
{
  unique_ptr<Node> node_copy = node->copy();
  return std::make_unique<Let>(tok, node_copy);
}
