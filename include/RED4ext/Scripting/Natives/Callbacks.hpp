#pragma once

#include <RED4ext/RTTITypes.hpp>
namespace RED4ext {

struct CallbackStruct;

struct CallbackId {
    union {
        uint64_t (__fastcall* OnEvent)(IScriptable*, void*);
        uint16_t ids[4];
        CName fullname;
    } action;
    union {
        CName name;
        uint32_t instanceOffset;
    } name;
};

struct CallbackDefinition : CallbackId
{
    CallbackStruct *callbackStruct;
};

struct CallbackInstance : CallbackDefinition {
    uint16_t listenerIndex;
    uint32_t unk1A;
    uint16_t id;
};

struct CallbackStorage : CallbackInstance
{
    uint16_t asyncID;
    uint8_t hasAction;
};

struct CallbackStruct
{
    // Calls the OnEvent with the instance + offset & event
    void (__fastcall* FireCallback)(CallbackDefinition* definition, IScriptable* instance, void* event);

    // Copy the definition into storage
    void (__fastcall* StoreDefinition)(CallbackId*, CallbackId*);

    // Copy the storage struct
    void (__fastcall* CopyStorage)(CallbackId*, CallbackId*);

    // CallbackDefinition is also passed into this
    void (__fastcall* Initialize)(CallbackStorage*);
};

namespace ent {
struct CallbackManager
{
    static constexpr const char* NAME = "entCallbackManager";
    static constexpr const char* ALIAS = NAME;

    // 1.52 RVA: 0x2BC1C80 / 45882496
    /// @pattern 48 89 5C 24 10 48 89 6C 24 18 56 57 41 54 41 56 41 57 48 83 EC 40 48 8B E9 48 8B F2 48 83 C1 5B
    uint16_t __fastcall AddCallback(CallbackInstance *callback);

    // 1.52 RVA: 0x2BC1E70 / 45882992
    /// @pattern 40 55 56 57 48 8D AC 24 70 E0 FF FF B8 90 20 00 00 E8 CA 4A E4 FF 48 2B E0 48 8B 42 08 0F 57 C0
    void __fastcall RegisterComponentToListeners(Handle<IComponent> *componentHandle);

    // 1.52 RVA: 0x2BC2740 / 45885248
    /// @pattern 48 89 5C 24 08 57 48 83 EC 30 48 8D 59 5B 48 8B F9 48 8B CB E8 C7 8C F7 FF 8B 57 44 48 8D 4F 38
    void __fastcall ResizeCallbackInstances();

    DynArray<void*> unk00;
    DynArray<void*> unk10;
    DynArray<uint32_t> idToIndex;
    uint64_t unk30;
    DynArray<CallbackInstance> callbackInstances;
    DynArray<Handle<IScriptable>> listeners;
    uint8_t unk58;
    uint8_t unk59;
    uint8_t unk5A;
    SharedMutex mutex;
};
// ASSERT 0x60 etc

struct EntityCallback
{
    static constexpr const char* NAME = "entEntityCallback";
    static constexpr const char* ALIAS = NAME;
    static constexpr const uintptr_t VFT_RVA = 0x35EB980;

    virtual int64_t __fastcall Destruct(int16_t, int64_t);
    virtual int64_t __fastcall AddCallback(int16_t asyncId, CallbackStorage *callbackStorage);
    virtual CallbackId * __fastcall AddCallbackWithAction(int16_t asyncId, CallbackStorage *callbackStorage, CName action);
    
    CallbackManager * callbackManager;
    HandleBase componentHandle;
    uint16_t listenerIndex;
    CallbackId ids[512];
    uint32_t numIds;
};

} // namespace ent

// struct CallbackDefinition
// {
//     uint64_t (__fastcall* OnEvent)(IScriptable*, void*);
//     uint32_t instanceOffset;
//     uint32_t unk0C;
//     CallbackStruct* callbackStruct;
// };

} // namespace RED4ext