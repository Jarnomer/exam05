#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator() {}

TargetGenerator::TargetGenerator(const TargetGenerator &other) { *this = other; }

TargetGenerator &TargetGenerator::operator=(const TargetGenerator &other) {
  book = other.book;
  return *this;
}

TargetGenerator::~TargetGenerator() {}

void TargetGenerator::learnTargetType(const ATarget *ptr) {
  if (ptr)
    book.insert({ptr->getType(), ptr->clone()});
}

void TargetGenerator::forgetTargetType(const std::string &tag) { book.erase(tag); }

ATarget *TargetGenerator::createTarget(const std::string &tag) {
  auto it = book.find(tag); 
  if (it != book.end())
    return it->second;
  return nullptr;
}
