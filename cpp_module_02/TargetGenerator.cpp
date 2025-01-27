#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator() {}

TargetGenerator::TargetGenerator(const TargetGenerator &other) { *this = other; }

TargetGenerator &TargetGenerator::operator=(const TargetGenerator &other) {
  book = other.book;
  return *this;
}

TargetGenerator::~TargetGenerator() {
  for (auto &it : book) {
    delete it.second;
  }
  book.clear();
}

void TargetGenerator::learnTargetType(const ATarget *ptr) {
  if (ptr) {
    book.insert({ptr->getType(), ptr->clone()});
  }
}

void TargetGenerator::forgetTargetType(const std::string &tag) {
  if (auto it = book.find(tag); it != book.end()) {
    delete it->second;
    book.erase(it);
  }
}

ATarget *TargetGenerator::createTarget(const std::string &tag) {
  if (auto it = book.find(tag); it != book.end()) {
    return it->second;
  }
  return nullptr;
}
