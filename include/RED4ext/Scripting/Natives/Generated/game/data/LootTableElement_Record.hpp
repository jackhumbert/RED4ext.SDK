#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/data/TweakDBRecord.hpp>

namespace RED4ext
{
namespace game::data
{
struct LootTableElement_Record : game::data::TweakDBRecord
{
    static constexpr const char* NAME = "gamedataLootTableElement_Record";
    static constexpr const char* ALIAS = "LootTableElement_Record";

    uint8_t unk48[0xA0 - 0x48]; // 48
};
RED4EXT_ASSERT_SIZE(LootTableElement_Record, 0xA0);
} // namespace game::data
using gamedataLootTableElement_Record = game::data::LootTableElement_Record;
using LootTableElement_Record = game::data::LootTableElement_Record;
} // namespace RED4ext

// clang-format on
