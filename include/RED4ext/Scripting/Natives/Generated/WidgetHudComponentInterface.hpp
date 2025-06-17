#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Handle.hpp>
#include <RED4ext/NativeTypes.hpp>
#include <RED4ext/Scripting/Natives/Generated/WidgetBaseComponent.hpp>
#include <RED4ext/Scripting/Natives/Generated/ink/Widget.hpp>

namespace RED4ext
{
struct CMaterialTemplate;
namespace ink { struct HudEntriesResource; }
namespace world::ui { struct MeshTargetBinding; }

struct __declspec(align(0x10)) WidgetHudComponentInterface : WidgetBaseComponent
{
    struct Widget
    {
        CName name;
        uint64_t unk00[28];
        ink::Widget* inkWidget;
        uint64_t unkF0;
        uint64_t gameController;
        uint64_t unk100;
        uint64_t unk108;
        uint64_t unk110;
        uint64_t unk118;
    };
    RED4EXT_ASSERT_SIZE(Widget, 0x120);


    static constexpr const char* NAME = "WidgetHudComponentInterface";
    static constexpr const char* ALIAS = NAME;
    static constexpr const uint32_t VFT = 4101049622;

    // something with world::ui::IWidgetGameControllerType
    virtual void * sub_258(void *) override;

    // 1.52 RVA: 0x1354150 / 20267344
    /// @pattern 48 89 5C 24 10 57 48 83 EC 20 48 8B F9 E8 CE E9 FF FF 48 8D 05 C7 CC FA 01 48 8D 8F A0 01 00 00
    WidgetHudComponentInterface();

    // 1.52 RVA: 0x1354360 / 20267872
    /// @pattern 48 89 5C 24 10 57 48 83 EC 20 48 8D 05 BF CA FA 01 48 8B D9 48 89 01 48 81 C1 D8 01 00 00 E8 BD
    ~WidgetHudComponentInterface();

    Ref<CMaterialTemplate> externalMaterial; // 1A0
    Handle<world::ui::MeshTargetBinding> meshTargetBinding; // 1B8
    DynArray<Widget> widgets; // 1C8
    Ref<ink::HudEntriesResource> hudEntriesResource; // 1D8
};
RED4EXT_ASSERT_SIZE(WidgetHudComponentInterface, 0x1F0);
} // namespace RED4ext

// clang-format on
