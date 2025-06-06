#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/world/IRuntimeSystem.hpp>
#include <RED4ext/Scripting/Natives/Generated/ent/Factory.hpp>

namespace RED4ext
{
namespace world
{
struct RuntimeSystemEntity : world::IRuntimeSystem
{
    static constexpr const char* NAME = "worldRuntimeSystemEntity";
    static constexpr const char* ALIAS = NAME;

    // scene, maybe
    void *unk48;
    uint64_t unk50;
    uint64_t unk58;
    DynArray<ent::Factory> factories;
    SharedSpinLock unk70;
    // uint64_t unk78;
    HashMap<uint64_t, uint64_t> unk80;
};
RED4EXT_ASSERT_SIZE(RuntimeSystemEntity, 0xA8);
} // namespace world
using worldRuntimeSystemEntity = world::RuntimeSystemEntity;
} // namespace RED4ext

// clang-format on
