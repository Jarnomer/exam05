#include "SpellBook.hpp"

SpellBook::SpellBook() {}

SpellBook::SpellBook(const SpellBook &other) { *this = other; }

SpellBook &SpellBook::operator=(const SpellBook &other) {
  book = other.book;
  return *this;
}

SpellBook::~SpellBook() {
  for (auto it = book.begin(); it != book.end(); ++it) {
    delete it->second;
  }
  book.clear();
}

void SpellBook::learnSpell(const ASpell *ref) {
  if (ref != nullptr) {
    std::string tag = ref->getName();
    book[tag] = ref->clone();
  }
}

void SpellBook::forgetSpell(const std::string &tag) {
  auto it = book.find(tag);
  if (it != book.end()) {
    delete it->second;
    book.erase(it);
  }
}

ASpell *SpellBook::createSpell(const std::string &tag) {
  ASpell *spell = nullptr;
  auto it = book.find(tag);
  if (it != book.end()) {
    spell = book[tag];
  }
  return (spell);
}
