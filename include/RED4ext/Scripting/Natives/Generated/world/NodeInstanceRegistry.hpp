#pragma once

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/world/INodeInstanceRegistry.hpp>

namespace RED4ext
{
namespace world { 
struct NodeInstanceRegistry : world::INodeInstanceRegistry
{
    static constexpr const char* NAME = "worldNodeInstanceRegistry";
    static constexpr const char* ALIAS = NAME;

    uint8_t unk48[0x60100 - 0x48]; // 48


    uint8_t unk48[0x50 - 0x48];
    uint64_t unk50;
    uint32_t unk58;
    uint32_t unk5C;
    // int8_t unk60[0x20058 - 0x60];
    
    #pragma pack(1)
    struct RED4ext::world::NodeInstanceRegistryItem
    {
      RED4ext::ResourceAsyncReference unk00;
      uint64_t unk08;
      uint64_t unk10;
      uint32_t unk18;
    } [0x2000];

    // RED4ext::ResourceAsyncReference unk60[0x4000-1];
    uint64_t unk20058;
    int64_t unk20060;
    int64_t unk20068;
    int8_t unk20070[0x60080 - 0x20070];
    uint8_t unk60080;
};
RED4EXT_ASSERT_SIZE(NodeInstanceRegistry, 0x60100);
} // namespace world
} // namespace RED4ext
