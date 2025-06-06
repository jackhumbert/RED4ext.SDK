#pragma once

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/IVehicleSystem.hpp>

namespace RED4ext
{
namespace vehicle { struct BaseObject; }
namespace game { 

// AIbehaviorEventHandler maybe? could be optimization artifact
struct VehicleInterface2 {
    virtual ~VehicleInterface2();
    virtual void sub_08();
};

// dynamic array of some sort? used elsewhere
struct VehicleInterface3 {
    virtual ~VehicleInterface3();
    // references vehicleVsVehicleCollisions & trafficVsTrafficCollisions
    // sets up all chassis filterData in unkED00
    virtual void sub_08(void *);
};

struct VehicleSystem : IVehicleSystem, VehicleInterface2, VehicleInterface3
{
    static constexpr const char* NAME = "gameVehicleSystem";
    static constexpr const char* ALIAS = "VehicleSystem";
    static constexpr const uintptr_t VFT = gameVehicleSystem_VFT_Addr;

// virtuals

    virtual void __fastcall sub_1A8() override;
    virtual void __fastcall sub_1B0() override;
    virtual void __fastcall sub_1B8() override;
    virtual void __fastcall sub_1C0() override;
    virtual void __fastcall sub_1C8() override;
    virtual void __fastcall sub_1D0() override;
    virtual void __fastcall sub_1D8() override;
    virtual void __fastcall sub_1E0() override;
    virtual void __fastcall sub_1E8() override;
    virtual void __fastcall sub_1F0() override;
    virtual void __fastcall sub_1F8() override;
    virtual void __fastcall sub_200() override;
    virtual void __fastcall sub_208() override;
    virtual void __fastcall sub_210() override;
    virtual void __fastcall sub_218() override;
    virtual void __fastcall sub_220() override;
    virtual void __fastcall sub_228() override;
    virtual void __fastcall sub_230() override;
    virtual void __fastcall sub_238() override;
    virtual void __fastcall sub_240() override;
    virtual void __fastcall sub_248() override;
    virtual void __fastcall sub_250() override;
    virtual void __fastcall sub_258() override;
    virtual void __fastcall sub_260() override;
    virtual void __fastcall sub_268() override;
    virtual void __fastcall sub_270() override;
    virtual void __fastcall sub_278() override;
    virtual void __fastcall sub_280() override;
    virtual void __fastcall sub_288() override;
    virtual void __fastcall sub_290() override;
    virtual void __fastcall sub_298() override;
    virtual void __fastcall sub_2A0() override;
    virtual void __fastcall sub_2A8() override;
    virtual void __fastcall sub_2B0() override;
    virtual void __fastcall sub_2B8() override;
    virtual void __fastcall sub_2C0() override;
    virtual void __fastcall sub_2C8() override;
    virtual void __fastcall sub_2D0() override;
    virtual void __fastcall sub_2D8() override;
    virtual void __fastcall sub_2E0() override;
    virtual void __fastcall sub_2E8() override;
    virtual void __fastcall sub_2F0() override;
    virtual void __fastcall sub_2F8() override;
    virtual void __fastcall sub_300() override;
    virtual void __fastcall sub_308() override;
    virtual void __fastcall sub_310() override;
    virtual void __fastcall sub_318() override;
    virtual void __fastcall sub_320() override;
    virtual void __fastcall sub_328() override;
    virtual void *__fastcall sub_330() override;
    virtual void __fastcall sub_338() override;
    virtual void __fastcall sub_340() override;
    virtual void __fastcall sub_348() override;
    virtual void __fastcall sub_350() override;
    virtual void __fastcall sub_358() override;
    virtual void __fastcall sub_360() override;
    virtual void __fastcall sub_368() override;
    virtual void __fastcall sub_370() override;
    virtual void __fastcall sub_378() override;

    // gets unk179AB pointers 
    virtual uint64_t ** sub_380(void ** a2);

// methods

    // 1.6 RVA: 0x1CE65E0 / 30303712
    /// @pattern 40 53 56 41 56 48 83 EC 30 8B 81 A0 79 01 00 48 8D B1 00 ED 00 00 4C 8B F1 48 8D 14 40 48 8D 1C
    void __fastcall UpdateVehicleArrays();

// callbacks

