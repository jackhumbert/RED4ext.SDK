#pragma once

#include "RED4ext/CName.hpp"
#include "RED4ext/DynArray.hpp"
#include <RED4ext/Common.hpp>
#include <stdint.h>

namespace RED4ext
{

namespace user
{
struct ConfigVarFlags
{
    uint32_t isInPreGame : 1;            // 0x001
    uint32_t isInGame : 1;               // 0x002
    uint32_t isVisible : 1;              // 0x004
    uint32_t isPlatformSpecific : 1;     // 0x008
    uint32_t isDynamic : 1;              // 0x010
    uint32_t unk20 : 1;                  // 0x020
    uint32_t isInitialized : 1;          // 0x040
    uint32_t listHasDisplayValues : 1;   // 0x080
    uint32_t canBeRestoredToDefault : 1; // 0x100
    uint32_t isInput : 1;                // 0x200
    uint32_t isDisabled : 1;             // 0x400
};
enum class EConfigVarFlags : int
{
    isInPreGame = 0x001,
    isInGame = 0x002,
    isVisible = 0x004,
    isPlatformSpecific = 0x008,
    isDynamic = 0x010,
    unk20 = 0x020,
    isInitialized = 0x040,
    listHasDisplayValues = 0x080,
    canBeRestoredToDefault = 0x100,
    isInput = 0x200,
    isDisabled = 0x400,
};
DEFINE_ENUM_FLAG_OPERATORS(EConfigVarFlags);

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
// enum class EConfigVarUnk : short
//{
//     Unk0000 = 0x0000,
//     Backend1 = 0x0001,
//     Scripts = 0x0002,
//     Backend3 = 0x0003,
//     Default = 0xFFFF
// };

// struct RuntimeSettingsVar;
//
// struct RuntimeSettingsVar_vtbl
//{
//     void*(__fastcall * sub_00)(RuntimeSettingsVar*);
//     void(__fastcall* Deinitialize)(RuntimeSettingsVar*, uint64_t);
//     bool(__fastcall* WasModifiedSinceLastSave)(RuntimeSettingsVar*);
//     bool(__fastcall* HasRequestedValue)(RuntimeSettingsVar*);
//     bool(__fastcall* HasDefaultValue)(RuntimeSettingsVar*);
//     void(__fastcall* RestoreDefault)(RuntimeSettingsVar*);
//     void(__fastcall* SetRequestedValue)(RuntimeSettingsVar*, int*);
//     void(__fastcall* sub_38)();
//     void(__fastcall* sub_40)();
//     void(__fastcall* sub_48)();
//     void(__fastcall* sub_50)();
// };

// 1.52  RVA: 0x2B9B330 / 45724464
/// @pattern 40 53 48 83 EC 20 65 48 8B 04 25 58 00 00 00 8B 0D EB DF FF 01 BA 9C 07 00 00 48 8B 0C C8 8B 04
void* __fastcall GetSettings();

// InGameConfig::Var
#pragma pack(push, 1)
struct RuntimeSettingsVar
{
    // vft RVA: 0x32BB5C8
    // str RVA: 0x32BB408
    // Entity/VisualController
    /// @pattern 45 6E 74 69 74 79 2F 56 69 73 75 61 6C 43 6F 6E 74 72 6F 6C 6C 65 72
    /// @offset -448
    // static constexpr const uintptr_t VFT = userRuntimeSettingsVar_VFT_Addr;

    // 1.52 RVA: 0x2B97BC0 / 45710272
    /// @pattern 40 53 48 83 EC 20 48 89 51 10 48 8D 05 F7 39 72 00 48 8B 54 24 50 48 8B D9 48 89 01 4C 89 41 08
    RuntimeSettingsVar(CName groupPath, CName name, CName displayName, DynArray<CName>* displayNameKeys,
                       CName description, EConfigVarType type, EConfigVarUpdatePolicy updatePolicy,
                       EConfigVarImportPolicy importPolicy, ConfigVarFlags flags, uint32_t order);

    RuntimeSettingsVar()
    {
        displayNameKeys = RED4ext::DynArray<RED4ext::CName>(new RED4ext::Memory::DefaultAllocator());
        unk44 = 0xFF;
        unk45 = 0xFF;
        bitfield = (ConfigVarFlags)0ui32;
    }

