#pragma once

#include <map>

#include "ASpell.hpp"

class SpellBook {
private:
  std::map<std::string, ASpell *> book;

  SpellBook(const SpellBook &other);
  SpellBook &operator=(const SpellBook &other);

public:
  SpellBook();
  ~SpellBook();

  void learnSpell(const ASpell *spell);
  void forgetSpell(const std::string &tag);
  ASpell *createSpell(const std::string &tag);
};
