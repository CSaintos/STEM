#include "token.hpp"

stem::Token::Token()
{
  init();
}

void stem::Token::init()
{
  m_type = stem::TokenType::EMPTY;
  m_lexemes = "";
  m_pos.init();
}

std::string stem::Token::to_string()
{
  std::string output = "";

  if (m_type == TokenType::DIGIT || m_type == TokenType::IDENTIFIER)
  {
    output = TokenUtils::m_TS_map[m_type] + ":" + m_lexemes;
  }
  else
  {
    output = TokenUtils::m_TS_map[m_type];
  }

  return output;
}

std::unordered_map<stem::TokenType, std::string> stem::TokenUtils::m_TS_map = 
{
  {TokenType::SPACE, "SPACE"},
  {TokenType::SEMICOLON, "SEMICOLON"},
  {TokenType::COLON, "COLON"},
  {TokenType::LPAREN, "LPAREN"},
  {TokenType::RPAREN, "RPAREN"},
  {TokenType::LBRACKET, "LBRACKET"},
  {TokenType::RBRACKET, "RBRACKET"},
  {TokenType::LBRACE, "LBRACE"},
  {TokenType::AMPERSAND, "AMPERSAND"},
  {TokenType::VSLASH, "VSLASH"},
  {TokenType::TILDE, "TILDE"},
  {TokenType::EQUAL, "EQUAL"},
  {TokenType::LESSTHAN, "LESSTHAN"},
  {TokenType::MORETHAN, "MORETHAN"},
  {TokenType::EXCLAMATION, "EXCLAMATION"},
  {TokenType::COMMA, "COMMA"},
  {TokenType::DOT, "DOT"},
  {TokenType::PLUS, "PLUS"},
  {TokenType::MINUS, "MINUS"},
  {TokenType::ASTERISK, "ASTERISK"},
  {TokenType::FSLASH, "FSLASH"},
  {TokenType::PERCENT, "PERCENT"},
  {TokenType::CARET, "CARET"},
  {TokenType::UNDERSCORE, "UNDERSCORE"},
  {TokenType::DIGIT, "DIGIT"},
  {TokenType::IDENTIFIER, "IDENTIFIER"},
  {TokenType::COMMENT, "COMMENT"},
  {TokenType::LET, "LET"},
  {TokenType::AND, "AND"},
  {TokenType::OR, "OR"},
  {TokenType::XOR, "XOR"},
  {TokenType::ONLYIF, "ONLYIF"},
  {TokenType::IFANDONLYIF, "IFANDONLYIF"},
  {TokenType::EMPTY, "EMPTY"}, 
  {TokenType::UNKNOWN, "UNKNOWN"}
};

std::unordered_map<std::string, stem::TokenType> stem::TokenUtils::m_RT_map =
{
  {" ", TokenType::SPACE},
  {";", TokenType::SEMICOLON},
  {":", TokenType::COLON},
  {"(", TokenType::LPAREN},
  {")", TokenType::RPAREN},
  {"[", TokenType::LBRACKET},
  {"]", TokenType::RBRACKET},
  {"{", TokenType::LBRACE},
  {"}", TokenType::RBRACE},
  {"&", TokenType::AMPERSAND},
  {"|", TokenType::VSLASH},
  {"~", TokenType::TILDE},
  {"=", TokenType::EQUAL},
  {"<", TokenType::LESSTHAN},
  {">", TokenType::MORETHAN},
  {"!", TokenType::EXCLAMATION},
  {",", TokenType::COMMA},
  {".", TokenType::DOT},
  {"+", TokenType::PLUS},
  {"-", TokenType::MINUS},
  {"*", TokenType::ASTERISK},
  {"/", TokenType::FSLASH},
  {"%", TokenType::PERCENT},
  {"^", TokenType::CARET},
  {"_", TokenType::UNDERSCORE},
  {"0", TokenType::DIGIT},
  {"1", TokenType::DIGIT},
  {"2", TokenType::DIGIT},
  {"3", TokenType::DIGIT},
  {"4", TokenType::DIGIT},
  {"5", TokenType::DIGIT},
  {"6", TokenType::DIGIT},
  {"7", TokenType::DIGIT},
  {"8", TokenType::DIGIT},
  {"9", TokenType::DIGIT},
  {"A", TokenType::IDENTIFIER},
  {"B", TokenType::IDENTIFIER},
  {"C", TokenType::IDENTIFIER},
  {"D", TokenType::IDENTIFIER},
  {"E", TokenType::IDENTIFIER},
  {"F", TokenType::IDENTIFIER},
  {"G", TokenType::IDENTIFIER},
  {"H", TokenType::IDENTIFIER},
  {"I", TokenType::IDENTIFIER},
  {"J", TokenType::IDENTIFIER},
  {"K", TokenType::IDENTIFIER},
  {"L", TokenType::IDENTIFIER},
  {"M", TokenType::IDENTIFIER},
  {"N", TokenType::IDENTIFIER},
  {"O", TokenType::IDENTIFIER},
  {"P", TokenType::IDENTIFIER},
  {"Q", TokenType::IDENTIFIER},
  {"R", TokenType::IDENTIFIER},
  {"S", TokenType::IDENTIFIER},
  {"T", TokenType::IDENTIFIER},
  {"U", TokenType::IDENTIFIER},
  {"V", TokenType::IDENTIFIER},
  {"W", TokenType::IDENTIFIER},
  {"X", TokenType::IDENTIFIER},
  {"Y", TokenType::IDENTIFIER},
  {"Z", TokenType::IDENTIFIER},
  {"a", TokenType::IDENTIFIER},
  {"b", TokenType::IDENTIFIER},
  {"c", TokenType::IDENTIFIER},
  {"d", TokenType::IDENTIFIER},
  {"e", TokenType::IDENTIFIER},
  {"f", TokenType::IDENTIFIER},
  {"g", TokenType::IDENTIFIER},
  {"h", TokenType::IDENTIFIER},
  {"i", TokenType::IDENTIFIER},
  {"j", TokenType::IDENTIFIER},
  {"k", TokenType::IDENTIFIER},
  {"l", TokenType::IDENTIFIER},
  {"m", TokenType::IDENTIFIER},
  {"n", TokenType::IDENTIFIER},
  {"o", TokenType::IDENTIFIER},
  {"p", TokenType::IDENTIFIER},
  {"q", TokenType::IDENTIFIER},
  {"r", TokenType::IDENTIFIER},
  {"s", TokenType::IDENTIFIER},
  {"t", TokenType::IDENTIFIER},
  {"u", TokenType::IDENTIFIER},
  {"v", TokenType::IDENTIFIER},
  {"w", TokenType::IDENTIFIER},
  {"x", TokenType::IDENTIFIER},
  {"y", TokenType::IDENTIFIER},
  {"z", TokenType::IDENTIFIER},
  {"//", TokenType::COMMENT},
  {"let", TokenType::LET},
  {"&&", TokenType::AND},
  {"&|", TokenType::OR},
  {"||", TokenType::XOR},
  {"->", TokenType::ONLYIF},
  {"<->", TokenType::IFANDONLYIF},
  {"", TokenType::EMPTY}
};
