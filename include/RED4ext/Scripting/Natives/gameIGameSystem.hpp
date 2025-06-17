#pragma once

#include <RED4ext/Common.hpp>
#include <RED4ext/JobQueue.hpp>
#include <RED4ext/Scripting/Natives/IUpdatableSystem.hpp>

namespace RED4ext
{
struct GameInstance;

namespace world
{
struct RuntimeScene;
}

namespace game
{
struct SaveLock;

struct IGameSystem : IUpdatableSystem
{
    static constexpr const char* NAME = "gameIGameSystem";
    static constexpr const char* ALIAS = "IGameSystem";

    /// @hash 1854670959
    static constexpr const uint32_t VFT = 1854670959;

    // arg to sub_190
    struct HighLow
    {
        void* unk00;
        void* performance;
        uint8_t crowdDensity;
    };

    // 1.52 RVA: 0xAEC190 / 11452816
    /// @pattern 40 53 48 83 EC 20 48 8B D9 E8 22 B8 F8 FF 48 8D 05 4B 92 6C 02 48 C7 43 40 00 00 00 00 48 89 03
    //IGameSystem();

    /// @hash 2606044598
    virtual CClass* GetNativeType() override;     
    virtual ~IGameSystem() override = default;

    virtual void OnWorldAttached(world::RuntimeScene* aScene);                                        // 110
    virtual void OnBeforeWorldDetach(world::RuntimeScene* aScene);                                    // 118
    virtual void OnWorldDetached(world::RuntimeScene* aScene);                                        // 120
    virtual void OnAfterWorldDetach();                                                                // 128
    virtual uint32_t OnBeforeGameSave(const JobGroup& aJobGroup, void* a2);                           // 130
    virtual void OnGameSave(void* aStream);                                                           // 138
    virtual void OnAfterGameSave();                                                                   // 140
    virtual void OnGameLoad(const JobGroup& aJobGroup, bool& aSuccess, void* aStream);                // 148
    // 158 ReturnOne, something WaitingForEntities, "Saved"
    // right before player attach
    virtual bool OnGameRestored();                                                                    // 150
    virtual void OnGamePrepared();                                                                    // 158
    virtual void OnGamePaused();                                                                      // 160
    virtual void OnGameResumed();                                                                     // 168
    // 178, 138, 148 fire when going out-of-bounds
    // something with a CString @ 0x08 - PointOfNoReturnSave?    
    virtual void* IsSavingLocked(SaveLock* aLock, bool a2);                                           // 170
    virtual void OnStreamingWorldLoaded(world::RuntimeScene* aScene, uint64_t a2, 
        const JobGroup& aJobGroup);                                                                   // 178
    virtual void sub_180();                                                                           // 180
    virtual void sub_188();       
    // called from GameInstance->sub_20, recieves some struct based on game performance setting & crowd density
    virtual void sub_190(void* a1);                                                                   // 190
    virtual void sub_198();                                                                           // 198
    // called after created & gameInstance is set
    // OnInitialize called
    // Tweaks loaded
    virtual void OnInitialize(const JobHandle& aJob);                                                 // 1A0
    virtual void OnUninitialize();                                                                    // 1A8


    // 1.52 RVA: 0xAEC8E0 / 11454688
    // Sets gameInstance, creates unkThing, calls sub_198
    // Called from GameInstance->sub_20
    /// @pattern 48 89 5C 24 10 57 48 83 EC 20 48 8B FA 66 C7 44 24 30 00 00 0F B7 44 24 30 48 8D 54 24 30 4C 89
    void ** __fastcall SetGameInstance(void ** unkThing, GameInstance * gameInstance);

    // 1.52 RVA: 0xAEC970 / 11454832
    // Unsets unk40, calls sub_1A0
    /// @pattern 40 53 48 83 EC 20 48 8B 01 48 8B D9 FF 90 A0 01 00 00 48 C7 43 40 00 00 00 00 48 83 C4 20 5B C3
    __int64 __fastcall Unset();

    GameInstance* gameInstance; // 40
};
RED4EXT_ASSERT_SIZE(IGameSystem, 0x48);
} // namespace game
} // namespace RED4ext

#ifdef RED4EXT_HEADER_ONLY
#include <RED4ext/Scripting/Natives/gameIGameSystem-inl.hpp>
#endif
