#pragma once

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/NativeTypes.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/Object.hpp>
#include <RED4ext/Scripting/Natives/Generated/WorldTransform.hpp>
#include <RED4ext/Scripting/Natives/vehiclePhysics.hpp>
#include <RED4ext/Scripting/Natives/vehiclePhysicsData.hpp>
#include <RED4ext/Scripting/Natives/vehicleAirControl.hpp>
#include <RED4ext/Scripting/Natives/Generated/vehicle/ChassisComponent.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/OccupantSlotComponent.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/data/Vehicle_Record.hpp>
#include <RED4ext/Scripting/Natives/Generated/vehicle/Controller.hpp>
#include <RED4ext/Scripting/Natives/Generated/vehicle/CameraManager.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/interactions/Component.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/Puppet.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/IBlackboard.hpp>
#include <RED4ext/Scripting/Natives/Generated/AI/CAgent.hpp>
#include <RED4ext/Scripting/Natives/Generated/move/Component.hpp>
#include <RED4ext/Scripting/Natives/ActionInterface.hpp>

namespace RED4ext
{
namespace weapon { struct Object; }
namespace AI { struct Archetype; }
namespace world
{
struct RuntimeSystemPhysics;
}
namespace ent
{
struct Entity;
}
namespace vehicle
{
struct Physics;
struct PhysicsData;
struct AirControl;
struct Weapon;

//struct Interface : game::Object::Interface
//{
//    virtual uint64_t __fastcall Destruct(char a1) override; // 00
//
//    // Returns 0
//    virtual uint64_t __fastcall sub_08() override;
//};

#pragma pack(push, 1)
struct BaseObject : game::Object
{
    static constexpr const char* NAME = "vehicleBaseObject";
    static constexpr const char* ALIAS = "VehicleObject";
    static constexpr const uintptr_t VFT_RVA = 0x341BB90 + 0x1800;

// overridden member functions

    virtual CClass* __fastcall GetNativeType() override;

    virtual void __fastcall OnRequestComponents(char *) override;

    virtual CString* __fastcall sub_1C0(CString*) override;

    // Looks at unk580, sub_1D0
    virtual RED4ext::CName* __fastcall GetAudioResourceName(RED4ext::CName*) override;

    // Somethign with unk388 & vehicle controller, sub_1F8
    virtual uint64_t __fastcall OnTakeControl(game::ComponentHelper*) override; 

    // Also sends out some red event
    virtual uint64_t __fastcall sub_218(WorldTransform*) override;

// new member functions

    // Loads some vehicle tweaks and sets things up
    virtual void __fastcall sub_268();

    // Loads more tweaks and vehicle weapons
    virtual void __fastcall sub_270();

    // Returns 0.0
    virtual double __fastcall sub_278();

    // Updates physics World Transform, creates physicsData, engine data
    virtual int32_t __fastcall sub_280();

    // Calls physics sub_80
    virtual uint64_t __fastcall sub_288();

    // Calls physics sub_88
    virtual uint64_t __fastcall sub_290();

    // Returns 45.0
    virtual float __fastcall sub_298();

    // Empty function
    virtual void __fastcall sub_2A0();

    // Something with blackboard and effect data
    virtual uint64_t __fastcall sub_2A8();

    // Empty function
    virtual void __fastcall sub_2B0();

    // Call physics sub_58, runs update with chassis
    virtual void __fastcall sub_2B8(uint64_t, uint64_t);

    // Empty function
    virtual void __fastcall sub_2C0();

    // Raytraces, decides isOnGround, physics sub_C0
    virtual void __fastcall sub_2C8();

    // Empty function, calls physics sub_118
    virtual void __fastcall sub_2D0();

    // Empty function, calls physics sub_120
    virtual void __fastcall sub_2D8();

    // Something with the entity stored separately flag, maybe mounting related, calls sub_310
    virtual uint64_t __fastcall sub_2E0();

