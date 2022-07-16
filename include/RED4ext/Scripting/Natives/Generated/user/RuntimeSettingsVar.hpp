#pragma once

#include <RED4ext/Common.hpp>

namespace RED4ext
{

namespace user
{
struct EConfigVarFlags
{
    uint32_t isInPreGame : 1;
    uint32_t isInGame : 1;
    uint32_t isVisible : 1;
    uint32_t isPlatformSpecific : 1;
    uint32_t isDynamic : 1;
    uint32_t unk20 : 1;
    uint32_t isInitialized : 1;
    uint32_t listHasDisplayValues : 1;
    uint32_t canBeRestoredToDefault : 1;
    uint32_t isInput : 1;
    uint32_t isDisabled : 1;
};
enum class EConfigVarType : char
{
    Bool = 0,       // bool
    Int = 1,        // int
    Float = 2,      // float
    Name = 3,       // name
    IntList = 4,    // int_list
    FloatList = 5,  // float_list
    StringList = 6, // string_list
    NameList = 7,   // name_list
};
enum class EConfigVarUpdatePolicy : char
{
    Disabled = 0,                   // update_disabled
    Immediately = 1,                // immediately
    ConfirmationRequired = 2,       // require_confirmation
    RestartRequired = 3,            // require_restart
    LoadLastCheckpointRequired = 4, // require_load_last_checkpoint
};
enum class EConfigVarImportPolicy : char
{
    ReadValue = 0x0, // read_value
    Ignore = 0x1     // ignore
};
//enum class EConfigVarUnk : short
//{
//    Unk0000 = 0x0000,
//    Backend1 = 0x0001,
//    Scripts = 0x0002,
//    Backend3 = 0x0003,
//    Default = 0xFFFF
//};

//struct RuntimeSettingsVar;
//
//struct RuntimeSettingsVar_vtbl
//{
//    void*(__fastcall * sub_00)(RuntimeSettingsVar*);
//    void(__fastcall* Deinitialize)(RuntimeSettingsVar*, uint64_t);
//    bool(__fastcall* WasModifiedSinceLastSave)(RuntimeSettingsVar*);
//    bool(__fastcall* HasRequestedValue)(RuntimeSettingsVar*);
//    bool(__fastcall* HasDefaultValue)(RuntimeSettingsVar*);
//    void(__fastcall* RestoreDefault)(RuntimeSettingsVar*);
//    void(__fastcall* UpdateValue)(RuntimeSettingsVar*, int*);
//    void(__fastcall* sub_38)();
//    void(__fastcall* sub_40)();
//    void(__fastcall* sub_48)();
//    void(__fastcall* sub_50)();
//};

#pragma pack(push, 1)
struct RuntimeSettingsVar
{
    //static constexpr const uintptr_t VFT = 0x32B9DC8 + 0xC00;

    RuntimeSettingsVar()
    {
        displayNameKeys = RED4ext::DynArray<RED4ext::CName>(new RED4ext::Memory::DefaultAllocator());
        updatePolicy = RED4ext::user::EConfigVarUpdatePolicy::Immediately;
        unk44 = 0xFF;
        unk45 = 0xFF;
        bitfield.isInPreGame = true;
        bitfield.isInGame = true;
        bitfield.isVisible = true;
        bitfield.isInitialized = true;
        bitfield.isDisabled = false;
        bitfield.canBeRestoredToDefault = true;
    }

    virtual RED4ext::Memory::IAllocator* __fastcall GetAllocator(RuntimeSettingsVar*)
    {
        return Memory::DefaultAllocator::Get();
    }
    virtual void __fastcall Deinitialize(uint64_t) {
        //if (displayNameKeys.size)
        //{
        //    displayNameKeys.Clear();
        //}
    }
    virtual bool __fastcall WasModifiedSinceLastSave() = 0;
    virtual bool __fastcall HasChange() = 0;
    virtual bool __fastcall IsDefault() = 0;
    virtual bool __fastcall RestoreDefault(char) = 0;
    virtual void __fastcall UpdateValue(void* value) = 0;
    virtual void __fastcall ApplyChange() = 0;
    virtual void __fastcall RevertChange() = 0;
    virtual void __fastcall ChangeWasWritten() = 0;
    virtual void __fastcall UpdateAll(void* value) = 0;

    // custom
    virtual void __fastcall GetValueToWrite(char* value) = 0;
    virtual ScriptInstance* __fastcall GetValuePtr() = 0;

