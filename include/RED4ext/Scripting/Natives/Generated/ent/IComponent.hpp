#pragma once

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/CName.hpp>
#include <RED4ext/NativeTypes.hpp>
#include <RED4ext/Scripting/IScriptable.hpp>
// #include <RED4ext/Scripting/Natives/Generated/ent/Entity.hpp>

#include <RED4ext/Scripting/Natives/entIComponent.hpp>

namespace RED4ext
{
namespace ent {
// struct Entity;
// struct IComponent : IScriptable
// {
//     static constexpr const char* NAME = "entIComponent";
//     static constexpr const char* ALIAS = "IComponent";

//     CName name; // 40
//     CName owner; // 48 "player"
//     Handle<Entity> entity; // 50
//     CRUID id; // 60
//     uint64_t unk68;
//     void *unk70;
//     uint64_t unk78;
//     uint64_t unk80;
//     uint8_t unk88;
//     uint8_t unk89;
//     uint8_t unk8A;
//     bool isEnabled; // 8B
//     bool isReplicable; // 8C
//     uint8_t unk8D[0x90 - 0x8D]; // 8D
// };
RED4EXT_ASSERT_SIZE(IComponent, 0x90);
} // namespace ent
using IComponent = ent::IComponent;
} // namespace RED4ext
