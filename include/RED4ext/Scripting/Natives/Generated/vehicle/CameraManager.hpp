#pragma once

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/IScriptable.hpp>
#include <RED4ext/Scripting/Natives/Generated/Vector4.hpp>
#include <RED4ext/Scripting/Natives/Generated/Vector3.hpp>
#include <RED4ext/Scripting/Natives/Generated/Quaternion.hpp>
#include <RED4ext/Scripting/Natives/Generated/ent/Entity.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/data/Vehicle_Record.hpp>
#include <RED4ext/Scripting/Natives/Generated/vehicle/TPPCameraComponent.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/FPPCameraComponent.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/CameraComponent.hpp>

namespace RED4ext
{
namespace vehicle {

struct TPPCameraComponent;
struct CameraManager : IScriptable
{
    static constexpr const char* NAME = "vehicleCameraManager";
    static constexpr const char* ALIAS = "VehicleCameraManager";

    // 1.52 RVA: 0x1C6C270 / 29803120
    /// @pattern 48 89 5C 24 20 55 56 57 48 8B EC 48 83 EC 60 48 8B F9 48 8B F2 48 8B 49 50 48 85 C9 74 05 E8 6D
    __int64 __fastcall LoadTweaks(Handle<Vehicle_Record>* record);

    void * unk40; 
    float customTarget; 
    float unk4C;
    Handle<TPPCameraComponent> tppCamera; 
    Handle<game::FPPCameraComponent> fppCamera;
    Handle<game::CameraComponent> blendCamera;
    Handle<void> unkHandle80;
    uint32_t activeCameraType; 
    float SensitivityConfig_Base_pad; 
    float SensitivityConfig_Base_mouse; 
    float SensitivityConfig_UserTPP_padX; 
    float SensitivityConfig_UserTPP_padY; 
    float SensitivityConfig_UserTPP_mouseX;
    float SensitivityConfig_UserTPP_mouseY; 
    float SensitivityConfig_UserVehicleFPP_padX;
    float SensitivityConfig_UserVehicleFPP_padY; 
    float SensitivityConfig_UserVehicleFPP_mouseX;
    float SensitivityConfig_UserVehicleFPP_mouseY; 
    float cameraPlaneSettings_CameraCurves_sensitivityDebugEnabled; // BC 
    uint8_t data[96]; // C0,   0x60000400, get_struc_id("RED4ext::vehicle::TPPCameraData"),    96);
    void * photoModeCamera; // 120,  0x35500400, 0XFFFFFFFFFFFFFFFF, 8,  0XFFFFFFFFFFFFFFFF, 0,  0x000009);
    void * unk128; // 128,  0x30000400, -1, 8);
    float unk130; // 130,  0x80000400, -1, 4);
    float unk134; // 134,  0x80000400, -1, 4);
    Handle<BaseObject> vehicle; // 138
    void * unk148; // 148,  0x30000400, -1, 8);
    Vector4 unk150; // 150,  0x60000400, get_struc_id("RED4ext::Vector4"),   16);
    void * unk160; // 160,  0x30000400, -1, 8);
    Vector3 camCollisionOBBIncrease; // 168,  0x60000400, get_struc_id("RED4ext::Vector3"),   12);
    float cameraBlendTime; // 174,  0x80000400, -1, 4);
    uint8_t allowCameraReset; // 178,  0x000400,   -1, 1);
    uint8_t unk179; // 179,  0x000400,   -1, 1);
    uint8_t unk17A; // 17A,  0x000400,   -1, 1);
    uint8_t unk17B; // 17B,  0x000400,   -1, 1);
    uint8_t unk17C; // 17C,  0x000400,   -1, 1);
    uint8_t unk17D; // 17D,  0x000400,   -1, 1);
    uint8_t unk17E; // 17E,  0x000400,   -1, 1);
    uint8_t unk17F; // 17F,  0x000400,   -1, 1);
    float unk180; // 180,  0x80000400, -1, 4);
    float unk184; // 184,  0x80000400, -1, 4);
    float unk188; // 188,  0x80000400, -1, 4);
    float unk18C; // 18C,  0x80000400, -1, 4);
    float unk190; // 190,  0x80000400, -1, 4);
    void * unk198; // 198,  0x30000400, -1, 8);
    Vector3 unk1A0; // 1A0,  0x60000400, get_struc_id("RED4ext::Vector3"),   12);
    Vector3 unk1AC; // 1AC,  0x60000400, get_struc_id("RED4ext::Vector3"),   12);
    void * unk1B8; // 1B8,  0x80000400, -1, 8);
    Quaternion vehicleOrientation; // 1C0,  0x60000400, get_struc_id("RED4ext::Quaternion"),    16);
    Vector4 unk1D0; // 1D0,  0x80000400, -1, 16);
    Vector4 vehiclePosition; // 1E0,  0x60000400, get_struc_id("RED4ext::Vector4"),   16);
    float unk1F0; // 1F0,  0x80000400, -1, 4);
    float unk1F4; // 1F4,  0x80000400, -1, 4);
    float unk1F8; // 1F8,  0x80000400, -1, 4);
    float unk1FC; // 1FC,  0x80000400, -1, 4);
    float unk200; // 200,  0x80000400, -1, 4);
    float unk204; // 204,  0x80000400, -1, 4);
    float unk208; // 208,  0x80000400, -1, 4);
    float unk20C; // 20C,  0x80000400, -1, 4);
    float impactDamperDampFactor2; // 210,  0x80000400, -1, 4);
    float unk214; // 214,  0x80000400, -1, 4);
    float unk218; // 218,  0x80000400, -1, 4);
    float unk21C; // 21C,  0x80000400, -1, 4);
    float unk220; // 220,  0x80000400, -1, 4);
    float unk224; // 224,  0x80000400, -1, 4);
    float unk228; // 228,  0x80000400, -1, 4);
    float unk22C; // 22C,  0x80000400, -1, 4);
    float unk230; // 230,  0x80000400, -1, 4);
    float unk234; // 234,  0x80000400, -1, 4);
    float sideDampFactor2; // 238,  0x80000400, -1, 4);
    float unk23C; // 23C,  0x80000400, -1, 4);
    float unk240; // 240,  0x80000400, -1, 4);
    float unk244; // 244,  0x80000400, -1, 4);
    float forwardDampFactor2; // 248,  0x80000400, -1, 4);
    float unk24C; // 24C,  0x80000400, -1, 4);
    float unk250; // 250,  0x80000400, -1, 4);
    float unk254; // 254,  0x80000400, -1, 4);
    float heightDampFactor2; // 258,  0x80000400, -1, 4);
    float unk25C; // 25C,  0x80000400, -1, 4);
    float unk260; // 260,  0x80000400, -1, 4);
    float unk264; // 264,  0x80000400, -1, 4);
    float rollCorrectionDampFactor2; // 268,  0x80000400, -1, 4);
    float unk26C; // 26C,  0x80000400, -1, 4);
    float unk270; // 270,  0x80000400, -1, 4);
    float unk274; // 274,  0x80000400, -1, 4);
    float pitchCorrectionDampFactor2; // 278,  0x80000400, -1, 4);
    float unk27C; // 27C,  0x80000400, -1, 4);
    float unk280; // 280,  0x80000400, -1, 4);
    float unk284; // 284,  0x80000400, -1, 4);
    float smoothSpeedDampFactor2; // 288,  0x80000400, -1, 4);
    float unk28C; // 28C,  0x80000400, -1, 4);
    float unk290; // 290,  0x80000400, -1, 4);
    float unk294; // 294,  0x80000400, -1, 4);
    float steeringDampFactor2; // 298,  0x80000400, -1, 4);
    float unk29C; // 29C,  0x80000400, -1, 4);
    float unk2A0; // 2A0,  0x80000400, -1, 4);
    float unk2A4; // 2A4,  0x80000400, -1, 4);
    float unk2A8; // 2A8,  0x80000400, -1, 4);
    float unk2AC; // 2AC,  0x80000400, -1, 4);
    float unk2B0; // 2B0,  0x80000400, -1, 4);
    float maxDisplacementLeft; // 2B4,  0x80000400, -1, 4);
    float maxDisplacementRight; // 2B8,  0x80000400, -1, 4);
    float maxDisplacementForward; // 2BC,  0x80000400, -1, 4);
    float maxDisplacementBackward; // 2C0,  0x80000400, -1, 4);
    float maxDisplacementUp; // 2C4,  0x80000400, -1, 4);
    float maxDisplacementDown; // 2C8,  0x80000400, -1, 4);
    float displacementThresholdForward; // 2CC,  0x80000400, -1, 4);
    float sideDampFactor; // 2D0,  0x80000400, -1, 4);
    float forwardDampFactor; // 2D4,  0x80000400, -1, 4);
    float heightDampFactor; // 2D8,  0x80000400, -1, 4);
    float steeringDampFactor; // 2DC,  0x80000400, -1, 4);
    float steeringAngleLeft; // 2E0,  0x80000400, -1, 4);
    float steeringAngleRight; // 2E4,  0x80000400, -1, 4);
    float smoothSpeedDampFactor; // 2E8,  0x80000400, -1, 4);
    float directionFollowMaxVelocity; // 2EC,  0x80000400, -1, 4);
    float maxAccelerationTiltAngle; // 2F0,  0x80000400, -1, 4);
    float maxSlowdownTiltAngle; // 2F4,  0x80000400, -1, 4);
    float impactDamperDampFactor; // 2F8,  0x80000400, -1, 4);
    float impactThreshold; // 2FC,  0x80000400, -1, 4);
    float impactBlendSpeed; // 300,  0x80000400, -1, 4);
    float impactStrengthCoef; // 304,  0x80000400, -1, 4);
    float maxRollCorrection; // 308,  0x80000400, -1, 4);
    float maxPitchCorrectionUP; // 30C,  0x80000400, -1, 4);
    float maxPitchCorrectionDown; // 310,  0x80000400, -1, 4);
    float rollCorrectionDampFactor; // 314,  0x80000400, -1, 4);
    float pitchCorrectionDampFactor; // 318,  0x80000400, -1, 4);
    float unk31C; // 31C,  0x80000400, -1, 4);
    void * unkCallback; // 320,  0x35500400, 0XFFFFFFFFFFFFFFFF, 8,  0XFFFFFFFFFFFFFFFF, 0,  0x000009);
    Handle<ent::Entity> puppet; // 328,  0x60000400, get_struc_id("RED4ext::Handle"),    16);
    Handle<game::FPPCameraComponent> vehicleFFP; // 338,  0x60000400, get_struc_id("RED4ext::Handle"),    16);
    uint8_t isInCombat; // 348,  0x000400,   -1, 1);
    uint8_t unk379[7]; // 349,  0x000400,   -1, 7);
    Handle<void> vehicleBlendCamera; // 350,  0x60000400, get_struc_id("RED4ext::Handle"),    16);
    Handle<void> unkHandle360;       // 360,  0x60000400, get_struc_id("RED4ext::Handle"),    16);
    Handle<void> unkHandle370;       // 370,  0x60000400, get_struc_id("RED4ext::Handle"),    16);
    uint8_t unk380; // 380,  0x000400,   -1, 1);
    uint8_t unk381; // 381,  0x000400,   -1, 1);
    uint8_t unk382; // 382,  0x000400,   -1, 1);
    uint8_t unk383; // 383,  0x000400,   -1, 1);
    uint8_t unk384; // 384,  0x000400,   -1, 1);
    uint8_t unk385; // 385,  0x000400,   -1, 1);
    uint8_t unk386; // 386,  0x000400,   -1, 1);
    uint8_t unk387; // 387,  0x000400,   -1, 1);
    uint64_t unk388;
};
RED4EXT_ASSERT_SIZE(CameraManager, 0x390);
 //char (*__kaboom)[sizeof(CameraManager)] = 1;
} // namespace vehicle
using VehicleCameraManager = vehicle::CameraManager;
} // namespace RED4ext
