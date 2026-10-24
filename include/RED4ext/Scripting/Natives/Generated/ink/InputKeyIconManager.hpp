#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/ISerializable.hpp>
#include <RED4ext/Scripting/Natives/Generated/ink/TextureAtlas.hpp>
#include <RED4ext/Scripting/Natives/Generated/input/EInputDevice.hpp>

namespace RED4ext
{
namespace ink
{
    
struct InputIconPartData {
    CName part;
};

struct InputIconTextureData {
    uint64_t unk00;
    uint64_t unk08;
    ResourcePath atlasPath;
    CName partName;
};

struct InputKeyIconManager : ISerializable
{
    static constexpr const char* NAME = "inkInputKeyIconManager";
    static constexpr const char* ALIAS = NAME;

    struct InputDeviceTextureData {
        Handle<ink::TextureAtlas> atlas;
        Map<uint32_t, ink::InputIconPartData> parts;
    };

    // 2.31: Map<input::EInputDevice, InputDeviceTextureData> inputDevices at 0x68
    // (size was 0x1E8); not re-verified on 2.5
    uint8_t unk30[0x200 - 0x30]; // 30
};
RED4EXT_ASSERT_SIZE(InputKeyIconManager, 0x200);
} // namespace ink
using inkInputKeyIconManager = ink::InputKeyIconManager;
} // namespace RED4ext

// clang-format on
