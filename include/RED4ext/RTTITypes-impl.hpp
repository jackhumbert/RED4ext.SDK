#pragma once

#ifdef RED4EXT_STATIC_LIB
#include <RED4ext/RTTITypes.hpp>
#endif

#include <RED4ext/Addresses.hpp>
#include <RED4ext/REDfunc.hpp>

RED4EXT_INLINE RED4ext::IScriptable* RED4ext::CClass::AllocInstance()
{
    using func_t = IScriptable* (*)(CClass*, uint32_t, bool);
    static REDfunc<func_t> func(Addresses::CClass_GetFunction);
    return func(this, GetSize(), 0);
}

RED4EXT_INLINE bool RED4ext::CClass::IsA(IRTTIType* aType)
{
    if (this == aType)
    {
        return true;
    }

    if (parent)
    {
        return parent->IsA(aType);
    }

    return false;
}

RED4EXT_INLINE RED4ext::CClassFunction* RED4ext::CClass::GetFunction(CName aName)
{
    using func_t = CClassFunction* (*)(CClass*, CName);
    static REDfunc<func_t> func(Addresses::CClass_GetFunction);
    return func(this, aName);
}
