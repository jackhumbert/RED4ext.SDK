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

    // 1.6  RVA: 0x1D5A770 / 30779248
    /// @pattern 48 8B C4 48 81 EC B8 00 00 00 F3 0F 10 81 94 00 00 00 F3 0F 59 05 E6 0B 38 01 48 89 58 10 48 8B
    void __fastcall ReferencePoseSetup();

    
    RED4ext::Vector4 referencePose1 = Vector4(INFINITY, INFINITY, INFINITY, INFINITY);
    RED4ext::Vector4 referencePose2 = Vector4(INFINITY, INFINITY, INFINITY, INFINITY);
    float invBoneDistance = INFINITY;
    float unk24 = INFINITY;
    float unk28 = INFINITY;
    float unk2C = INFINITY;
    int32_t unk30 = -1;
    RED4ext::Vector3 unk34;
    RED4ext::Quaternion unk40;
    void *physx3Thing1;
    uint64_t unk58;
    float boneDistance = 0;
    float actualTotalVerticalDistance;
    float actualVisualSuspensionDroop = 0;
    float tireRadius = -INFINITY;
    float rimRadius;
    float tireWidth;
    float wheelOffset;
    float tireLateralSlipEffectMul;
    float tireRollingResistanceCoef;
    float springReboundDampingLowRate;
    float springBoundDampingLowRate;
    float tireLongitudinalSlipEffectMul;
    float tireFrictionCoef;
    float frictionMulLongitudinal = -INFINITY;
    float tireGrip = -INFINITY;
    float invTireGrip = -INFINITY;
    float maxBrakingTorque;
    float extremeCompressionEventScalor;
    float springDamping;
    float frictionMulLateral;
    float springDampingLowRateCompression;
    float springReboundDamping;
    float stringStiffness;
    float swaybarStiffness;
    float springDampingHighRateCompression;
    float mass = 0.1;
    float swaybarLengthScalar = 0.3;
    float swaybarDisplacementLimit = 0.6;
    float visualSuspensionDroop;
    float logicalSuspensionCompressionLength;
    float visualSuspensionCompressionLength;
    float wheelsVerticalOffset;
    uint8_t isDrive;
    uint8_t isMainBrake;
    uint8_t isHandBrake;
    uint8_t unkE3[5];
    void *parent3;
    RED4ext::Handle<void> vehicleWheelDimensionsPreset;
    RED4ext::Handle<void> vehicleWheelDrivingPreset;
    RED4ext::Handle<void> vehicleWheelRolePreset;
    RED4ext::CName boneName1;
    RED4ext::CName boneName2;
};
RED4EXT_ASSERT_SIZE(VehiclePhysicsInsert1, 0x130);
} // namespace physics
} // namespace RED4ext
