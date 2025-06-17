#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/CName.hpp>
#include <RED4ext/DynArray.hpp>
#include <RED4ext/Scripting/Natives/Generated/Box.hpp>
#include <RED4ext/Handle.hpp>
#include <RED4ext/ISerializable.hpp>
#include <RED4ext/Scripting/Natives/Generated/Transform.hpp>
#include <RED4ext/Scripting/Natives/Generated/physics/ApperanceMaterial.hpp>

namespace RED4ext
{
namespace physics { struct FilterData; }

namespace physics
{
struct __declspec(align(0x10)) ICollider : ISerializable
{
    static constexpr const char* NAME = "physicsICollider";
    static constexpr const char* ALIAS = NAME;

    /// @hash 2046757127:idata
    static constexpr const uint32_t VFT = 2046757127;

    // 2.1  RVA: 0x1B7958
    /// @pattern 45 33 C0 48 8D 05 EE 9D 85 02 48 89 01 4C 89 41 08 4C 89 41 10 41 8D 40 01 4C 89 41 18 4C 89 41
    RED4ext::physics::ICollider *__fastcall cstr();

    /// @pattern /mov(physicsICollider_Class_p) /retn
    virtual CClass * GetNativeType() override;

    virtual void sub_D8() = 0;
    virtual void sub_E0() = 0;
    virtual void * CreatePxShape(Vector3 * descUnk140, void * descUnkB0, bool one, void * descUnkC0) = 0;
    // called in a loop in a big chassis update
    // get bounds?
    virtual Box * sub_F0(Box * bounds) = 0;
    virtual void sub_F8() = 0;
    virtual void sub_100() = 0;
    /// @pattern C7 02 00 00 80 3F 48 8B C2 C7 42 04 00 00 80 3F C7 42 08 00 00 80 3F C3
    virtual Vector3 * sub_108(Vector3 * a1);
    virtual void sub_110();
    virtual void sub_118();
    virtual bool sub_120();
    virtual void sub_128();
    virtual void sub_130() = 0;
    virtual void sub_138();
    virtual void sub_140() = 0;

    Transform localToBody; // 30
    CName material; // 50
    DynArray<physics::ApperanceMaterial> materialApperanceOverrides; // 58
    CName tag; // 68
    Handle<physics::FilterData> filterData; // 70
    float volumeModifier; // 80
    bool isImported; // 84
    bool isQueryShapeOnly; // 85
    uint8_t unk86[0x90 - 0x86]; // 86
};
RED4EXT_ASSERT_SIZE(ICollider, 0x90);
} // namespace physics
using physicsICollider = physics::ICollider;
} // namespace RED4ext

// clang-format on
