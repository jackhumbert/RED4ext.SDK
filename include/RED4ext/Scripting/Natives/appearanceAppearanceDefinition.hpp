#pragma once

#include <RED4ext/CName.hpp>
#include <RED4ext/Common.hpp>
#include <RED4ext/DynArray.hpp>
#include <RED4ext/ISerializable.hpp>
#include <RED4ext/NativeTypes.hpp>
#include <RED4ext/Package.hpp>
#include <RED4ext/Scripting/Natives/Generated/appearance/AppearancePart.hpp>
#include <RED4ext/Scripting/Natives/Generated/appearance/AppearancePartOverrides.hpp>
#include <RED4ext/Scripting/Natives/Generated/ent/EntityParametersBuffer.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/HitRepresentationOverride.hpp>
#include <RED4ext/Scripting/Natives/Generated/red/TagList.hpp>

namespace RED4ext
{
struct CMesh;
struct CResource;

namespace appearance
{
struct AppearanceDefinition : ISerializable
{
    static constexpr const char* NAME = "appearanceAppearanceDefinition";
    static constexpr const char* ALIAS = NAME;
    static constexpr const uintptr_t VFT = appearanceAppearanceDefinition_VFT_Addr;

    // 1.52 RVA: 0xFDDF20 / 16637728
    /// @pattern 48 89 5C 24 10 48 89 74 24 18 57 48 83 EC 20 48 8B F9 E8 09 D3 1C FF 48 8D 05 FA 46 2B 02 33 F6
    AppearanceDefinition();

    CName name;                                                           // 30
    CName parentAppearance;                                               // 38
    DynArray<DynArray<CName>> partsMasks;                                 // 40
    DynArray<appearance::AppearancePart> partsValues;                     // 50
    RaRef<CMesh> proxyMesh;                                               // 60
    CName proxyMeshAppearance;                                            // 68
    RaRef<CResource> cookedDataPathOverride;                              // 70
    DynArray<appearance::AppearancePartOverrides> partsOverrides;         // 78
    red::TagList visualTags;                                              // 88
    red::TagList inheritedVisualTags;                                     // 98
    DynArray<game::HitRepresentationOverride> hitRepresentationOverrides; // A8
    ent::EntityParametersBuffer parametersBuffer;                         // B8
    uint32_t censorFlags;                                                 // E0
    uint8_t forcedLodDistance;                                            // E4
    uint8_t unkE5[0xF0 - 0xE5];                                           // E5
    DeferredDataBuffer compiledData;                                      // F0
    ObjectPackageHeader compiledDataHeader;                               // 148
    DynArray<RaRef<CResource>> resolvedDependencies;                      // 1B8
    DynArray<RaRef<CResource>> looseDependencies;                         // 1C8
};
RED4EXT_ASSERT_SIZE(AppearanceDefinition, 0x1D8);
} // namespace appearance
} // namespace RED4ext
