#pragma once

#include <RED4ext/Common.hpp>
#include <RED4ext/RTTITypes.hpp>
#include <RED4ext/DynArray.hpp>

namespace RED4ext 
{
struct IScriptable;
namespace world {
    struct RuntimeInfo;
}
namespace Memory {
    struct IAllocator;
}
struct GameSystemData;
struct IGameInstance // : IDynamicStorage
{
    // static constexpr const uintptr_t VFT = 0x35FAC80;

    virtual ~IGameInstance();                                       // 00
    virtual IScriptable* GetSystem(const CBaseRTTIType* aType) = 0; // 08
    virtual world::RuntimeInfo* GetRuntimeInfo();                   // 10
    virtual Memory::IAllocator* GetAllocator();                     // 18
    // sub_20: break
    virtual void CreateSystems(uint8_t*, uint64_t, uint32_t*);
    // sub_28: Calls game::IGameSystem::RegisterUpdates() for each system
    virtual bool RegisterUpdates(world::RuntimeInfo **runtimeInfo);
    // sub_30: break
    virtual void* GetUnk130();
    // sub_38: break
    virtual void* GetUnk138();
    // sub_40: break
    virtual void SaveGame(uint64_t, uint64_t, uint64_t);
    // sub_48: break
    virtual void SomethingAutoSave_sub_1B8(uint64_t);
    // sub_50: empty
    virtual void SomethingAutoSave_sub_1C0() { }              
    virtual void Systems130();                            // 58
    // returns value of GameSystemData flags
    virtual uint8_t sub_60(GameSystemData*, uint8_t *);                      // 60

    // 1.52 RVA: 0x2CFF000 / 47181824
    /// @pattern 40 55 53 56 57 41 56 48 8D 6C 24 C9 48 81 EC B0 00 00 00 48 8B F1 E8 A5 E7 C9 FF 48 8D 05 5E BC
    // IGameInstance();

    // 1.52 RVA: 0x29CA390 / 43819920
    // calls sub20 with some unknown values from a1
    /// @pattern 48 89 5C 24 10 57 48 83 EC 20 48 8B F9 48 8B DA 0F B6 4A 32 E8 67 DC 1E 00 0F B6 47 08 48 8D 54
    // static void *__fastcall FrameworkSetupCallback(uint64_t *a1, uint64_t a2);

    // 1.52 RVA: 0x2CFFC40 / 47184960
    // sets gameIsLoading to true
    /// @pattern 48 89 5C 24 10 4C 89 4C 24 20 55 56 57 41 54 41 55 41 56 41 57 48 8D 6C 24 D9 48 81 EC F0 00 00
    __int64 __fastcall RegisterGameLoadCallbacks(__int64 a2, uint8_t  *a3, __int64 a4);

    // 1.52 RVA: 0x2D005A0 / 47187360
    // Uses a struct to call system->sub_150
    /// @pattern 48 89 5C 24 18 48 89 74 24 20 57 48 83 EC 20 48 8B F1 48 8B DA 0F B6 4A 32 E8 52 7A EB FF 48 8B
    // static void __fastcall OnGameLoad(uint64_t *a1, __int64 a2);

    // 1.52 RVA: 0x2D00650 / 47187536
    // passes in a struct to set gameIsLoading to false
    /// @pattern 48 89 5C 24 10 57 48 83 EC 20 48 8B F9 0F B6 4A 32 E8 AA 79 EB FF 48 8B 47 08 80 38 00 75 0A 48
    // static void __fastcall OnPostGameLoad(uint64_t *a1, __int64 a2);

    // 1.52 RVA: 0x2D00090 / 47186064
    /// @pattern 48 89 5C 24 08 57 48 83 EC 20 48 8B 59 38 8B 79 44 48 C1 E7 04 48 03 FB 48 3B DF 74 18 0F 1F 00
    void __fastcall Systems160();

    // 1.52 RVA: 0x2D000D0 / 47186128
    // returns 0 if any system->sub_158 returns 0
    /// @pattern 48 89 6C 24 20 56 48 83 EC 20 80 B9 28 01 00 00 00 48 8B E9 40 B6 01 74 5C 48 89 5C 24 30 48 8B
    bool __fastcall Systems158();

    // 1.52 RVA: 0x2D00160 / 47186272
    /// @pattern 48 8B C4 48 89 50 10 55 53 56 57 41 55 41 57 48 8D 68 A1 48 81 EC B8 00 00 00 48 8B 59 38 4D 8B
    void __fastcall RegisterStreamingWorldLoadedCallback(__int64 a2, __int64 a3);

    // 1.52 RVA: 0x2D006B0 / 47187632
    // calls system->sub_180
    /// @pattern 48 89 5C 24 18 48 89 74 24 20 57 48 83 EC 20 48 8B F1 48 8B DA 0F B6 4A 32 E8 42 79 EB FF 48 8B
    // static void *__fastcall OnStreamingWorldLoaded(uint64_t *a1, __int64 a2);

    // 1.52 RVA: 0x2D00400 / 47186944
    // calls system->sub_120(a2)
    /// @pattern 48 89 5C 24 08 48 89 74 24 10 57 48 83 EC 20 48 8B 79 38 48 8B F2 8B 59 44 48 C1 E3 04 48 03 DF
    void __fastcall WorldPendingDetach(void* runtimeScene);

    // 1.52 RVA: 0x2CFFA00 / 47184384
    // also sets gameSystemPtr+0x8 to 0
    /// @pattern 48 89 5C 24 08 48 89 6C 24 10 48 89 74 24 18 57 48 83 EC 20 48 8B 79 38 48 8B F2 8B 59 44 48 8B
    void __fastcall WorldDetached(void* runtimeScene);

    // 1.52 RVA: 0x2D00760 / 47187808
    // calls system->sub_168 if a2, else system->sub_170
    /// @pattern 48 89 5C 24 08 57 48 83 EC 20 88 91 29 01 00 00 48 8B 59 38 8B 79 44 48 C1 E7 04 48 03 FB 48 3B
    void __fastcall Systems168o170(bool a2);

    // 1.52 RVA: 0x2CFFA90 / 47184528
    // passes a3 into systems->sub_178
    /// @pattern 48 8B C4 53 57 41 55 41 57 48 83 EC 68 48 8B 59 38 45 0F B6 E8 8B 79 44 4C 8B FA 48 C1 E7 04 48
    void __fastcall Systems178(DynArray<void*> *a2, bool a3);
};

}