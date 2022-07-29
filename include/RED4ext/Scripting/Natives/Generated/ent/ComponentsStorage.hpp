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

    virtual CClass* GetNativeType() override
    {

    }

    // 1.52 RVA: 0x103FAD0 / 17038032
    /// @pattern 48 89 5C 24 08 48 89 6C 24 10 48 89 74 24 18 57 41 56 41 57 48 83 EC 30 4C 8B 41 30 4C 8D 71 30
    RED4ext::RefCnt * __fastcall AddComponent(Handle<IComponent>);

    // 1.52 RVA: 0x1040100 / 17039616
    /// @pattern 48 83 C1 30 E9 77 20 3B FF
    DynArray<Handle<IComponent>> * __fastcall CopyComponents(DynArray<Handle<IComponent>> *a2);

    DynArray<Handle<ent::IComponent>> components; // 30
};
RED4EXT_ASSERT_SIZE(ComponentsStorage, 0x40);
} // namespace ent
} // namespace RED4ext
