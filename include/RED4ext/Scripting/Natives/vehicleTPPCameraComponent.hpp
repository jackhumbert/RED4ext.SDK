#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/RED4ext.hpp>
#include <RED4ext/Common.hpp>
#include <RED4ext/Handle.hpp>
#include <RED4ext/Scripting/Natives/Generated/Vector3.hpp>
#include <RED4ext/Scripting/Natives/Generated/Quaternion.hpp>
#include <RED4ext/Scripting/Natives/Generated/WorldTransform.hpp>
// #include <RED4ext/Scripting/Natives/Generated/vehicle/BaseObject.hpp>
#include <RED4ext/Scripting/Natives/Generated/vehicle/ChassisComponent.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/CameraComponent.hpp>

namespace RED4ext::vehicle {

struct BaseObject;
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

struct HeadLookAtStruct
{
  float maxYaw;
  float maxX;
  float centerYawThresholdX;
  float pitchUpY;
  float pitchDownY;
  float rotationSpeed;
};

struct TPPCameraSmoothFloat
{
  float currentValue;
  float targetValue;
  float timeToChange;
  float deltaValue;
};

struct TPPCameraSmoothQuaternion
{
  Quaternion currentValue;
  Quaternion targetValue;
  float timeToChange;
  float unk[3];
  Quaternion deltaValue;
};

struct TPPCameraUpdate
{
  TPPCameraPreset *preset;
  // also some sort of time delta
  float anotherDeltaTime;
  float deltaTime;
  Transform transform;
  Vector4 locationFromOffset;
};

struct __declspec(align(0x10)) TPPCameraComponent : public game::CameraComponent
{
    static constexpr const char* NAME = "vehicleTPPCameraComponent";
    static constexpr const char* ALIAS = NAME;
    static constexpr const uint32_t VFT = 1345328297;

    struct CameraPreset
    {
        RED4ext::Vector4 linearVelocity;
        RED4ext::Quaternion orientation;
        float yawDelta;
        float pitchDelta;
        uint8_t isUsingMouse;
        uint8_t unk29;
        uint8_t unk2A;
        uint8_t unk2B;
        float unk2C;
        uint8_t isInAir;
        uint8_t unk31[7];
        float unk38;
        float unk3C;
        RED4ext::Vector4 angularVelocity;
        float affectsPitch;
        uint8_t unk54;
        uint8_t unk55;
        uint8_t unk56;
        uint8_t unk57;
        void *cameraSystem;
    };

// virtual overrides

    void TargetedCameraInterface_CopyParameters(void *);
    Vector3* TargetedCameraInterface_GetInitialPosition(Vector3 *);
    Quaternion* TargetedCameraInterface_GetInitialOrientation(Quaternion*);

    // updates preset1 & preset2
    // does autoCentering math
    // updates yaw, pitch
    // calls UpdateSmoothValues
    // airFlowDistortion math
    // calls UpdatePosition
    // calls Update
    // 1.6 RVA: 0x1CF4250 / 30360144
    /// @pattern 48 89 5C 24 20 55 56 57 48 8D 6C 24 F0 48 81 EC 10 01 00 00 44 0F 29 94 24 C0 00 00 00 48 8B F2
    void __fastcall TargetedCameraInterface_Update(float *a2);

    const char* TargetedCameraInterface_GetTypeName();
    
    // calls GetLocationFromOffset at the beginning, Update at the end
    // 1.6 RVA: 0x1CF2410 / 30352400
    /// @pattern 48 8B C4 48 89 70 18 48 89 78 20 55 48 8D 68 A8 48 81 EC 50 01 00 00 0F 29 78 D8 48 8B F9 0F 57
    void TargetedCameraInterface_sub_58();

// new virtuals

    virtual bool sub_320(HeadLookAtStruct *a2);
    virtual bool sub_328();

// methods

    // 1.6 RVA: 0x1CF3C10 / 30358544
    /// @pattern F3 0F 10 42 04 8B 02 F3 0F 10 4A 08 F3 0F 11 81 B4 02 00 00 F3 0F 11 89 B8 02 00 00 89 81 B0 02
    __int64 __fastcall UpdateData(void * a2);

    // 1.6  RVA: 0x1CF47B0 / 30361520
    // 1.61hf1 RVA: 0x1CF5270 / 30364272
    /// @pattern 40 53 48 81 EC 90 00 00 00 F3 0F 10 15 ? ? 3E 01 0F 57 C0 F3 0F 2A 81 20 03 00 00 48 8B D9 F3
    void __fastcall UpdateTPP();

    // 1.52 RVA: 0x1CC4600 / 30164480
    // 1.6  RVA: 0x1CF0CB0 / 30346416
    // 1.61hf1 RVA: 0x1CF1770 / 30349168
    /// @pattern 48 8B C4 48 89 58 18 48 89 78 20 55 48 8D 68 D8 48 81 EC 20 01 00 00 0F 28 05 ? ? ? 01 0F 57
    Vector4 *__fastcall GetLocationFromOffset(Vector4 *location, Vector3 *lookAtOffset);

