#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/PersistentState.hpp>

namespace RED4ext
{
namespace game
{
struct ComponentPS : game::PersistentState
{
    static constexpr const char* NAME = "gameComponentPS";
    static constexpr const char* ALIAS = "GameComponentPS";
    static constexpr const uint32_t VFT = 1897269373;

    inline virtual void sub_130() { };
    inline virtual void sub_138() { };
    inline virtual void sub_140() { };
    inline virtual void sub_148() { };
    inline virtual void sub_150() { };

};
RED4EXT_ASSERT_SIZE(ComponentPS, 0x68);
} // namespace game
using gameComponentPS = game::ComponentPS;
using GameComponentPS = game::ComponentPS;
} // namespace RED4ext

// clang-format on
