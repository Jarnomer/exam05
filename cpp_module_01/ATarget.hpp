#pragma once

#include <iostream>

class ASpell;

class ATarget {
protected:
  std::string type;

public:
  ATarget();
  ATarget(const std::string &type);

  ATarget(const ATarget &other);
  ATarget &operator=(const ATarget &other);

  virtual ~ATarget();

  const std::string &getType() const;

  void getHitBySpell(const ASpell &spell) const;

  virtual ATarget *clone() const = 0;
};
