#include "Character.hpp"

using namespace std;
using namespace stem;

Character::Character()
{
  init();
}

Character::Character(const Character &character)
  : type(character.type),
    pos(character.pos),
    c(character.c)
{}

void Character::init()
{
  type = CharacterType::EMPTY;
  pos.init();
  c = '\0';
}

string Character::to_string()
{
  string output = "";

  if (type == CharacterType::DIGIT || type == CharacterType::ALPHA)
  {
    output = CharacterUtils::repr_map[type] + ":" + c;
  }
  else 
  {
    output = CharacterUtils::repr_map[type];
  }

  return output;
}