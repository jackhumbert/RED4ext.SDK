#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/IScriptable.hpp>
#include <RED4ext/Map.hpp>
#include <RED4ext/SharedMutex.hpp>

namespace RED4ext
{
namespace world
{
struct EffectBlackboard : IScriptable
{
    static constexpr const char* NAME = "worldEffectBlackboard";
    static constexpr const char* ALIAS = NAME;

    // 1.6  RVA: 0x1037C20 / 17005600
    /// @pattern 48 89 5C 24 08 48 89 54 24 10 56 57 41 56 48 83 EC 50 48 8D 79 68 0F 29 74 24 40 4C 8D 71 40 0F
    void __fastcall SetValue(CName parameterName, float clampedValue);
    
    Map<CName, float> unk40;
    SharedSpinLock unk68;
};
RED4EXT_ASSERT_SIZE(EffectBlackboard, 0x70);
} // namespace world
using worldEffectBlackboard = world::EffectBlackboard;
} // namespace RED4ext

// clang-format on
