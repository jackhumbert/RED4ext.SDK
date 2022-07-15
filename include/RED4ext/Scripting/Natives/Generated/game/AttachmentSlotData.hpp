#pragma once

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Handle.hpp>
#include <RED4ext/NativeTypes.hpp>

namespace RED4ext
{
namespace game {     
struct ItemObject;
namespace data { struct AttachmentSlot_Record; }
struct AttachmentSlotData
{
    static constexpr const char* NAME = "gameAttachmentSlotData";
    static constexpr const char* ALIAS = "AttachmentSlotData";

    TweakDBID slotID; // 00
    Handle<game::ItemObject> itemObject; // 08
    uint8_t unk18[0x28 - 0x18]; // 18
    ItemID activeItemID; // 28
    ItemID prevItemID; // 38
    uint64_t unk48[2];
    Handle<data::AttachmentSlot_Record> record;
    uint64_t unk68;
    DynArray<void*> unk70;
};
RED4EXT_ASSERT_SIZE(AttachmentSlotData, 0x80);
} // namespace game
using AttachmentSlotData = game::AttachmentSlotData;
} // namespace RED4ext
