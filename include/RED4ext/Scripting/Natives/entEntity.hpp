#pragma once

// This file is generated by Jack

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/Vector2.hpp>
#include <RED4ext/Scripting/IScriptable.hpp>
#include <RED4ext/Scripting/Natives/Generated/ECustomCameraTarget.hpp>
#include <RED4ext/Scripting/Natives/Generated/RenderSceneLayerMask.hpp>
#include <RED4ext/Scripting/Natives/entComponentsStorage.hpp>
//#include <RED4ext/Scripting/Natives/Generated/ent/PlaceholderComponent.hpp>
#include <RED4ext/Scripting/Natives/entEntityDefinition.hpp>
#include <RED4ext/Scripting/Natives/ScriptGameInstance.hpp>
#include <RED4ext/ResourcePath.hpp>
#include <RED4ext/GameEngine.hpp>
#include <RED4ext/Scripting/Natives/Callbacks.hpp>
#include <RED4ext/Scripting/Natives/Generated/red/Taglist.hpp>

namespace RED4ext
{
namespace ent
{
//struct ComponentsStorage;
//struct PlaceholderComponent;
struct Entity : IScriptable
{
    static constexpr const char* NAME = "entEntity";
    static constexpr const char* ALIAS = "Entity";
    static constexpr const uintptr_t VFT_RVA = entEntity_VFT_RVA;
    
    virtual void __fastcall sub_110() { }
    virtual float __fastcall sub_118();
    virtual Vector2* __fastcall sub_120(Vector2* a1, Vector2* a2);
    virtual void __fastcall sub_128();
    virtual bool __fastcall sub_130();
    virtual void sub_138();

    // called when components are loaded
    virtual void __fastcall sub_140(Handle<void>*, int16_t*) { };
    virtual void __fastcall sub_148(uintptr_t) { };
    virtual void __fastcall sub_150() { };
    virtual void __fastcall Attach(void *) { };
    virtual uintptr_t __fastcall Detach() { };
    virtual void __fastcall sub_168(uint16_t) { };
    virtual void __fastcall sub_170() { };
    virtual uintptr_t __fastcall sub_178();

    // GatherEventListeners maybe
    virtual void __fastcall sub_180(Handle<CallbackManager>*) { };
    virtual void __fastcall OnRequestComponents(char *) { };
    virtual void __fastcall sub_190() { };
    virtual void __fastcall sub_198() { };
    virtual void __fastcall sub_1A0() { };
    virtual uintptr_t __fastcall CopyComponentsToStorage(EntityDefinition * definition, void * a2);
    virtual RED4ext::CClass* __fastcall sub_1B0();
    virtual void __fastcall sub_1B8();
    virtual CString* __fastcall sub_1C0(CString*); // Get "<UNKNOWN>"

    /// @pattern 48 89 5C 24 08 57 48 81 EC 00 01 00 00 48 8B 02 48 8B FA 48 89 41 60 48 8B D9 48 8B 42 08 48 89
    uint64_t SetupEntityAndComponents(EntityDefinition* definition);

    // 1.52 RVA: 0x1030DA0 / 16977312
    /// @pattern 40 55 53 56 57 41 54 41 55 41 56 41 57 48 8D 6C 24 88 48 81 EC 78 01 00 00 4C 8B EA 49 8B D9 48
    void __fastcall ReassembleAppearance(__int64 rdx0, uint64_t a3, uint64_t unk58, DynArray<Handle<IComponent>> *components, Handle<IComponent> *end);

    // 1.52 RVA: 0x1031BF0 / 16980976
    /// @pattern 48 89 5C 24 18 48 89 74 24 20 57 48 83 EC 20 80 A1 5C 01 00 00 F9 48 8B F1 48 83 C1 70 E8 6E 5D
    // char __fastcall SetAnimatedVisualComponentFlags();

    // 1.52 RVA: 0x103B3F0 / 17019888
    /// @pattern 40 55 53 57 48 8D 6C 24 B9 48 81 EC B0 00 00 00 48 83 C1 70 E8 77 C5 3F FF 48 8B 18 8B 78 0C 48
    // void __fastcall ProcessIPlacedComponents();

    // 1.52 RVA: 0x1037B30 / 17005360
    /// @pattern 40 56 48 83 EC 50 48 89 5C 24 68 48 8B F1 48 89 7C 24 48 48 8B DA 8B BA 00 01 00 00 48 C1 E7 04
    __int64 __fastcall SomethingListeners(Handle<IScriptable> *a2);

    // 1.52 RVA: 0x1035260 / 16994912
    /// @pattern 48 89 5C 24 08 57 48 83 EC 30 48 8B 02 48 8B D9 48 89 44 24 20 48 8D 4C 24 20 48 8B 42 08 48 8B
    // void __fastcall SomethingListeners2(Handle<IScriptable> *a2);

    // 1.52 RVA: 0x1035300 / 16995072
    /// @pattern 48 83 C1 70 E9 77 26 40 FF
    // DynArray<Handle<IComponent>> *__fastcall GetComponents();

    enum Flags : uint8_t {
        Unk1 = 0x1,
        hasAnimatedComponent = 0x2,
        hasVisualControllerComponent = 0x4
    };

    uint32_t unk40;
    uint32_t unk44;
    uint64_t tweakRecord;
    CName currentAppearance;
    uint64_t unk58;
    ResourcePath resource; // 60
    uint64_t unk68;
    ComponentsStorage componentsStorage; // 70
    void* placeholder; // B0
    void* runtime; // B8
    ScriptGameInstance* scriptGameInstance; // C0
    Handle<void> unkC8;
    CallbackManager callbackManager; // D8
    red::TagList entityTags; // 138
    void * unk148;
    float updatingTransform;
    uint8_t customCameraTarget;
    uint8_t unk155;
    uint8_t entityStoredSeparatelyMode;
    uint8_t unk157;
    uint16_t unk158;
    uint8_t unk15A;
    uint8_t renderSceneLayerMask;
    Flags flags;
    uint8_t unk15D;
    uint8_t unk15E;
    uint8_t unk15F;
};
RED4EXT_ASSERT_OFFSET(Entity, tweakRecord, 0x48);
RED4EXT_ASSERT_OFFSET(Entity, currentAppearance, 0x50);
RED4EXT_ASSERT_OFFSET(Entity, entityTags, 0x138);
} // namespace ent
} // namespace RED4ext

#ifdef RED4EXT_HEADER_ONLY
#include <RED4ext/Scripting/Natives/entEntity-inc.hpp>
#endif
