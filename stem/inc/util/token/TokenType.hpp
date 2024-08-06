/**
 * @brief This file is part of {{ stem.inc.util.token }}
 * 
 * @file TokenType.hpp
 * @author Christian Santos
 * @version 1.0.1 
 * @date 8/5/2024
*/

#pragma once

namespace stem
{
  /**
   * @enum TokenType
   * @brief Specifies Type of Token
   */
  enum class TokenType
  {
    TILDE,
    EXCLAMATION,
    ASPERAND,
    PERCENT,
    CARET,
    AMPERSAND,
    ASTERISK,
    LPAREN,
    RPAREN,
    MINUS,
    UNDERSCORE,
    EQUAL,
    PLUS,
    LBRACKET,
    LBRACE,
    RBRACKET,
    RBRACE,
    VSLASH,
    SEMICOLON,
    COLON,
    COMMA,
    LESSTHAN,
    DOT,
    MORETHAN,
    FSLASH,
    SPACE,
    DIGIT,
    IDENTIFIER,
    COMMENT,
    LET,
    AND,
    OR,
    XOR,
    ONLYIF,
    IFANDONLYIF,
    EMPTY,
    UNKNOWN
  };
}
