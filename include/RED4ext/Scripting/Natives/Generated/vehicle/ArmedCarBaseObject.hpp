#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/vehicle/CarBaseObject.hpp>
#include <RED4ext/Scripting/Natives/vehicleArmedCarBaseObject.hpp>

namespace RED4ext
{
namespace vehicle
{
// struct __declspec(align(0x10)) ArmedCarBaseObject : vehicle::CarBaseObject
// {
//     static constexpr const char* NAME = "vehicleArmedCarBaseObject";
//     static constexpr const char* ALIAS = NAME;

// 2.5: upstream #232 has ArmedCarBaseObject at 0xD20. Our layout lives in the hand-written
// vehicle*.hpp headers and is still the 2.31 one, pending re-verification on 2.5.
//     uint8_t unkC30[0xD00 - 0xC40]; // C40
// };
RED4EXT_ASSERT_SIZE(ArmedCarBaseObject, 0xD00);
} // namespace vehicle
using vehicleArmedCarBaseObject = vehicle::ArmedCarBaseObject;
} // namespace RED4ext

// clang-format on
