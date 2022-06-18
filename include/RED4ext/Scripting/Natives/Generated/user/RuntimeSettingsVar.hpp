#pragma once

#include <RED4ext/Common.hpp>

namespace RED4ext
{

namespace user
{

enum RuntimeSettingsVarBitfield : uint32_t
{
    isInPreGame = 0x1,
    isInGame = 0x2,
    isVisible = 0x4,
    isPlatformSpecific = 0x8,
    isDynamic = 0x10,
    unk20 = 0x20,
    isInitialized = 0x40,
    listHasDisplayValues = 0x80,
    canBeRestoredToDefault = 0x100,
    isInput = 0x400,
    isDisabled = 0x800,
};

enum ConfigVarType : uint8_t
{
    Bool = 0, // bool
    Int = 1, // int
    Float = 2, // float
    Name = 3, // name
    IntList = 4, // int_list
    FloatList = 5, // float_list
    StringList = 6, // string_list
    NameList = 7, // name_list
};

enum ConfigVarUpdatePolicy : uint8_t
{
    Disabled = 0, // update_disabled
    Immediately = 1, // immediately
    ConfirmationRequired = 2, // require_confirmation
    RestartRequired = 3, // require_restart
    LoadLastCheckpointRequired = 4, // require_load_last_checkpoint
};

enum ConfigVarImportPolicy : uint8_t
{
    ReadValue = 0x0, // read_value
    Ignore = 0x1     // ignore
};

enum ConfigVarUnk : uint16_t
{
    Unk0000 = 0x0000, 
    Backend1 = 0x0001,
    Scripts = 0x0002,
    Backend3 = 0x0003,
    Default = 0xFFFF
};

#pragma pack(push, 1)
struct RuntimeSettingsVar
{
    virtual void* __fastcall sub_00(RuntimeSettingsVar*);
    virtual void __fastcall Deinitialize(RuntimeSettingsVar*, uint64_t);
    virtual bool __fastcall WasModifiedSinceLastSave(RuntimeSettingsVar*);
    virtual bool __fastcall HasRequestedValue(RuntimeSettingsVar*);
    virtual bool __fastcall HasDefaultValue(RuntimeSettingsVar*);
    virtual void __fastcall RestoreDefault(RuntimeSettingsVar*);
    virtual void __fastcall UpdateValue(RuntimeSettingsVar*, int*);
    virtual void __fastcall sub_38();
    virtual void __fastcall sub_40();
    virtual void __fastcall sub_48();
    virtual void __fastcall sub_50();

    CName name;
    CName groupPath;
    CName displayName;
    DynArray<CName> displayNameKeys;
    CName description;
    ConfigVarType type;
    ConfigVarUpdatePolicy updatePolicy;
    ConfigVarImportPolicy importPolicy;
    uint8_t unk3B;
    RuntimeSettingsVarBitfield bitfield;
    uint32_t order;
    ConfigVarUnk setSource;
    uint8_t unk46;
    uint8_t unk47;
};
RED4EXT_ASSERT_SIZE(RuntimeSettingsVar, 0x48);
//char (*__kaboom)[sizeof(RuntimeSettingsVar)] = 1;

struct RuntimeSettingsVarBool : RuntimeSettingsVar
{
    bool value;
    bool defaultValue;
    bool value2;
    bool value3;
    uint32_t unk4C;
};
RED4EXT_ASSERT_SIZE(RuntimeSettingsVarBool, 0x50);
//char (*__kaboom)[sizeof(RuntimeSettingsVarBool)] = 1;

struct RuntimeSettingsVarFloat : RuntimeSettingsVar
{
    float value;
    float defaultValue;
    float value2;
    float value3;
    float minValue;
    float maxValue;
    float stepValue;
    uint32_t unk64;
};
RED4EXT_ASSERT_SIZE(RuntimeSettingsVarFloat, 0x68);

struct RuntimeSettingsVarFloatList : RuntimeSettingsVar
{
    uint32_t unk48;
    uint32_t index;
    uint32_t defaultIndex;
    uint32_t index2;
    uint32_t index3;
    uint32_t unk5C;
    DynArray<float> values;
    DynArray<float> displayValues;
};

struct RuntimeSettingsVarInt : RuntimeSettingsVar
{
    uint32_t value;
    uint32_t defaultValue;
    uint32_t value2;
    uint32_t value3;
    uint32_t minValue;
    uint32_t maxValue;
    uint32_t stepValue;
    uint32_t unk64;
};

struct RuntimeSettingsVarIntList : RuntimeSettingsVar
{
    uint32_t unk48;
    uint32_t index;
    uint32_t defaultIndex;
    uint32_t index2;
    uint32_t index3;
    uint32_t unk5C;
    DynArray<int32_t> values;
    DynArray<int32_t> displayValues;
};

struct RuntimeSettingsVarName : RuntimeSettingsVar
{
    CName value;
    uint64_t defaultValue;
    CName value2;
    CName value3;
};

struct RuntimeSettingsVarNameList : RuntimeSettingsVar
{
    CName value;
    uint32_t index;
    uint32_t defaultIndex;
    uint32_t index2;
    uint32_t index3;
    DynArray<CName> values;
    DynArray<CName> displayValues;
};

struct RuntimeSettingsVarStringList : RuntimeSettingsVar
{
    CString value;
    uint32_t index;
    uint32_t defaultIndex;
    uint32_t index2;
    uint32_t index3;
    DynArray<CString> values;
    DynArray<CString> displayValues;
};
#pragma pack(pop)
} // namespace user
} // namespace RED4ext
