#include "SpellBook.hpp"

SpellBook::SpellBook() {}

SpellBook::SpellBook(const SpellBook &other) { *this = other; }

SpellBook &SpellBook::operator=(const SpellBook &other) {
  book = other.book;
  return *this;
}

SpellBook::~SpellBook() {
  for (auto &it : book) {
    delete it.second;
  }
  book.clear();
}

void SpellBook::learnSpell(const ASpell *ptr) {
  if (ptr) {
    book.insert({ptr->getName(), ptr->clone()});
  }
}

void SpellBook::forgetSpell(const std::string &tag) {
  if (auto it = book.find(tag); it != book.end()) {
    delete it->second;
    book.erase(it);
  }
}

ASpell *SpellBook::createSpell(const std::string &tag) {
  if (auto it = book.find(tag); it != book.end()) {
    return it->second;
  }
  return nullptr;
}
