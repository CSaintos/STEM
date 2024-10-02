#include "Interpreter.hpp"

using namespace stem;
using namespace std;

Interpreter::Interpreter()
  : parse_trees(nullptr)
{}

void Interpreter::interpret(vector<unique_ptr<Node>>* parse_trees)
{
  this->parse_trees = parse_trees;

  for (int i = 0; i < parse_trees->size(); i++)
  {
    // DEBUG
    cout << (*parse_trees)[i]->to_string() << endl;
    bool change = false;
    do {
      change = (*parse_trees)[i]->interpret();
      if (change)
      {
        // DEBUG
        cout << (*parse_trees)[i]->to_string() << endl;
      }
    } while (change);
    // DEBUG
    cout << endl;
  }
}
