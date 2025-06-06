#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/vehicle/CarBaseObject.hpp>

namespace RED4ext
{
namespace vehicle
{
struct __declspec(align(0x10)) ArmedCarBaseObject : vehicle::CarBaseObject
{
    static constexpr const char* NAME = "vehicleArmedCarBaseObject";
    static constexpr const char* ALIAS = NAME;

    virtual void sub_148(uintptr_t a1, uintptr_t a2) override;

    virtual uint8_t sub_338() override;                                     // 338 return 0u8
    virtual uint64_t sub_340(DynArray<void*> *) override;                   // 340 dynArray at A00
    virtual void sub_350() override;                                        // 350 update blackboard to 1
    virtual void sub_358(Handle<ISerializable>*) override;                  // 358 update blackboard to -1
    virtual void LoadWeapons(DynArray<void*>) override;                     // 388 
    virtual void sub_390(uint32_t weaponIndex) override;                    // 390
    virtual void sub_398() override;                                        // 398
    virtual void sub_3A0() override;                                        // 3A0 rendering system, blackboard
    virtual void sub_3A8() override;                                        // 3A8
    virtual void sub_3B0(uint32_t weaponIndex) override;                    // 3B0 calls sub_3C0
    virtual void * sub_3B8(weapon::Object *weaponObject,                    // 3B8 calls generic shoot
        Vector4 *weaponPosition, Vector4 *offset, 
        Vector4 *tracePosition, float range, __int64 numProjectiles, 
        __int64 a8, __int64 a9, __int64 a10) override;                                
    virtual uint8_t GetWeaponIndex(int) override;                           // 3D0 only shootPrimary
  
    DynArray<void*> unkC30;
    Handle<ISerializable> statsSystem;
    Handle<ISerializable> statPoolsSystem;
    Handle<ISerializable> inventoryManager;
    Handle<ISerializable> targetingSystem;
    Handle<ISerializable> unkC80;
    Handle<ISerializable> unkC90;
    Handle<ISerializable> unkCA0;
    Handle<ISerializable> unkCB0;
    float unkCC0;
    float unkCC4;
    Handle<ISerializable> unkCC8;
    uint8_t dualPowerWeaponPos;
    uint8_t missleWeaponPos;
    uint8_t unkCDA;
    uint8_t unkCDB;
    uint8_t unkCDC;
    uint8_t unkCDD;
    uint8_t unkCDE;
    uint8_t unkCDF;
    uint64_t unkCE0;
    uint64_t unkCE8;
};
RED4EXT_ASSERT_SIZE(ArmedCarBaseObject, 0xCF0);
} // namespace vehicle
using vehicleArmedCarBaseObject = vehicle::ArmedCarBaseObject;
} // namespace RED4ext

// clang-format on
