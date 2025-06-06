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

    virtual CBaseRTTIType* GetNativeType() = 0;      // 00
    virtual CBaseRTTIType* GetParentType() = 0;      // 08
    virtual Memory::IAllocator* GetAllocator() = 0;  // 10
    virtual ~CBaseEngine() = 0;                      // 18
    // checks unkF8 against 5, 4
    virtual void sub_20() = 0;
    // checks unkF8 against 4, 5
    virtual void sub_28() = 0;
    // something with SystemMenuPause CName
    virtual void sub_30() = 0;
    virtual void Terminate(int32_t aExitStatus) = 0;
    // increment unk44, etc
    virtual void sub_40() = 0;
    // decrement unk44, etc
    virtual void sub_48() = 0;                       // 48
    // call sub_D0, various prop things
    virtual void sub_50() = 0;
    virtual void sub_58() = 0;                       // 58
    virtual void sub_60() = 0;                       // 60
    // create unk98
    virtual void sub_68() = 0;
    virtual void sub_70() = 0;                       // 70
    virtual void sub_78() = 0;                       // 78
    virtual void sub_80() = 0;                       // 80
    virtual void sub_88(uint64_t a2, char a3) = 0;    // 88
    virtual void sub_90(int a2, CString *a3, uint64_t a4) = 0; // 90
    virtual void sub_98() = 0;                       // 98
    virtual void sub_A0() = 0;                       // A0
    virtual void sub_A8() = 0;                       // A8
    virtual void sub_B0() = 0;                       // B0
    // uses CBaseEngine string
    virtual void TakeScreenshot(const rend::SingleScreenShotData& acData, bool a2 = false) = 0; // B8
    virtual void sub_C0() = 0;                       // C0
    virtual void sub_C8(CGameOptions& aOptions) = 0; // C8
    virtual void sub_D0() = 0;                       // D0
    // Load everything
    virtual void sub_D8(int64_t a2) = 0;
    // register some Initialization callbacks: GameServicesAsync
    // Physics, LoadRenderResources, Recorder, Animation, DebugServer
    // DebugNetwork, Finialization
    virtual void sub_E0(uint64_t a2, uint64_t a3, uint64_t a4) = 0;                       // E0
    virtual void sub_E8() = 0;                       // E8
    virtual void sub_F0() = 0;                       // F0
    virtual void sub_F8() = 0;                       // F8
    // doesn't actually exist, start of an interface
    // virtual void sub_100() = 0;                      // 100

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
    int64_t unk68;                             // 68
    CString scriptsCompilationErrors;          // 70
    DynArray<CString> scriptsValidationErrors; // 90
    int64_t unkA0;                             // A0
    audio::Thing* audioThing;                  // A8
    int64_t unkB0;                             // B0
    int64_t unkB8;                             // B8
    uint8_t padC0[0x10];                       // C0
    UnkD0* unkD0;                              // D0
    double unkD8;                              // D8
    double unkE0;                              // E0
    int32_t unkE8;                             // E8
    int64_t unkF0;                             // F0
    int64_t unkF8;                             // F8
    int64_t unk100;                            // 100
    volatile EEngineState engineState;         // 108
    int32_t unk10C;                            // 10C
    int32_t unk110;                            // 110
    Unk108* unk118;                            // 118
    Unk110 unk120;                             // 120
    CString buildString;                       // 130
    CString scriptsBlobPath;                   // 150
    int32_t unk170;                            // 170
    int8_t unk174;                             // 174
    int64_t unk178;                            // 178
    int64_t unk180;                            // 180
    int64_t unk188;                            // 188
    int64_t unk190;                            // 190
    int8_t unk198[178];                        // 198
    int32_t unk24C;                            // 24C
    int8_t unk250[64];                         // 250
    DynArray<void*> unk290;                    // 290
    DynArray<void*> unk2A0;                    // 2A0
    int64_t unk2B0;                            // 2B0
    int64_t unk2B8;                            // 2B8
    int64_t unk2C0;                            // 2C0
    int64_t unk2C8;                            // 2C8
    int32_t unk2D0;                            // 2D0
    bool isEP1;                                // 2D4 - IsEP1()
    int64_t unk2D8;                            // 2D8
    int64_t unk2E0;                            // 2E0
};
RED4EXT_ASSERT_SIZE(CBaseEngine, 0x2D8);
RED4EXT_ASSERT_OFFSET(CBaseEngine, scriptsLoaded, 0x54);
RED4EXT_ASSERT_OFFSET(CBaseEngine, unkD0, 0xD0);
RED4EXT_ASSERT_OFFSET(CBaseEngine, scriptsValidationErrors, 0x90);
RED4EXT_ASSERT_OFFSET(CBaseEngine, scriptsBlobPath, 0x150);
RED4EXT_ASSERT_OFFSET(CBaseEngine, isEP1, 0x2D4);

