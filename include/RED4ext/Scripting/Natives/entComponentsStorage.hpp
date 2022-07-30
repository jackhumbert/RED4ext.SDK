#pragma once

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/DynArray.hpp>
#include <RED4ext/Handle.hpp>
#include <RED4ext/ISerializable.hpp>
#include <RED4ext/Scripting/Natives/Generated/ent/IComponent.hpp>

namespace RED4ext
{
namespace ent { struct IComponent; }

namespace ent { 
struct ComponentsStorage : ISerializable
{
    static constexpr const char* NAME = "entComponentsStorage";
    static constexpr const char* ALIAS = NAME;

    virtual CClass* GetNativeType() override;

    // 1.52 RVA: 0x103FAD0 / 17038032
    /// @pattern 48 89 5C 24 08 48 89 6C 24 10 48 89 74 24 18 57 41 56 41 57 48 83 EC 30 4C 8B 41 30 4C 8D 71 30
    RED4ext::RefCnt * __fastcall AddComponent(Handle<IComponent>);

    // 1.52 RVA: 0x1040100 / 17039616
    /// @pattern 48 83 C1 30 E9 77 20 3B FF
    DynArray<Handle<IComponent>> * __fastcall CopyComponents(DynArray<Handle<IComponent>> *a2);

    // 1.52 RVA: 0x103FBB0 / 17038256
    /// @pattern 48 89 5C 24 08 48 89 74 24 10 48 89 7C 24 18 41 56 48 83 EC 30 8B 5A 0C 48 8D 71 30 8B 49 3C 4C
    void __fastcall AddComponents(DynArray<Handle<IComponent>> *a2);

    // 1.52 RVA: 0x104B2A0 / 17085088
    /// @pattern 83 79 3C 00 0F 94 C0 C3
    bool __fastcall IsEmpty();

    // 1.52 RVA: 0x8A92B0 / 9081520
    /// @pattern 8B 41 3C C3
    __int64 __fastcall GetSize();

    // 1.52 RVA: 0x103FC70 / 17038448
    /// @pattern 48 89 5C 24 08 48 89 74 24 10 57 48 83 EC 20 48 8B 59 30 48 8B F2 8B 79 3C 48 C1 E7 04 48 03 FB
    void __fastcall SomethingCRUIDs( __int64 a2);

    // 1.52 RVA: 0x103FCF0 / 17038576
    /// @pattern 48 89 5C 24 10 48 89 6C 24 18 48 89 74 24 20 57 48 83 EC 30 48 8B 59 30 33 ED 8B 41 3C 48 8B F1
    void __fastcall FreeMemory();

    // 1.52 RVA: 0x103FDC0 / 17038784
    // might also pop from the list?
    /// @pattern 48 89 5C 24 10 48 89 6C 24 18 56 57 41 56 48 83 EC 30 48 8B 59 30 49 8B F8 8B 41 3C 4C 8B F2 48
    Handle<IComponent> *__fastcall GetComponentByCRUID(Handle<IComponent> *componentHandle, CRUID cruid);

    DynArray<Handle<ent::IComponent>> components; // 30
};
RED4EXT_ASSERT_SIZE(ComponentsStorage, 0x40);
} // namespace ent
} // namespace RED4ext