    CName name;
    CName groupPath;
    CName displayName;
    DynArray<CName> displayNameKeys;
    CName description;
    EConfigVarType type;
    EConfigVarUpdatePolicy updatePolicy;
    EConfigVarImportPolicy importPolicy;
    uint8_t unk3B;
    EConfigVarFlags bitfield;
    uint32_t order;
    uint8_t unk44;
    uint8_t unk45;
    uint8_t unk46;
    uint8_t unk47;
};
RED4EXT_ASSERT_SIZE(RuntimeSettingsVar, 0x48);
//char (*__kaboom)[sizeof(RuntimeSettingsVar)] = 1;

struct RuntimeSettingsVarBool : public RuntimeSettingsVar
{
    RuntimeSettingsVarBool() : RuntimeSettingsVar()
    {
    }

    virtual bool __fastcall WasModifiedSinceLastSave() override
    {
        return importPolicy != RED4ext::user::EConfigVarImportPolicy::Ignore && valueWrittenToFile != valueValidated;
    }

    virtual bool __fastcall HasChange() override
    {
        return valueInput != valueValidated;
    }

    virtual bool __fastcall IsDefault() override
    {
        uint8_t value;
        if (HasChange())
        {
            value = valueInput;
        }
        else
        {
            value = valueValidated;
        }
        return value == defaultValue;
    }

    virtual bool __fastcall RestoreDefault(char a1) override
    {
        auto wasDefault = IsDefault();
        if (wasDefault)
            return !wasDefault;
        unk44 = a1;
        if (((a1 - 2) & 0xFD) != 0)
        {
            if (((a1 - 1) & 0xFD) != 0)
            {
                if (!a1)
                {
                    UpdateValue(&defaultValue);
                    // UserSettings = GetUserSettings();
                    // AddSettingsDataToSettings(UserSettings, a1);
                }
                return !wasDefault;
            }
        UpdateImmediately:
            UpdateValue(&defaultValue);
            // v9 = GetUserSettings();
            // sub_7FF62769C390(v9, a1);
            return !wasDefault;
        }
        switch (updatePolicy)
        {
        case RED4ext::user::EConfigVarUpdatePolicy::Disabled:
            return !wasDefault;
        case RED4ext::user::EConfigVarUpdatePolicy::Immediately:
            goto UpdateImmediately;
        case RED4ext::user::EConfigVarUpdatePolicy::ConfirmationRequired:
            UpdateValue(&defaultValue);
            // v8 = GetUserSettings();
            // SettingsConfirmChange_0(v8, a1);
            break;
        case RED4ext::user::EConfigVarUpdatePolicy::RestartRequired:
            UpdateValue(&defaultValue);
            // v7 = GetUserSettings();
            // SettingsRestartRequired_0(v7, a1);
            break;
        case RED4ext::user::EConfigVarUpdatePolicy::LoadLastCheckpointRequired:
            UpdateValue(&defaultValue);
            // v6 = GetUserSettings();
            // SettingsLoadLastCheckpoint_0(v6, a1);
            break;
        default:
            // LogError_f("E:\\R6.Release\\dev\\src\\common\\redConfig\\include\\inGameConfigVar.hpp", 44, line,
            //            "Unknown in-game config var update policy (%d)", (unsigned __int8)a1->updatePolicy);
            //__debugbreak();
            break;
        }
        return !wasDefault;
    }

    virtual void __fastcall UpdateValue(void* value) override
    {
        valueInput = *(uint8_t*)value;
    }

    virtual void __fastcall ApplyChange() override
    {
        valueValidated = valueInput;
    }

    virtual void __fastcall RevertChange() override
    {
        valueInput = valueValidated;
    }

    virtual void __fastcall ChangeWasWritten() override
    {
        valueWrittenToFile = valueValidated;
    }

    virtual void __fastcall UpdateAll(void* value) override
    {
        valueWrittenToFile = *(uint8_t*)value;
        valueInput = *(uint8_t*)value;
        valueValidated = *(uint8_t*)value;
    }

    virtual void __fastcall GetValueToWrite(char* value) override
    {
        sprintf(value, "%d", valueValidated);
    }

    virtual ScriptInstance* __fastcall GetValuePtr()
    {
        return (ScriptInstance*)&valueValidated;
    }
    
