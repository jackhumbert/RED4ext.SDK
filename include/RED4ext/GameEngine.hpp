#pragma once

#include <cstdint>

#include <RED4ext/CString.hpp>
#include <RED4ext/Common.hpp>
#include <RED4ext/DynArray.hpp>
#include <RED4ext/Handle.hpp>
#include <RED4ext/HashMap.hpp>
#include <RED4ext/Scripting/Natives/Generated/rend/SingleScreenShotData.hpp>
#include <RED4ext/Scripting/Natives/Generated/services/GameServices.hpp>

namespace RED4ext
{
struct CBaseRTTIType;
struct IScriptable;
struct CGameOptions;
struct IGameInstance;

namespace Memory
{
struct IAllocator;
}
//namespace game { struct IGameSystem; struct GameFeatureManager; }
namespace world { struct RuntimeScene;  } //struct RuntimeInfo;
namespace audio { struct Thing; }

enum class EEngineState : int32_t
{
    Idle = 0,
    BaseInitialization = 1,
    Initialization = 2,
    Running = 3
};

// struct GameInstance
// {
//     virtual ~GameInstance() = 0;                                    // 00
//     virtual IScriptable* GetSystem(const CBaseRTTIType* aType) = 0; // 08
//     virtual void Unk_10() = 0;                                      // 10
//     virtual void Unk_18() = 0;                                      // 18
//     virtual void Unk_20() = 0;                                      // 20
//     virtual void Unk_28() = 0;                                      // 28
//     virtual void Unk_30() = 0;                                      // 30
//     virtual void Unk_38() = 0;                                      // 38
//     virtual void Unk_40() = 0;                                      // 40
//     virtual void Unk_48() = 0;                                      // 48
//     virtual void Unk_50() = 0;                                      // 50
//     virtual void Unk_58() = 0;                                      // 58
//     virtual void Unk_60() = 0;                                      // 60
//     virtual void Unk_68() = 0;                                      // 68

//     HashMap<CBaseRTTIType*, Handle<IScriptable>> systemMap;        // 08 - Maps implementation type to instance
//     DynArray<Handle<IScriptable>> systemInstances;                 // 38
//     HashMap<CBaseRTTIType*, CBaseRTTIType*> systemImplementations; // 48 - Maps interface type to implementation type
//     uintptr_t unk78[(0x138 - 0x78) >> 3];                          // 78
// };
// RED4EXT_ASSERT_SIZE(GameInstance, 0x138);

struct CBaseEngine
{
    // static constexpr const uintptr_t VFT = 0x31A27D8;

    // https://github.com/yamashi/RED4ext/commit/2d30f32826276458f86da8b4c26940924044564d
    struct UnkD0
    {
        uint8_t pad0[0x140];
        uint32_t unk140;
        uint8_t pad144[0x164 - 0x144];
        uint32_t unk164;
        uint8_t pad158[0x164 - 0x158];
        uint32_t unk174;
        void* hWnd;
        uint8_t pad180[0x9];
        uint8_t isClipped;
    };
    RED4EXT_ASSERT_OFFSET(UnkD0, unk164, 0x164);
    RED4EXT_ASSERT_OFFSET(UnkD0, unk174, 0x174);
    RED4EXT_ASSERT_OFFSET(UnkD0, hWnd, 0x178);
    RED4EXT_ASSERT_OFFSET(UnkD0, isClipped, 0x189);

    struct Unk108
    {
        // static constexpr const uintptr_t VFT = 0x31A2920;

        int64_t unk0;
        int64_t unk8;
        int64_t unk10;
        int32_t unk18;
        int32_t unk1C;
    };
    RED4EXT_ASSERT_SIZE(Unk108, 0x20);

    struct Unk110
    {
        int8_t unk0;
        int32_t unk4;
        int32_t unk8;
        int32_t unkC;
    };
    RED4EXT_ASSERT_SIZE(Unk110, 0x10);

