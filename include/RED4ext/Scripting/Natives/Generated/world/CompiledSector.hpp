#pragma once

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>

namespace RED4ext
{
namespace world { 
struct CompiledSector
{
    static constexpr const char* NAME = "worldCompiledSector";
    static constexpr const char* ALIAS = NAME;

    uint8_t unk00[0x28 - 0x0]; // 0
    DynArray<Handle<Node>> nodes; // 28
    DynArray<NodeRef> nodeRefs; // 38
    DynArray<uint32_t> variantIndices; // 48
    int64_t variantStart; // 58
};
RED4EXT_ASSERT_SIZE(CompiledSector, 0x60);
} // namespace world
} // namespace RED4ext
