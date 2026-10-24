#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>

namespace RED4ext
{
namespace world
{
struct CompiledSector
{
    static constexpr const char* NAME = "worldCompiledSector";
    static constexpr const char* ALIAS = NAME;

    // 2.31 layout (size 0x60); 2.5 grew it by 8 somewhere, not re-verified:
    // uint8_t unk00[0x28 - 0x0]; // 0
    // DynArray<Handle<Node>> nodes; // 28
    // DynArray<NodeRef> nodeRefs; // 38
    // DynArray<uint32_t> variantIndices; // 48
    // int64_t variantStart; // 58
    uint8_t unk00[0x68 - 0x0]; // 0
};
RED4EXT_ASSERT_SIZE(CompiledSector, 0x68);
} // namespace world
using worldCompiledSector = world::CompiledSector;
} // namespace RED4ext

// clang-format on
