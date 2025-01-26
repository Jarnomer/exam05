#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator() {}

TargetGenerator::TargetGenerator(const TargetGenerator &other) {
  *this = other;
}

TargetGenerator &TargetGenerator::operator=(const TargetGenerator &other) {
  book = other.book;
  return *this;
}

TargetGenerator::~TargetGenerator() {
  for (auto it = book.begin(); it != book.end(); ++it) {
    delete it->second;
  }
  book.clear();
}

void TargetGenerator::learnTargetType(const ATarget *ref) {
  if (ref != nullptr) {
    std::string tag = ref->getType();
    book[tag] = ref->clone();
  }
}

void TargetGenerator::forgetTargetType(const std::string &tag) {
  auto it = book.find(tag);
  if (it != book.end()) {
    delete it->second;
    book.erase(it);
  }
}

ATarget *TargetGenerator::createTarget(const std::string &tag) {
  ATarget *target = nullptr;
  auto it = book.find(tag);
  if (it != book.end()) {
    target = book[tag];
  }
  return (target);
}
