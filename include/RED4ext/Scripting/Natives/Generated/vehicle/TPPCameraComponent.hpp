#pragma once

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/RED4ext.hpp>
#include <RED4ext/Common.hpp>
#include <RED4ext/Handle.hpp>
#include <RED4ext/Scripting/Natives/Generated/Vector3.hpp>
#include <RED4ext/Scripting/Natives/Generated/WorldTransform.hpp>
#include <RED4ext/Scripting/Natives/Generated/vehicle/BaseObject.hpp>
#include <RED4ext/Scripting/Natives/Generated/vehicle/ChassisComponent.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/CameraComponent.hpp>

namespace RED4ext
{
namespace vehicle {

struct TPPCameraPreset
{
    Vector3 lookAtOffset;
    float defaultRotationPitch;
    float boomLength;
    float airFlowDistortionSpeedMin;
    float airFlowDistortionSpeedMax;
    float airFlowDistortionHorizontal;
    float airFlowDistortionVertical;
    uint32_t distance;
    int32_t index;
};

struct TPPCameraComponent : game::CameraComponent
{
    static constexpr const char* NAME = "vehicleTPPCameraComponent";
    static constexpr const char* ALIAS = "vehicleTPPCameraComponent";

    Handle<BaseObject> vehicle;
    WorldTransform unkWorldTransform;
    float yawDelta;
    float pitchDelta;
    uint8_t isUsingMouse;
    uint8_t unk2E1;
    uint8_t unk2E2;
    uint8_t unk2E3;
    float unk2E4;
    uint8_t isInAir;
    uint8_t unk2E9[7];
    float unk2F0;
    float unk2F4;
    Vector4 unk2F8;
    uint32_t unk300;
    uint8_t unk304;
    uint8_t unk305;
    uint8_t unk306;
    uint8_t unk307;
    float unk308;
    float unk30C;
    void* runtimePhysicsSystem;
    uint64_t unk318;
    WorldTransform unkWorldTransform320;
    WorldTransform unkWorldTransform340;
    WorldPosition unkWorldPosition360;
    Handle<ChassisComponent> chassis;
    float pitch;
    float yaw;
    float currentSpeed;
    Vector3 unkPID38C;
    float airFlowDistortionSpeed;
    Vector3 unkPID39C;
    float currentBoomLength;
    float unk3AC;
    float unk3B0;
    float unk3B4;
    uint32_t unk3B8;
    uint32_t unk3BC;
    Quaternion q1;
    Vector3 unkPID2;
    Vector3 unkPID3;
    float unk3E8;
    float unk3EC;
    Quaternion q4;
    Quaternion q5;
    float unk410;
    float unk414;
    float unk418;
    Vector3 PID2;
    uint64_t unk428;
    Quaternion q7;
    float unk440;
    Vector3 PID3;
    float autoCenterTimer;
    float boomLength;
    float cameraPitch;
    Vector3 otherPosition;
    float slopeCorretionInAirLastValue;
    float unk46C;
    float unk470;
    float unk474;
    float unk478;
    float unk47C;
    float unk480;
    uint8_t collisionDetection;
    uint8_t elasticBoomVelocity;
    uint8_t elasticBoomAcceleration;
    uint8_t drivingDirectionCompensation;
    uint8_t slopeAdjustement;
    uint8_t airFlowDistortion;
    uint8_t lockedCamera;
    uint8_t unk48B;
    float fov;
    float autoCenterStartTimeGamepad;
    float autoCenterStartTimeMouse;
    float autoCenterMaxSpeedThreshold;
    float autoCenterSpeed;
    float cameraMinPitch;
    float cameraMaxPitch;
    float cameraSphereRadius;
    float cameraBoomExtensionSpeed;
    float slopeCorrectionOnGroundStrength;
    float slopeCorrectionOnGroundPitchMin;
    float slopeCorrectionOnGroundPitchMax;
    float slopeCorrectionInAirPitchMin;
    float slopeCorrectionInAirPitchMax;
    float slopeCorrectionInAirSpeedMax;
    float slopeCorrectionInAirStrength;
    float slopeCorrectionInAirFallCoef;
    float slopeCorrectionInAirRaiseCoef;
    float slopeCorrectionInAirDampFactor;
    float drivingDirectionCompensationSpeedMin;
    float drivingDirectionCompensationSpeedMax;
    float drivingDirectionCompensationSpeedCoef;
    float drivingDirectionCompensationAngle;
    float drivingDirectionCompensationAngleSmooth;
    float drivingDirectionCompensationAngularVelocityMin;
    float elasticBoomForwardAccelerationCoef;
    float elasticBoomAccelerationExpansionLength;
    float elasticBoomSpeedExpansionSpeedMin;
    float elasticBoomSpeedExpansionSpeedMax;
    float elasticBoomSpeedExpansionLength;
    float headLookAtMaxYaw;
    float headLookAtCenterYawThreshold;
    float headLookAtMaxPitchUp;
    float headLookAtMaxPitchDown;
    float headLookAtRotationSpeed;
    DynArray<TPPCameraPreset> cameraPresets;
    uint32_t presetDistance;
    uint32_t presetIndex;
    TPPCameraPreset preset1;
    float timeSinceLastMovement;
    TPPCameraPreset preset2;
    uint32_t presetIndex2;
    float unk590;
    float unk594;
    float unk598;
    float unk59C;
    float unk5A0;
    float unk5A4;
    float unk5A8;
    float unk5AC;
    float unk5B0;
    float unk5B4;
    float airFlowDistortionX;
    float airFlowDistortionY;
};
RED4EXT_ASSERT_SIZE(TPPCameraComponent, 0x5C0);
RED4EXT_ASSERT_OFFSET(TPPCameraComponent, isInAir, 0x2E0);
//char (*__kaboom)[sizeof(TPPCameraComponent)] = 1;
//char (*__kaboom)[offsetof(TPPCameraComponent, isInAir)] = 1;
} // namespace vehicle
} // namespace RED4ext
