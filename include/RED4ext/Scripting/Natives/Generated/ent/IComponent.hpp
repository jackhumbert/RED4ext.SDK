#pragma once

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/CName.hpp>
#include <RED4ext/NativeTypes.hpp>
#include <RED4ext/Scripting/IScriptable.hpp>
#include <RED4ext/Scripting/Natives/Generated/ent/Entity.hpp>

namespace RED4ext
{
namespace ent {
struct Entity;
struct IComponent : IScriptable
{
    static constexpr const char* NAME = "entIComponent";
    static constexpr const char* ALIAS = "IComponent";

    //virtual CClass* GetNativeType() override
    //{

    //}

    virtual void sub_110();
    virtual void sub_118();
    virtual void sub_120();
    virtual void sub_128();
    virtual void sub_130();
    virtual void sub_138();
    virtual void sub_140();
    virtual void sub_148();
    virtual void sub_150();
    virtual void sub_158();
    // called on initialize components
    virtual bool sub_160();
    virtual void sub_168();
    virtual void sub_170();
    // called on initialize components
    virtual uint64_t sub_178(uint64_t);
    virtual void sub_180();
    virtual void OnRequestComponents();
    virtual void sub_190();
    virtual void sub_198();
    virtual void sub_1A0();
    virtual void sub_1A8();
    virtual void sub_1B0();
    virtual void sub_1B8();
    virtual void sub_1C0();
    virtual void sub_1C8();
    virtual void sub_1D0();
    virtual void sub_1D8();
    virtual void sub_1E0();
    virtual void sub_1E8();
    // called on gather event listeners
    virtual void sub_1F0(uint64_t);
    virtual void sub_1F8();
    virtual void sub_200();
    virtual void sub_208();
    virtual void Initialize();
    virtual void sub_218();
    virtual void sub_220();
    virtual void sub_228();
    // called on initialize components
    virtual uint32_t sub_230();

    CName name; // 40
    CName owner; // 48 "player"
    Handle<Entity> entity; // 50
    CRUID id; // 60
    uint64_t unk68;
    void *unk70;
    uint64_t unk78;
    uint64_t unk80;
    uint8_t unk88;
    uint8_t unk89;
    uint8_t unk8A;
    bool isEnabled; // 8B
    bool isReplicable; // 8C
    uint8_t unk8D[0x90 - 0x8D]; // 8D
};
RED4EXT_ASSERT_SIZE(IComponent, 0x90);
 //char (*__kaboom)[sizeof(IComponent)] = 1;
} // namespace ent
using IComponent = ent::IComponent;
} // namespace RED4ext
