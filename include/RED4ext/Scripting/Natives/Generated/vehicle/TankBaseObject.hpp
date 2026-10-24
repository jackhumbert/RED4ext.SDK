#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/vehicle/BaseObject.hpp>

namespace RED4ext
{
namespace vehicle
{
struct __declspec(align(0x10)) TankBaseObject : vehicle::BaseObject
{
    static constexpr const char* NAME = "vehicleTankBaseObject";
    static constexpr const char* ALIAS = "TankObject";

    uint8_t unkBA0[0xC00 - 0xBA0]; // BA0
};
// 2.5: upstream #232 has TankBaseObject at 0xC20. Kept at the 2.31 size until the vehicle
// layout in vehicleBaseObject.hpp is re-verified on 2.5.
RED4EXT_ASSERT_SIZE(TankBaseObject, 0xC00);
} // namespace vehicle
using vehicleTankBaseObject = vehicle::TankBaseObject;
using TankObject = vehicle::TankBaseObject;
} // namespace RED4ext

// clang-format on
