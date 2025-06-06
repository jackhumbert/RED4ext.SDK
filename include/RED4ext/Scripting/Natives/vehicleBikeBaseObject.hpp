#pragma once

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/vehicle/WheeledBaseObject.hpp>

namespace RED4ext
{
namespace vehicle { 
struct BikeBaseObject : vehicle::WheeledBaseObject
{
    static constexpr const char* NAME = "vehicleBikeBaseObject";
    static constexpr const char* ALIAS = "BikeObject";
    static constexpr const uintptr_t VFT = vehicleBikeBaseObject_VFT_Addr;

    // 1.52 RVA: 0x1C66270 / 29778544
    /// @pattern 48 89 5C 24 10 57 48 83 EC 20 FE 42 62 4C 8D 15 EC 04 1D 02 33 C0 C6 44 24 30 01 48 89 42 30 48
    bool __fastcall EnableTiltControl(CStackFrame* a2);

};
} // namespace vehicle
using BikeObject = vehicle::BikeBaseObject;
} // namespace RED4ext
