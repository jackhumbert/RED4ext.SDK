#pragma once

#include <cstdint>

#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/IScriptable.hpp>

namespace RED4ext
{
namespace game::data
{
struct TweakDBRecord : IScriptable
{
    static constexpr const char* NAME = "gamedataTweakDBRecord";
    static constexpr const char* ALIAS = "TweakDBRecord";

    virtual CClass* GetNativeType() override;
    virtual Memory::IAllocator* GetAllocator() override; 
    virtual ~TweakDBRecord() override = default;

    virtual void sub_108() { };                    // 108
    virtual uint32_t GetTweakBaseHash() const; // { }; // 110 - Murmur3 of record type name

    TweakDBID recordID;
};
RED4EXT_ASSERT_SIZE(TweakDBRecord, 0x48);
} // namespace game::data
using gamedataTweakDBRecord = game::data::TweakDBRecord;
using TweakDBRecord = game::data::TweakDBRecord;
} // namespace RED4ext