    uint8_t valueValidated;
    uint8_t defaultValue;
    uint8_t valueInput;
    uint8_t valueWrittenToFile;
    uint32_t unk4C;
};
RED4EXT_ASSERT_SIZE(RuntimeSettingsVarBool, 0x50);
//char (*__kaboom)[sizeof(RuntimeSettingsVarBool)] = 1;

struct RuntimeSettingsVarFloat : public RuntimeSettingsVar
{
    //static constexpr const uintptr_t VFT = 0x35E6D08 + 0xC00;

    RuntimeSettingsVarFloat() : RuntimeSettingsVar() {

    }

    virtual bool __fastcall WasModifiedSinceLastSave() override
    {
        return importPolicy != RED4ext::user::EConfigVarImportPolicy::Ignore && valueWrittenToFile != valueValidated;
    }

    virtual bool __fastcall HasChange() override
    {
        return valueInput != valueValidated;
    }

    virtual bool __fastcall IsDefault() override
    {
        float value;
        if (HasChange())
        {
            value = valueInput;
        } else
        {
            value = valueValidated;
        }
        return value == defaultValue;
    }

    virtual bool __fastcall RestoreDefault(char a1) override
    {
        auto wasDefault = IsDefault();
        if (wasDefault)
            return !wasDefault;
        unk44 = a1;
        if (((a1 - 2) & 0xFD) != 0) {
            if (((a1 - 1) & 0xFD) != 0)
            {
                if (!a1)
                {
                    UpdateValue((int*)&defaultValue);
                    //UserSettings = GetUserSettings();
                    //AddSettingsDataToSettings(UserSettings, a1);
                }
                return !wasDefault;
            }
        UpdateImmediately:
            UpdateValue((int*)&defaultValue);
            //v9 = GetUserSettings();
            //sub_7FF62769C390(v9, a1);
            return !wasDefault;
        }
        switch (updatePolicy)
        {
            case RED4ext::user::EConfigVarUpdatePolicy::Disabled:
                return !wasDefault;
            case RED4ext::user::EConfigVarUpdatePolicy::Immediately:
                goto UpdateImmediately;
            case RED4ext::user::EConfigVarUpdatePolicy::ConfirmationRequired:
                UpdateValue((int*)&defaultValue);
                //v8 = GetUserSettings();
                //SettingsConfirmChange_0(v8, a1);
                break;
            case RED4ext::user::EConfigVarUpdatePolicy::RestartRequired:
                UpdateValue((int*)&defaultValue);
                //v7 = GetUserSettings();
                //SettingsRestartRequired_0(v7, a1);
                break;
            case RED4ext::user::EConfigVarUpdatePolicy::LoadLastCheckpointRequired:
                UpdateValue((int*)&defaultValue);
                //v6 = GetUserSettings();
                //SettingsLoadLastCheckpoint_0(v6, a1);
                break;
            default:
                //LogError_f("E:\\R6.Release\\dev\\src\\common\\redConfig\\include\\inGameConfigVar.hpp", 44, line,
                //           "Unknown in-game config var update policy (%d)", (unsigned __int8)a1->updatePolicy);
                //__debugbreak();
                break;
        }
        return !wasDefault;
    }

    virtual void __fastcall UpdateValue(void* value) override
    {
        valueInput = *(float*)value;
    }

    virtual void __fastcall ApplyChange() override
    {
        valueValidated = valueInput;
    }

    virtual void __fastcall RevertChange() override
    {
        valueInput = valueValidated;
    }

    virtual void __fastcall ChangeWasWritten() override
    {
        valueWrittenToFile = valueValidated;
    }

    virtual void __fastcall UpdateAll(void* value) override
    {
        valueWrittenToFile = *(float*)value;
        valueInput = *(float*)value;
        valueValidated = *(float*)value;
    }

    virtual void __fastcall GetValueToWrite(char* value) override
    {
        sprintf(value, "%f", valueValidated);
    }

    virtual ScriptInstance* __fastcall GetValuePtr()
    {
        return (ScriptInstance*)&valueValidated;
    }

