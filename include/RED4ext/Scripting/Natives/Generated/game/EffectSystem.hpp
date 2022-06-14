#pragma once

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/IEffectSystem.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/EffectSet.hpp>
#include <RED4ext/NativeTypes.hpp>

namespace RED4ext
{
namespace game { 
struct EffectSystem : game::IEffectSystem
{
    static constexpr const char* NAME = "gameEffectSystem";
    static constexpr const char* ALIAS = "EffectSystem";

    uintptr_t unk48[7];
    DynArray<uint64_t> effectNameHashes;
    DynArray<ResourceHandle<EffectSet>> effectResources;
    uint32_t unkA0;
    uint32_t unkA4;
    DynArray<uintptr_t> unkA8;
    uintptr_t unkB8[8];

};
RED4EXT_ASSERT_SIZE(EffectSystem, 0xF8);
} // namespace game
using EffectSystem = game::EffectSystem;
} // namespace RED4ext
