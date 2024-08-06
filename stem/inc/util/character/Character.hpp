/**
 * @file stem/inc/util/character/Character.hpp
 * @author Christian Santos
 * @version 1.0.0
 * @date 8/5/2024
 */

#pragma once

#include "CharacterType.hpp"
#include "CharacterUtils.hpp"
#include "Position.hpp"

namespace stem
{
  struct Character
  {
    CharacterType type;
    Position pos;
    char c;

    Character();
    /// copy constructor
    Character(const Character &character);
    void init();
    std::string to_string();
  };
}