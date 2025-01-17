#include "UnaOpNode.hpp"

using namespace mua;
using namespace std;

UnaOpNode::UnaOpNode(Token &tok_op)
{
  tok = tok_op;
}

UnaOpNode::UnaOpNode(unique_ptr<Node> &node_op, unique_ptr<Node> &node)
  : node(std::move(node))
{
  tok = node_op->tok;
  void* trash = node_op.release();
  this->node->parent = this;
}

UnaOpNode::UnaOpNode(Token &tok_op, unique_ptr<Node> &node)
  : node(std::move(node))
{
  tok = tok_op;
  this->node->parent = this;
}

UnaOpNode::~UnaOpNode()
{}

string UnaOpNode::to_string()
{
  return ("(" + tok.to_string() + ", " + node->to_string() + ")");
}

string UnaOpNode::to_repr()
{
  return "";
}

bool UnaOpNode::hasGrandchildren()
{
  return (!node->isLeaf());
}

bool UnaOpNode::interpret(const unordered_set<InterpretType> &flags)
{
  cout << "UnaOpNode interpret" << endl;
  return false;
}
