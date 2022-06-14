#pragma once

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/IScriptable.hpp>
#include <RED4ext/Scripting/Natives/Generated/ECustomCameraTarget.hpp>
#include <RED4ext/Scripting/Natives/Generated/RenderSceneLayerMask.hpp>

namespace RED4ext
{
namespace ent {
struct IComponent;
struct Entity : IScriptable
{
    static constexpr const char* NAME = "entEntity";
    static constexpr const char* ALIAS = "Entity";

    //uint8_t unk40[0x154 - 0x40]; // 40
    //ECustomCameraTarget customCameraTarget; // 154
    //uint8_t unk155[0x15B - 0x155]; // 155
    //RenderSceneLayerMask renderSceneLayerMask; // 15B
    //uint8_t unk15C[0x160 - 0x15C]; // 15C
    
    uint32_t unk40;
    uint32_t unk44;
    uint64_t tweakRecord;
    uint64_t unk48[4];
    void* componentStorage;
    void* unk78[4];
    uint64_t unk98;
    DynArray<Handle<ent::IComponent>> components;
    Handle<ent::Entity> parent;
    void* unkC0;
    uint64_t unkC8[2];
    void* eventList;
    uint64_t unkE0;
    void* eventList2;
    uint64_t unkF0;
    DynArray<void*> unkF8;
    void* unk108;
    DynArray<void*> unk110;
    DynArray<void*> unk120;
    uint64_t unk118;
    uint32_t unk138;
    uint32_t unk13C;
    DynArray<void*> effects;
    float unk150;
    uint8_t customCameraTarget;
    uint8_t unk155;
    uint8_t entityStoredSeparatelyMode;
    uint8_t unk157;
    uint8_t unk158;
    uint8_t unk159;
    uint8_t unk15A;
    uint8_t renderSceneLayerMask;
    uint8_t unk15C[4];
};
RED4EXT_ASSERT_SIZE(Entity, 0x160);
} // namespace ent
using Entity = ent::Entity;
} // namespace RED4ext