    // 2.5 inserted 4 slots before Terminate (was 38) and 1 more before TakeScreenshot (was B8).
    // Notes from 2.31 on sub_40..sub_B0 are kept on CGameEngine with their old offsets; the
    // exact position of the 5th inserted slot is unknown, so those haven't been re-placed.
    virtual CBaseRTTIType* GetNativeType() = 0;     // 00
    virtual CBaseRTTIType* GetParentType() = 0;     // 08
    virtual Memory::IAllocator* GetAllocator() = 0; // 10
    virtual ~CBaseEngine() = 0;                     // 18
    // 2.31: checks unkF8 against 5, 4
    virtual void sub_20() = 0;                      // 20
    // 2.31: checks unkF8 against 4, 5
    virtual void sub_28() = 0;                      // 28
    // 2.31: something with SystemMenuPause CName
    virtual void sub_30() = 0;                      // 30
    virtual void sub_38() = 0;                      // 38
    virtual void sub_40() = 0;                      // 40
    virtual void sub_48() = 0;                      // 48
    virtual void sub_50() = 0;                      // 50
    virtual void Terminate(int32_t aExitStatus) = 0; // 58
    virtual void sub_60() = 0;                      // 60
    virtual void sub_68() = 0;                      // 68
    virtual void sub_70() = 0;                      // 70
    virtual void sub_78() = 0;                      // 78
    virtual void sub_80() = 0;                      // 80
    virtual void sub_88() = 0;                      // 88
    virtual void sub_90() = 0;                      // 90
    virtual void sub_98() = 0;                      // 98
    virtual void sub_A0() = 0;                      // A0
    virtual void sub_A8() = 0;                      // A8
    virtual void sub_B0() = 0;                      // B0
    virtual void sub_B8() = 0;                      // B8
    virtual void sub_C0() = 0;                      // C0
    virtual void sub_C8() = 0;                      // C8
    virtual void sub_D0() = 0;                      // D0
    virtual void sub_D8() = 0;                      // D8
    // uses CBaseEngine string
    virtual void TakeScreenshot(const rend::SingleScreenShotData& acData, bool a2 = false) = 0; // E0 (2.31: B8)
    virtual void sub_E8() = 0;                       // E8 (2.31: C0)
    virtual void sub_F0(CGameOptions& aOptions) = 0; // F0 (2.31: C8)
    virtual void sub_F8() = 0;                       // F8 (2.31: D0)
    // Load everything
    virtual void sub_100(int64_t a2) = 0;            // 100 (2.31: D8)
    // register some Initialization callbacks: GameServicesAsync
    // Physics, LoadRenderResources, Recorder, Animation, DebugServer
    // DebugNetwork, Finialization
    virtual void sub_108(uint64_t a2, uint64_t a3, uint64_t a4) = 0; // 108 (2.31: E0)
    virtual void sub_110() = 0;                      // 110 (2.31: E8)
    virtual void sub_118() = 0;                      // 118 (2.31: F0)
    virtual void sub_120() = 0;                      // 120 (2.31: F8)
    // doesn't actually exist, start of an interface
    // virtual void sub_128() = 0;                   // 128 (2.31: 100)

