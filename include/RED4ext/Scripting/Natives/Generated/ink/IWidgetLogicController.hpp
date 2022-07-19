#pragma once

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/CName.hpp>
#include <RED4ext/Scripting/IScriptable.hpp>

namespace RED4ext
{
namespace ink { 
struct IWidgetLogicController : IScriptable
{
    static constexpr const char* NAME = "inkIWidgetLogicController";
    static constexpr const char* ALIAS = "inkILogicController";

    Handle<void*> unk40;
    Handle<void*> unk50;
    Handle<void*> unk60;
    CName audioMetadataName; // 70
};
RED4EXT_ASSERT_SIZE(IWidgetLogicController, 0x78);
} // namespace ink
using inkILogicController = ink::IWidgetLogicController;
} // namespace RED4ext
