#pragma once

#ifdef RED4EXT_STATIC_LIB
#include <RED4ext/Scripting/Natives/Generated/game/IGameSystem.hpp>
#endif

#include <RED4ext/Addresses.hpp>
#include <RED4ext/Relocation.hpp>

RED4EXT_INLINE void* RED4ext::game::IGameSystem::RegisterUpdate(uintptr_t lookup) { // 110 - registerTick?
    return 0;
}

RED4EXT_INLINE bool RED4ext::game::IGameSystem::sub_118(void * a1) // 118 onAttach
{
    return true;
}

RED4EXT_INLINE bool RED4ext::game::IGameSystem::sub_120() // 120
{
    return true;
}

RED4EXT_INLINE void RED4ext::game::IGameSystem::sub_128() // 128
{
}

RED4EXT_INLINE void RED4ext::game::IGameSystem::sub_130() // 130
{
}

RED4EXT_INLINE void RED4ext::game::IGameSystem::sub_138() // AK::MemoryMgr::StopProfileThreadUsage
{
}
 
RED4EXT_INLINE void RED4ext::game::IGameSystem::sub_140() // 140
{
}

RED4EXT_INLINE void RED4ext::game::IGameSystem::sub_148() // 148
{
}

RED4EXT_INLINE void RED4ext::game::IGameSystem::sub_150() // 150
{
}

RED4EXT_INLINE uint64_t RED4ext::game::IGameSystem::sub_158() // 158 ReturnOne
{ 
    return 1;
}
RED4EXT_INLINE void RED4ext::game::IGameSystem::sub_160() // 160
{
}

RED4EXT_INLINE void RED4ext::game::IGameSystem::sub_168() // 168
{
}

RED4EXT_INLINE void RED4ext::game::IGameSystem::sub_170() // 170
{
}

RED4EXT_INLINE uintptr_t RED4ext::game::IGameSystem::sub_178(uintptr_t a1, uintptr_t a2) // 178 - sub_7FF6FA8EC940
{
    a2 = 0;
    reinterpret_cast<RED4ext::CString* (*)(RED4ext::CString*)>(RED4ext::Addresses::CString_Initialize)(
        (RED4ext::CString*)(a2 + 8));
    return a2;
}
RED4EXT_INLINE void RED4ext::game::IGameSystem::sub_180() // 180
{
}

RED4EXT_INLINE void RED4ext::game::IGameSystem::sub_188() // 188
{
}

RED4EXT_INLINE void RED4ext::game::IGameSystem::sub_190() // 190
{
}

RED4EXT_INLINE void RED4ext::game::IGameSystem::sub_198() // 198
{
}

RED4EXT_INLINE void RED4ext::game::IGameSystem::sub_1A0() // 1A0
{
}
 