    float valueValidated;
    float defaultValue;
    float valueInput;
    float valueWrittenToFile;
    float minValue;
    float maxValue;
    float stepValue;
    uint32_t unk64;
};
RED4EXT_ASSERT_SIZE(RuntimeSettingsVarFloat, 0x68);

struct RuntimeSettingsVarFloatList : public RuntimeSettingsVar
{
    uint32_t unk48;
    uint32_t valueValidated;
    uint32_t defaultValue;
    uint32_t valueInput;
    uint32_t valueWrittenToFile;
    uint32_t unk5C;
    DynArray<float> values;
    DynArray<float> displayValues;
};

struct RuntimeSettingsVarInt : public RuntimeSettingsVar
{
    //static constexpr const uintptr_t VFT = 0x35E6CB0 + 0xC00;
    RuntimeSettingsVarInt() : RuntimeSettingsVar()
    {
    }

    virtual bool __fastcall WasModifiedSinceLastSave() override
    {
        return importPolicy != RED4ext::user::EConfigVarImportPolicy::Ignore && valueWrittenToFile != valueValidated;
    }

    virtual bool __fastcall HasChange() override
    {
        return valueInput != valueValidated;
    }

    virtual bool __fastcall IsDefault() override
    {
        int32_t value;
        if (HasChange())
        {
            value = valueInput;
        }
        else
        {
            value = valueValidated;
        }
        return value == defaultValue;
    }

    virtual bool __fastcall RestoreDefault(char a1) override
    {
        auto wasDefault = IsDefault();
        if (wasDefault)
            return !wasDefault;
        unk44 = a1;
        if (((a1 - 2) & 0xFD) != 0)
        {
            if (((a1 - 1) & 0xFD) != 0)
            {
                if (!a1)
                {
                    UpdateValue(&defaultValue);
                    // UserSettings = GetUserSettings();
                    // AddSettingsDataToSettings(UserSettings, a1);
                }
                return !wasDefault;
            }
        UpdateImmediately:
            UpdateValue(&defaultValue);
            // v9 = GetUserSettings();
            // sub_7FF62769C390(v9, a1);
            return !wasDefault;
        }
        switch (updatePolicy)
        {
        case RED4ext::user::EConfigVarUpdatePolicy::Disabled:
            return !wasDefault;
        case RED4ext::user::EConfigVarUpdatePolicy::Immediately:
            goto UpdateImmediately;
        case RED4ext::user::EConfigVarUpdatePolicy::ConfirmationRequired:
            UpdateValue(&defaultValue);
            // v8 = GetUserSettings();
            // SettingsConfirmChange_0(v8, a1);
            break;
        case RED4ext::user::EConfigVarUpdatePolicy::RestartRequired:
            UpdateValue(&defaultValue);
            // v7 = GetUserSettings();
            // SettingsRestartRequired_0(v7, a1);
            break;
        case RED4ext::user::EConfigVarUpdatePolicy::LoadLastCheckpointRequired:
            UpdateValue(&defaultValue);
            // v6 = GetUserSettings();
            // SettingsLoadLastCheckpoint_0(v6, a1);
            break;
        default:
            // LogError_f("E:\\R6.Release\\dev\\src\\common\\redConfig\\include\\inGameConfigVar.hpp", 44, line,
            //            "Unknown in-game config var update policy (%d)", (unsigned __int8)a1->updatePolicy);
            //__debugbreak();
            break;
        }
        return !wasDefault;
    }

    virtual void __fastcall UpdateValue(void* value) override
    {
        valueInput = *(int32_t*)value;
    }

    virtual void __fastcall ApplyChange() override
    {
        valueValidated = valueInput;
    }

    virtual void __fastcall RevertChange() override
    {
        valueInput = valueValidated;
    }

    virtual void __fastcall ChangeWasWritten() override
    {
        valueWrittenToFile = valueValidated;
    }

    virtual void __fastcall UpdateAll(void* value) override
    {
        valueWrittenToFile = *(int32_t*)value;
        valueInput = *(int32_t*)value;
        valueValidated = *(int32_t*)value;
    }

    virtual void __fastcall GetValueToWrite(char* value) override
    {
        sprintf(value, "%d", valueValidated);
    }

    virtual ScriptInstance* __fastcall GetValuePtr()
    {
        return (ScriptInstance*)&valueValidated;
    }

    int32_t valueValidated;
    int32_t defaultValue;
    int32_t valueInput;
    int32_t valueWrittenToFile;
    int32_t minValue;
    int32_t maxValue;
    uint32_t stepValue;
    uint32_t unk64;
};

struct RuntimeSettingsVarIntList : public RuntimeSettingsVar
{
    RuntimeSettingsVarIntList() : RuntimeSettingsVar()
    {
        values = RED4ext::DynArray<int32_t>(new Memory::DefaultAllocator());
    }
    virtual bool __fastcall WasModifiedSinceLastSave() override
    {
        return importPolicy != RED4ext::user::EConfigVarImportPolicy::Ignore && valueWrittenToFile != valueValidated;
    }

