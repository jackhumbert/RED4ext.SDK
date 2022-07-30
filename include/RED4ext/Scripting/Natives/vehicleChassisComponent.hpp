#pragma once

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/NativeTypes.hpp>
#include <RED4ext/Scripting/Natives/Generated/ent/IPlacedComponent.hpp>

namespace RED4ext
{
namespace physics { struct SystemResource; }

namespace vehicle { 
struct ChassisComponent : ent::IPlacedComponent
{
    static constexpr const char* NAME = "vehicleChassisComponent";
    static constexpr const char* ALIAS = NAME;

    // 1.52 RVA: 0x1C6FCA0 / 29818016
    /// @pattern 4C 8B DC 53 48 83 EC 70 8B 81 60 01 00 00 48 8B D9 49 8D 4B 08 41 89 43 08 E8 82 60 7D FE 84 C0
    __int64 __fastcall Unknown1();

    uint8_t unk120[0x128 - 0x120]; // 120
    Ref<physics::SystemResource> collisionResource; // 128
    Ref<physics::SystemResource> optionalPlayerOnlyCollisionResource; // 140
    uint8_t unk158[0x190 - 0x158]; // 158
};
RED4EXT_ASSERT_SIZE(ChassisComponent, 0x190);
} // namespace vehicle
} // namespace RED4ext
