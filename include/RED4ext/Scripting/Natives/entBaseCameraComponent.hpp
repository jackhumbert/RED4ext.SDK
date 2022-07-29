#pragma once

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/SWeaponPlaneParams.hpp>
#include <RED4ext/Scripting/Natives/Generated/ent/IPlacedComponent.hpp>
#include <RED4ext/Scripting/Natives/Generated/WorldTransform.hpp>
#include <RED4ext/Scripting/Natives/entCameraInterface.hpp>

namespace RED4ext
{
namespace ent { 
struct BaseCameraComponent : ent::IPlacedComponent, ent::CameraInterface
{
    static constexpr const char* NAME = "entBaseCameraComponent";
    static constexpr const char* ALIAS = "entCameraComponent";
    static constexpr const uintptr_t VFT_RVA = 0x3297238;

    virtual void sub_258();
    virtual void sub_260();
    virtual void sub_268();
    virtual void GetZoom();
    virtual void sub_278();
    virtual void GetNearPlaneOverride();
    virtual void GetFarPlaneOverride();
    virtual void GetMotionBlurScale();
    virtual void GetUnk170();
    virtual void GetWeaponPlane();
    virtual void GetUnk190();
    virtual void sub_2B0();
    virtual void SetFov();
    virtual void CameraCopyIsh();
    virtual void SetZoom();
    virtual void SetZoomWeaponValue();
    virtual void SetNearPlaneOverride();
    virtual void SetFarPlaneOverride();
    virtual void SetMotionBlurScale();
    virtual void SetUnk170();
    virtual void SetWeaponPlane();
    virtual void SetUnk190();
    virtual void sub_308();
    virtual void sub_310();
    virtual void sub_318();

    WorldTransform placeholderTransform;
};
RED4EXT_ASSERT_SIZE(BaseCameraComponent, 0x1D0);
} // namespace ent
using entCameraComponent = ent::BaseCameraComponent;
} // namespace RED4ext
