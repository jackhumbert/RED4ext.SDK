#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/CName.hpp>
#include <RED4ext/DynArray.hpp>
#include <RED4ext/Handle.hpp>
#include <RED4ext/Scripting/Natives/Generated/Transform.hpp>
#include <RED4ext/Scripting/Natives/Generated/physics/ISystemObject.hpp>
#include <RED4ext/Scripting/Natives/Generated/physics/SystemBodyParams.hpp>

namespace RED4ext
{
namespace physics { struct ICollider; }

namespace physics
{
struct __declspec(align(0x10)) SystemBody : physics::ISystemObject
{
    static constexpr const char* NAME = "physicsSystemBody";
    static constexpr const char* ALIAS = NAME;

    static constexpr const uint32_t VFT = 2297825699;

    DynArray<Handle<physics::ICollider>> collisionShapes; // 38, Setup
    uint8_t unk48[0x49 - 0x48]; // 48
    bool isQueryBodyOnly; // 49, Overrides
    uint8_t unk4A[0x50 - 0x4A]; // 4A
    physics::SystemBodyParams params; // 50, Setup
    Transform localToModel; // B0, Setup
    CName mappedBoneName; // D0, Ragdoll
    uint8_t unkD8[0xE0 - 0xD8]; // D8
    Transform mappedBoneToBody; // E0, Ragdoll
};
RED4EXT_ASSERT_SIZE(SystemBody, 0x100);
} // namespace physics
using physicsSystemBody = physics::SystemBody;
} // namespace RED4ext

// clang-format on
