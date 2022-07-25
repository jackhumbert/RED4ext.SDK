#pragma once

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/CName.hpp>
#include <RED4ext/Handle.hpp>
#include <RED4ext/NativeTypes.hpp>
#include <RED4ext/Scripting/Natives/Generated/ent/GameEntity.hpp>
#include <RED4ext/Scripting/Natives/Generated/Vector4.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/PlayerSocket.hpp>
#include <RED4ext/Scripting/Natives/Generated/red/TagList.hpp>
#include <RED4ext/Scripting/Natives/Generated/WorldTransform.hpp>

namespace RED4ext
{
namespace ent { struct SlotComponent; }
namespace game { struct PersistentState; }

namespace game { 
struct Object : ent::GameEntity
{
    static constexpr const char* NAME = "gameObject";
    static constexpr const char* ALIAS = "GameObject";
    
    virtual void __fastcall sub_1C8() { };
    virtual RED4ext::CName* __fastcall GetAudioResourceName(RED4ext::CName*); // 1D0
    virtual bool __fastcall OnControlTaken(); // 1D8
    virtual bool __fastcall OnControlReleased(); // 1E0
    virtual void __fastcall OnTransformUpdated(); // 1E8
    virtual void __fastcall sub_1F0() { };
    virtual uint64_t __fastcall OnTakeControl(uintptr_t); // 1F8
    virtual uint64_t __fastcall OnReleaseControl(); // 200
    virtual void __fastcall sub_208() { };
    virtual void __fastcall sub_210() { };
    virtual uint64_t __fastcall sub_218(WorldTransform*);
    virtual uint64_t __fastcall sub_220(void*);

    // Updates some position with placeholder - called by other member functions
    virtual uint64_t __fastcall sub_228();

    // Called by ReplicateAnimFeature
    virtual void __fastcall sub_230(Handle<IScriptable>* obj, CName inputName, Handle<IScriptable> value){};

    // Called by ReplicateAnimEvent
    virtual void __fastcall sub_238(Handle<IScriptable> * obj, CName eventName) { };

    // Called by QueueReplicatedEvent
    virtual void __fastcall sub_240(Handle<IScriptable>* event){};

    // Called by ReplicateInputFloat
    virtual void __fastcall sub_248(Handle<IScriptable>* obj, CName inputName, float value){};

    // Called by ReplicateInputBool
    virtual void __fastcall sub_250(Handle<IScriptable>* obj, CName inputName, bool value){};

    // Called by ReplicateInputInt
    virtual void __fastcall sub_258(Handle<IScriptable>* obj, CName inputName, int value){};

    // Called by ReplicateInputVector
    virtual void __fastcall sub_260(Handle<IScriptable>* obj, CName inputName, Vector4 value){};

    // game::Object interface, accepts instance - 0x160 shift
    struct Interface
    {
        virtual uint64_t __fastcall Destruct(char a1); // 00
        virtual uint64_t __fastcall sub_08();           // 08
    };

    struct Flags
    {
        uint8_t Unk1 : 1;
        uint8_t Unk2 : 1;
        uint8_t IsPlayerController : 1;
        uint8_t EnabledTransformUpdates : 1;
    };

    Interface gameObjectInterface; // 160
    Handle<game::PersistentState> persistentState; // 168
    LocalizationString displayName; // 178
    LocalizationString displayDescription; // 1A0
    CName audioResourceName; // 1C8
    game::PlayerSocket playerSocket; // 1D0
    float visibilityCheckDistance; // 1F8
    RED4ext::game::Object::Flags flags;
    uint8_t unk1FD[3];
    RED4ext::HandleBase owner;
    uint64_t unk210; // 210
    Handle<ent::SlotComponent> uiSlotComponent; // 218
    uint8_t unk228[0x230 - 0x228]; // 228
    red::TagList tags; // 230
};
RED4EXT_ASSERT_SIZE(Object, 0x240);
} // namespace game
using GameObject = game::Object;
} // namespace RED4ext