    virtual RED4ext::Memory::IAllocator* __fastcall GetAllocator(RuntimeSettingsVar*)
    {
        return new Memory::DefaultAllocator();
    }
    virtual RuntimeSettingsVar* __fastcall Deinitialize(bool shouldFree)
    {
        if (displayNameKeys.capacity)
        {
            displayNameKeys.Clear();
        }
        if ((shouldFree & 1) != 0)
        {
            // idk
        }
        return this;
    }
    virtual bool __fastcall WasModifiedSinceLastSave() = 0;
    virtual bool __fastcall HasChange() = 0; // HasRequestedValue
    virtual bool __fastcall IsDefault() = 0; // HasDefaultValue
    virtual bool __fastcall RestoreDefault(uint8_t) = 0;
    virtual void __fastcall SetRequestedValue(void* value) = 0; // InternalSetRequestedValue
    virtual void __fastcall AcceptChange() = 0; // InternalAcceptValue
    virtual void __fastcall RejectChange() = 0; // InternalRejectValue
    virtual void __fastcall MarkAsSaved() = 0; // InternalMarkAsSaved
    virtual void __fastcall LoadValue(void* value) = 0; // InternalLoadValue

    CName name = CName();            // 08
    CName groupPath = CName();       // 10
    CName displayName = CName();     // 18
    DynArray<CName> displayNameKeys; // 20
    CName description = CName();     // 30
    EConfigVarType type;             // 38
    EConfigVarUpdatePolicy updatePolicy = EConfigVarUpdatePolicy::Immediately;
    EConfigVarImportPolicy importPolicy = EConfigVarImportPolicy::ReadValue;
    uint8_t unk3B;
    ConfigVarFlags bitfield;
    uint32_t order;
    // last update flag
    uint8_t unk44;
    // assigned to in init
    uint8_t unk45;
    uint8_t unk46;
    uint8_t unk47;
};
RED4EXT_ASSERT_SIZE(RuntimeSettingsVar, 0x48);
// char (*__kaboom)[sizeof(RuntimeSettingsVar)] = 1;

struct RuntimeSettingsVarBool : public RuntimeSettingsVar
{
    // vft RVA: 0x35E7838
    // str RVA: 0x35E77F0
    // Failed to create temporary file for saving '%hs' (temp file: '%hs')
    /// @pattern 46 61 69 6C 65 64 20 74 6F 20 63 72 65 61 74 65 20 74 65 6D 70 6F 72 61 72 79 20 66 69 6C 65 20
    /// @offset -72
    // static constexpr const uintptr_t VFT = userRuntimeSettingsVarBool_VFT_Addr;

    RuntimeSettingsVarBool()
        : RuntimeSettingsVar()
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

    virtual bool __fastcall RestoreDefault(uint8_t a1) override
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
                    SetRequestedValue(&defaultValue);
                    // UserSettings = GetUserSettings();
                    // AddSettingsDataToSettings(UserSettings, a1);
                }
                return !wasDefault;
            }
        UpdateImmediately:
            SetRequestedValue(&defaultValue);
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
            SetRequestedValue(&defaultValue);
            // v8 = GetUserSettings();
            // SettingsConfirmChange_0(v8, a1);
            break;
        case RED4ext::user::EConfigVarUpdatePolicy::RestartRequired:
            SetRequestedValue(&defaultValue);
            // v7 = GetUserSettings();
            // SettingsRestartRequired_0(v7, a1);
            break;
        case RED4ext::user::EConfigVarUpdatePolicy::LoadLastCheckpointRequired:
            SetRequestedValue(&defaultValue);
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

    virtual void __fastcall SetRequestedValue(void* value) override
    {
        valueInput = *(uint8_t*)value;
    }

    virtual void __fastcall AcceptChange() override
    {
        valueValidated = valueInput;
    }

    virtual void __fastcall RejectChange() override
    {
        valueInput = valueValidated;
    }

    virtual void __fastcall MarkAsSaved() override
    {
        valueWrittenToFile = valueValidated;
    }

