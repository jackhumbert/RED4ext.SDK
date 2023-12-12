#pragma once

// This file is generated by Jack

#include <RED4ext/Common.hpp>
#include <cstdint>

namespace RED4ext
{
namespace vehicle
{
struct PID
{
    static constexpr const char* NAME = "vehiclePID";

    enum IntegralState : int8_t {
        Below = -1,
        Equal = 0,
        Above = 1
    };

    // 1.52 RVA: 0x1D08F00
    /// @pattern F3 0F 11 49 0C F3 0F 11 51 10 F3 0F 11 59 14 C3
    void __fastcall UpdatePID(float P, float I, float D);

    // 1.52 RVA: 0x1D08F10
    /// @pattern 33 C0 F3 0F 11 49 08 48 89 01 C3
    void __fastcall Reset(float correction);

    // 1.52 RVA: 0x1D08F20
    /// @pattern F3 0F 10 41 08 C3
    float __fastcall GetCorrection();

    // 1.52 RVA: 0x1D08F30
    /// @pattern 33 C0 F3 0F 11 49 0C 48 89 01 48 89 41 18 F3 0F 11 51 10 F3 0F 11 59 14 C3
    void __fastcall Initialize(float P, float I, float D);

    // 1.52 RVA: 0x1D08F50
    /// @pattern 48 83 EC 38 F3 0F 10 29 0F 28 E1 0F 2E ED 4C 8B C1 0F 29 74 24 20 0F 57 DB 0F 29 7C 24 10 0F 28
    IntegralState __fastcall Process(float error, float timeDelta);

    float integral;
    float lastError;
    float correction;
    float P;
    float I;
    float D;
    float unk18;
    float customTarget;
};
RED4EXT_ASSERT_SIZE(PID, 0x20);
} // namespace vehicle
} // namespace RED4ext