    // updates airFlowDistortionSpeed, currentSpeed, drivingDirectionSmooth, angularVelocitySmooth, isInAir, currentBoomLength
    // 1.6 RVA: 0x1CF54E0 / 30364896
    /// @pattern 48 89 5C 24 08 57 48 81 EC 80 00 00 00 F3 0F 10 05 AB 69 3E 01 0F 57 E4 F3 0F 2A A1 24 03 00 00
    // __int64 __fastcall UpdateSmoothValues(TPPCameraUpdate *update);

    // called before Update
    // uses preset to update pitch, unk480
    // updates unkWorldPosition470
    // updates boomLength
    // updates initialTransform
    // calls UpdatePitch(v4, unk340, update)
    // 1.6 RVA: 0x1CF4970 / 30361968
    /// @pattern 48 8B C4 48 89 58 18 48 89 70 20 55 57 41 56 48 8D 68 C8 48 81 EC 20 01 00 00 0F B6 B9 8A 04 00
    void __fastcall UpdatePosition(TPPCameraUpdate *update);

    // updates cameraDirection
    // updates cameraPitch from slopeAdjustment
    // 1.6  RVA: 0x1CF5DB0 / 30367152
    // 1.61hf1 RVA: 0x1CF6870 / 30369904
    /// @pattern 48 8B C4 48 89 58 08 57 48 81 EC 90 00 00 00 F3 0F 10 05 ?  ?  ?  01 0F 57 ED 0F 29 70 E8 49 8B
    void __fastcall UpdatePitch(Vector4 *localPosition, Vector3 *cameraPosition, TPPCameraUpdate *update);

    // uses driving direction variables, a3 is unkTransform340 & update->locationFromOffset, and X from unkWorldPosition470
    // 1.6 RVA: 0x1CF57B0 / 30365616
    /// @pattern 48 8B C4 F3 0F 11 58 20 53 56 57 48 81 EC 10 01 00 00 F3 0F 10 81 D8 04 00 00 49 8B F8 F3 0F 10
    void __fastcall GetYaw(float *yaw, Vector4 *a3, float isInAir);

    Handle<BaseObject> vehicle;
    CameraPreset data;
    void* runtimePhysicsSystem;
    uint64_t unk318;
    // position set in Target::sub_58, orientation set in Update()
    WorldTransform initialTransform;
    // position set in Target::sub_58
    WorldTransform unkWorldTransform340;
    WorldPosition unkWorldPosition360;
    Handle<ChassisComponent> chassis;
    float pitch;
    float yaw;
    TPPCameraSmoothFloat currentSpeed;
    TPPCameraSmoothFloat airFlowDistortionSpeed;
    TPPCameraSmoothFloat currentBoomLength;
    uint32_t unk3B8;
    uint32_t unk3BC;
    TPPCameraSmoothQuaternion angularVelocitySmooth;
    TPPCameraSmoothQuaternion drivingDirectionSmooth;
    TPPCameraSmoothFloat isInAir;
    float autoCenterTimer;
    float boomLength;
    float cameraPitch;
    Vector3 cameraDirection;
    float slopeCorretionInAirLastValue;
    float currentAirFlowDistortionSpeed;
    // result of some calc, only keeps Z comp of part of another transform
    // X is unaffected if cameraLocked
    WorldPosition unkWorldPosition470;
    // when 0.0, unkTransform340 is updated directly from initialTransform, yaw = 0.0 - some sort of time value to ease
    // how much cam should be centered - min of 1.0 if timer threshold exceeded
    float centeringDelta;
    uint8_t collisionDetection;
    uint8_t elasticBoomVelocity;
    uint8_t elasticBoomAcceleration;
    uint8_t drivingDirectionCompensation;
    uint8_t slopeAdjustement;
    uint8_t airFlowDistortion;
    bool lockedCamera;
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
    float airFlowDistortionAmplitude;
    TPPCameraSmoothFloat airFlowDistortionXSmooth;
    TPPCameraSmoothFloat airFlowDistortionYSmooth;
    float unk5B4;
    float airFlowDistortionX;
    float airFlowDistortionY;
    uint8_t unk640[0x680 - 0x640]; // 640
};
RED4EXT_ASSERT_SIZE(TPPCameraComponent, 0x680);
// RED4EXT_ASSERT_OFFSET(TPPCameraComponent, data.isInAir, 0x2E0);
//char (*__kaboom)[sizeof(TPPCameraComponent)] = 1;
using vehicleTPPCameraComponent = vehicle::TPPCameraComponent;
//char (*__kaboom)[offsetof(TPPCameraComponent, isInAir)] = 1;
} // namespace RED4ext

// clang-format on
