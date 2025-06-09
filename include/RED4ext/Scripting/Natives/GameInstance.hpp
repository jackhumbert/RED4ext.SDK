#pragma once

#include <RED4ext/IDynamicStorage.hpp>
#include <RED4ext/Scripting/Natives/Generated/world/RuntimeScene.hpp>
#include <RED4ext/Scripting/Natives/Generated/world/RuntimeInfo.hpp>
// #include <RED4ext/Scripting/Natives/Generated/game/GameFeatureManager.hpp>
 #include <RED4ext/Scripting/Natives/IGameInstance.hpp>

namespace RED4ext {

namespace game { struct IGameSystem; struct GameFeatureManager; }

struct UpdatableSystems {
    // 1.52 RVA: 0xB90F10 / 12128016
    // called from GameInstance->SetRuntimeScene
    /// @pattern 40 53 48 83 EC 40 48 89 51 08 48 8B D9 48 8D 54 24 20 E8 59 02 00 00 48 8B 4B 08 48 8D 54 24 20
    __int64 __fastcall SetRuntimeScene(RED4ext::world::RuntimeScene *);

    DynArray<Handle<IScriptable>> * gameSystems;
    world::RuntimeScene* runtimeSystems;
    Handle<game::GameFeatureManager> featureManager;
    uint8_t unk20;
    uint8_t unk21;
    uint8_t unk22;
    uint8_t unk23;
    uint8_t unk24;
    uint8_t unk25;
    uint8_t unk26;
    uint8_t unk27;
    // retrieved from userSettings
    uint64_t gameplay_perfomance;
    uint64_t graphics_raytracing;
};

struct GameSystemData
{
  CName name;
  bool inPreview;
  bool inSingleplayer;
  bool onClient;
  bool onServer;
};

// void game::GameSystemsSetup::LoadConfigFile(void)
/// @hash 2463305925
DynArray<GameSystemData> *__fastcall GetGameSystemsData(DynArray<GameSystemData> *gameSystemsData);

// 1.52 RVA: 0x2D028E0 / 47196384
// loads gameSystems from base\systems\game_systems_startup.csv
/// @pattern 40 55 48 8D 6C 24 A9 48 81 EC B0 00 00 00 4C 89 B4 24 98 00 00 00 4C 8B F1 48 8D 0D 40 7C 02 02
void __fastcall LoadGameSystemsData(DynArray<GameSystemData> *rcx0);

struct GameInstance : IGameInstance
{
    // static constexpr const uintptr_t VFT = 0x35FC738;

    virtual ~GameInstance() override;                                      // 00
    // creates some systems, calls systems' sub_190, sub198
    // calls GetGameSystemsData
    // job::Counter CreateSystems(game::InstanceInitInfo const &)
    virtual void CreateSystems(uint8_t*, uint64_t, uint32_t*) override;           // 20
    // calls parent func, then sets unk130 & unk138 from the struct the runtimeInfo is in
    virtual bool RegisterUpdates(world::RuntimeInfo **runtimeInfo) override;                // 28
    virtual void* GetUnk130() override;                               // 30
    virtual void* GetUnk138() override;                               // 38
    // Registers callbacks: SaveGame/PreSaveSystems, SaveGame/SaveSystems
    virtual void SaveGame(uint64_t, uint64_t, uint64_t) override;          // 40
    virtual void SomethingAutoSave_sub_1B8(uint64_t) override;             // 48
    virtual void SomethingAutoSave_sub_1C0() override;                     // 50
    // no longer exists
    // virtual void Unk_68() = 0;                                     // 68

    // 1.52 RVA: 0x2D494B0 / 47486128
    /// @pattern 40 53 48 83 EC 20 48 8B D9 E8 42 5B FB FF 48 8D 05 73 32 8B 00 48 89 03 33 C0 48 89 83 30 01 00
    GameInstance();

    // 1.52 RVA: 0x2CFF590 / 47183248
    // called from LoadGame callback, calls systems->sub_118
    /// @pattern 48 89 5C 24 08 48 89 74 24 10 57 48 83 EC 20 48 8B F9 48 89 51 78 48 8B 89 10 01 00 00 48 8B F2
    __int64 __fastcall SetRuntimeScene(world::RuntimeScene *);

    /**
     * @brief calls systems->sub_190 & sub_198
     * @address 0x2CFF600
     * @param unkThing is some sort of logging struct
     * @param a3 is a flag that gets passed to sub_60
     * @pattern 4C 89 44 24 18 48 89 54 24 10 48 89 4C 24 08 55 53 56 57 41 54 41 55 41 56 41 57 48 8D 6C 24 E1
    */
    __int64 *__fastcall Setup(void **unkThing, uint8_t *a3);

    HashMap<CBaseRTTIType*, Handle<IScriptable>> systemMap;        // 08 - Maps implementation type to instance
    DynArray<Handle<IScriptable>> systemInstances;                 // 38
    HashMap<CBaseRTTIType*, CBaseRTTIType*> systemImplementations; // 48 - Maps interface type to implementation type
    //uintptr_t unk78[(0x138 - 0x78) >> 3];                          // 78

    world::RuntimeScene * runtimeScene; // 78
    world::RuntimeInfo runtimeInfo; // 80
    // 0x100: 0x415643FF7B
    int64_t unk100;
    IGameInstance* self; // 108
    UpdatableSystems* updatableSystems; // 110
    Handle<game::GameFeatureManager> gameFeatureManager; // 118
    bool gameIsLoading; // 128
    uint8_t isPaused;
    uint8_t unk12A[6];
    // actual GameInstance starts here
    int64_t unk130; // 130
    int64_t unk138; // 138
};
RED4EXT_ASSERT_SIZE(GameInstance, 0x140);
}
