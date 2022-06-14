#pragma once

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/DynArray.hpp>
#include <RED4ext/NativeTypes.hpp>
#include <RED4ext/Scripting/Natives/Generated/CResource.hpp>
#include <RED4ext/Scripting/Natives/Generated/world/StreamingSectorCategory.hpp>
#include <RED4ext/Scripting/Natives/Generated/world/CompiledSector.hpp>

namespace RED4ext
{
struct CResource;
namespace world { struct StreamingSectorInplaceContent; }

namespace world { 
struct StreamingSector : CResource
{
    static constexpr const char* NAME = "worldStreamingSector";
    static constexpr const char* ALIAS = NAME;

    CompiledSector compiledData; // 0x40
    DynArray<Ref<CResource>> localInplaceResource; // A0
    DynArray<void*> unkB0; // B0
    RaRef<world::StreamingSectorInplaceContent> externInplaceResource; // C0
    Handle<world::PrefabVariantsList> variants; // C8
    uint8_t level; // D8
    world::StreamingSectorCategory category; // D9
    uint8_t unkDA[0xE0 - 0xDA]; // DA
};
RED4EXT_ASSERT_SIZE(StreamingSector, 0xE0);
} // namespace world
} // namespace RED4ext
