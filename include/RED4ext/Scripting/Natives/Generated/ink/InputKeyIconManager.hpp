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

    uint8_t unk30[0x68 - 0x30]; // 30
    Map<input::EInputDevice, InputDeviceTextureData> inputDevices; // 68
    uint8_t unk90[0x1E8 - 0x90]; // 90
};
RED4EXT_ASSERT_SIZE(InputKeyIconManager, 0x1E8);
} // namespace ink
using inkInputKeyIconManager = ink::InputKeyIconManager;
} // namespace RED4ext

// clang-format on
