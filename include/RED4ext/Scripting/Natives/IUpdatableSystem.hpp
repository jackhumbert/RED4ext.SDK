#pragma once

#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/IScriptable.hpp>

namespace RED4ext
{
struct UpdateRegistrar;

struct IUpdatableSystem : IScriptable
{
    static constexpr const char* NAME = "IUpdatableSystem";
    static constexpr const char* ALIAS = NAME;

    // static constexpr const uintptr_t VFT = IUpdatableSystem_VFT_Addr;

    // virtual CClass* GetNativeType() override;
    virtual ~IUpdatableSystem() override = default;

    // 1.52 RVA: 0xA86060 / 11034720
    /// @pattern 0F B6 C1 83 F8 0C 77 7B 48 8D 15 91 9F 57 FF 8B 8C 82 EC 60 A8 00 48 03 CA FF E1 48 8D 05 46 18
    // static const char *__fastcall GetStringForUnk0(Unk0);

    // sub_108 - adds callbacks to the lookup - there are at least 10 dynarrays
    virtual void OnRegisterUpdates(UpdateRegistrar* aRegistrar);
};
RED4EXT_ASSERT_SIZE(IUpdatableSystem, 0x40);

} // namespace RED4ext

#ifdef RED4EXT_HEADER_ONLY
#include <RED4ext/Scripting/Natives/IUpdatableSystem-inl.hpp>
#endif
