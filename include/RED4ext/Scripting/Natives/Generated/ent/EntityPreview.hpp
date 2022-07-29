#pragma once

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/ent/Entity.hpp>

namespace RED4ext
{
namespace ent { 
struct EntityPreview : ent::Entity
{
    static constexpr const char* NAME = "entEntityPreview";
    static constexpr const char* ALIAS = NAME;

    virtual uintptr_t __fastcall CopyComponentsToStorage(EntityDefinition * definition, void * a2) override;

    void * unk160;
    void * unk168;
    void * unk170;
    void * unk178;
    void * unk180;
    void * unk188;
    void * unk190;
    uint32_t unk198;
    uint32_t unk1A0;
    void * unk1A8;
    void * unk1B0;
};
RED4EXT_ASSERT_SIZE(EntityPreview, 0x1B8);
} // namespace ent
} // namespace RED4ext
