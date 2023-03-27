#pragma once

// clang-format off

// This file is generated by Jack

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/physicsBaseProxy.hpp>
#include <RED4ext/Scripting/Natives/physicsProxyCache.hpp>

namespace RED4ext::physics {
struct PhysicalSystemProxy : BaseProxy
{
    // just after 3BC43730h & 3F266666h
    // 1.6  RVA: 0x313D790
    // 1.62 RVA: 0x314592C
    static constexpr const uintptr_t VFT = 0x314592C;

    // offsets bodies from unk948.offset
    // runs aggregate->sub_60 or sub_78
    // put bodies to sleep if they're not kinematic
    // set flags to 0x40
    virtual void sub_10(ProxyCacheID *);

    // unsets flags 0x40
    // runs aggregate->sub_80 or sub_70
    //
    virtual void sub_18(ProxyCacheID *);

    virtual uint32_t sub_48() = 0;
    // handles stateValue.unk18 as well
    virtual bool sub_50(uint32_t bodyIndex, uint32_t shapeIndex, physics::StateValue updateType, void* data, size_t dataSize);
    virtual bool sub_58(uint32_t bodyIndex, uint32_t shapeIndex, physics::StateValue updateType, void* data, size_t dataSize, bool wakeOption);
    // PhysX D6Joints
    DynArray<void*> joints;
    // PxRigidBody*
    DynArray<void*> bodies;
    // PxAggregate*
    void* aggregate;
    uint8_t unk68;
};
}