    double unk8;                               // 08
    float unk10;                               // 10
    float unk14;                               // 14
    float unk18;                               // 18
    float unk1C;                               // 1C
    float unk20;                               // 20
    int64_t unk28;                             // 28
    int32_t unk30;                             // 30
    int8_t unk34;                              // 34
    uint64_t scriptsTimestamp;                 // 38
    int8_t unk40;                              // 40
    SharedSpinLock terminationLock;            // 41
    int32_t unk44;                             // 44
    int8_t terminating;                        // 48
    int8_t unk49;                              // 49
    int8_t unk4A;                              // 4A
    int8_t unk4B;                              // 4B
    int32_t exitStatus;                        // 4C
    int32_t unk50;                             // 50
    bool scriptsLoaded;                        // 54
    bool scriptsSilentCompilation;             // 55
    bool scriptsSilentValidation;              // 56
    int8_t unk57;                              // 57
    int8_t unk58;                              // 58
    int16_t unk5A;                             // 5A
    int32_t interopStartingPort;               // 5C
    int64_t unk60;                             // 60
    DynArray<void*> unk68;                     // 68 - DynArray<red::AbsolutePath>, script mod blobs (-LoadScriptMods)
    int64_t unk78;                             // 78
    int64_t unk80;                             // 80
    int64_t unk88;                             // 88
    CString scriptsCompilationErrors;          // 90
    DynArray<CString> scriptsValidationErrors; // B0
    int64_t unkA0;                             // C0
    audio::Thing* audioThing;                  // C8
    int64_t unkB0;                             // D0
    int64_t unkB8;                             // D8
    uint8_t padC0[0x10];                       // E0
    UnkD0* unkD0;                              // F0
    double unkD8;                              // F8
    double unkE0;                              // 100
    int32_t unkE8;                             // 108
    int64_t unkF0;                             // 110
    int64_t unkF8;                             // 118
    int64_t unk100;                            // 120
    volatile EEngineState engineState;         // 128
    int32_t unk10C;                            // 12C
    int32_t unk110;                            // 130
    Unk108* unk118;                            // 138
    Unk110 unk120;                             // 140
    CString buildString;                       // 150
    CString scriptsBlobPath;                   // 170
    int32_t unk170;                            // 190
    int8_t unk174;                             // 194
    int64_t unk178;                            // 198
    int64_t unk180;                            // 1A0
    int64_t unk188;                            // 1A8
    int64_t unk190;                            // 1B0
    int8_t unk198[178];                        // 1B8
    int32_t unk24C;                            // 26C
    int8_t unk250[64];                         // 270
    DynArray<void*> unk290;                    // 2B0
    DynArray<void*> unk2A0;                    // 2C0
    int64_t unk2B0;                            // 2D0
    int64_t unk2B8;                            // 2D8
    int64_t unk2C0;                            // 2E0
    int64_t unk2C8;                            // 2E8
    int32_t unk2D0;                            // 2F0
    bool isEP1;                                // 2F4 - IsEP1()
    CString unk2F8Path;                        // 2F8 - red::AbsolutePath
    int64_t unk2D8;                            // 318
    int64_t unk2E0;                            // 320
};
RED4EXT_ASSERT_SIZE(CBaseEngine, 0x328);
RED4EXT_ASSERT_OFFSET(CBaseEngine, scriptsLoaded, 0x54);
RED4EXT_ASSERT_OFFSET(CBaseEngine, scriptsCompilationErrors, 0x90);
RED4EXT_ASSERT_OFFSET(CBaseEngine, scriptsValidationErrors, 0xB0);
RED4EXT_ASSERT_OFFSET(CBaseEngine, unkD0, 0xF0);
RED4EXT_ASSERT_OFFSET(CBaseEngine, engineState, 0x128);
RED4EXT_ASSERT_OFFSET(CBaseEngine, scriptsBlobPath, 0x170);
RED4EXT_ASSERT_OFFSET(CBaseEngine, isEP1, 0x2F4);

struct BaseGameEngine : CBaseEngine
{
    // static constexpr const uintptr_t VFT = 0x3374328;

    virtual CBaseRTTIType* GetNativeType() override; // 00
    virtual CBaseRTTIType* GetParentType() override; // 08
    virtual ~BaseGameEngine() override;              // 18
    // 2.31 also overrode sub_50 and sub_60; their 2.5 slots are unknown
    virtual void sub_100(int64_t a2) override;       // 100 (2.31: D8)
    // register Initialization callbacks: BaseInitialization, VirtualRUIDs
    // LoadTweakDB, Blackboard, EnumerateWorlds, PSClassBindings
    virtual void sub_108(uint64_t a2, uint64_t a3, uint64_t a4) override; // 108 (2.31: E0)

    int64_t unk2E8; // 328
};
RED4EXT_ASSERT_SIZE(BaseGameEngine, 0x330);

struct CGameFramework
{
    // static constexpr const uintptr_t VFT = 0x3599FE8;

    virtual Memory::IAllocator* GetAllocator();
    virtual void Destruct(char);
    virtual void sub_10();

    // 1.52 RVA: 0x138AF20 / 20492064
    /// @pattern 48 8B 49 10 48 85 C9 0F 85 33 58 97 01 C3
    // void __fastcall Systems168o170(bool a2);

    // 1.52 RVA: 0x138B060 / 20492384
    // then call engine->sub_80, sets stateMachine to 4?
    /// @pattern 48 89 5C 24 08 57 48 83 EC 20 33 C0 48 8B F9 87 41 24 48 8B 59 10 48 85 DB 0F 84 17 01 00 00 E8
    uint64_t __fastcall Systems_120_128_130();

    void* updateManagerHolder; // 08
    IGameInstance* gameInstance; // 10
    world::RuntimeScene* runtimeScene; // 18
    void* stateMachine; // 20
};
RED4EXT_ASSERT_SIZE(CGameFramework, 0x28);
RED4EXT_ASSERT_OFFSET(CGameFramework, gameInstance, 0x10);

struct Unk338
{
    // static constexpr const uintptr_t VFT = 0x3599380;

