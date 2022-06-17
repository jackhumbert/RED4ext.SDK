#pragma once

#include <RED4ext/Common.hpp>

namespace RED4ext
{

namespace user
{

enum RuntimeSettingsVarBitfield
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

enum ConfigVarType
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

enum ConfigVarUpdatePolicy
{
    Disabled = 0, // update_disabled
    Immediately = 1, // immediately
    ConfirmationRequired = 2, // require_confirmation
    RestartRequired = 3, // require_restart
    LoadLastCheckpointRequired = 4, // require_load_last_checkpoint
};

enum ConfigVarImportPolicy
{
    ReadValue = 0x0, // read_value
    Ignore = 0x1 // ignore
};

class RuntimeSettingsVar
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
    int32_t order;
    uint8_t unk44;
    uint8_t unk45;
    uint8_t unk46;
    uint8_t unk47;
};

class RuntimeSettingsVarBool : RuntimeSettingsVar
{
    bool value;
    bool defaultValue;
    bool value2;
    bool value3;
};

class RuntimeSettingsVarFloat : RuntimeSettingsVar
{
    float value;
    uint32_t defaultValue;
    uint32_t value2;
    uint32_t value3;
    uint32_t minValue;
    uint32_t maxValue;
    uint32_t stepValue;
    uint32_t unk64;
};

class RuntimeSettingsVarFloatList : RuntimeSettingsVar
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

class RuntimeSettingsVarInt : RuntimeSettingsVar
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

class RuntimeSettingsVarIntList : RuntimeSettingsVar
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

class RuntimeSettingsVarName : RuntimeSettingsVar
{
    CName value;
    uint64_t defaultValue;
    CName value2;
    CName value3;
};

class RuntimeSettingsVarNameList : RuntimeSettingsVar
{
    CName value;
    uint32_t index;
    uint32_t defaultIndex;
    uint32_t index2;
    uint32_t index3;
    DynArray<CName> values;
    DynArray<CName> displayValues;
};

class RuntimeSettingsVarStringList : RuntimeSettingsVar
{
    CString value;
    uint32_t index;
    uint32_t defaultIndex;
    uint32_t index2;
    uint32_t index3;
    DynArray<CString> values;
    DynArray<CString> displayValues;
};

} // namespace user
} // namespace RED4ext
