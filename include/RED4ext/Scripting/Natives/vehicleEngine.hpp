#pragma once

// This file is generated by Jack

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/vehicleWheeledBaseObject.hpp>

namespace RED4ext::vehicle {

struct Engine {
    WheeledBaseObject *wheeledVehicle;
    uint8_t unk08[0x80 - 0x8];
};
RED4EXT_ASSERT_SIZE(Engine, 0x80);

}