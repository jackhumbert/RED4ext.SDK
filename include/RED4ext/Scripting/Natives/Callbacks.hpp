#pragma once

//#include <RED4ext/NativeTypes.hpp>
//#include <RED4ext/Scripting/Natives/Generated/ent/IComponent.hpp>

namespace RED4ext {

//namespace ent
//{
//struct IComponent;
//}
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
    union Type {
        CName name;
        struct Details {
            uint16_t listenerIndex;
            uint16_t unk1A;
            uint16_t unk1C;
            uint16_t id;
        };
    } type;
};

struct CallbackStorage : CallbackInstance
{
    uint16_t typeId;
    uint8_t isScripted;
    uint8_t unk23;
    uint32_t unk24;
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

struct CallbackManager
{
    static constexpr const char* NAME = "CallbackManager";
    static constexpr const char* ALIAS = NAME;

    // 1.52 RVA: 0x2BC1620 / 45880864
    /// @pattern 48 89 6C 24 20 56 57 41 54 48 83 EC 20 4C 8B 41 38 41 BC FF FF 00 00 0F B7 FA 48 8B F1 48 C1 E7
    __int64 __fastcall Unknown1(uint16_t a2);

    // &ids
    // // 1.52 RVA: 0x2BC17C0 / 45881280
    // /// @pattern 48 89 5C 24 18 56 57 41 54 41 56 41 57 48 83 EC 30 8B 71 0C 4C 8B F2 8B 51 08 4D 8B F9 45 8B E0
    // __int64 __fastcall Unknown2(__int64, unsigned int, char *);

    // 1.52 RVA: 0x2BC1780 / 45881216
    /// @pattern 48 89 5C 24 08 57 48 83 EC 20 48 8B F9 48 83 C1 5B E8 EA 9C F7 FF 83 7F 2C 00 B9 FF FF FF FF 0F
    bool __fastcall ResetIdsSize();

    // 1.52 RVA: 0x2BC1B60 / 45882208
    /// @pattern 40 56 41 56 48 83 EC 48 48 83 3A 00 48 8B F2 4C 8B F1 0F 84 F2 00 00 00 48 89 5C 24 60 48 83 C1
    void __fastcall AddToUnk00(RED4ext::HandleBase *a2);

    // 1.52 RVA: 0x2BC1C80 / 45882496
    /// @pattern 48 89 5C 24 10 48 89 6C 24 18 56 57 41 54 41 56 41 57 48 83 EC 40 48 8B E9 48 8B F2 48 83 C1 5B
    uint16_t __fastcall AddCallback(CallbackInstance *callback);

    // 1.52 RVA: 0x2BC1E70 / 45882992
    /// @pattern 40 55 56 57 48 8D AC 24 70 E0 FF FF B8 90 20 00 00 E8 CA 4A E4 FF 48 2B E0 48 8B 42 08 0F 57 C0
    void __fastcall RegisterComponentToListeners(Handle<IScriptable>* componentHandle);

    // 1.52 RVA: 0x2BC2440 / 45884480
    // Takes an event class
    /// @pattern 48 8B C4 41 56 41 57 48 83 EC 78 83 79 0C 00 4C 8B FA 4C 8B F1 0F 84 D0 02 00 00 48 89 58 10 48
    void __fastcall Unknown6(RED4ext::CClass *a2);

    // 1.52 RVA: 0x2BC2740 / 45885248
    /// @pattern 48 89 5C 24 08 57 48 83 EC 30 48 8D 59 5B 48 8B F9 48 8B CB E8 C7 8C F7 FF 8B 57 44 48 8D 4F 38
    void __fastcall ResizeCallbackInstances();

    // 1.52 RVA: 0x2BC27A0 / 45885344
    /// @pattern 48 89 5C 24 18 55 56 41 54 41 55 41 56 48 83 EC 30 48 8B E9 4C 8B EA 48 83 C1 5B E8 60 8C F7 FF
    void __fastcall SomethingListeners(Handle<IScriptable> *a2);


    DynArray<Handle<IScriptable>> unk00;
    DynArray<Handle<IScriptable>> unk10;
    DynArray<uint32_t> idToIndex; // 20
    uint64_t unk30;
    DynArray<CallbackInstance> callbackInstances; //38
    DynArray<Handle<IScriptable>> listeners; // 48
    uint16_t lastUnk1C; // 58
    SharedMutex mutex1; // 5A
    SharedMutex mutex2; // 5B
};
// ASSERT 0x60 etc

struct Callback
{
    static constexpr const char* NAME = "Callback";
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

// struct CallbackDefinition
// {
//     uint64_t (__fastcall* OnEvent)(IScriptable*, void*);
//     uint32_t instanceOffset;
//     uint32_t unk0C;
//     CallbackStruct* callbackStruct;
// };

} // namespace RED4ext
