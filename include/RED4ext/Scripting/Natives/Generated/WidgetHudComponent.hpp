#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/WidgetHudComponentInterface.hpp>

namespace RED4ext
{

namespace ent { struct Entity; }
namespace cp { struct PlayerSystem; }

struct WidgetHudComponent_Interface
{
    // static constexpr const uintptr_t VFT = 0x35559B8;

    virtual void WHCI_sub_00();
    virtual void WHCI_sub_08();
    // set thing in some system E0
    virtual void WHCI_sub_10(ent::Entity*);
    // unset thing
    virtual void WHCI_sub_18(ent::Entity*);
    virtual void WHCI_sub_20();
    virtual void WHCI_sub_28();

    Handle<cp::PlayerSystem> playerSystem;
    uint32_t unk208;
    uint32_t unk20C;
};

struct __declspec(align(0x10)) WidgetHudComponent : WidgetHudComponentInterface, WidgetHudComponent_Interface
{
    static constexpr const char* NAME = "WidgetHudComponent";
    static constexpr const char* ALIAS = NAME;
    static constexpr const uint32_t VFT = 1246893262;
};
RED4EXT_ASSERT_SIZE(WidgetHudComponent, 0x210);
} // namespace RED4ext

// clang-format on