    virtual void sub_00();
    virtual void sub_08();
    virtual void sub_10();
    virtual void sub_18();
    virtual void sub_20();
    virtual void sub_28();
    virtual void sub_30();
    virtual void sub_38();
    virtual void sub_40();
    virtual void sub_48();
    virtual ~Unk338() = default;

    uint64_t unk08;
    uint64_t unk10;
    uint64_t unk18;
    uint64_t unk20;
    uint64_t unk28;
    uint64_t unk30;
    uint8_t unk38;
    uint8_t unk39;
    uint8_t unk3A;
    uint8_t unk3B;
    float unk3C;
    uint8_t unk40;
    uint8_t unk41;
    uint8_t unk42;
    uint8_t unk43;
    uint8_t unk44;
    uint8_t unk45;
    uint8_t unk46;
    uint8_t unk47;
    uint8_t unk48;
    uint8_t unk49;
    uint8_t unk4A;
    uint8_t unk4B;
    uint8_t unk4C;
    uint8_t unk4D;
    uint8_t unk4E;
    uint8_t unk4F;
    uint64_t unk50[4];
};
RED4EXT_ASSERT_SIZE(Unk338, 0x70);

struct CGameEngine : BaseGameEngine
{
    // static constexpr const uintptr_t VFT = 0x3591C30;

    virtual CBaseRTTIType* GetNativeType() override; // 00
    virtual CBaseRTTIType* GetParentType() override; // 08
    virtual ~CGameEngine() override;                 // 18
    virtual void sub_20() override;
    virtual void sub_28() override;
    // 2.31 notes on overrides in the sub_40..sub_B0 range, which shifted by 0x20 or 0x28 in 2.5:
    //   sub_50: (no notes)
    //   sub_78: gets unk318
    //   sub_80: gets unk328
    //   sub_88(uint64_t a2, char a3): something with unk308
    //   sub_90(int a2, CString* a3, uint64_t a4): more with unk308
    //   sub_98: more unk308
    // creates game services (servicesGameServicesWin)
    virtual void sub_E8() override;                  // E8 (2.31: C0)
    // something unk300
    virtual void sub_F8() override;                  // F8 (2.31: D0)
    // initializes sound, input & viewport
    virtual void sub_100(int64_t a2) override;       // 100 (2.31: D8)
    // register Initialization callbacks: BaseEngineRegularSystemInitialization
    // FreeCamera, RegisterNativeFunctions, ScriptsDebugger, GameFramework
    // EnumerateGameDefs, InkSystem
    virtual void sub_108(uint64_t a2, uint64_t a3, uint64_t a4) override; // 108 (2.31: E0)
    // do nothing with unk308
    virtual void sub_110() override;                 // 110 (2.31: E8)

    static CGameEngine* Get();

    // 1.52 RVA: 0x29919A0 / 43588000
    /// @pattern 48 89 5C 24 10 57 48 83 EC 20 48 8B F9 0F B6 4A 32 E8 5A 66 22 00 48 8B 87 C0 00 00 00 8B 10 85
    // static void __fastcall InitializeScriptsDebugger(uint64_t *a1, uint64_t a2);

    // 1.52 RVA: 0x2991B50 / 43588432
    /// @pattern 48 89 5C 24 18 48 89 6C 24 20 56 48 83 EC 60 48 8B F1 48 8B DA 0F B6 4A 32 E8 A2 64 22 00 48 8B
    // static void __fastcall InitializeGameFramework(uint64_t * a1, uint64_t a2);

    int64_t unk2F0;                       // 330
    int64_t unk2F8;                       // 338
    int32_t unk300;                       // 340
    int32_t unk304;                       // 344
    CGameFramework* framework;            // 348
    services::GameServices* gameServices; // 350
    int64_t unk318;                       // 358
    int64_t unk320;                       // 360
    int64_t unk328;                       // 368
    int64_t unk330;                       // 370
    int64_t unk338;                       // 378
    int32_t unk340;                       // 380
    int64_t unk348;                       // 388
};
RED4EXT_ASSERT_SIZE(CGameEngine, 0x390);
RED4EXT_ASSERT_OFFSET(CGameEngine, framework, 0x348);
} // namespace RED4ext

#ifdef RED4EXT_HEADER_ONLY
#include <RED4ext/GameEngine-inl.hpp>
#endif
