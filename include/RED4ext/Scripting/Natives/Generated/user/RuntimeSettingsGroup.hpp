#pragma once

#include <RED4ext/Common.hpp>

namespace RED4ext
{

namespace user
{

class RuntimeSettingsGroup
{
    CName parentPath;
    CName path;
    CName name;
    CName displayName;
    DynArray<CName> groups;
    HashMap<CName, class RuntimeSettingsVar*> m_options;
    uint64_t order;
};

} // namespace user
} // namespace RED4ext
