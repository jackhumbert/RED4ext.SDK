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
struct __declspec(align(0x10)) AVBaseObject : vehicle::BaseObject
{
    static constexpr const char* NAME = "vehicleAVBaseObject";
    static constexpr const char* ALIAS = "AVObject";

};
// 2.5: upstream #232 has AVBaseObject at 0xBC0. Kept at the 2.31 size until the vehicle
// layout in vehicleBaseObject.hpp is re-verified on 2.5.
RED4EXT_ASSERT_SIZE(AVBaseObject, 0xBA0);
} // namespace vehicle
using vehicleAVBaseObject = vehicle::AVBaseObject;
using AVObject = vehicle::AVBaseObject;
} // namespace RED4ext

// clang-format on
