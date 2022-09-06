#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/world/IQuestPrefabStateListener.hpp>

namespace RED4ext
{
namespace quest { 
struct QuestPrefabsHandler : world::IQuestPrefabStateListener
{
    static constexpr const char* NAME = "questQuestPrefabsHandler";
    static constexpr const char* ALIAS = NAME;

    uint8_t unk30[0xF0 - 0x30]; // 30
};
RED4EXT_ASSERT_SIZE(QuestPrefabsHandler, 0xF0);
} // namespace quest
} // namespace RED4ext

// clang-format on