    virtual void __fastcall LoadValue(void* value) override
    {
        valueWrittenToFile = *(uint8_t*)value;
        valueInput = *(uint8_t*)value;
        valueValidated = *(uint8_t*)value;
    }

    uint8_t valueValidated;
    uint8_t defaultValue;
    uint8_t valueInput;
    uint8_t valueWrittenToFile;
    uint32_t unk4C;
};
RED4EXT_ASSERT_SIZE(RuntimeSettingsVarBool, 0x50);
// char (*__kaboom)[sizeof(RuntimeSettingsVarBool)] = 1;

struct RuntimeSettingsVarFloat : public RuntimeSettingsVar
{
    // vft RVA: 0x35E8508
    // str RVA: 0x35E84A0
    // Unknown error.
    /// @pattern 55 6E 6B 6E 6F 77 6E 20 65 72 72 6F 72 2E
    /// @offset -104
    // static constexpr const uintptr_t VFT = userRuntimeSettingsVarFloat_VFT_Addr;

    RuntimeSettingsVarFloat()
        : RuntimeSettingsVar()
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
        float value;
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

    virtual bool __fastcall RestoreDefault(uint8_t a1) override
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
                    SetRequestedValue((int*)&defaultValue);
                    // UserSettings = GetUserSettings();
                    // AddSettingsDataToSettings(UserSettings, a1);
                }
                return !wasDefault;
            }
        UpdateImmediately:
            SetRequestedValue((int*)&defaultValue);
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
            SetRequestedValue((int*)&defaultValue);
            // v8 = GetUserSettings();
            // SettingsConfirmChange_0(v8, a1);
            break;
        case RED4ext::user::EConfigVarUpdatePolicy::RestartRequired:
            SetRequestedValue((int*)&defaultValue);
            // v7 = GetUserSettings();
            // SettingsRestartRequired_0(v7, a1);
            break;
        case RED4ext::user::EConfigVarUpdatePolicy::LoadLastCheckpointRequired:
            SetRequestedValue((int*)&defaultValue);
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

    virtual void __fastcall SetRequestedValue(void* value) override
    {
        valueInput = *(float*)value;
    }

    virtual void __fastcall AcceptChange() override
    {
        valueValidated = valueInput;
    }

    virtual void __fastcall RejectChange() override
    {
        valueInput = valueValidated;
    }

    virtual void __fastcall MarkAsSaved() override
    {
        valueWrittenToFile = valueValidated;
    }

    virtual void __fastcall LoadValue(void* value) override
    {
        valueWrittenToFile = *(float*)value;
        valueInput = *(float*)value;
        valueValidated = *(float*)value;
    }

    float valueValidated;     // 48
    float defaultValue;       // 4C
    float valueInput;         // 50
    float valueWrittenToFile; // 54
    float minValue;           // 58
    float maxValue;           // 5C
    float stepValue;          // 60
    uint32_t unk64;           // 64
};
RED4EXT_ASSERT_SIZE(RuntimeSettingsVarFloat, 0x68);

struct RuntimeSettingsVarFloatList : public RuntimeSettingsVar
{
    // Unknown error.
    /// @pattern 55 6E 6B 6E 6F 77 6E 20 65 72 72 6F 72 2E
    /// @offset -192
    /// @version 3.0.3933216
    /// @rva 0x35E8560
    // static constexpr const uintptr_t VFT = userRuntimeSettingsVarFloatList_VFT_Addr;

    float value;                   // 48
    float valueValidated;          // 4C
    float defaultValue;            // 50
    float valueInput;              // 54
    float valueWrittenToFile;      // 58
    uint32_t unk5C;                // 5C
    DynArray<float> values;        // 60
    DynArray<CName> displayValues; // 70
};
RED4EXT_ASSERT_SIZE(RuntimeSettingsVarFloatList, 0x80);

struct RuntimeSettingsVarInt : public RuntimeSettingsVar
{
    // vft RVA: 0x35E84B0
    // str RVA: 0x35E84A0
    // Unknown error.
    /// @pattern 55 6E 6B 6E 6F 77 6E 20 65 72 72 6F 72 2E
    /// @offset -16
    // static constexpr const uintptr_t VFT = userRuntimeSettingsVarInt_VFT_Addr;

    RuntimeSettingsVarInt()
        : RuntimeSettingsVar()
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

