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
struct VehicleFxWheelsDecals_Record : game::data::TweakDBRecord
{
    static constexpr const char* NAME = "gamedataVehicleFxWheelsDecals_Record";
    static constexpr const char* ALIAS = "VehicleFxWheelsDecals_Record";

    uint8_t materials[3];
    uint8_t wet_material_overrides[3];
    uint8_t rain_material_overrides[3];
    uint8_t smear_materials[3];

    uint8_t unk[32];
};
RED4EXT_ASSERT_SIZE(VehicleFxWheelsDecals_Record, 0x78);
} // namespace game::data
using gamedataVehicleFxWheelsDecals_Record = game::data::VehicleFxWheelsDecals_Record;
using VehicleFxWheelsDecals_Record = game::data::VehicleFxWheelsDecals_Record;
} // namespace RED4ext

// clang-format on