    virtual bool __fastcall HasChange() override
    {
        return valueInput != valueValidated;
    }

    virtual bool __fastcall IsDefault() override
    {
        uint32_t value;
        if (HasChange())
        {
            value = valueInput;
        }
        else
        {
            value = valueValidated;
        }
        return value == defaultValue;
    }

    virtual bool __fastcall RestoreDefault(char a1) override
    {
        auto wasDefault = IsDefault();
        if (!wasDefault)
        {
            uint32_t size = values.size;
            int32_t value = defaultValue;
            if (size)
            {
                if (value >= 0)
                {
                    if (value >= size)
                        value = size - 1;
                }
                else
                {
                    value = 0;
                }
            }
            else
            {
                value = -1;
            }
            unk44 = a1;
            if (((a1 - 2) & 0xFD) != 0)
            {
                if (((a1 - 1) & 0xFD) != 0)
                {
                    if (!a1)
                    {
                        UpdateValue(&defaultValue);
                        // UserSettings = GetUserSettings();
                        // AddSettingsDataToSettings(UserSettings, a1);
                    }
                    return !wasDefault;
                }
            UpdateImmediately:
                UpdateValue(&defaultValue);
                // v9 = GetUserSettings();
                // sub_7FF62769C390(v9, a1);
                return !wasDefault;
            }
            switch (updatePolicy)
            {
            case RED4ext::user::EConfigVarUpdatePolicy::Disabled:
                return !wasDefault;
            case RED4ext::user::EConfigVarUpdatePolicy::Immediately:
                goto UpdateImmediately;
            case RED4ext::user::EConfigVarUpdatePolicy::ConfirmationRequired:
                UpdateValue(&defaultValue);
                // v8 = GetUserSettings();
                // SettingsConfirmChange_0(v8, a1);
                break;
            case RED4ext::user::EConfigVarUpdatePolicy::RestartRequired:
                UpdateValue(&defaultValue);
                // v7 = GetUserSettings();
                // SettingsRestartRequired_0(v7, a1);
                break;
            case RED4ext::user::EConfigVarUpdatePolicy::LoadLastCheckpointRequired:
                UpdateValue(&defaultValue);
                // v6 = GetUserSettings();
                // SettingsLoadLastCheckpoint_0(v6, a1);
                break;
            default:
                // LogError_f("E:\\R6.Release\\dev\\src\\common\\redConfig\\include\\inGameConfigVar.hpp", 44, line,
                //            "Unknown in-game config var update policy (%d)", (unsigned __int8)a1->updatePolicy);
                //__debugbreak();
                break;
            }
        }
        return !wasDefault;
    }

    virtual void __fastcall UpdateValue(void* value) override
    {
        valueInput = *(uint32_t*)value;
    }

    virtual void __fastcall ApplyChange() override
    {
        valueValidated = valueInput;
    }

    virtual void __fastcall RevertChange() override
    {
        valueInput = valueValidated;
    }

    virtual void __fastcall ChangeWasWritten() override
    {
        valueWrittenToFile = valueValidated;
    }

    virtual void __fastcall UpdateAll(void* value) override
    {
        valueWrittenToFile = *(uint32_t*)value;
        valueInput = *(uint32_t*)value;
        valueValidated = *(uint32_t*)value;
    }

    virtual void __fastcall GetValueToWrite(char* value) override
    {
        sprintf(value, "%d", valueValidated);
    }

    virtual ScriptInstance* __fastcall GetValuePtr()
    {
        return (ScriptInstance*)&valueValidated;
    }

    uint32_t unk48;
    uint32_t valueValidated;
    uint32_t defaultValue;
    uint32_t valueInput;
    uint32_t valueWrittenToFile;
    uint32_t unk5C;
    DynArray<int32_t> values;
    DynArray<CName> displayValues;
};

struct RuntimeSettingsVarName : RuntimeSettingsVar
{
    CName valueValidated;
    CName defaultValue;
    CName valueInput;
    CName valueWrittenToFile;
};

struct RuntimeSettingsVarNameList : RuntimeSettingsVar
{
    RuntimeSettingsVarNameList() : RuntimeSettingsVar()
    {
        values = RED4ext::DynArray<uint32_t>(new Memory::DefaultAllocator());
    }
    virtual bool __fastcall WasModifiedSinceLastSave() override
    {
        return importPolicy != RED4ext::user::EConfigVarImportPolicy::Ignore && valueWrittenToFile != valueValidated;
    }

