#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/DynArray.hpp>
#include <RED4ext/Scripting/Natives/Generated/Transform.hpp>
#include <RED4ext/Scripting/Natives/Generated/ent/FallbackSlot.hpp>
#include <RED4ext/Scripting/Natives/Generated/ent/IPlacedComponent.hpp>
#include <RED4ext/Scripting/Natives/Generated/ent/Slot.hpp>

namespace RED4ext
{
namespace ent
{
struct __declspec(align(0x10)) SlotComponent : ent::IPlacedComponent, IHookable
{
    static constexpr const char* NAME = "entSlotComponent";
    static constexpr const char* ALIAS = "SlotComponent";
    
    static constexpr const uint32_t VFT = 2108229929;

    // creates ent::SlotAttachment
    virtual Handle<ent::ITransformAttachment>* CreateTransformAttachment(Handle<ent::ITransformAttachment>* aAttachment, 
                                                                         CName name,
                                                                         Handle<void>* aDestination) override;

    // 2.0 scripts
    /// @pattern 48 89 5C 24 08 48 89 74 24 10 57 48 83 EC 20 49 8B F0 48 8B F9 E8 A6 52 6A FF 83 F8 FF 74 28 4C
    bool GetSlotTransform(CName slotName, WorldTransform *worldTransform);

    // 1.6 RVA: 0x115CEA0 / 18206368
    /// @pattern 48 89 5C 24 10 48 89 6C 24 18 56 48 83 EC 20 49 8B F0 48 8B D9 85 D2 0F 88 80 00 00 00 3B 91 2C
    // bool __fastcall GetSlotGlobalTransform(int slotIndex, WorldTransform *transform);

    // 1.6 RVA: 0x115C4C0 / 18203840
    /// @pattern 40 57 48 83 EC 20 83 B9 58 01 00 00 00 49 8B F8 4C 8B CA 4C 8B D1 74 53 4C 8B DA 33 D2 49 C1 EB
    bool __fastcall GetSlotGlobalTransform(CName slotName, WorldTransform *worldTransform);

    // 1.52 RVA: 0x115C370 / 18203504
    /// @pattern 83 B9 58 01 00 00 00 4C 8B C2 4C 8B D1 74 4D 4C 8B DA 33 D2 49 C1 EB 20 45 33 D8 41 8B C3 F7 B1
    /// @nth 0/2

    /// @hash 688524786
    __int64 GetSlotIndex(CName slotName) {
        return Hook<__int64, 688524786>(slotName);
    }

    // 1.6 RVA: 0x115CAC0 / 18205376
    /// @pattern 48 89 5C 24 10 48 89 74 24 18 57 48 83 EC 20 49 8B D9 49 8B F8 48 8B F1 85 D2 78 72 3B 91 2C 01
    bool __fastcall GetSlotLocalTransform(int slotIndex, WorldTransform *offset, WorldTransform *transform);

    /// @hash 2420184407
    bool GetLocalSlotTransformFromIndex(int slotIndex, Transform *transform) {
        return Hook<bool, 2420184407>(slotIndex, transform);
    }

    struct Unk140 {
        Handle<IComponent> unk00;
        WorldTransform unk10;
    };

    DynArray<ent::Slot> slots; // 120
    DynArray<ent::FallbackSlot> fallbackSlots; // 130
    // 0x28 big
    DynArray<Unk140> unk140;
    HashMap<CName, int32_t> slotIndexLookup;
    uint64_t animatedComponent;
    uint64_t unk188;
    uintptr_t unk190;
    uint8_t unk198;
    uint8_t unk199[7];
};
RED4EXT_ASSERT_SIZE(SlotComponent, 0x1A0);
RED4EXT_ASSERT_OFFSET(SlotComponent, slots, 0x120);
} // namespace ent
using entSlotComponent = ent::SlotComponent;
using SlotComponent = ent::SlotComponent;
} // namespace RED4ext

// clang-format on
