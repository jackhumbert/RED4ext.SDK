#pragma once

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/SWeaponPlaneParams.hpp>
#include <RED4ext/Scripting/Natives/Generated/ent/IPlacedComponent.hpp>
#include <RED4ext/Scripting/Natives/Generated/WorldTransform.hpp>
#include <RED4ext/Scripting/Natives/Generated/Transform.hpp>
#include <RED4ext/Scripting/Natives/entTargetedCameraInterface.hpp>

namespace RED4ext
{
namespace ent { 
struct BaseCameraComponent
    : ent::IPlacedComponent
    , public ent::TargetedCameraInterface
{
    static constexpr const char* NAME = "entBaseCameraComponent";
    static constexpr const char* ALIAS = "entCameraComponent";
    static constexpr const uint32_t VFT = 3664712257;

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
    virtual void sub_2B0(Transform* otherTransform, Transform* localTransform);
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

    // WorldTransform placeholderTransform; // 1D0
};
RED4EXT_ASSERT_SIZE(BaseCameraComponent, 0x1E0);
} // namespace ent
using entCameraComponent = ent::BaseCameraComponent;
} // namespace RED4ext
