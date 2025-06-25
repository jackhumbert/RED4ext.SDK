#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/ink/SettingsSelectorController.hpp>

namespace RED4ext
{
namespace ink
{
struct SettingsSelectorControllerKeyBinding : ink::SettingsSelectorController
{
    static constexpr const char* NAME = "inkSettingsSelectorControllerKeyBinding";
    static constexpr const char* ALIAS = "SettingsSelectorControllerKeyBinding";

    // uint8_t unkC8[0xE0 - 0xC8]; // C8
    uint32_t listeningForInput; // C8
    uint32_t callbackFired; // CC
    uint64_t unkD0; // D0
    uint64_t unkD8; // D8
};
RED4EXT_ASSERT_SIZE(SettingsSelectorControllerKeyBinding, 0xE0);
} // namespace ink
using inkSettingsSelectorControllerKeyBinding = ink::SettingsSelectorControllerKeyBinding;
using SettingsSelectorControllerKeyBinding = ink::SettingsSelectorControllerKeyBinding;
} // namespace RED4ext

// clang-format on