    virtual bool __fastcall RestoreDefault(uint8_t a1) override
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
                    SetRequestedValue(&defaultValue);
                    // UserSettings = GetUserSettings();
                    // AddSettingsDataToSettings(UserSettings, a1);
                }
                return !wasDefault;
            }
        UpdateImmediately:
            SetRequestedValue(&defaultValue);
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
            SetRequestedValue(&defaultValue);
            // v8 = GetUserSettings();
            // SettingsConfirmChange_0(v8, a1);
            break;
        case RED4ext::user::EConfigVarUpdatePolicy::RestartRequired:
            SetRequestedValue(&defaultValue);
            // v7 = GetUserSettings();
            // SettingsRestartRequired_0(v7, a1);
            break;
        case RED4ext::user::EConfigVarUpdatePolicy::LoadLastCheckpointRequired:
            SetRequestedValue(&defaultValue);
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

    virtual void __fastcall SetRequestedValue(void* value) override
    {
        valueInput = *(int32_t*)value;
    }

    virtual void __fastcall AcceptChange() override
    {
        valueValidated = valueInput;
    }

    virtual void __fastcall RejectChange() override
    {
        valueInput = valueValidated;
    }

    virtual void __fastcall MarkAsSaved() override
    {
        valueWrittenToFile = valueValidated;
    }

    virtual void __fastcall LoadValue(void* value) override
    {
        valueWrittenToFile = *(int32_t*)value;
        valueInput = *(int32_t*)value;
        valueValidated = *(int32_t*)value;
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
RED4EXT_ASSERT_SIZE(RuntimeSettingsVarInt, 0x68);

struct RuntimeSettingsVarIntList : public RuntimeSettingsVar
{
    RuntimeSettingsVarIntList()
        : RuntimeSettingsVar()
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

    virtual bool __fastcall RestoreDefault(uint8_t a1) override
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
                        SetRequestedValue(&defaultValue);
                        // UserSettings = GetUserSettings();
                        // AddSettingsDataToSettings(UserSettings, a1);
                    }
                    return !wasDefault;
                }
            UpdateImmediately:
                SetRequestedValue(&defaultValue);
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
                SetRequestedValue(&defaultValue);
                // v8 = GetUserSettings();
                // SettingsConfirmChange_0(v8, a1);
                break;
            case RED4ext::user::EConfigVarUpdatePolicy::RestartRequired:
                SetRequestedValue(&defaultValue);
                // v7 = GetUserSettings();
                // SettingsRestartRequired_0(v7, a1);
                break;
            case RED4ext::user::EConfigVarUpdatePolicy::LoadLastCheckpointRequired:
                SetRequestedValue(&defaultValue);
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

    virtual void __fastcall SetRequestedValue(void* value) override
    {
        valueInput = *(uint32_t*)value;
    }

    virtual void __fastcall AcceptChange() override
    {
        valueValidated = valueInput;
    }

    virtual void __fastcall RejectChange() override
    {
        valueInput = valueValidated;
    }

    virtual void __fastcall MarkAsSaved() override
    {
        valueWrittenToFile = valueValidated;
    }

    virtual void __fastcall LoadValue(void* value) override
    {
        valueWrittenToFile = *(uint32_t*)value;
        valueInput = *(uint32_t*)value;
        valueValidated = *(uint32_t*)value;
    }

    int32_t value;                 // 48
    int32_t valueValidated;        // 4C
    int32_t defaultValue;          // 50
    int32_t valueInput;            // 54
    int32_t valueWrittenToFile;    // 58
    int32_t unk5C;                 // 5C
    DynArray<int32_t> values;      // 60
    DynArray<CName> displayValues; // 70
};
RED4EXT_ASSERT_SIZE(RuntimeSettingsVarIntList, 0x80);

struct RuntimeSettingsVarName : RuntimeSettingsVar
{
    // 1.52
    // vft RVA: 0x35E7890
    // str RVA: 0x35E77F0
    // Failed to create temporary file for saving '%hs' (temp file: '%hs')
    /// @pattern 46 61 69 6C 65 64 20 74 6F 20 63 72 65 61 74 65 20 74 65 6D 70 6F 72 61 72 79 20 66 69 6C 65 20
    /// @offset -160
    // static constexpr const uintptr_t VFT = userRuntimeSettingsVarName_VFT_Addr;

