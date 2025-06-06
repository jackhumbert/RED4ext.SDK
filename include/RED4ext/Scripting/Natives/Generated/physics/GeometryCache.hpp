#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/DynArray.hpp>
#include <RED4ext/NativeTypes.hpp>
#include <RED4ext/Scripting/Natives/Generated/CResource.hpp>
#include <RED4ext/Scripting/Natives/Generated/physics/GeometryKey.hpp>
#include <RED4ext/Scripting/Natives/Generated/physics/SectorCacheEntry.hpp>
#include <RED4ext/Scripting/Natives/Generated/physics/SectorEntry.hpp>

namespace RED4ext
{
namespace physics
{
struct __declspec(align(0x10)) GeometryCache : CResource
{
    static constexpr const char* NAME = "physicsGeometryCache";
    static constexpr const char* ALIAS = NAME;

    // 1.6 RVA: 0x442D50 / 4468048
    /// @pattern 40 55 53 56 57 41 56 48 8D 6C 24 C9 48 81 EC C0 00 00 00 44 8B 99 08 01 00 00 48 8B D9 66 FF 81
    __int64 __fastcall LoadAlwaysloadedSectorGeometriesSetup(__int64 a2);

    // 1.6 RVA: 0x4430B0 / 4468912
    /// @pattern 48 8B C4 55 41 56 41 57 48 8D 68 98 48 81 EC 50 01 00 00 4C 8B F1 44 8B FA 3B 51 5C 0F 87 30 03
    __int64 __fastcall LoadSectorGeometriesSetup(uint32_t);

    struct LoadSectorGeometriesStruct {
        uint32_t numSectors;
        uint32_t unk04;
        DynArray<GeometryKey> sectorGeometries;
        DynArray<SectorCacheEntry> sectorCacheEntries;
        Handle<GeometryCache> geometryCache;
    };

    // 1.6 RVA: 0x43FD90 / 4455824
    /// @pattern 40 55 41 55 48 8D 6C 24 E8 48 81 EC 18 01 00 00 48 8B 41 30 0F 57 C0 4C 8B E9 F3 0F 7F 44 24 20
    static void __fastcall LoadSectorGeometries(LoadSectorGeometriesStruct*);

    // 1.6 RVA: 0x440390 / 4457360
    /// @pattern 40 55 41 55 48 8D 6C 24 E8 48 81 EC 18 01 00 00 48 8B 41 28 0F 57 C0 4C 8B E9 F3 0F 7F 44 24 20
    static void __fastcall LoadAlwaysloadedSectorGeometries(void *);

    // 1.6 RVA: 0x442A10 / 4467216
    /// @pattern 48 89 5C 24 08 57 48 83 EC 20 0F B6 42 0C 48 8B D9 3C 04 0F 85 A0 00 00 00 44 8B 42 04 48 8D B9
    bool __fastcall HasGeometryKey(GeometryKey *a2);

    // 1.6 RVA: 0x442CE0 / 4467936
    /// @pattern 40 56 48 83 EC 20 48 8B F1 3B 51 5C 76 08 B0 01 48 83 C4 20 5E C3 48 89 5C 24 30 48 8B 59 50 48
    bool __fastcall Unknown(uint32_t a2);

    // 1.6 RVA: 0x442830 / 4466736
    /// @pattern 40 55 48 83 EC 20 48 8B E9 3B 51 5C 0F 87 9F 00 00 00 48 89 5C 24 30 48 89 74 24 38 48 8B 71 50
    void __fastcall FreeSector(uint32_t);

    // 1.6 RVA: 0x442680 / 4466304
    /// @pattern 48 89 5C 24 20 55 56 57 48 83 EC 40 0F B6 42 0C 48 8B F9 3C 04 0F 85 A2 00 00 00 44 8B 42 04 48
    void __fastcall FreeGeometryKey(GeometryKey *key);

    // 1.6 RVA: 0x442390 / 4465552
    /// @pattern 40 56 48 83 EC 20 66 FF 89 10 01 00 00 48 8B F1 80 B9 12 01 00 00 02 75 5C 48 89 5C 24 30 8B 99
    void __fastcall FreeAlwaysLoaded();

    // 1.6 RVA: 0x4428F0 / 4466928
    /// @pattern 48 89 5C 24 20 48 89 54 24 10 57 48 83 EC 40 48 8D B9 81 01 00 00 48 8B D9 48 8B CF E8 DF E4 74
    bool __fastcall FreeKey(__int64 rdx0);

    // 1.6 RVA: 0x441520 / 4461856
    /// @pattern 4C 89 4C 24 20 48 89 54 24 10 48 89 4C 24 08 55 53 56 57 41 54 41 55 41 56 48 8D 6C 24 E1 48 81
    __int64 __fastcall sub_7FF75B921520(__int64 rdx0, __int64 *a3, DynArray<void*> **a4, unsigned __int8 a5);

    // 1.6 RVA: 0x442410 / 4465680
    /// @pattern 40 53 55 56 57 48 81 EC A8 00 00 00 0F B6 42 0C 48 8B F9 3C 04 0F 85 D9 00 00 00 44 8B 42 04 48
    bool __fastcall sub_7FF75B922410(GeometryKey *geoKey);

    DynArray<DeferredDataBuffer> bufferTableSectors; // 40
    DynArray<physics::SectorEntry> sectorEntries; // 50
    DynArray<physics::GeometryKey> sectorGeometries; // 60
    DynArray<physics::SectorCacheEntry> sectorCacheEntries; // 70
    DeferredDataBuffer alwaysLoadedSectorDDB; // 80
    uint8_t unkD8[0xE0 - 0xD8]; // D8
    physics::SectorEntry alwaysLoadedSector; // E0
    // GeometryKey.ta to Handle<physx::PxBase>
    HashMap<uint64_t, uint64_t> unk120; // 120
    HashMap<uint64_t, uint64_t> unk150; // 150
    // for unk120
    SharedSpinLock unk180;
    uint64_t unk188;
};
RED4EXT_ASSERT_SIZE(GeometryCache, 0x190);
} // namespace physics
using physicsGeometryCache = physics::GeometryCache;
} // namespace RED4ext

// clang-format on
