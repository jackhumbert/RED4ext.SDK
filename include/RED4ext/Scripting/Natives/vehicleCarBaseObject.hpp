#pragma once

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/vehicle/WheeledBaseObject.hpp>
#include <RED4ext/Scripting/Natives/Generated/vehicle/PID.hpp>

namespace RED4ext
{
namespace vehicle {
struct CarBaseObject : vehicle::WheeledBaseObject
{
    static constexpr const char* NAME = "vehicleCarBaseObject";
    static constexpr const char* ALIAS = "CarObject";

    PID pitchPID;
    PID rollPID;
    float pitchCorrection;
    float rollCorrection;
    uint64_t unk9E8;
};
RED4EXT_ASSERT_SIZE(CarBaseObject, 0x9F0);
} // namespace vehicle
using CarObject = vehicle::CarBaseObject;
} // namespace RED4ext