    virtual bool __fastcall HasChange() override
    {
        return valueInput != valueValidated;
    }

    virtual bool __fastcall IsDefault() override
    {
        uint32_t value;
        if (HasChange())
        {
            value = valueInput;
        }
        else
        {
            value = valueValidated;
        }
        return value == defaultValue;
    }

    virtual bool __fastcall RestoreDefault(char a1) override
    {
        auto wasDefault = IsDefault();
        if (!wasDefault)
        {
            uint32_t size = values.size;
            int32_t value = defaultValue;
            if (size)
            {
                if (value >= 0)
                {
                    if (value >= size)
                        value = size - 1;
                }
                else
                {
                    value = 0;
                }
            }
            else
            {
                value = -1;
            }
            unk44 = a1;
            if (((a1 - 2) & 0xFD) != 0)
            {
                if (((a1 - 1) & 0xFD) != 0)
                {
                    if (!a1)
                    {
                        UpdateValue(&defaultValue);
                        // UserSettings = GetUserSettings();
                        // AddSettingsDataToSettings(UserSettings, a1);
                    }
                    return !wasDefault;
                }
            UpdateImmediately:
                UpdateValue(&defaultValue);
                // v9 = GetUserSettings();
                // sub_7FF62769C390(v9, a1);
                return !wasDefault;
            }
            switch (updatePolicy)
            {
            case RED4ext::user::EConfigVarUpdatePolicy::Disabled:
                return !wasDefault;
            case RED4ext::user::EConfigVarUpdatePolicy::Immediately:
                goto UpdateImmediately;
            case RED4ext::user::EConfigVarUpdatePolicy::ConfirmationRequired:
                UpdateValue(&defaultValue);
                // v8 = GetUserSettings();
                // SettingsConfirmChange_0(v8, a1);
                break;
            case RED4ext::user::EConfigVarUpdatePolicy::RestartRequired:
                UpdateValue(&defaultValue);
                // v7 = GetUserSettings();
                // SettingsRestartRequired_0(v7, a1);
                break;
            case RED4ext::user::EConfigVarUpdatePolicy::LoadLastCheckpointRequired:
                UpdateValue(&defaultValue);
                // v6 = GetUserSettings();
                // SettingsLoadLastCheckpoint_0(v6, a1);
                break;
            default:
                // LogError_f("E:\\R6.Release\\dev\\src\\common\\redConfig\\include\\inGameConfigVar.hpp", 44, line,
                //            "Unknown in-game config var update policy (%d)", (unsigned __int8)a1->updatePolicy);
                //__debugbreak();
                break;
            }
        }
        return !wasDefault;
    }

    virtual void __fastcall UpdateValue(void* value) override
    {
        valueInput = *(uint32_t*)value;
    }

    virtual void __fastcall ApplyChange() override
    {
        valueValidated = valueInput;
    }

    virtual void __fastcall RevertChange() override
    {
        valueInput = valueValidated;
    }

    virtual void __fastcall ChangeWasWritten() override
    {
        valueWrittenToFile = valueValidated;
    }

    virtual void __fastcall UpdateAll(void* value) override
    {
        valueWrittenToFile = *(uint32_t*)value;
        valueInput = *(uint32_t*)value;
        valueValidated = *(uint32_t*)value;
    }

    virtual void __fastcall GetValueToWrite(char* value) override
    {
        sprintf(value, "%d", valueValidated);
    }

    virtual ScriptInstance* __fastcall GetValuePtr()
    {
        return (ScriptInstance *) & valueValidated;
    }

    CName value;
    uint32_t valueValidated;
    uint32_t defaultValue;
    uint32_t valueInput;
    uint32_t valueWrittenToFile;
    DynArray<uint32_t> values;
    DynArray<CName> displayValues;
};

struct RuntimeSettingsVarStringList : RuntimeSettingsVar
{
    CString value;
    uint32_t valueValidated;
    uint32_t defaultValue;
    uint32_t valueInput;
    uint32_t valueWrittenToFile;
    DynArray<CString> values;
    DynArray<CString> displayValues;
};
#pragma pack(pop)
} // namespace user
} // namespace RED4ext
