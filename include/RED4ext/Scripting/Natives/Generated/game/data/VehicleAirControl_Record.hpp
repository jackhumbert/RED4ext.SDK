#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/data/TweakDBRecord.hpp>

namespace RED4ext
{
namespace game::data
{
struct VehicleAirControl_Record : game::data::TweakDBRecord
{
    static constexpr const char* NAME = "gamedataVehicleAirControl_Record";
    static constexpr const char* ALIAS = "VehicleAirControl_Record";
    
    uint8_t yaw[3]; // 48
    uint8_t pitch[3];
    uint8_t roll[3];
    uint8_t velocityPID[3];
    uint8_t anglePID[3];
    uint8_t flippedOverRecoveryPID[3];
    uint8_t massReference[3];
    uint8_t unk[3][64/3];
};
RED4EXT_ASSERT_SIZE(VehicleAirControl_Record, 0xA0);
} // namespace game::data
using gamedataVehicleAirControl_Record = game::data::VehicleAirControl_Record;
using VehicleAirControl_Record = game::data::VehicleAirControl_Record;
} // namespace RED4ext

// clang-format on