    virtual uint64_t __fastcall sub_2E8();

    virtual uint64_t __fastcall sub_2F0();

    // updates wheel positions, calls sub_310
    virtual uint64_t __fastcall sub_2F8();

    // Get vehicle record handle
    virtual Handle<game::data::Vehicle_Record> * __fastcall GetRecord(Handle<game::data::Vehicle_Record>*);

    // Get unk tweak record/hash
    virtual uint64_t __fastcall sub_308(uint64_t *);

    // mount/engine related
    virtual uint64_t __fastcall sub_310();

    // checks something in engine data
    virtual uint64_t __fastcall sub_318();

    // some physics & wheel stuff
    virtual uint64_t __fastcall sub_320();
    virtual uint64_t __fastcall sub_328();
    virtual uint64_t __fastcall sub_330();
    virtual uint64_t __fastcall sub_338();
    virtual uint64_t __fastcall sub_340();
    virtual uint64_t __fastcall sub_348();

    // Something wheels
    virtual uint64_t __fastcall sub_350();

    // Something vehicle audio
    virtual uint64_t __fastcall sub_358();

    // Process vehicle weapons
    virtual void __fastcall sub_360(float, uint32_t index);

    // Fire vehicle weapon, calls generic weapon shoot
    virtual uint64_t __fastcall sub_368(weapon::Object *weaponObject, Vector4 *weaponPosition, Vector4 *offset, Vector4 *tracePosition, float range, __int64 numProjectiles, __int64 a8, __int64 a9, __int64 a10);

    // Empty Function
    virtual void __fastcall sub_370();

    // Get Aim Trace Position
    virtual Vector3* __fastcall sub_378(Vector3*);

    // Get shoot value for index
    virtual uint8_t __fastcall sub_380(int);

// non-virtual methods

    // 1.52 RVA: 0x1C4D3A0 / 29676448
    /// @pattern 48 8B 81 B8 02 00 00 F3 0F 10 80 BC 01 00 00 C3
    float __fastcall GetTotalMass();

    // 1.52 RVA: 0x1C4D3B0 / 29676464
    /// @pattern 48 8B 81 B8 02 00 00 F3 0F 10 40 40 C3
    float __fastcall GetInverseMass();

    // 1.52 RVA: 0x1C4D3C0 / 29676480
    /// @pattern 48 8B 81 08 05 00 00 48 8B 89 B8 02 00 00 F3 0F 10 40 68 F3 0F 59 81 BC 01 00 00 C3
    float __fastcall GetGravitationalForce();

    // 1.52 RVA: 0x1C4D3E0 / 29676512
    /// @pattern 8B 81 0C 06 00 00 C3
    float __fastcall GetUnk60C();

    // 1.52 RVA: 0x1C4D3F0 / 29676528
    /// @pattern 48 89 5C 24 10 48 89 7C 24 20 55 48 8D 6C 24 A9 48 81 EC 90 00 00 00 83 B9 D0 05 00 00 00 48 8B
    CString *__fastcall GetDisplayName(CString *);

    // 1.52 RVA: 0x1C4D630 / 29677104
    /// @pattern 48 89 5C 24 10 48 89 6C 24 18 48 89 74 24 20 57 48 83 EC 30 48 8B 99 C0 02 00 00 48 8B FA 48 8B
    Handle<void> *__fastcall GetCurveSetData(Handle<void> *);

    // 1.52 RVA: 0x1C4D7B0 / 29677488
    /// @pattern 48 8B 81 08 05 00 00 C3
    world::RuntimeSystemPhysics *__fastcall GetVehicleSystem();

    // 1.52 RVA: 0x1C4D7E0 / 29677536
    /// @pattern 40 53 48 83 EC 20 48 8B DA 44 3B 81 4C 09 00 00 73 2A 41 8B C0 4C 8D 04 40 48 8B 81 40 09 00 00
    Quaternion *__fastcall GetWeaponOrientation(Quaternion *, uint32_t index);

