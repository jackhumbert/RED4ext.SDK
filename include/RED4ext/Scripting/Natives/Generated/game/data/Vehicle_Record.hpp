#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/data/SpawnableObject_Record.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/data/VehicleDriveModelData_Record.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/data/VehicleCameraManager_Record.hpp>
#include <RED4ext/Scripting/Natives/gamedataTweakValue.hpp>

namespace RED4ext
{
namespace game::data {
struct Vehicle_Record : game::data::SpawnableObject_Record
{
    static constexpr const char* NAME = "gamedataVehicle_Record";
    static constexpr const char* ALIAS = "Vehicle_Record";
    static constexpr const uintptr_t VFT = gamedataVehicle_Record_VFT_Addr;

    /// @pattern 48 89 5C 24 10 57 48 83 EC 40 0F B7 81 93 00 00 00 4C 8B C9 4C 8B 05 3D 9F 65 03 48 8B DA 0F B6
    // Handle<VehicleDriveModelData_Record> * __fastcall GetVehDriveModelDataAIHandle(Handle<VehicleDriveModelData_Record> *);

    /// @pattern 48 89 5C 24 10 57 48 83 EC 40 0F B7 81 D8 00 00 00 4C 8B C9 4C 8B 05 3D 9E 65 03 48 8B DA 0F B6
    // Handle<VehicleDriveModelData_Record> * __fastcall GetVehDriveModelDataHandle(Handle<VehicleDriveModelData_Record> *);

    // 1.52 RVA: 0xC0E9C0 / 12642752
    /// @pattern 40 55 53 57 48 8B EC 48 83 EC 60 0F B7 81 E1 00 00 00 48 8B FA 44 0F B6 89 E3 00 00 00 48 8B D1
    // Handle<VehicleCameraManager_Record> * __fastcall GetVehicleCameraManagerHandle(Handle<VehicleCameraManager_Record> *);

    // TweakValue player_audio_resource;
    // TweakValue traffic_audio_resource;
    // TweakValue debugStatusString;
    // TweakValue model;
    // TweakValue vehDefaultState;
    // TweakValue vehAirControlAI;
    // TweakValue tppCameraParams;
    // TweakValue vehPassL_FPPCameraParams;
    // TweakValue vehPassCombatL_ProceduralFPPCameraParams;
    // TweakValue drivingParamsGeneric;
    // TweakValue vehAirControl;
    // TweakValue trafficSuspension;
    // TweakValue vehPassCombatL_FPPCameraParams;
    // TweakValue vehDriveModelData;
    // TweakValue vehDriverCombat_FPPCameraParams;
    // TweakValue drivingParamsRace;
    // TweakValue vehPassL_ProceduralFPPCameraParams;
    // TweakValue vehDriver_ProceduralFPPCameraParams;
    // TweakValue vehPassR_FPPCameraParams;
    // TweakValue vehDriverCombat_ProceduralFPPCameraParams;
    // TweakValue vehEngineData;
    // TweakValue vehImpactTraffic;
    // TweakValue destruction;
    // TweakValue cameraManagerParams;
    // TweakValue visualDestruction;
    // TweakValue driving;
    // TweakValue manufacturer;
    // TweakValue icon;
    // TweakValue vehPassCombatR_FPPCameraParams;
    // TweakValue weaponSafeModeBounds;
    // TweakValue affiliation;
    // TweakValue drivingParamsPanic;
    // TweakValue vehDriver_FPPCameraParams;
    // TweakValue vehDataPackage;
    // TweakValue crowdMemberSettings;
    // TweakValue fxWheelsDecals;
    // TweakValue fxWheelsDecalsFrontOverride;
    // TweakValue type;
    // TweakValue vehBehaviorData;
    // TweakValue vehPassCombatR_ProceduralFPPCameraParams;
    // TweakValue bikeDriveModelData;
    // TweakValue fxWheelsParticles;
    // TweakValue tankDriveModelData;
    // TweakValue isHackable;
    // TweakValue vehPassR_ProceduralFPPCameraParams;
    // TweakValue fxCollision;
    // TweakValue vehDriveModelDataAI;
    // TweakValue vehicleUIData;
    // TweakValue vehWheelDimensionsSetup;
    // TweakValue rightBLinkerlightColor;
    // TweakValue queryOnlyExceptions;
    // TweakValue randomPassengers;
    // TweakValue preventionPassengers;
    // TweakValue headlightColor;
    // TweakValue utilityLightColor;
    // TweakValue brakelightColor;
    // TweakValue tppCameraPresets;
    // TweakValue reverselightColor;
    // TweakValue interiorDamageColor;
    // TweakValue weapons;
    // TweakValue interiorColor;
    // TweakValue leftBlinkerlightColor;
    // TweakValue attachmentSlots;
    // TweakValue displayName;
    // TweakValue audioResourceName;
    // TweakValue curvesPath;
    // TweakValue widgetStyleSheetPath;
    // TweakValue archetypeName;
    // TweakValue destroyedAppearance;
    // TweakValue rightBackCamberOffset;
    // TweakValue leftFrontCamberOffset;
    // TweakValue rightFrontCamberOffset;
    // TweakValue leftBackCamberOffset;
    // TweakValue unmountOffsetPosition;
    // TweakValue rightBackCamber;
    // TweakValue leftFrontCamber;
    // TweakValue leftBackCamber;
    // TweakValue hitCooldown;
    // TweakValue rightFrontCamber;
    // TweakValue maxVehiclePassengersCount;
    // TweakValue minVehiclePassengersCount;
    // TweakValue blockadeLeftPassengerOffset;
    // TweakValue blockadeRightPassengerOffset;
    // TweakValue usesSecondaryHoodEmitter;
    // TweakValue enableDestruction;
    // TweakValue isArmoredVehicle;
    uint8_t unkF8[0x5A0 - 0xF8]; // F8
};
RED4EXT_ASSERT_SIZE(Vehicle_Record, 0x5A0);
} // namespace game::data
using gamedataVehicle_Record = game::data::Vehicle_Record;
using Vehicle_Record = game::data::Vehicle_Record;
} // namespace RED4ext

// clang-format on
