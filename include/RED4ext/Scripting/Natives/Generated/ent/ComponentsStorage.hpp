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
    
    DynArray<Handle<ent::IComponent>> components; // 30
};
RED4EXT_ASSERT_SIZE(ComponentsStorage, 0x40);
} // namespace ent
} // namespace RED4ext
