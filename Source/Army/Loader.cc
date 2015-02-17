#include "Loader.hh"

#include "../Mikan/Engine.hh"
#include "Army.hh"
#include <vector>

namespace PA {
namespace Army {

Loader::Loader() {
    load_json(Mikan::Engine::ROOT_DIR + "Information/armies.json");

    for (const auto armies_json : root["armies"]) {
        std::vector<Unit> units;
        for (const auto unit_json : armies_json["units"]) {
            Unit unit;
            if (unit_json.asString() == "Archer") {
                unit.type = Type::Archer;
            }
            units.push_back(unit);
        }
    
        const int province_id = armies_json["province"].asInt();
        auto found = std::find_if(Mikan::Entity::entities.begin(),
                                  Mikan::Entity::entities.end(),
                                  [province_id](Mikan::Entity* entity) {
            const auto province = (PA::Province::Province*)entity;
            return province->id == province_id;
        });
        auto province = (PA::Province::Province*)*found;
        new Army(*province, units);
    }
}

} // namespace Army
} // namespace PA

