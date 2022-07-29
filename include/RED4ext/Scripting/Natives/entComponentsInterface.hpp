#pragma once

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/IScriptable.hpp>
#include <RED4ext/Scripting/Natives/Generated/ent/ComponentsStorage.hpp>
#include <RED4ext/ResourcePath.hpp>

namespace RED4ext
{
namespace ent
{
struct ComponentsInterface {
    static constexpr const char* NAME = "entEntity";
    static constexpr const char* ALIAS = "Entity";

    virtual void * Destruct(char);

    ComponentsStorage storage;
};
} // namespace ent
} // namespace RED4ext
