#pragma once

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/CName.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/CameraComponent.hpp>

namespace RED4ext
{
namespace game { 
struct FPPCameraComponent : game::CameraComponent
{
    static constexpr const char* NAME = "gameFPPCameraComponent";
    static constexpr const char* ALIAS = "FPPCameraComponent";

    uint8_t unk2A0[0x360 - 0x2A0]; // 2A0
    float pitchMin; // 360
    float pitchMax; // 364
    float yawMaxLeft; // 368
    float yawMaxRight; // 36C
    bool headingLocked; // 370
    uint8_t unk371[0x464 - 0x371]; // 371
    float sensitivityMultX; // 464
    float sensitivityMultY; // 468
    uint8_t unk46C[0x478 - 0x46C]; // 46C
    CName timeDilationCurveName; // 478
    float unk480;
    float unk484;
    uint8_t unk488;
    uint8_t unk489[3];
    float yawOffset;
    float unk490;
    float unk494[3];
    uint8_t unk4A0;
    uint8_t unk4A1[7];
    float unk4A8;
    float yawInput;
    float pitchInput;
    float unk4B4;
    uint32_t unk4B8[6];
};
RED4EXT_ASSERT_SIZE(FPPCameraComponent, 0x4D0);
} // namespace game
using FPPCameraComponent = game::FPPCameraComponent;
} // namespace RED4ext