    // 1.6 RVA: 0x1CECC60 / 30329952
    /// @pattern 48 89 5C 24 18 55 56 57 41 56 41 57 48 83 EC 70 4C 8B F9 4C 8B F2 0F B6 4A 32 E8 41 0E F2 00 49
    static void SingleFixedStep(RED4ext::game::VehicleSystem **vehicleSystem_p, void*);

    // 1.6 RVA: 0x1CECFE0 / 30330848
    /// @pattern 48 89 74 24 10 48 89 7C 24 18 41 56 48 83 EC 30 48 8B 44 24 60 4C 8B F1 41 8B F9 41 8B F0 0F B6
    static void __fastcall Interpolation(RED4ext::game::VehicleSystem **vehicleSystem_p, __int64 a2, unsigned int a3, unsigned int a4, __int64 a5);

    // updates physics states of vehicles in unkED00
    // 1.6 RVA: 0x1CED150 / 30331216
    /// @pattern 48 89 74 24 10 48 89 7C 24 20 41 56 48 83 EC 30 48 8B 44 24 60 4C 8B F1 41 8B F9 41 8B F0 0F B6
    static void __fastcall PreUpdateAndPreMove(RED4ext::game::VehicleSystem **rcx0, __int64 a2, unsigned int a3, unsigned int a4, __int64 a5);

    // 1.6 RVA: 0x1CE2DB0 / 30289328
    /// @pattern 48 89 5C 24 10 48 89 4C 24 08 55 56 57 41 54 41 55 41 56 41 57 48 83 EC 60 48 8B 39 4C 8B F1 0F
    static void __fastcall BeginUpdate(RED4ext::game::VehicleSystem **rcx0);

    // calls sub_380, updates physics states
    // 1.6 RVA: 0x1CED0A0 / 30331040
    /// @pattern 48 89 74 24 10 48 89 7C 24 18 41 56 48 83 EC 30 48 8B 44 24 60 4C 8B F1 41 8B F9 41 8B F0 0F B6
    static void __fastcall PostMove(RED4ext::game::VehicleSystem **vehicleSystem_p, __int64 a2, unsigned int a3, unsigned int a4, __int64 a5);

    // something with vehicle->unk368
    // 1.6  RVA: 0x1C8AA80 / 29928064
    /// @pattern 48 89 5C 24 10 57 48 83 EC 20 48 8B F9 0F B6 4A 32 E8 2A 30 F8 00 48 8B 0F F3 0F 10 4F 08 48 8B
    static void *__fastcall FixedUpdate_PreSolve(__int64, __int64);

    // calls vehicle->sub_2B8
    // 1.6  RVA: 0x1C8A9F0 / 29927920
    /// @pattern 48 89 5C 24 10 57 48 83 EC 30 48 8B F9 0F B6 4A 32 E8 BA 30 F8 00 0F B6 47 0C 4C 8D 47 18 F3 0F
    static void *__fastcall FixedUpdate(__int64, __int64);

    uint64_t unk50[3];
    uint64_t unk78;
    uint64_t unk80[4];
    uint64_t unkA0;
    uint64_t unkA8[43];
    uint64_t unk200;
    uint64_t unk208[7519];
    struct HandleStorage {
        uint32_t unk00;
        uint32_t unk04;
        Handle<vehicle::BaseObject> handle;
    } unkED00[1500];
    uint32_t unk179A0;
    uint32_t unk179A4;
    uint64_t unk179AB[1500];
    uint32_t unk1A888;
    uint32_t unk1A88C;
    uint64_t unk1A890;
    uint64_t unk1A898[3009];
    float unk206A0;
    uint32_t unk206A4;
    uint64_t unk206A8[28];
    uint8_t unk20788;
    SharedSpinLock unk20789;
    uint8_t unk2078A;
    uint8_t unk2078B;
    uint8_t unk2078C;
    uint8_t unk2078D;
    uint8_t unk2078E;
    uint8_t unk2078F;
    // Map<uint32_t, RED4ext::vehicle::Unk588> unk20790;
    Map<uint32_t, uint64_t> unk20790;
    uint64_t unk207B8[4];
    SharedSpinLock unk207D8;
    DynArray<uint64_t> unk207E0;
    uint64_t unk207F0[19];
    SharedSpinLock unk20888;
    uint64_t unk20890[6];
    uint8_t unk208C0[0x20A80-133312];
};
// RED4EXT_ASSERT_SIZE(VehicleSystem, 0x208C0);
} // namespace game
using VehicleSystem = game::VehicleSystem;
} // namespace RED4ext
