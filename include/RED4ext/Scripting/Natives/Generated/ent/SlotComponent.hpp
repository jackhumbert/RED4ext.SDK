#pragma once

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/DynArray.hpp>
#include <RED4ext/Scripting/Natives/Generated/ent/FallbackSlot.hpp>
#include <RED4ext/Scripting/Natives/Generated/ent/IPlacedComponent.hpp>
#include <RED4ext/Scripting/Natives/Generated/ent/Slot.hpp>

namespace RED4ext
{
namespace ent { 
struct SlotComponent : ent::IPlacedComponent
{
    static constexpr const char* NAME = "entSlotComponent";
    static constexpr const char* ALIAS = "SlotComponent";

    DynArray<ent::Slot> slots; // 120
    DynArray<ent::FallbackSlot> fallbackSlots; // 130
    DynArray<uintptr_t> unk140;
    HashMap<CName, uint64_t> slotIndexLookup;
    uint64_t unk180;
    uint64_t unk188;
    uintptr_t unk190;
    uint8_t unk198;
    uint8_t unk199[7];
};
RED4EXT_ASSERT_SIZE(SlotComponent, 0x1A0);
} // namespace ent
using SlotComponent = ent::SlotComponent;
} // namespace RED4ext
