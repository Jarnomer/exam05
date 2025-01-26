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

Warlock::~Warlock() {
  std::cout << name << ": My job here is done!\n";
  for (auto it = book.begin(); it != book.end(); ++it) {
    delete it->second;
  }
  book.clear();
}

const std::string &Warlock::getName() const { return name; }

const std::string &Warlock::getTitle() const { return title; }

void Warlock::setTitle(const std::string &title) { this->title = title; }

void Warlock::introduce() const { std::cout << name << ": I am " << name << ", " << title << "!\n"; };

void Warlock::learnSpell(const ASpell *ref) {
  if (ref != nullptr) {
    std::string tag = ref->getName();
    auto it = book.find(tag);
    if (it == book.end()) {
      book[tag] = ref->clone();
    }
  }
}

void Warlock::forgetSpell(const std::string &tag) {
  auto it = book.find(tag);
  if (it != book.end()) {
    delete it->second;
    book.erase(it);
  }
}

void Warlock::launchSpell(const std::string &tag, const ATarget &target) {
  auto it = book.find(tag);
  if (it != book.end()) {
    it->second->launch(target);
  }
}
