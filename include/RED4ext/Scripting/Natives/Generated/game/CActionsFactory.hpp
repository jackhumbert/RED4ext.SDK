#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/IActionsFactory.hpp>
#include <RED4ext/Scripting/Natives/actionActionBase.hpp>

namespace RED4ext
{
namespace action { struct ActionBase; }
namespace game { 

using CreateAction_t = action::ActionBase *(__fastcall *)(__int64, uint32_t *, unsigned int);

struct CActionsFactory : game::IActionsFactory
{
    static constexpr const char* NAME = "gameCActionsFactory";
    static constexpr const char* ALIAS = NAME;

    virtual bool sub_1A8();
    // creates an action of type
    virtual action::ActionBase* sub_1B0(action::Type type);
    // moves to cleanup
    virtual action::ActionBase* sub_1B8(action::ActionBase* action);

    // 1.52 RVA: 0x2941C10 / 43260944
    /// @pattern 4C 89 44 24 18 48 83 EC 48 4C 8D 91 A0 02 00 00 44 0F B7 CA 41 83 7A 08 00 74 4B 33 D2 41 8B C1
    void __fastcall AddActionTypeManual(action::Type type_1, CreateAction_t func);

    action::ActionBase *unk48;
    SharedSpinLock actionIdMUTX;
    action::ActionBase *actionCleanup[70];
    uint64_t unk288;
    uint64_t unk290;
    uint32_t numActionsCleanup;
    uint32_t unk29C;
    HashMap<uint64_t, uint64_t> actions;
    uint32_t totalSize;
    uint32_t unk2D4;
    uint8_t unk2D8[0x2F8 - 0x2D8]; // 2D8
};
RED4EXT_ASSERT_SIZE(CActionsFactory, 0x2F8);
} // namespace game
using gameCActionsFactory = game::CActionsFactory;
} // namespace RED4ext

// clang-format on
