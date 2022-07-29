#pragma once

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/DynArray.hpp>
#include <RED4ext/NativeTypes.hpp>
#include <RED4ext/Scripting/Natives/Generated/ent/ForcedLodDistance.hpp>
#include <RED4ext/Scripting/Natives/Generated/ent/IComponent.hpp>
#include <RED4ext/Scripting/Natives/Generated/ent/VisualControllerDependency.hpp>

namespace RED4ext
{
struct CMesh;
namespace appearance { struct CookedAppearanceData; }

namespace ent { 
struct VisualControllerComponent : ent::IComponent
{
    static constexpr const char* NAME = "entVisualControllerComponent";
    static constexpr const char* ALIAS = NAME;

    // 1.52 RVA: 0x1178AF0 / 18320112
    /// @pattern 88 91 F4 00 00 00 C3
    void __fastcall Set0xF4(char);

    // 1.52 RVA: 0x94B2B0 / 9745072
    /// @pattern 48 8D 81 A8 00 00 00 C3
    DynArray<VisualControllerDependency> *__fastcall GetAppearanceDependency();

    // 1.52 RVA: 0x11789B0 / 18319792
    /// @pattern 48 89 6C 24 18 56 57 41 56 48 83 EC 30 4C 8B F2 41 0F B6 E9 41 0F B6 D0 48 8B F9 E8 90 1B 00 00
    void __fastcall Unknown(__int64 a2, char a3, char a4);

    // 1.52 RVA: 0x117A560 / 18326880
    /// @pattern 48 8B C4 55 56 41 56 41 57 48 8D 68 A1 48 81 EC B8 00 00 00 48 83 B9 D8 00 00 00 00 44 0F B6 FA
    void __fastcall LoadUnkD8(char a2);

    Ref<CMesh> meshProxy; // 90
    DynArray<ent::VisualControllerDependency> appearanceDependency; // A8
    RaRef<appearance::CookedAppearanceData> cookedAppearanceData; // B8
    uint8_t unkC0[0xC8 - 0xC0]; // C0
    DynArray<ResourcePath> resourcePaths; // C8
    Handle<void> unkD8;
    uint64_t unkE8; // E8
    ent::ForcedLodDistance forcedLodDistance; // F0
    uint8_t unkF1[3];
    uint8_t unkF4;
    uint8_t unkF5; // flags?
    uint8_t unkF6[50];
};
RED4EXT_ASSERT_SIZE(VisualControllerComponent, 0x128);
} // namespace ent
} // namespace RED4ext
