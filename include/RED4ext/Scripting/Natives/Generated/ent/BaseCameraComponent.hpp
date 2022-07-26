#pragma once

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/SWeaponPlaneParams.hpp>
#include <RED4ext/Scripting/Natives/Generated/ent/IPlacedComponent.hpp>
#include <RED4ext/Scripting/Natives/Generated/WorldTransform.hpp>

namespace RED4ext
{
namespace ent { 

struct TargetedCameraInterface {
    virtual void sub_00();
    virtual void sub_08();
    virtual void sub_10();
    virtual void sub_18();
    virtual void CopyParameters(void *);
    virtual Vector3* GetInitialPosition(Vector3 *);
    virtual Quaternion* GetInitialOrientation(Quaternion*);
    virtual void sub_38();

    // Some transform math
    virtual void Update();
    virtual const char* GetTypeName();
    virtual float GetIntrefaceZoom();
    virtual void sub_58();
    virtual void sub_60();
    virtual void sub_68();
    virtual void sub_70();
    virtual void sub_78();

    // Apply something maybe
    virtual void sub_80();
    virtual void sub_88();
    virtual void sub_90();
    virtual void sub_98();
    
    float fov; // 128
    WorldTransform someTransform; // 12C
    uint8_t unk14C[0x15C - 0x14C]; // 14C
    float zoom; // 15C
    uint8_t unk160[0x164 - 0x160]; // 160
    float nearPlaneOverride; // 164
    float farPlaneOverride; // 168
    float motionBlurScale; // 16C
    uint8_t unk170[0x174 - 0x170]; // 170
    SWeaponPlaneParams weaponPlane; // 174
    uint8_t unk190[0x1B0 - 0x190]; // 190
};

struct BaseCameraComponent : ent::IPlacedComponent, TargetedCameraInterface
{
    static constexpr const char* NAME = "entBaseCameraComponent";
    static constexpr const char* ALIAS = "entCameraComponent";
    static constexpr const uintptr_t VFT_RVA = 0;

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
