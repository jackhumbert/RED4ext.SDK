#pragma once

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Handle.hpp>
#include <RED4ext/Scripting/Natives/Generated/WorldTransform.hpp>
#include <RED4ext/Scripting/Natives/Generated/ent/IComponent.hpp>
#include <RED4ext/Scripting/Natives/Generated/Box.hpp>

namespace RED4ext
{
namespace ent { struct ITransformBinding; }

namespace ent { 
struct IPlacedComponent : ent::IComponent
{
    static constexpr const char* NAME = "entIPlacedComponent";
    static constexpr const char* ALIAS = "IPlacedComponent";

    virtual void sub_238();
    virtual void sub_240();
    virtual void sub_248();
    virtual void GetFlags();

    Handle<ent::ITransformBinding> parentTransform; // 90
    uint8_t unkA0[0xC0 - 0xA0]; // A0
    WorldTransform worldTransform;
    WorldTransform localTransform;// E0
    Box bounds; // 100
};
RED4EXT_ASSERT_SIZE(IPlacedComponent, 0x120);
} // namespace ent
using IPlacedComponent = ent::IPlacedComponent;
} // namespace RED4ext
