#include "CharacterUtils.hpp"

using namespace std;
using namespace stem;

unordered_map<char, CharacterType> CharacterUtils::cC_map =
{
//  {'~', CharacterType::TILDE},
//  {'!', CharacterType::EXCLAMATION},
//  {'@', CharacterType::ASPERAND},
  {'%', CharacterType::PERCENT},
  {'^', CharacterType::CARET},
//  {'&', CharacterType::AMPERSAND},
  {'*', CharacterType::ASTERISK},
  {'(', CharacterType::LPAREN},
  {')', CharacterType::RPAREN},
  {'-', CharacterType::MINUS},
//  {'_', CharacterType::UNDERSCORE},
  {'=', CharacterType::EQUAL},
  {'+', CharacterType::PLUS},
  {'[', CharacterType::LBRACKET},
//  {'{', CharacterType::LBRACE},
  {']', CharacterType::RBRACKET},
//  {'}', CharacterType::RBRACE},
//  {'|', CharacterType::VSLASH},
  {';', CharacterType::SEMICOLON},
//  {':', CharacterType::COLON},
//  {',', CharacterType::COMMA},
//  {'<', CharacterType::LESSTHAN},
  {'.', CharacterType::DOT},
//  {'>', CharacterType::MORETHAN},
  {'/', CharacterType::FSLASH},
  {' ', CharacterType::SPACE},
  {'0', CharacterType::DIGIT},
  {'1', CharacterType::DIGIT},
  {'2', CharacterType::DIGIT},
  {'3', CharacterType::DIGIT},
  {'4', CharacterType::DIGIT},
  {'5', CharacterType::DIGIT},
  {'6', CharacterType::DIGIT},
  {'7', CharacterType::DIGIT},
  {'8', CharacterType::DIGIT},
  {'9', CharacterType::DIGIT},
  {'A', CharacterType::ALPHA},
  {'B', CharacterType::ALPHA},
  {'C', CharacterType::ALPHA},
  {'D', CharacterType::ALPHA},
  {'E', CharacterType::ALPHA},
  {'F', CharacterType::ALPHA},
  {'G', CharacterType::ALPHA},
  {'H', CharacterType::ALPHA},
  {'I', CharacterType::ALPHA},
  {'J', CharacterType::ALPHA},
  {'K', CharacterType::ALPHA},
  {'L', CharacterType::ALPHA},
  {'M', CharacterType::ALPHA},
  {'N', CharacterType::ALPHA},
  {'O', CharacterType::ALPHA},
  {'P', CharacterType::ALPHA},
  {'Q', CharacterType::ALPHA},
  {'R', CharacterType::ALPHA},
  {'S', CharacterType::ALPHA},
  {'T', CharacterType::ALPHA},
  {'U', CharacterType::ALPHA},
  {'V', CharacterType::ALPHA},
  {'W', CharacterType::ALPHA},
  {'X', CharacterType::ALPHA},
  {'Y', CharacterType::ALPHA},
  {'Z', CharacterType::ALPHA},
  {'a', CharacterType::ALPHA},
  {'b', CharacterType::ALPHA},
  {'c', CharacterType::ALPHA},
  {'d', CharacterType::ALPHA},
  {'e', CharacterType::ALPHA},
  {'f', CharacterType::ALPHA},
  {'g', CharacterType::ALPHA},
  {'h', CharacterType::ALPHA},
  {'i', CharacterType::ALPHA},
  {'j', CharacterType::ALPHA},
  {'k', CharacterType::ALPHA},
  {'l', CharacterType::ALPHA},
  {'m', CharacterType::ALPHA},
  {'n', CharacterType::ALPHA},
  {'o', CharacterType::ALPHA},
  {'p', CharacterType::ALPHA},
  {'q', CharacterType::ALPHA},
  {'r', CharacterType::ALPHA},
  {'s', CharacterType::ALPHA},
  {'t', CharacterType::ALPHA},
  {'u', CharacterType::ALPHA},
  {'v', CharacterType::ALPHA},
  {'w', CharacterType::ALPHA},
  {'x', CharacterType::ALPHA},
  {'y', CharacterType::ALPHA},
  {'z', CharacterType::ALPHA}
};

unordered_map<CharacterType, string> CharacterUtils::repr_map =
{
  {CharacterType::PERCENT, "PERCENT"},
  {CharacterType::CARET, "CARET"},
  {CharacterType::ASTERISK, "ASTERISK"},
  {CharacterType::LPAREN, "LPAREN"},
  {CharacterType::RPAREN, "RPAREN"},
  {CharacterType::MINUS, "MINUS"},
  {CharacterType::EQUAL, "EQUAL"},
  {CharacterType::PLUS, "PLUS"},
  {CharacterType::SEMICOLON, "SEMICOLON"},
  {CharacterType::DOT, "DOT"},
  {CharacterType::FSLASH, "FSLASH"},
  {CharacterType::SPACE, "SPACE"},
  {CharacterType::DIGIT, "DIGIT"},
  {CharacterType::ALPHA, "ALPHA"},
  {CharacterType::EMPTY, "EMPTY"},
  {CharacterType::UNKNOWN, "UNKNOWN"}
//  {CharacterType::TILDE, "TILDE"},
//  {CharacterType::EXCLAMATION, "EXCLAMATION"},
//  {CharacterType::ASPERAND, "ASPERAND"},
//  {CharacterType::AMPERSAND, "AMPERSAND"},
//  {CharacterType::UNDERSCORE, "UNDERSCORE"},
//  {CharacterType::LBRACKET, "LBRACKET"},
//  {CharacterType::LBRACE, "LBRACE"},
//  {CharacterType::RBRACKET, "RBRACKET"},
//  {CharacterType::RBRACE, "RBRACE"},
//  {CharacterType::VSLASH, "VSLASH"},
//  {CharacterType::COLON, "COLON"},
//  {CharacterType::COMMA, "COMMA"},
//  {CharacterType::LESSTHAN, "LESSTHAN"},
//  {CharacterType::MORETHAN, "MORETHAN"},
};
