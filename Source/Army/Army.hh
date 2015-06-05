#pragma once

#include <vector>
#include "../Province/Province.hh"
#include "../Mikan/Entity.hh"

namespace PA {
namespace Army {

enum class Type {
  Archer,
  Swordsman
};

struct Unit {
  Type type;
  unsigned short soldiers = 1000;
};

class Army : Mikan::Entity {
public:
  Army(Province::Province& location, std::vector<Unit> units);
  void tick(float delta_seconds) override;

private:
  Province::Province& location;
  std::vector<Unit> units;
};

} // namespace Army
} // namespace PA

