#pragma once

#include <map>

#include "ATarget.hpp"

class TargetGenerator {
private:
  std::map<std::string, ATarget *> book;

  TargetGenerator(TargetGenerator const &other);
  TargetGenerator &operator=(TargetGenerator const &other);

public:
  TargetGenerator();
  ~TargetGenerator();

  void learnTargetType(const ATarget *ref);
  void forgetTargetType(const std::string &tag);
  ATarget *createTarget(const std::string &tag);
};
