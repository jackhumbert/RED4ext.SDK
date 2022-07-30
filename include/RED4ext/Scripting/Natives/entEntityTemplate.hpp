#pragma once

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/CName.hpp>
#include <RED4ext/DynArray.hpp>
#include <RED4ext/Handle.hpp>
#include <RED4ext/NativeTypes.hpp>
#include <RED4ext/Scripting/Natives/Generated/ent/TemplateAppearance.hpp>
#include <RED4ext/Scripting/Natives/Generated/ent/TemplateBindingOverride.hpp>
#include <RED4ext/Scripting/Natives/Generated/ent/TemplateComponentBackendDataOverrideInfo.hpp>
#include <RED4ext/Scripting/Natives/Generated/ent/TemplateComponentResolveSettings.hpp>
#include <RED4ext/Scripting/Natives/Generated/ent/TemplateInclude.hpp>
#include <RED4ext/Scripting/Natives/Generated/res/StreamedResource.hpp>

namespace RED4ext
{
struct CResource;
namespace ent { struct VisualTagsSchema; }

namespace ent { 
struct EntityTemplate : res::StreamedResource
{
    static constexpr const char* NAME = "entEntityTemplate";
    static constexpr const char* ALIAS = NAME;
    static constexpr const uintptr_t VFT_RVA = 0x32A2E58;

    virtual void sub_20(Handle<ISerializable>*) override;

    // read from redpackage, maybe
    virtual void sub_28() override;

    DynArray<ent::TemplateInclude> includes; // 40
    DynArray<ent::TemplateAppearance> appearances; // 50
    CName defaultAppearance; // 60
    DynArray<ent::TemplateComponentResolveSettings> componentResolveSettings; // 68
    DynArray<ent::TemplateBindingOverride> bindingOverrides; // 78
    DynArray<ent::TemplateComponentBackendDataOverrideInfo> backendDataOverrides; // 88
    Handle<ent::VisualTagsSchema> visualTagsSchema; // 98
    uint8_t unkA8[0x118 - 0xA8]; // A8
    DataBuffer localData; // 118
    uint8_t unk140[0x1B0 - 0x140]; // 140
    DataBuffer includeInstanceBuffer; // 1B0
    uint64_t unk1D8;
    void * version;
    void * unk1E8;
    uint32_t unk1F0;
    uint32_t unk1F4;
    void * unk1F8[5];
    void * name;
    void * unk228;
    void * dependencyNames;
    void * unk238;
    uint64_t datasize;
    DataBuffer compiledData; // 248
    DynArray<RaRef<CResource>> resolvedDependencies; // 270
    DynArray<Ref<CResource>> inplaceResources; // 280
    uint8_t unk290[0x2A0 - 0x290]; // 290
    uint16_t compiledEntityLODFlags; // 2A0
    uint8_t unk2A2[0x2B0 - 0x2A2]; // 2A2
};
RED4EXT_ASSERT_SIZE(EntityTemplate, 0x2B0);
} // namespace ent
} // namespace RED4ext
