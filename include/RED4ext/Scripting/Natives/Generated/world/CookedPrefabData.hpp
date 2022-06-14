#pragma once

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/DynArray.hpp>
#include <RED4ext/NativeTypes.hpp>
#include <RED4ext/Scripting/Natives/Generated/CResource.hpp>

namespace RED4ext
{
struct CResource;

namespace world { 
struct CookedPrefabData : CResource
{
    static constexpr const char* NAME = "worldCookedPrefabData";
    static constexpr const char* ALIAS = NAME;

    DynArray<RaRef<CResource>> precookedDependencies; // 40
    DynArray<Ref<CResource>> dependencies; // 50
    DynArray<void*> unk60; // 60
};
RED4EXT_ASSERT_SIZE(CookedPrefabData, 0x70);
} // namespace world
} // namespace RED4ext
