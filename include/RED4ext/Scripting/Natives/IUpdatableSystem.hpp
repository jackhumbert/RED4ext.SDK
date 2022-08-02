#pragma once

// This file is generated from the Game's Reflection data

//#include <cstdint>
//#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/IScriptable.hpp>
//#include <RED4ext/Scripting/UpdateManager.hpp>

namespace RED4ext
{
//struct CGameFramework;


 //struct UpdateManagerHolder;

struct IUpdatableSystem : IScriptable
{
    static constexpr const char* NAME = "IUpdatableSystem";
    static constexpr const char* ALIAS = NAME;
    static constexpr const uintptr_t VFT_RVA = 0x31A6470;

    // 1.52 RVA: 0xA779C0 / 10975680
    /// @pattern 40 53 48 83 EC 20 48 8B D9 E8 82 7F 76 FF 48 8D 05 9B EA 72 02 48 89 03 48 8B C3 48 83 C4 20 5B
    IUpdatableSystem();
    
    virtual CClass* GetNativeType() override;
    virtual ~IUpdatableSystem() override;

    // 1.52 RVA: 0xA86060 / 11034720
    /// @pattern 0F B6 C1 83 F8 0C 77 7B 48 8D 15 91 9F 57 FF 8B 8C 82 EC 60 A8 00 48 03 CA FF E1 48 8D 05 46 18
    // static const char *__fastcall GetStringForUnk0(Unk0);

    // sub_110 - adds callbacks to the lookup - there are at least 10 dynarrays
    inline virtual void RegisterUpdates(void* holder) { }; 
};
//RED4EXT_ASSERT_SIZE(IUpdatableSystem, 0x40);


// struct __declspec(align(8)) UpdateLog
// {
//     struct Unk08
//     {
//         CGameEngine::CGameFramework *framework;
//         void *unk08;
//         uint8_t functionalTestsMode;
//         uint8_t headless;
//         uint8_t automator;
//         uint8_t unk13;
//         uint32_t unk14;
//         CString engineName;
//         uint64_t unk38;
//     };

//   void *func;
//   Unk08 *unk08;
//   UpdateEntry *entry;
//   uint32_t unk18;
//   uint8_t unk1C;
//   CGameEngine::CGameFramework *framework;
//   uint8_t unk28;
// };


} // namespace RED4ext
