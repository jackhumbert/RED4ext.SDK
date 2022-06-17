#pragma once

#include <RED4ext/Common.hpp>

namespace RED4ext
{

namespace user
{

class RuntimeSettingsGroup;

class RuntimeSettings
{
    CName unk00;
    HashMap<CName, RuntimeSettingsGroup> m_registry;
    uint64_t unk38;
    HashMap<uint64_t, uint64_t> unk40;
    DynArray<void*> unk70;
    HashMap<uint64_t, uint64_t> unk80;
    DynArray<void*> unkB0;
    HashMap<CString, uint32_t> updatePolicyOptions;
    HashMap<CString, uint32_t> importPolicyMapping;
    HashMap<CString, uint32_t> typeOptions;
    uint64_t unk150[8];
    uint8_t updatingSettingsVar;
    uint8_t unk191;
    uint8_t unk192;
    uint8_t unk193;
    uint8_t unk194;
    uint8_t unk195;
    uint8_t unk196;
    uint8_t unk197;
    DynArray<void*> settingVarsToUpdate;
    uint64_t unk1A8;
    DynArray<void*> unk1B0;
    uint64_t unk1C0;
    DynArray<void*> unk1C8;
    uint64_t unk1D8;
    DynArray<void*> unk1E0;
    uint64_t unk1F0;
    DynArray<void*> unk1F8;
    uint64_t unk208;
    DynArray<void*> unk210;
    DynArray<void*> unk220;
    DynArray<void*> unk230;
    uint64_t unk240[4];
    uint8_t unk260;
    uint8_t unk261;
    uint8_t unk262;
    uint8_t unk263;
    uint8_t unk264;
    uint8_t unk265;
    uint8_t unk266;
    uint8_t unk267;
    uint32_t unk268;
};

} // namespace user
} // namespace RED4ext
