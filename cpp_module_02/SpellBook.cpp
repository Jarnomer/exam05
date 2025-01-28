#include "SpellBook.hpp"

SpellBook::SpellBook() {}

SpellBook::SpellBook(const SpellBook &other) { *this = other; }

SpellBook &SpellBook::operator=(const SpellBook &other) {
  book = other.book;
  return *this;
}

SpellBook::~SpellBook() {}

void SpellBook::learnSpell(const ASpell *ptr) {
  if (ptr)
    book.insert({ptr->getName(), ptr->clone()});
}

void SpellBook::forgetSpell(const std::string &tag) { book.erase(tag); }

ASpell *SpellBook::createSpell(const std::string &tag) {
  auto it = book.find(tag); 
  if (it != book.end())
    return it->second;
  return nullptr;
}
