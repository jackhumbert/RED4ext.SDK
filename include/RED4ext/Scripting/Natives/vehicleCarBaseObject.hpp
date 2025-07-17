#pragma once

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/vehicle/WheeledBaseObject.hpp>
#include <RED4ext/Scripting/Natives/vehiclePID.hpp>

namespace RED4ext
{
namespace vehicle {
struct CarBaseObject : vehicle::WheeledBaseObject
{
    static constexpr const char* NAME = "vehicleCarBaseObject";
    static constexpr const char* ALIAS = "CarObject";
    static constexpr const uint32_t VFT = 2073038931;

    virtual void sub_148(uintptr_t a1, uintptr_t a2) override;      // checks populationSpawnParameter, sets vehicleREcord
    virtual void sub_270() override;                                // 270 
    virtual uint64_t sub_2A8() override;                            // 2A8

    PID pitchPID;
    PID rollPID;
    float pitchCorrection;
    float rollCorrection;
    uint64_t unk9E8;
};
RED4EXT_ASSERT_SIZE(CarBaseObject, 0xC40);
} // namespace vehicle
using CarObject = vehicle::CarBaseObject;
} // namespace RED4ext
