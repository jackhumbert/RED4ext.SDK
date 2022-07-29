#pragma once

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/data/SpawnableObject_Record.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/data/VehicleDriveModelData_Record.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/data/VehicleCameraManager_Record.hpp>

namespace RED4ext
{
namespace game::data {
struct Vehicle_Record : game::data::SpawnableObject_Record
{
    static constexpr const char* NAME = "gamedataVehicle_Record";
    static constexpr const char* ALIAS = "Vehicle_Record";
    static constexpr const uintptr_t VFT_RVA = 0x31DB408;

    /// @pattern 48 89 5C 24 10 57 48 83 EC 40 0F B7 81 93 00 00 00 4C 8B C9 4C 8B 05 3D 9F 65 03 48 8B DA 0F B6
    Handle<VehicleDriveModelData_Record> * __fastcall GetVehDriveModelDataAIHandle(Handle<VehicleDriveModelData_Record> *);

    /// @pattern 48 89 5C 24 10 57 48 83 EC 40 0F B7 81 D8 00 00 00 4C 8B C9 4C 8B 05 3D 9E 65 03 48 8B DA 0F B6
    Handle<VehicleDriveModelData_Record> * __fastcall GetVehDriveModelDataHandle(Handle<VehicleDriveModelData_Record> *);

    // 1.52 RVA: 0xC0E9C0 / 12642752
    /// @pattern 40 55 53 57 48 8B EC 48 83 EC 60 0F B7 81 E1 00 00 00 48 8B FA 44 0F B6 89 E3 00 00 00 48 8B D1
    Handle<VehicleCameraManager_Record> * __fastcall GetVehicleCameraManagerHandle(Handle<VehicleCameraManager_Record> *);

    uint8_t traffic_audio_resource[3];
    uint8_t player_audio_resource[3];
    uint8_t vehPassL_ProceduralFPPCameraParams[3];
    uint8_t driving[3];
    uint8_t type[3];
    uint8_t drivingParamsGeneric[3];
    uint8_t tppCameraParams[3];
    uint8_t vehDriver_ProceduralFPPCameraParams[3];
    uint8_t fxCollision[3];
    uint8_t vehDriveModelDataAI[3];
    uint8_t vehAirControlAI[3];
    uint8_t vehPassR_ProceduralFFPCameraParams[3];
    uint8_t vehPassCombatR_FPPCameraParams[3];
    uint8_t vehDriver_FPPCameraParams[3];
    uint8_t vehPassCombatL_FPPCameraParams[3];
    uint8_t manufacturer[3];
    uint8_t destruction[3];
    uint8_t vehEngineData[3];
    uint8_t vehDataPackage[3];
    uint8_t vehDriverCombat_ProceduralFPPCameraParams[3];
    uint8_t vehDefaultState[3];
    uint8_t drivingParamsPanic[3];
    uint8_t fxWheelsParticles[3];
    uint8_t vehPassR_FPPCameraParams[3];
    uint8_t vehAirControl[3];
    uint8_t crowdMemberSettings[3];
    uint8_t vehDriverCombat_FPPCameraParams[3];
    uint8_t vehPassCombatL_ProceduralFPPCameraParams[3];
    uint8_t vehBehaviorData[3];
    uint8_t vehWheelDimensionsSetup[3];
    uint8_t fxWheelsDecals[3];
    uint8_t affiliation[3];
    uint8_t vehDriveModelData[3];
    uint8_t vehPassL_FPPCameraParams[3];
    uint8_t icon[3];
    uint8_t cameraManagerParams[3];
    uint8_t vehPassCombatR_ProceduralFPPCameraParams[3];
    uint8_t model[3];
    uint8_t visualDestruction[3];
    uint8_t drivingParamsRace[3];
    uint8_t vehicleUIData[3];
    uint8_t vehImpactTraffic[3];
    uint8_t trafficSuspension[3];
    uint8_t interiorDamageColor[3];
    uint8_t leftBlinkerlightColor[3];
    uint8_t preventionPassengers[3];
    uint8_t headlightColor[3];
    uint8_t reverselightColor[3];
    uint8_t rightBLinkerlightColor[3];
    uint8_t interiorColor[3];
    uint8_t attachmentSlots[3];
    uint8_t brakelightColor[3];
    uint8_t tppCameraPresets[3];
    uint8_t weapons[3];
    uint8_t randomPassengers[3];
    uint8_t queryOnlyExceptions[3];
    uint8_t displayName[3];
    uint8_t widgetStyleSheetPath[3];
    uint8_t archetypeName[3];
    uint8_t audioResourceName[3];
    uint8_t destroyedAppearance[3];
    uint8_t curvesPath[3];
    uint8_t unmountOffsetPosition[3];
    uint8_t rightFrontCamberOffset[3];
    uint8_t leftFrontCamberOffset[3];
    uint8_t rightBackCamberOffset[3];
    uint8_t leftBackCamberOffset[3];
    uint8_t rightFrontCamber[3];
    uint8_t leftFrontCamber[3];
    uint8_t rightBackCamber[3];
    uint8_t leftBackCamber[3];
    uint8_t enableDestruction[3];
};
RED4EXT_ASSERT_SIZE(Vehicle_Record, 0x150);
} // namespace game::data
using Vehicle_Record = game::data::Vehicle_Record;
} // namespace RED4ext
