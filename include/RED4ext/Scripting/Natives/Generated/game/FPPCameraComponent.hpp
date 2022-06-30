#pragma once

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/CName.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/CameraComponent.hpp>

namespace RED4ext
{
    namespace anim {
        struct AnimFeature_FPPCamera;
    }
namespace game {
#pragma push(pack, 1)
struct FPPCameraComponent : game::CameraComponent
{
    static constexpr const char* NAME = "gameFPPCameraComponent";
    static constexpr const char* ALIAS = "FPPCameraComponent";

float unk2A0;
  float unk2A4;
  float unk2A8;
  float unk2AC;
  void *unk2B0;
  void *unk2B8;
  void *unk2C0;
  void *unk2C8;
  void *unk2D0;
  void *unk2D8;
  Handle<anim::AnimFeature_FPPCamera> animFeature;
  Handle<void> animationController;
  Handle<void> animatedComponent;
  DynArray<void*> unk310;
  DynArray<void*> paramsSetList;
  Quaternion entityOrientation;
  CName currentCameraParams;
  float pitchMinRounded;
  float pitchMaxRounded;
  float yawMaxLeftRounded;
  float yawMaxRightRounded;
  float yawMaxLeft;
  float yawMaxRight;
  float pitchMin;
  float pitchMax;
  float yawMaxLeft2;
  float yawMaxRight2;
  bool headingLocked;
  uint8_t unk371[3];
  float cameraNeedsResetTimer;
  float headingResetTimeout;
  uint8_t headingResetOnlyWhileMoving;
  uint8_t unk37D;
  uint8_t unk37E;
  uint8_t unk37F;
  float unk380;
  uint8_t maintainWorldSpacingHeading;
  uint8_t paramsLoaded;
  uint8_t normalizeYaw;
  uint8_t unk387;
  float unk388;
  float fov4;
  float fovFromSettings;
  uint8_t overrideFovSetting;
  uint8_t unk395;
  uint8_t unk396;
  uint8_t unk397;
  float fov3;
  float fovSmoothingDuration;
  float interesting;
  float unk3A4;
  float unk3A8;
  float unk3AC;
  float unk3B0;
  float unk3B4;
  float unk3B8;
  float yawRubberBandLimit;
  float yawRubberBandInputDamping;
  float yawRubberOnStretchSlowdown;
  float yawRubberReturnMultiplier;
  float pitchRubberBandLimit;
  float pitchRubberBandInputDamping;
  float pitchRubberOnStretchSlowdown;
  float pitchRubberReturnMultiplier;
  uint8_t unk3DC;
  uint8_t unk3DD;
  uint8_t unk3DE;
  uint8_t unk3DF;
  float unk3E0;
  float unk3E4;
  float fov1;
  float fov2;
  float unk3F0;
  float unk3F4;
  float unk3F8;
  float unk3FC;
  float unk400;
  float unk404;
  float unk408;
  Handle<void> tpp;
  float unk41C[2];
  Handle<void> unk428;
  float unk438;
  float unk43C;
  float yawInputHolder;
  float unk444;
  float unk448;
  float unk44C;
  float unk450;
  float unk454;
  float unk458;
  float unk45C;
  float unk460;
  float sensitivityMultX;
  float sensitivityMultY;
  uint8_t unk46C[12];
  CName timeDilationCurveName;
  float cameraInputDisableTimer;
  float unk484;
  uint8_t unk488;
  uint8_t unk489;
  uint8_t unk48A;
  uint8_t unk48B;
  float yawOffset;
  float pitchOffset;
  float unk494[3];
  uint8_t updated;
  uint8_t unk4A1[7];
  float unk4A8;
  float yawInput;
  float pitchInput;
  float unk4B4;
  uint64_t unk4B8Setting;
  uint64_t unk4C0Setting;
  uint8_t unk4C8;
  uint8_t unk4C9;
  uint8_t unk4CA;
  uint8_t unk4CB;
  uint32_t unk4CC;
};
#pragma pop(pack)
RED4EXT_ASSERT_SIZE(FPPCameraComponent, 0x4D0);
 //char (*__kaboom)[offsetof(FPPCameraComponent, unk488)] = 1;
} // namespace game
using FPPCameraComponent = game::FPPCameraComponent;
} // namespace RED4ext