    // 1.52 RVA: 0x1C4E190 / 29680016
    /// @pattern 40 55 56 57 48 8D 6C 24 B9 48 81 EC F0 00 00 00 48 8D B1 28 09 00 00 0F 29 B4 24 D0 00 00 00 48
    void __fastcall HornForDuration();

    // 1.52 RVA: 0x1C4E3F0 / 29680624
    /// @pattern 48 8B C4 55 56 57 48 8D 68 A1 48 81 EC F0 00 00 00 0F 29 70 D8 48 8D B1 20 09 00 00 48 8B F9 0F
    void __fastcall HornForDurationDelayed(float xmm1_4_0);

    // 1.52 RVA: 0x1C49080 / 29659264
    /// @pattern 48 83 EC 48 48 89 5C 24 50 48 8B D9 48 89 74 24 60 48 8D 4A 20 4C 89 74 24 38 48 8B F2 E8 8E 52
    void __fastcall ClearFinishMountingDelay(void *);

    // 1.52 RVA: 0x1C491C0 / 29659584
    /// @pattern C7 81 B4 08 00 00 00 00 80 3F C7 81 B8 08 00 00 00 00 80 3F C7 81 BC 08 00 00 00 00 80 3F C7 81
    void __fastcall Reset8B4();

    // 1.52 RVA: 0x1C492A0 / 29659808
    /// @pattern 48 8D 81 E0 08 00 00 C3
    void *__fastcall GetUnk8E0();

    // 1.52 RVA: 0x126CE00 / 19320320
    /// @pattern 48 8D 81 88 03 00 00 C3
    ActionInterface *__fastcall GetInterface();

    // 1.52 RVA: 0x72FE70 / 7536240
    /// @pattern 48 8B 81 B8 02 00 00 C3
    PhysicsData *__fastcall GetPhysicsData();

    // 1.52 RVA: 0x72FE80 / 7536256
    /// @pattern F2 0F 10 81 58 02 00 00 C3
    double __fastcall GetDeceleration();

