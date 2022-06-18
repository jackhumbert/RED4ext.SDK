#pragma once

#include <RED4ext/Common.hpp>

namespace RED4ext
{

namespace user
{

struct RuntimeSettingsGroup;
struct RuntimeSettingsVar;

enum SettingsLoadStatus : uint8_t
{
    NotLoaded = 0,
    InternalError = 1,
    FileIsMissing = 2,
    FileIsCorrupted = 3,
    Loaded = 4,
    ImportedFromOldVersion = 5,
};

#pragma pack(push, 1)
struct RuntimeSettings
{
    CName root;
    HashMap<CName, RuntimeSettingsGroup*> m_registry;
    uint8_t updatingValidators;
    uint8_t validatorsPadding[7];
    HashMap<uint64_t, uint64_t> m_validators;
    DynArray<void*> unk70;
    HashMap<uint64_t, uint64_t> unk80;
    DynArray<void*> unkB0;
    HashMap<CString, uint32_t> updatePolicyMapping;
    HashMap<CString, uint32_t> importPolicyMapping;
    HashMap<CString, uint32_t> typeMapping;
    uint64_t unk150[8];
    uint8_t updatingImmediateChanges;
    uint8_t settingVarsPadding[7];
    DynArray<RuntimeSettingsVar*> immediateChanges;
    uint8_t updatingConfirmChanges;
    uint8_t unk1B0padding[7];
    DynArray<void*> confirmChanges;
    uint8_t updatingRestartChanges;
    uint8_t unk1C8padding[7];
    DynArray<void*> restartChanges;
    uint8_t updatingCheckpointChanges;
    uint8_t unk1E0padding[7];
    DynArray<void*> checkpointChanges;
    uint8_t updatingData;
    uint8_t data_padding[7];
    DynArray<RuntimeSettingsVar*> data;
    uint8_t updatingDelayedChanges;
    uint8_t unk210padding[7];
    DynArray<RuntimeSettingsVar*> delayedChanges;
    DynArray<void*> unk220;
    DynArray<void*> unk230;
    uint64_t unk240[4];
    SettingsLoadStatus loadStatus;
    uint8_t unk261;
    uint8_t unk262;
    uint8_t unk263;
    uint8_t unk264;
    uint8_t unk265;
    uint8_t unk266;
    uint8_t unk267;
    uint8_t version;
    uint8_t unk269;
    uint8_t unk26A;
    uint8_t unk26B;
    uint32_t unk26C;
    uint32_t unk270;
    uint32_t unk274;
};
#pragma pop(push)
RED4EXT_ASSERT_SIZE(RuntimeSettings, 0x278);
// char (*__kaboom)[sizeof(RuntimeSettings)] = 1;

} // namespace user
} // namespace RED4ext
