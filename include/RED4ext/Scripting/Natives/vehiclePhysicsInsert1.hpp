#pragma once

// This file is generated by Jack

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/Transform.hpp>
#include <RED4ext/Scripting/Natives/Generated/Vector3.hpp>
#include <RED4ext/Scripting/Natives/Generated/FixedPoint.hpp>
#include <RED4ext/Scripting/Natives/Generated/vehicle/BaseObject.hpp>

namespace RED4ext
{
namespace physics { 
struct VehiclePhysicsInsert1
{
    static constexpr const char* NAME = "physicsVehiclePhysicsInsert1";
    static constexpr const char* ALIAS = NAME;

    // 1.6 RVA: 0x1D5A6C0 / 30779072
    /// @pattern 40 53 48 83 EC 30 F3 0F 10 41 08 48 8B D9 F3 0F 5C 81 DC 00 00 00 0F 29 74 24 20 F3 0F 10 71 18
    float __fastcall SinMath(float a2);

    float unk00;
    float unk04;
    float unk08;
    float unk0C;
    RED4ext::Vector4 unk10;
    float unk20;
    float unk24;
    float unk28;
    float unk2C;
    uint32_t unk30;
    RED4ext::Vector3 unk34;
    RED4ext::Quaternion unk40;
    void *physx3Thing1;
    uint64_t unk58;
    float unk60;
    float unk64;
    float unk68;
    float unk6C;
    RED4ext::Quaternion unk70;
    RED4ext::Vector3 unk80;
    float latSlip;
    float longSlip;
    RED4ext::Vector3 unk94;
    RED4ext::Vector4 unkA0;
    float unkB0;
    float unkB4;
    float unkB8;
    float unkBC;
    RED4ext::Vector4 unkC0;
    float unkD0;
    float unkD4;
    float unkD8;
    float unkDC;
    uint64_t unkE0;
    void *parent3;
    RED4ext::Handle<void> vehicleWheelDimensionsPreset;
    RED4ext::Handle<void> vehicleWheelDrivingPreset;
    RED4ext::Handle<void> vehicleWheelRolePreset;
    RED4ext::FixedPoint unk120;
    RED4ext::FixedPoint unk124;
    RED4ext::FixedPoint unk128;
    RED4ext::FixedPoint unk12C;
};
RED4EXT_ASSERT_SIZE(VehiclePhysicsInsert1, 0x130);
} // namespace physics
} // namespace RED4ext
