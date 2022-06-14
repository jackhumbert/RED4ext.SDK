#pragma once

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>

namespace RED4ext
{
namespace world { 
struct CompiledNodeInstanceSetupInfo
{
    static constexpr const char* NAME = "worldCompiledNodeInstanceSetupInfo";
    static constexpr const char* ALIAS = NAME;

    uint64_t id; // 00
    RED4ext::Vector4 position; // 08
    RED4ext::Quaternion rotation; // 18
    RED4ext::Vector3 scale; // 28
    float maxStreamingDistance; // 34
    RED4ext::Vector3 boundsMin; // 38
    RED4ext::Vector3 boundsMax; // 44
    uint64_t unk50; // 50
    RED4ext::ResourceAsyncReference questPrefabRef; // 58
    RED4ext::ResourceAsyncReference prefabDataRef; // 60
    uint64_t unk68; // 68
    uint32_t unk70; // 70
    uint32_t unk74; // 74
    uint32_t unk78; // 78
    uint8_t unk7C; // 7C
    uint8_t unk7D; // 7D
    uint16_t handleIndex; // 7E
};
RED4EXT_ASSERT_SIZE(CompiledNodeInstanceSetupInfo, 0x80);
} // namespace world
} // namespace RED4ext
