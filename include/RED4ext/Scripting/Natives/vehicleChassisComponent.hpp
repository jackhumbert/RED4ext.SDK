#pragma once

// This file is generated from the Game's Reflection data

#include <RED4ext/Common.hpp>
#include <RED4ext/NativeTypes.hpp>
#include <RED4ext/Scripting/Natives/Generated/Transform.hpp>
#include <RED4ext/Scripting/Natives/Generated/ent/IPlacedComponent.hpp>
#include <RED4ext/Scripting/Natives/Generated/physics/SimulationType.hpp>
#include <RED4ext/Scripting/Natives/entITransformAttachable.hpp>
#include <RED4ext/Scripting/Natives/physicsProxyHelper.hpp>
#include <RED4ext/Scripting/Natives/physicsProxyID.hpp>
#include <RED4ext/Scripting/Natives/physicsProxyCache.hpp>
#include <RED4ext/Scripting/Natives/physicsInitialState.hpp>
#include <cstdint>

namespace RED4ext
{
namespace physics
{
struct SystemResource;
struct ICollider;
struct FilterData;
} // namespace physics

namespace game { struct VehicleSystem; }

namespace vehicle
{

struct ChassisComponent : ent::IPlacedComponent, ent::ITransformAttachable
{
    static constexpr const char* NAME = "vehicleChassisComponent";
    static constexpr const char* ALIAS = NAME;

    /// @pattern 20 8A 67 5B F7 7F 00 00 6D 5F 63 6F 6C 6C 69 73 69 6F 6E 52 65 73 6F 75 72 63 65 00 00 00 00 00
    /// @offset 24
    // static constexpr const uintptr_t ITransformAttachable::VFT = 0;

    // virtuals

    // creates collider & proxyIDs
    // virtual sub_178(uint64_t);

    // references proxyIDs and unk180
    // virtual sub_180();

    // turns on/off collision based on a1
    virtual void sub_1E8(bool a1);

    // something with playerOnly proxyID
    virtual void ITransformAttachable_08(WorldTransform*, bool);

    // non-virtual methods

    // 1.52 RVA: 0x1C6FCA0 / 29818016
    /// @pattern 4C 8B DC 53 48 83 EC 70 8B 81 60 01 00 00 48 8B D9 49 8D 4B 08 41 89 43 08 E8 82 60 7D FE 84 C0
    __int64 __fastcall Unknown1();

    // 1.52 RVA: 0x1C71CB0 / 29826224
    /// @pattern 40 53 48 83 EC 20 80 B9 8B 00 00 00 00 48 8B D9 74 2F 8B 81 60 01 00 00 48 8D 4C 24 30 89 44 24
    void __fastcall SomethingIfEnabled();

    // 1.6 RVA: 0x1C9E610 / 30008848
    /// @pattern 40 55 41 55 48 8D AC 24 78 F9 FF FF 48 81 EC 88 07 00 00 8B 81 60 01 00 00 4C 8B E9 48 8D 8D B0
    bool __fastcall BigUpdate();

    // may set CCD based on the Z component of vehicle->unk568->linearVelocity (unk48) abs(Z) <= 13.0
    // 1.6 RVA: 0x1C9FE40 / 30015040
    /// @pattern 40 53 48 83 EC 40 48 89 74 24 60 48 8B D9 8B B1 70 01 00 00 48 89 7C 24 68 48 8B 79 50 48 85 FF
    void __fastcall Update();

    // 1.6  RVA: 0x1C9CBD0 / 30002128
    /// @pattern 48 89 5C 24 08 48 89 74 24 10 57 48 83 EC 30 48 8B DA 48 8B F9 45 84 C0 74 1C 48 8D B1 40 01 00
    Handle<RED4ext::physics::ICollider>** __fastcall GetCollisionShapes(Handle<RED4ext::physics::ICollider>** start_end,
                                                                        bool playerOnly);

    // 1.6  RVA: 0x1C9BED0 / 29998800
    /// @pattern 48 83 EC 48 41 0F 10 60 10 4D 8B C8 0F 29 74 24 30 0F 28 DC 0F 59 DC C7 44 24 0C 00 00 80 3F 0F
    WorldTransform* __fastcall TransformWorldTransform(WorldTransform* a2, WorldTransform* a3);

    // 1.6  RVA: 0x1C9C840 / 30001216
    /// @pattern 40 53 48 83 EC 20 8B 81 60 01 00 00 4C 8D 81 6C 01 00 00 48 8B DA 89 44 24 30 48 8B CB 48 8D 54
    // physics::ProxyHelper* __fastcall GetProxyHelperAndLock(physics::ProxyHelper* proxyHelper);

    // 1.6  RVA: 0x1C9C110 / 29999376
    /// @pattern 40 53 48 83 EC 40 8B 81 60 01 00 00 48 8B D9 48 8D 4C 24 50 89 44 24 50 E8 33 F1 7A FE 84 C0 74
    bool __fastcall SetDampingToPoint4();

    // does some bit testing on unk174 & shapeIndex for setting with filterDataBottom
    // 1.6  RVA: 0x1C9C300 / 29999872
    /// @pattern 48 89 5C 24 10 48 89 74 24 18 57 48 83 EC 40 8B 81 60 01 00 00 49 8B F0 4C 8D 81 6C 01 00 00 89
    __int64 __fastcall SetFilterData(physics::FilterData* filterData, physics::FilterData* filterDataBottom);

    // 1.6 RVA: 0x1C9DF40 / 30007104
    /// @pattern 48 89 5C 24 18 55 56 57 48 83 EC 60 48 8B 79 50 41 0F B6 E8 8B F2 48 8B D9 48 85 FF 0F 84 9F 01
    void __fastcall UpdatePhysicsState(uint32_t a2, bool unset);

    // data

    Ref<physics::SystemResource> collisionResource;                   // 128
    Ref<physics::SystemResource> optionalPlayerOnlyCollisionResource; // 140
    uint64_t unk158;
    physics::ProxyID proxyID; // 160
    physics::ProxyID proxyID_PlayerOnly; // 168
    physics::ProxyCacheID proxyCacheID; // 16C
    SharedSpinLock sharedMutex;
    uint32_t unk170;
    // colliders that have chassis_bottom tag - seems to extend past 32bits
    // 1 << shape_index
    uint32_t chassisBottomMask;
    uint64_t unk178;
    NativeArray<physics::InitialState, 16> * initialStates;
    game::VehicleSystem* vehicleSystem;
};
RED4EXT_ASSERT_SIZE(ChassisComponent, 0x190);
} // namespace vehicle
} // namespace RED4ext