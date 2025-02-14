#include "Warlock.hpp"

Warlock::Warlock() {}

Warlock::Warlock(const std::string &name, const std::string &title) : name(name), title(title) {
  std::cout << name << ": This looks like another boring day.\n";
}

Warlock::Warlock(const Warlock &other) { *this = other; }

Warlock &Warlock::operator=(const Warlock &other) {
  name = other.name;
  title = other.title;
  return *this;
}

Warlock::~Warlock() { std::cout << name << ": My job here is done!\n"; }

const std::string &Warlock::getName() const { return name; }

const std::string &Warlock::getTitle() const { return title; }

void Warlock::setTitle(const std::string &title) { this->title = title; }

void Warlock::introduce() const { std::cout << name << ": I am " << name << ", " << title << "!\n"; };

void Warlock::learnSpell(const ASpell *ptr) {
  if (ptr)
    book.insert({ptr->getName(), ptr->clone()});
}

void Warlock::forgetSpell(const std::string &tag) { book.erase(tag); }

void Warlock::launchSpell(const std::string &tag, const ATarget &ref) {
  auto it = book.find(tag);
  if (it != book.end())
    it->second->launch(ref);
}
