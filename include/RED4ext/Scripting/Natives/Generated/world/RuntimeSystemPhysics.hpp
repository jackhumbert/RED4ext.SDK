#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/world/IRuntimeSystem.hpp>
#include <RED4ext/Scripting/Natives/Generated/physics/GeometryCache.hpp>

namespace RED4ext
{
namespace world
{
struct RuntimeSystemPhysics : world::IRuntimeSystem
{
    static constexpr const char* NAME = "worldRuntimeSystemPhysics";
    static constexpr const char* ALIAS = NAME;
    
    /// @hash 3990752513
    // static constexpr const uintptr_t VFT = worldRuntimeSystemPhysics_VFT_Addr;

    // virtual (last)
    // 1.6 RVA: 0xB27000 / 11694080
    /// @pattern 40 53 48 83 EC 40 8B 41 58 48 8B D9 48 8D 4C 24 50 89 44 24 50 E8 46 35 99 FF 48 8B 8B 80 01 00
    __int64 __fastcall FreeGeos();


    // uint8_t unk48[0x1B0 - 0x48]; // 48
    // Handle<physics::GeometryCache> geoCache; // 1B0
    // uint8_t unk1C0[0x1F8 - 0x1C0]; // 1C0
    
    uint8_t unk48[0x200 - 0x48]; // 48
};
RED4EXT_ASSERT_SIZE(RuntimeSystemPhysics, 0x200);
} // namespace world
using worldRuntimeSystemPhysics = world::RuntimeSystemPhysics;
} // namespace RED4ext

// clang-format on
