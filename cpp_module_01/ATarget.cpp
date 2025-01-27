#include "ATarget.hpp"
#include "ASpell.hpp"

ATarget::ATarget() {}

ATarget::ATarget(const std::string &type) : type(type) {}

ATarget::ATarget(const ATarget &other) { *this = other; }

ATarget &ATarget::operator=(const ATarget &other) {
  type = other.type;
  return *this;
}

ATarget::~ATarget() {}

const std::string &ATarget::getType() const { return type; }

void ATarget::getHitBySpell(const ASpell &ref) const {
  std::cout << type << " has been " << ref.getEffects() << "!\n";
}