struct BaseGameEngine : CBaseEngine
{
    // static constexpr const uintptr_t VFT = 0x3374328;

    virtual CBaseRTTIType* GetNativeType() override;      // 00
    virtual CBaseRTTIType* GetParentType() override;      // 08
    virtual ~BaseGameEngine() override;                   // 18
    virtual void sub_50() override;
    virtual void sub_60() override;
    virtual void sub_D8(int64_t a2) override;
    // register Initialization callbacks: BaseInitialization, VirtualRUIDs
    // LoadTweakDB, Blackboard, EnumerateWorlds, PSClassBindings
    virtual void sub_E0(uint64_t a2, uint64_t a3, uint64_t a4) override;

    int64_t unk2D8;          // 2D8
};
RED4EXT_ASSERT_SIZE(BaseGameEngine, 0x2E0);
// RED4EXT_ASSERT_OFFSET(BaseGameEngine, watchdogThread, 0x2D8);

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

    virtual CBaseRTTIType* GetNativeType() override;      // 00
    virtual CBaseRTTIType* GetParentType() override;      // 08
    virtual ~CGameEngine() override;                      // 18
    virtual void sub_20() override;
    virtual void sub_28() override;
    virtual void sub_50() override;
    // gets unk318
    virtual void sub_78() override;
    // gets unk328
    virtual void sub_80() override;
    // something with unk308
    virtual void sub_88(uint64_t a2, char a3) override;
    // more with unk308
    virtual void sub_90(int a2, CString *a3, uint64_t a4) override;
    // more unk308
    virtual void sub_98() override;
    // creates game services (servicesGameServicesWin)
    virtual void sub_C0() override;    
    // something unk300
    virtual void sub_D0() override;
    // initializes sound, input & viewport
    virtual void sub_D8(int64_t a2) override;
    // register Initialization callbacks: BaseEngineRegularSystemInitialization
    // FreeCamera, RegisterNativeFunctions, ScriptsDebugger, GameFramework
    // EnumerateGameDefs, InkSystem
    virtual void sub_E0(uint64_t a2, uint64_t a3, uint64_t a4) override;
    // do nothing with unk308
    virtual void sub_E8() override;

    static CGameEngine* Get();

    // 1.52 RVA: 0x29919A0 / 43588000
    /// @pattern 48 89 5C 24 10 57 48 83 EC 20 48 8B F9 0F B6 4A 32 E8 5A 66 22 00 48 8B 87 C0 00 00 00 8B 10 85
    // static void __fastcall InitializeScriptsDebugger(uint64_t *a1, uint64_t a2);

    // 1.52 RVA: 0x2991B50 / 43588432
    /// @pattern 48 89 5C 24 18 48 89 6C 24 20 56 48 83 EC 60 48 8B F1 48 8B DA 0F B6 4A 32 E8 A2 64 22 00 48 8B
    // static void __fastcall InitializeGameFramework(uint64_t * a1, uint64_t a2);

    int64_t unk2E0;            // 2E0
    int64_t unk2E8;            // 2E8
    int64_t unk2F0;            // 2F0
    int64_t unk2F8;            // 2F8
    int32_t unk300;            // 300
    int32_t unk304;            // 304
    CGameFramework* framework; // 308
    services::GameServices* gameServices; // 310
    int64_t unk318;            // 318
    int64_t unk320;            // 320
    int64_t unk328;            // 328
    int64_t unk330;            // 330
    Unk338 * unk338;           // 338
    int32_t unk340;            // 340
    int64_t unk348;            // 348

};
RED4EXT_ASSERT_SIZE(CGameEngine, 0x350);
RED4EXT_ASSERT_OFFSET(CGameEngine, framework, 0x308);
} // namespace RED4ext

#ifdef RED4EXT_HEADER_ONLY
#include <RED4ext/GameEngine-inl.hpp>
#endif
