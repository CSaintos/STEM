#include "ValueNode.hpp"

using namespace mua;
using namespace std;

ValueNode::ValueNode(Token &tok_value)
{
  tok = tok_value;
}

unique_ptr<Node> ValueNode::copy()
{
  return std::make_unique<ValueNode>(tok);
}