    CName valueValidated;
    CName defaultValue;
    CName valueInput;
    CName valueWrittenToFile;
};
RED4EXT_ASSERT_SIZE(RuntimeSettingsVarName, 0x68);

struct RuntimeSettingsVarNameList : RuntimeSettingsVar
{
    // vft RVA: 0x35E7940
    // str RVA: 0x35E77F0
    // Failed to create temporary file for saving '%hs' (temp file: '%hs')
    /// @pattern 46 61 69 6C 65 64 20 74 6F 20 63 72 65 61 74 65 20 74 65 6D 70 6F 72 61 72 79 20 66 69 6C 65 20
    /// @offset -336
    // static constexpr const uintptr_t VFT = userRuntimeSettingsVarNameList_VFT_Addr;

    RuntimeSettingsVarNameList()
        : RuntimeSettingsVar()
    {
        values = RED4ext::DynArray<CName>(new Memory::DefaultAllocator());
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

    virtual bool __fastcall RestoreDefault(uint8_t a1) override
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
                        SetRequestedValue(&defaultValue);
                        // UserSettings = GetUserSettings();
                        // AddSettingsDataToSettings(UserSettings, a1);
                    }
                    return !wasDefault;
                }
            UpdateImmediately:
                SetRequestedValue(&defaultValue);
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
                SetRequestedValue(&defaultValue);
                // v8 = GetUserSettings();
                // SettingsConfirmChange_0(v8, a1);
                break;
            case RED4ext::user::EConfigVarUpdatePolicy::RestartRequired:
                SetRequestedValue(&defaultValue);
                // v7 = GetUserSettings();
                // SettingsRestartRequired_0(v7, a1);
                break;
            case RED4ext::user::EConfigVarUpdatePolicy::LoadLastCheckpointRequired:
                SetRequestedValue(&defaultValue);
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

    virtual void __fastcall SetRequestedValue(void* value) override
    {
        valueInput = *(uint32_t*)value;
    }

    virtual void __fastcall AcceptChange() override
    {
        valueValidated = valueInput;
    }

    virtual void __fastcall RejectChange() override
    {
        valueInput = valueValidated;
    }

    virtual void __fastcall MarkAsSaved() override
    {
        valueWrittenToFile = valueValidated;
    }

    // like this in FloatList, NameList, StringList, IntList
    virtual void __fastcall LoadValue(void* aValue) override
    {
        if (!bitfield.isDynamic || values.size)
        {
            valueWrittenToFile = *(uint32_t*)aValue;
            valueInput = *(uint32_t*)aValue;
            valueValidated = *(uint32_t*)aValue;
        }
        else
        {
            value = *(CName*)aValue;
            bitfield.unk20 = true;
        }
    }

    CName value;                   // 48
    uint32_t valueValidated;       // 50
    uint32_t defaultValue;         // 54
    uint32_t valueInput;           // 58
    uint32_t valueWrittenToFile;   // 5C
    DynArray<CName> values;        // 60
    DynArray<CName> displayValues; // 70
};
RED4EXT_ASSERT_SIZE(RuntimeSettingsVarNameList, 0x80);

struct RuntimeSettingsVarStringList : RuntimeSettingsVar
{
    // Entity/VisualController
    /// @pattern 45 6E 74 69 74 79 2F 56 69 73 75 61 6C 43 6F 6E 74 72 6F 6C 6C 65 72
    /// @offset -536
    /// @version 3.0.3933216
    /// @rva 0x32BB620
    // static constexpr const uintptr_t VFT = userRuntimeSettingsVarStringList_VFT_Addr;

    CString value;                 // 48
    uint32_t valueValidated;       // 68
    uint32_t defaultValue;         // 6C
    uint32_t valueInput;           // 70
    uint32_t valueWrittenToFile;   // 74
    DynArray<CString> values;      // 78
    DynArray<CName> displayValues; // 88
};
RED4EXT_ASSERT_SIZE(RuntimeSettingsVarStringList, 0x98);
#pragma pack(pop)
} // namespace user
} // namespace RED4ext
