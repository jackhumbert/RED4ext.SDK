#pragma once

#ifdef RED4EXT_STATIC_LIB
#include <RED4ext/Scripting/IScriptable.hpp>
#endif

#include <RED4ext/Detail/AddressHashes.hpp>
#include <RED4ext/RTTITypes.hpp>
#include <RED4ext/Relocation.hpp>

namespace RED4ext
{

RED4EXT_INLINE CClass* IScriptable::GetNativeType()
{
    static UniRelocFunc<decltype(&IScriptable::GetNativeType)> func(VFT, 0);
    return func(this);
}

RED4EXT_INLINE IScriptable::IScriptable()
    : valueHolder(nullptr)
    , nativeType(nullptr)
{
}

RED4EXT_INLINE IScriptable::~IScriptable()
{
    DestructValueHolder();
}

RED4EXT_INLINE CClass* IScriptable::GetType()
{
    if (nativeType)
    {
        return nativeType;
    }

    return GetNativeType();
}

RED4EXT_INLINE void IScriptable::sub_D8(int64_t a1, int64_t a2)
{
    UniRelocFunc<decltype(&IScriptable::sub_D8)> func(VFT, 0xD8);
    func(this, a1, a2);
}

RED4EXT_INLINE void IScriptable::sub_E0()
{
}

RED4EXT_INLINE void IScriptable::sub_E8()
{
}

RED4EXT_INLINE void IScriptable::sub_F0()
{
}

RED4EXT_INLINE void IScriptable::sub_F8()
{
}

RED4EXT_INLINE void IScriptable::sub_100()
{
}

RED4EXT_INLINE void* IScriptable::GetValueHolder()
{
    if (valueHolder)
    {
        return valueHolder;
    }

    auto type = nativeType;
    if (!type)
    {
        type = GetNativeType();
    }

    type->InitializeProperties(this);
    return valueHolder;
}

RED4EXT_INLINE void IScriptable::DestructValueHolder()
{
    using func_t = void* (*)(IScriptable*);
    static UniversalRelocFunc<func_t> func(Detail::AddressHashes::IScriptable_DestructValueHolder);
    func(this);
}

RED4EXT_INLINE IScriptable::operator const WeakHandle<IScriptable>&() const noexcept
{
    return *reinterpret_cast<const WeakHandle<IScriptable>*>(&ref);
}

RED4EXT_INLINE IScriptable::operator Handle<IScriptable>() noexcept
{
    if (ref.instance)
    {
        return *reinterpret_cast<const WeakHandle<IScriptable>*>(&ref);
    }
    else
    {
        return Handle<IScriptable>(this);
    }
}

}