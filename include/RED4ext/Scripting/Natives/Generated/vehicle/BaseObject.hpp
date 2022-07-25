#pragma once

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/NativeTypes.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/Object.hpp>
#include <RED4ext/Scripting/Natives/Generated/WorldTransform.hpp>
#include <RED4ext/Scripting/Natives/Generated/physics/VehiclePhysics.hpp>
#include <RED4ext/Scripting/Natives/Generated/physics/VehiclePhysicsStruct.hpp>
#include <RED4ext/Scripting/Natives/Generated/physics/VehicleBaseObjectAirControl.hpp>
#include <RED4ext/Scripting/Natives/Generated/vehicle/ChassisComponent.hpp>

namespace RED4ext
{
namespace AI { struct Archetype; }
namespace world
{
struct RuntimeSystemPhysics;
}
namespace physics
{
struct VehiclePhysics;
struct VehiclePhysicsStruct;
struct VehicleBaseObjectAirControl;
} // namespace physics
namespace ent
{
struct Entity;
}
namespace vehicle
{
struct Weapon;
#pragma pack(push, 1)
struct BaseObject : game::Object
{
    static constexpr const char* NAME = "vehicleBaseObject";
    static constexpr const char* ALIAS = "VehicleObject";

// overridden member functions

    virtual CString* __fastcall sub_1C0(CString*) override;

    // Looks at unk580, sub_1D0
    virtual RED4ext::CName* __fastcall GetAudioResourceName(RED4ext::CName*) override;

    // Somethign with unk388 & vehicle controller, sub_1F8
    virtual uint64_t __fastcall OnTakeControl(uintptr_t) override; 

    // Also sends out some red event
    virtual uint64_t __fastcall sub_218(WorldTransform*) override;

// new member functions

    // Loads some vehicle tweaks and sets things up
    virtual void __fastcall sub_268();

    // Loads more tweaks and vehicle weapons
    virtual void __fastcall sub_270();

    // Returns 0.0
    virtual double __fastcall sub_278();

    // Updates physics World Transform, creates physicsStruct, engine data
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

    // Empty function
    virtual void __fastcall sub_2D0();

    // Empty function
    virtual void __fastcall sub_2D8();

    // Something with the entity stored separately flag
    virtual uint64_t __fastcall sub_2E0();


    //virtual void __fastcall VehicleWheelRuntimeStuff();
    //virtual void __fastcall Return1();
    //virtual void __fastcall VehicleUpdateSomePositionsStuff();
    //virtual void __fastcall GetVehicleRecord();
    //virtual void __fastcall GetVehicleUnkTweakRecord();
    //virtual void __fastcall MountVehicleStartMaybe();
    //virtual void __fastcall ReturnZero();
    //virtual void __fastcall EmptyFunctionWithUnk568();
    //virtual void __fastcall ReleaseHandle();
    //virtual void __fastcall ReleaseHandle();
    //virtual void __fastcall ReleaseHandle();
    //virtual void __fastcall ReleaseHandle();
    //virtual void __fastcall Return1();
    //virtual void __fastcall EmptyFunction();
    //virtual void __fastcall EmptyFunction();
    //virtual void __fastcall j_VehicleProcessWeapons();
    //virtual void __fastcall VehicleFireWeapon();
    //virtual void __fastcall EmptyFunction();
    //virtual void __fastcall GetTracePosition();
    //virtual void __fastcall GetShootValueForIndexBasic();

    struct Interface : game::Object::Interface
    {
        virtual uint64_t __fastcall Destruct(char a1) override; // 00

        // Returns 0
        virtual uint64_t __fastcall sub_08() override;
    };

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
    physics::VehiclePhysics* physics;             // 2B0
    physics::VehiclePhysicsStruct* physicsStruct; // 2B8
    Handle<void> curveSetData;
    Handle<void> chassis;
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
    float unk368;
    uint32_t unk36C;
    DynArray<void*> archetype;
    uint64_t unk380;
    void* someAction;
    DynArray<void*> unk390;
    DynArray<void*> unk3A0;
    void* unk3B0;
    DynArray<void*> unk3B8;
    DynArray<void*> unk3C8;
    void* unk3D8;
    DynArray<void*> unk3E0;
    void* unk3F0[17];
    Handle<void> baseDrivingParams[4];
    void* unk388[4];
    Handle<void> vehicleController;
    Handle<void> wheelRuntimePSData;
    Handle<void> cameraManager;
    world::RuntimeSystemPhysics* vehicleSystem;
    Handle<void> blackboard;
    Handle<void> blackboard2;
    Handle<void> controllerMaybe;
    uint64_t unk540;
    Handle<void> drivingPuppet;
    Handle<void> mountedPuppet;
    void*unk568;
    void* unk570;
    physics::VehicleBaseObjectAirControl* airControl; // 578
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
    Handle<void> slotComponent;
    uint64_t unkTweakRecord;
    Handle<void> vehicleRecord;
    float unk5E8;
    float unk5EC;
    float unk5F0;
    float unk5F4[7];
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
    uint64_t unk790[11];
    void* unk7E8;
    uint64_t unk7F0[3];
    Box bounds;
    Vector4 unk828;
    Vector4 unk838;
    uint32_t unk848[17];
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
//char (*__kaboom)[offsetof(BaseObject, weapons)] = 1;
} // namespace vehicle
using VehicleObject = vehicle::BaseObject;
} // namespace RED4ext
