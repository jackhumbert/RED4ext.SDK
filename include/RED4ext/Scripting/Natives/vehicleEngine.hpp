#pragma once

// This file is generated by Jack

#include <cstdint>
#include <RED4ext/Common.hpp>

namespace RED4ext::vehicle {

struct WheeledBaseObject;

struct Engine {
    WheeledBaseObject *wheeledVehicle;
    uint8_t unk08[0x80 - 0x8];
};
RED4EXT_ASSERT_SIZE(Engine, 0x80);

}