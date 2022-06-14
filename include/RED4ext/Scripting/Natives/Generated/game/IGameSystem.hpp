#pragma once

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/IScriptable.hpp>
#include <RED4ext/Addresses.hpp>

namespace RED4ext
{
namespace game { 
struct IGameSystem : IScriptable
{
    static constexpr const char* NAME = "gameIGameSystem";
    static constexpr const char* ALIAS = "IGameSystem";

    virtual void* RegisterUpdate(uintptr_t lookup); // 110 registerTick? / Update
    virtual bool sub_118(void *); // 108 onAttach
    virtual bool sub_120(); // 120 onDetach
    virtual void sub_128(); // 128 Setup
    virtual void sub_130(); // 130
    virtual void sub_138(); // AK::MemoryMgr::StopProfileThreadUsage(void)
    virtual void sub_140(); // 140
    virtual void sub_148(); // 148
    virtual void sub_150(); // 150
    virtual uint64_t sub_158(); // 158 ReturnOne
    virtual void sub_160(); // 160
    virtual void sub_168(); // 168
    virtual void sub_170(); // 170
    virtual uintptr_t sub_178(uintptr_t a1, uintptr_t a2); // 178 - sub_7FF6FA8EC940                      
    virtual void sub_180(); // 180
    virtual void sub_188(); // 188
    virtual void sub_190(); // 190
    virtual void sub_198(); // 198 LoadFromTweakDB
    virtual void sub_1A0(); // 1A0

    uint8_t unk40[0x48 - 0x40]; // 40
};
RED4EXT_ASSERT_SIZE(IGameSystem, 0x48);
} // namespace game
using IGameSystem = game::IGameSystem;
} // namespace RED4ext

#ifdef RED4EXT_HEADER_ONLY
#include <RED4ext/Scripting/Natives/Generated/game/IGameSystem-inl.hpp>
#endif
