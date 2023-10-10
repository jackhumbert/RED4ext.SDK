#pragma once

// clang-format off

// This file is generated by Jack

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/physicsProxyType.hpp>
#include <RED4ext/Scripting/Natives/physicsStateValue.hpp>
#include <RED4ext/Scripting/Natives/physicsProxyCache.hpp>

namespace RED4ext {
namespace ent { struct Entity; struct IComponent; }
namespace physics {
struct ProxyCacheID;
struct BaseProxyDesc;
struct BaseProxy {
    // just after "TimeDeltaOverride"
    // 1.6  RVA: 0x313A550
    // 1.61hf1 RVA: 0x3142700
    static constexpr const uintptr_t VFT = 0x3142700;

    virtual void sub_00();
    // iterates through physicsSystemResource->bodies
    // creates rigid bodies through physx, sets them up
    virtual void Process(BaseProxyDesc*);
    virtual void sub_10(ProxyCacheID*);
    // does something with aggregate/bodies
    virtual void sub_18(ProxyCacheID*);
    virtual void sub_20(ProxyCacheID*);
    virtual void sub_28();
    virtual void sub_30();
    virtual void sub_38();
    virtual void sub_40();
    // number of rigidBodies
    virtual uint32_t sub_48() = 0;
    // similar to sub_58, but seems to be mostly reads/gets
    // gets rigidFlag & 4 != 1
    virtual bool sub_50(uint32_t bodyIndex, uint32_t shapeIndex, StateValue updateType, void* data,
                        size_t dataSize);
    // does different things based on updateType
    // calls pxRigidBody_Update & returns 1 if successful/handled
    // if bodyIndex belongs to a PxRigidBody, the processing continues
    // 12: PxRigidBodyExt::addForce
    // 15: setLinearVelocity & setAngularVelocity
    // 73: setRigidBodyFlag(4, data), setRigidBodyFlag(64, data)
    virtual bool sub_58(uint32_t bodyIndex, uint32_t shapeIndex, StateValue updateType, void* data,
                        size_t dataSize, bool wakeOption);
    virtual void sub_60();
    virtual void sub_68();
    virtual void sub_70();

    Handle<ent::Entity> entity;
    Handle<ent::IComponent> component;
    // num of handles used
    uint32_t numHandles;
    uint32_t unk2C;
    physics::ProxyID proxyID;
    // some index in a global array/storage of refCounts (inc on creation, dec on deletion)
    ProxyType type;
    // set from desc.unkB8 (0x17 for chassis)
    uint8_t unk35;
    uint8_t unk36;
    enum class Flags : uint8_t {
        // checked when enabling/disabling collision
        unk40 = 0x40,
    } flags;
    // 
    uint64_t unk38;

//    void DisableCollision() {
//        if (flags.unk40) {
//            if (unk38 == 0) {
//                // add to unk948.systemKeys
//            }
//            unk38 = 2;
//        } else {
//            if (unk38 != 0) {
//                // remove from unk948.systemKeys
//                // set unk2A2054[ProxyID.id] to -1
//            }
//            unk38 = 0;
//        }
//    }
//
//    void EnableCollision() {
//        if (flags.unk40) {
//            if (unk38 != 0) {
//                // remove from unk948.systemKeys
//            }
//            unk38 = 0;
//        } else {
//            if (unk38 == 0) {
//                // add to unk948.systemKeys
//                // set unk2A2054 to unk948.unk00
//            }
//            unk38 = 1;
//        }
//    }
};


// 1.6 RVA: 0x4B8750 / 4949840
/// @pattern 48 8B C4 48 89 58 10 55 56 57 41 54 41 56 48 8D 68 A9 48 81 EC F0 00 00 00 44 0F 29 50 88 49 8B
bool __fastcall pxRigidBody_Get(void* data, __int64 a2, RED4ext::physics::StateValue updateType,
                                void* rigidBody, uint32_t shapeIndex);

// does different things based on updateType:
// 1:  setKinematicTarget(a3)
// 2:  setGlobalPose(a3) don't wake
// 3:  setGlobalPose(a3)
// 4:  setLinearVelocity(a3)
// 5:  setAngularVelocity(a3)
// 7:  setLinearDamping(a3)
// 8:  setAngularDamping(a3)
// 13: if a3 putToSleep() else wakeUp()
// 16: PxRigidBodyExt::setMassAndUpdateInertia
// 17: setMassSpaceInertiaTensor(a3)
// 21: setRigidBodyFlag(1, a3)
// 22: setActorFlag(2, a3 == 0)
// 32: shapes[shapeIndex]->setSimulationFilterData(a3), sets all if shapeIndex == -1
// 33: shapes[shapeIndex]->setQueryFilterData(a3), sets all if shapeIndex == -1
// 34: shapes[shapeIndex]->setLocalPose(a3), sets all if shapeIndex == -1
// 38: setCMassLocalPose(a3)
// 41: shapes[shapeIndex]->setFlag(2, a3), sets all if shapeIndex == -1
// 42: shapes[shapeIndex]->setFlag(1, a3), sets all if shapeIndex == -1
// 1.6 RVA: 0x4B9570 / 4953456
/// @pattern 48 8B C4 55 56 57 41 56 48 8D 68 B1 48 81 EC D8 00 00 00 44 0F 29 48 98 49 8B F0 44 0F 29 50 88
bool __fastcall pxRigidBody_Update(void* pxRigidBody, RED4ext::physics::StateValue updateType, void* a3,
                                   __int64 a4, unsigned int shapeIndex, bool isAsleep);

// 1.6 RVA: 0x44AF80 / 4501376
/// @pattern 48 89 5C 24 18 48 89 74 24 20 57 48 83 EC 60 8B 1A 0F 57 C0 0F 29 44 24 40 48 8D 54 24 70 0F 28
RED4ext::Transform* __fastcall ProxyID_GetGlobalPose(RED4ext::Transform* a1, RED4ext::physics::ProxyID* proxyID,
                                                        unsigned int bodyIndex);

// 1.6  RVA: 0x44A800 / 4499456
/// @pattern 48 89 5C 24 08 48 89 74 24 18 57 48 83 EC 50 8B 02 48 8B D9 41 8B D0 89 44 24 68 48 8D 4C 24 68
RED4ext::Transform* __fastcall GetShapeLocalPos(RED4ext::Transform*, RED4ext::physics::ProxyID* proxyID,
                                                unsigned int bodyIndex, uint32_t shapeIndex);

}
}