    world::RuntimeSystemPhysics* physicsSystem;
    float unk248;
    bool isOnGround;
    uint8_t unk24D[3];
    uint32_t isInTrafficPhysicsState;
    float acceleration;
    float deceleration;
    float handbrake;
    float strafeY;
    float strafeX;
    float turnInput;
    float leanFB;
    float rockFB;
    uint8_t shootPrimary;
    uint8_t shootSecondary;
    uint8_t shootTertiary;
    uint8_t vehicleCameraInverse;
    float cameraX;
    float cameraY;
    float cameraMouseX;
    float cameraMouseY;
    uint8_t cycleLights;
    uint8_t horn;
    uint8_t unk28A;
    uint8_t unk28B;
    float unk29C;
    float unk2A0;
    float unk2A4;
    float unk2A8;
    float unk2AC;
    float unk2B0;
    float unk2B4;
    float unk2B8;
    float unk2BC;
    Physics* physics;             // 2B0
    PhysicsData* physicsData; // 2B8
    Handle<void> curveSetData;
    Handle<ChassisComponent> chassis;
    float unk2E0[16];
    uint64_t chassisType;
    uint64_t unk328;
    WorldTransform worldTransform;
    Vector3 unk350;
    float unk35C;
    uint8_t unk360;
    uint8_t unk361;
    uint8_t unk362;
    uint8_t unk363;
    float unk364;
    Handle<AI::CAgent> aiComponent;
    Handle<move::Component> moveComponent;
    ActionInterface actionInterface; // 388
    Handle<void> baseDrivingParams[4];
    Handle<game::interactions::Component> interactionsComponent;
    Handle<game::interactions::Component> passengerInteractions;
    Handle<Controller> vehicleController;
    Handle<void> wheelRuntimePSData;
    Handle<CameraManager> cameraManager;
    world::RuntimeSystemPhysics* vehicleSystem;
    Handle<game::IBlackboard> blackboard;
    Handle<void> blackboard2;
    Handle<void> controllerMaybe;
    uint64_t unk540;
    Handle<game::Puppet> drivingPuppet;
    Handle<game::Puppet> mountedPuppet;
    void*unk568;
    void* unk570;
    AirControl* airControl; // 578
    void* unk580;
    void* unk588;
    void* unk590;
    void* destructionParams;
    void* unk5A0;
    void* unk5A8;
    float turnX;
    float turnXRelated2;
    float turnXRelated;
    float deltaTurnX;
    Handle<game::OccupantSlotComponent> occupantSlotComponent;
    uint64_t unkTweakRecord;
    Handle<game::data::Vehicle_Record> vehicleRecord;
    float unk5E8;
    float unk5EC;
    float unk5F0;
    float unk5F4;
    float unk5F8;
    uint8_t unk5FC;
    uint8_t unk5FD;
    uint8_t unk5FE;
    uint8_t unk5FF;
    float unk600;
    float unk604;
    float unk608;
    float unk60C;
    uint8_t important;
    uint8_t ignoreImpulses;
    uint8_t unk612;
    uint8_t unk613;
    uint32_t unk614;
    DynArray<void*> uiComponents;
    Matrix unk628;
    Matrix unk668;
    float unk6A8[18];
    uint64_t unk6F0[2];
    uint32_t unk700[4];
    uint64_t unk710[10];
    void* unk760;
    uint64_t unk768[4];
    uint32_t unk788[2];
    uint64_t unk790;
    uint64_t unk798;
    uint64_t unk7A0;
    uint64_t unk7A8;
    uint64_t targetToReach;
    uint64_t unk7B8;
    uint64_t targetToFollow;
    uint64_t unk7C8;
    uint64_t splineToFollow;
    uint64_t splineBackwardToFollow;
    uint64_t unk7E0;
    void* unk7E8;
    uint64_t unk7F0[3];
    Box bounds;
    Handle<void> unk828;
    Vector4 unk838;
    uint8_t unk848;
    uint8_t unk849;
    uint8_t unk84A;
    uint8_t unk84B;
    float unk84C;
    float unk850;
    uint32_t unk854[14];
    uint32_t unk88C;
    uint32_t unk890[2];
    Handle<void> vehicleAudio;
    uint64_t unk8A8;
    uint8_t hasDestructionParams;
    uint8_t unk8B1;
    uint8_t unk8B2;
    uint8_t unk8B3;
    float unk8B4[5];
    DynArray<void*> unk8C8;
    uint64_t unk8D8[2];
    Vector3 unk8E8;
    float unk8F4;
    DynArray<Handle<ent::Entity>> projectiles;
    uint8_t updatingProjectiles;
    uint8_t unk909;
    uint8_t unk90A;
    uint8_t unk90B;
    float unk90C;
    uint32_t unk910[8];
    uint8_t meleeHonkDelay[3];
    uint8_t meleeHonkDuration[3];
    uint8_t collisionHonkDelay[3];
    uint8_t collisionHonkDuration[3];
    uint8_t collisionHonkUpperThreshold[3];
    uint8_t unk93F;
    DynArray<Weapon> weapons;
    Vector3 tracePosition;
    uint8_t unk95C;
    uint8_t unk95D;
    uint8_t unk95E;
    uint8_t unk95F;
    uint64_t unk960;
    DynArray<void*> puppets;
    uint64_t unk978;
};
#pragma pack(pop)
RED4EXT_ASSERT_SIZE(BaseObject, 0x980);
RED4EXT_ASSERT_OFFSET(BaseObject, weapons, 0x940);
//char (*__kaboom)[sizeof(BaseObject)] = 1;
//char (*__kaboom2)[offsetof(BaseObject, unk7E0)] = 1;
} // namespace vehicle
using VehicleObject = vehicle::BaseObject;
} // namespace RED4ext
