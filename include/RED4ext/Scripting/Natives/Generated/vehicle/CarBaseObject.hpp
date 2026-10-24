#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/vehicle/WheeledBaseObject.hpp>
#include <RED4ext/Scripting/Natives/vehiclePID.hpp>

#include <RED4ext/Scripting/Natives/vehicleCarBaseObject.hpp>

namespace RED4ext
{
// 2.5: upstream #232 has CarBaseObject at 0xC60. Our layout lives in the hand-written
// vehicle*.hpp headers and is still the 2.31 one, pending re-verification on 2.5.
namespace vehicle {
// struct __declspec(align(0x10)) CarBaseObject : vehicle::WheeledBaseObject
// {
//     static constexpr const char* NAME = "vehicleCarBaseObject";
//     static constexpr const char* ALIAS = "CarObject";
    // uint8_t unkBE0[0xC40 - 0xBF0]; // BF0
// };
RED4EXT_ASSERT_SIZE(CarBaseObject, 0xC40);
} // namespace vehicle
using vehicleCarBaseObject = vehicle::CarBaseObject;
using CarObject = vehicle::CarBaseObject;
} // namespace RED4ext

// clang-format on
