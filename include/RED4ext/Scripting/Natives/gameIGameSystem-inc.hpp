#pragma once

#ifdef RED4EXT_STATIC_LIB
#include <RED4ext/Scripting/Natives/gameIGameSystem.hpp>
#endif

namespace RED4ext
{
namespace game
{

inline CClass* IGameSystem::GetNativeType()
{
    RelocVirtualFunc<decltype(&IGameSystem::GetNativeType)> call(VFT_RVA, 0x000);
    return (this->*call)();
}

inline bool IGameSystem::sub_118(void * a1)
{
    RelocVirtualFunc<decltype(&IGameSystem::sub_118)> call(VFT_RVA, 0x118);
    return (this->*call)(a1);
}

inline bool IGameSystem::sub_120()
{
    RelocVirtualFunc<decltype(&IGameSystem::sub_120)> call(VFT_RVA, 0x120);
    return (this->*call)();
}

inline void IGameSystem::sub_128()
{
    RelocVirtualFunc<decltype(&IGameSystem::sub_128)> call(VFT_RVA, 0x128);
    return (this->*call)();
}

inline void IGameSystem::sub_130()
{
    RelocVirtualFunc<decltype(&IGameSystem::sub_130)> call(VFT_RVA, 0x130);
    return (this->*call)();
}

inline void IGameSystem::sub_138()
{
    RelocVirtualFunc<decltype(&IGameSystem::sub_138)> call(VFT_RVA, 0x138);
    return (this->*call)();
}

inline void IGameSystem::sub_140()
{
    RelocVirtualFunc<decltype(&IGameSystem::sub_140)> call(VFT_RVA, 0x140);
    return (this->*call)();
}

inline void IGameSystem::sub_148()
{
    RelocVirtualFunc<decltype(&IGameSystem::sub_148)> call(VFT_RVA, 0x148);
    return (this->*call)();
}

inline void IGameSystem::sub_150()
{
    RelocVirtualFunc<decltype(&IGameSystem::sub_150)> call(VFT_RVA, 0x150);
    return (this->*call)();
}

inline uint64_t IGameSystem::sub_158()
{
    RelocVirtualFunc<decltype(&IGameSystem::sub_158)> call(VFT_RVA, 0x158);
    return (this->*call)();
}

inline void IGameSystem::sub_160()
{
    RelocVirtualFunc<decltype(&IGameSystem::sub_160)> call(VFT_RVA, 0x160);
    return (this->*call)();
}

inline void IGameSystem::sub_168()
{
    RelocVirtualFunc<decltype(&IGameSystem::sub_168)> call(VFT_RVA, 0x168);
    return (this->*call)();
}

inline void IGameSystem::sub_170()
{
    RelocVirtualFunc<decltype(&IGameSystem::sub_170)> call(VFT_RVA, 0x170);
    return (this->*call)();
}

inline uintptr_t IGameSystem::sub_178(uintptr_t a1)
{
    RelocVirtualFunc<decltype(&IGameSystem::sub_178)> call(VFT_RVA, 0x178);
    return (this->*call)(a1);
}

inline void IGameSystem::sub_180()
{
    RelocVirtualFunc<decltype(&IGameSystem::sub_180)> call(VFT_RVA, 0x180);
    return (this->*call)();
}

inline void IGameSystem::sub_188()
{
    RelocVirtualFunc<decltype(&IGameSystem::sub_188)> call(VFT_RVA, 0x188);
    return (this->*call)();
}

inline void IGameSystem::sub_190(IGameSystem::HighLow * hl)
{
    RelocVirtualFunc<decltype(&IGameSystem::sub_190)> call(VFT_RVA, 0x190);
    return (this->*call)(hl);
}

inline void IGameSystem::sub_198(void * a1)
{
    RelocVirtualFunc<decltype(&IGameSystem::sub_198)> call(VFT_RVA, 0x198);
    return (this->*call)(a1);
}

inline void IGameSystem::sub_1A0()
{
    RelocVirtualFunc<decltype(&IGameSystem::sub_1A0)> call(VFT_RVA, 0x1A0);
    return (this->*call)();
}

} // namespace game
} // namespace RED4ext
