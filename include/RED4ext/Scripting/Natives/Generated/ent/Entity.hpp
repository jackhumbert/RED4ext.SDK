#pragma once

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/Vector2.hpp>
#include <RED4ext/Scripting/IScriptable.hpp>
#include <RED4ext/Scripting/Natives/Generated/ECustomCameraTarget.hpp>
#include <RED4ext/Scripting/Natives/Generated/RenderSceneLayerMask.hpp>
#include <RED4ext/Scripting/Natives/Generated/ent/ComponentsStorage.hpp>
//#include <RED4ext/Scripting/Natives/Generated/ent/PlaceholderComponent.hpp>
#include <RED4ext/Scripting/Natives/Generated/ent/EntityDefinition.hpp>
#include <RED4ext/ResourcePath.hpp>

//#define RELOC_VFUNC(vft_offset, retType, name, args) virtual retType name(args) { \
//    auto call = reinterpret_cast<retType (*)(args)>(*(uintptr_t*)(VFT_RVA + vft_offset + RelocBase::GetImageBase())); \
//    return call(); }
//
//#define RELOC_FUNC(vft_offset, retType, name, ...) retType name(__VA_ARGS__)  \
//    {                                                                         \
//        RelocFunc<decltype(&name)> call(vft_offset);                          \
//        return (this->*call)(__VA_ARGS__);                                    \
//    }

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
    static constexpr const uintptr_t VFT_RVA = 0x329FC30;
    
    virtual void __fastcall sub_110() { }
    virtual float __fastcall sub_118();
    virtual Vector2 * __fastcall sub_120(Vector2 * a1, Vector2 * a2) {
        a1->X = a2->Y;
        a1->Y = a2->X * a2->Y;
        return a1;
    }
    virtual void __fastcall sub_128();
    virtual bool __fastcall sub_130() {
        return this->flags & Flags::Unk1;
    }
    //virtual void __fastcall sub_138() { };

    //RELOC_VFUNC(0x138, void, sub_138, void);

    /// @pattern 48 89 5C 24 08 57 48 81 EC 00 01 00 00 48 8B 02 48 8B FA 48 89 41 60 48 8B D9 48 8B 42 08 48 89
    //RELOC_FUNC(16977024, uint64_t, SetupEntityAndComponents, RED4ext::ent::EntityDefinition* definition);


    virtual void sub_138()
    {
        RelocVirtualFunc<decltype(&Entity::sub_138)> call(VFT_RVA, 0x138);
        return (this->*call)();
    }

    // called when components are loaded
    virtual void __fastcall sub_140(Handle<void*>*, int16_t*) { };
    virtual void __fastcall sub_148(uintptr_t) { };
    virtual void __fastcall sub_150() { };
    virtual void __fastcall Attach() { };
    virtual uintptr_t __fastcall Detach() { };
    virtual void __fastcall sub_168() { };
    virtual void __fastcall sub_170() { };
    virtual uintptr_t __fastcall sub_178();

    // GatherEventListeners maybe
    virtual void __fastcall sub_180() { };
    virtual void __fastcall OnRequestComponents(char *) { };
    virtual void __fastcall sub_190() { };
    virtual void __fastcall sub_198() { };
    virtual void __fastcall sub_1A0() { };
    virtual uintptr_t __fastcall CopyComponentsToStorage(EntityDefinition * definition, void * a2);
    virtual RED4ext::CClass* __fastcall sub_1B0();
    virtual void __fastcall sub_1B8();
    virtual CString* __fastcall sub_1C0(CString*); // Get "<UNKNOWN>"

    /// @pattern 48 89 5C 24 08 57 48 81 EC 00 01 00 00 48 8B 02 48 8B FA 48 89 41 60 48 8B D9 48 8B 42 08 48 89
    uint64_t SetupEntityAndComponents(EntityDefinition* definition)
    {
        RelocFunc<decltype(&Entity::SetupEntityAndComponents)> call(16977024);
        return call(this, definition);
        //return std::invoke(&call, this, definition);
    }

    // 1.52 RVA: 0x1031BF0 / 16980976
    /// @pattern 48 89 5C 24 18 48 89 74 24 20 57 48 83 EC 20 80 A1 5C 01 00 00 F9 48 8B F1 48 83 C1 70 E8 6E 5D
    char __fastcall SetAnimatedVisualComponentFlags();

    // 1.52 RVA: 0x103B3F0 / 17019888
    /// @pattern 40 55 53 57 48 8D 6C 24 B9 48 81 EC B0 00 00 00 48 83 C1 70 E8 77 C5 3F FF 48 8B 18 8B 78 0C 48
    void __fastcall ProcessIPlacedComponents();

    // not sure these are part of the vft
    //virtual void __fastcall sub_1C8(); // Deconstruct something
    //virtual void __fastcall sub_1D0(); // Ref thing
    //virtual void __fastcall sub_1D8();


    //uint8_t unk40[0x154 - 0x40]; // 40
    //ECustomCameraTarget customCameraTarget; // 154
    //uint8_t unk155[0x15B - 0x155]; // 155
    //RenderSceneLayerMask renderSceneLayerMask; // 15B
    //uint8_t unk15C[0x160 - 0x15C]; // 15C
    
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
    ResourcePath resource;
    uint64_t unk68;
    ComponentsStorage componentsStorage;
    void* placeholder;
    void* runtime;
    GameInstance** gameInstance_p;
    Handle<void> unkC8;
    void* eventList;
    uint64_t unkE0;
    void* eventList2;
    uint64_t unkF0;
    DynArray<void*> unkF8;
    void* unk108;
    DynArray<void*> unk110;
    void * unk120;
    void * unk128;
    void * unk130;
    DynArray<void*> effects;
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
RED4EXT_ASSERT_SIZE(Entity, 0x160);
} // namespace ent
using Entity = ent::Entity;
} // namespace RED4ext
