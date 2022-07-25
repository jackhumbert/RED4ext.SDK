#pragma once

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/IScriptable.hpp>
#include <RED4ext/Scripting/Natives/Generated/ECustomCameraTarget.hpp>
#include <RED4ext/Scripting/Natives/Generated/RenderSceneLayerMask.hpp>

namespace RED4ext
{
namespace ent
{
struct IComponent;
struct PlaceholderComponent;
struct Entity : IScriptable
{
    static constexpr const char* NAME = "entEntity";
    static constexpr const char* ALIAS = "Entity";
    
    virtual void __fastcall sub_110() { }
    virtual float __fastcall sub_118();
    virtual uintptr_t __fastcall sub_120(uintptr_t, uintptr_t);
    virtual void __fastcall sub_128();
    virtual bool __fastcall sub_130();
    virtual void __fastcall sub_138() { };
    virtual void __fastcall sub_140() { };
    virtual void __fastcall sub_148() { };
    virtual void __fastcall sub_150() { };
    virtual void __fastcall sub_158() { };
    virtual void __fastcall sub_160() { };
    virtual void __fastcall sub_168() { };
    virtual void __fastcall sub_170() { };
    virtual uintptr_t __fastcall sub_178();
    virtual void __fastcall sub_180() { };
    virtual void __fastcall OnRequestComponents() { };
    virtual void __fastcall sub_190() { };
    virtual void __fastcall sub_198() { };
    virtual void __fastcall sub_1A0() { };
    virtual uintptr_t __fastcall CopyComponentsToStorage(void * definition, void * a2);
    virtual RED4ext::CClass* __fastcall sub_1B0();
    virtual void __fastcall sub_1B8();
    virtual CString* __fastcall sub_1C0(CString*); // Get "<UNKNOWN>"

    // not sure these are part of the vft
    //virtual void __fastcall sub_1C8(); // Deconstruct something
    //virtual void __fastcall sub_1D0(); // Ref thing
    //virtual void __fastcall sub_1D8();


    //uint8_t unk40[0x154 - 0x40]; // 40
    //ECustomCameraTarget customCameraTarget; // 154
    //uint8_t unk155[0x15B - 0x155]; // 155
    //RenderSceneLayerMask renderSceneLayerMask; // 15B
    //uint8_t unk15C[0x160 - 0x15C]; // 15C
    
    uint32_t unk40;
    uint32_t unk44;
    uint64_t tweakRecord;
    CName currentAppearance;
    uint64_t unk58;
    uint64_t unk60;
    uint64_t unk68;
    void* componentStorage;
    void* unk78[4];
    uint64_t unk98;
    DynArray<Handle<ent::IComponent>> components;
    PlaceholderComponent* placeholder;
    void* runtime;
    void* gameInstance;
    uint64_t unkC8[2];
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
    uint8_t unk158;
    uint8_t unk159;
    uint8_t unk15A;
    uint8_t renderSceneLayerMask;
    uint8_t unk15C;
    uint8_t unk15D;
    uint8_t unk15E;
    uint8_t unk15F;
};
RED4EXT_ASSERT_SIZE(Entity, 0x160);
} // namespace ent
using Entity = ent::Entity;
} // namespace RED4ext
