#pragma once

// This file is generated from the Game's Reflection data
// More data added by Jack

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/DynArray.hpp>
#include <RED4ext/Scripting/Natives/Generated/ent/IComponent.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/AnimParamSlotsOption.hpp>

namespace RED4ext
{
namespace game {
struct TransactionSystem;
struct IAttachmentSlotsListener;
struct AttachmentSlotData;
namespace weapon
{
struct Object;
}
struct AttachmentSlots : ent::IComponent
{
    static constexpr const char* NAME = "gameAttachmentSlots";
    static constexpr const char* ALIAS = NAME;

    Handle<weapon::Object> itemObject;
    uint64_t parentHashId;
    TransactionSystem* transactionSystem;
    DynArray<AttachmentSlotData> data;
    DynArray<Handle<IAttachmentSlotsListener>> unkC0;
    DynArray<void*> unkD0;
    DynArray<AnimParamSlotsOption> animParams;
    DynArray<void*> unkF0;
    SharedMutex unk100;
    uint8_t padding[7];
    uint64_t unk108[2];
};
RED4EXT_ASSERT_SIZE(AttachmentSlots, 0x118);
} // namespace game
} // namespace RED4ext
