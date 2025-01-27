#pragma once

#include <iostream>

#include "SpellBook.hpp"

class Warlock {
private:
  std::string name;
  std::string title;

  SpellBook book;

  Warlock();
  Warlock(const Warlock &other);
  Warlock &operator=(const Warlock &other);

public:
  Warlock(const std::string &name, const std::string &title);
  ~Warlock();

  const std::string &getName() const;
  const std::string &getTitle() const;

  void setTitle(const std::string &title);

  void introduce() const;

  void learnSpell(const ASpell *ptr);
  void forgetSpell(const std::string &tag);
  void launchSpell(const std::string &tag, const ATarget &ref);
};
