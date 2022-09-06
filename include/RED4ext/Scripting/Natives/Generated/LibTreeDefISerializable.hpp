#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/CName.hpp>
#include <RED4ext/Handle.hpp>

namespace RED4ext
{
struct ISerializable;

struct LibTreeDefISerializable
{
    static constexpr const char* NAME = "LibTreeDefISerializable";
    static constexpr const char* ALIAS = NAME;

    uint16_t variableId; // 00
    uint8_t unk02[0x8 - 0x2]; // 2
    CName treeVariable; // 08
    Handle<ISerializable> v; // 10
};
RED4EXT_ASSERT_SIZE(LibTreeDefISerializable, 0x20);
} // namespace RED4ext

// clang-format on
