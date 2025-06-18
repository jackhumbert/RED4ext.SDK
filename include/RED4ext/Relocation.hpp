#pragma once

#include <cstdint>
#include <filesystem>
#include <string_view>

#include <Windows.h>

#include <RED4ext/Api/Sdk.hpp>

namespace RED4ext
{
class RelocBase
{
public:
    static uintptr_t GetImageBase();
};

/**
 * @brief Represent a native function, use this to relocate its address at runtime.
 * @tparam T The type.
 */
template<typename T>
class RelocFuncBase : private RelocBase
{
public:
    RelocFuncBase(uintptr_t aOffset)
        : m_address(reinterpret_cast<T>(aOffset + GetImageBase()))
    {
    }

    RelocFuncBase(uintptr_t aVftOffset, uintptr_t aOffset)
        : m_address(*reinterpret_cast<T*>(aVftOffset + aOffset + GetImageBase()))
    {
    }

    inline operator T() const
    {
        return m_address;
    }

private:
    T m_address;
};

/**
 * @brief Represent a native function, use this to relocate its address at runtime.
 * @tparam T The type.
 */
template<typename T>
class RelocFunc
{
};

template<typename R, typename... Args>
class RelocFunc<R (*)(Args...)> : public RelocFuncBase<R (*)(Args...)>
{
    using RelocFuncBase<R (*)(Args...)>::RelocFuncBase;
};

template<typename C, typename R, typename... Args>
class RelocFunc<R (C::*)(Args...)> : public RelocFuncBase<R (*)(C*, Args...)>
{
    using RelocFuncBase<R (*)(C*, Args...)>::RelocFuncBase;
};

/**
 * @brief Represent a native virtual member function, use this to relocate its address at runtime.
 * @tparam T The type.
 */
//template<typename T>
//class RelocVirtualFunc : private RelocBase
//{
//public:
//    RelocVirtualFunc(uintptr_t aVftOffset, uintptr_t aOffset)
//        : m_address(*reinterpret_cast<T*>(aVftOffset + aOffset + GetImageBase()))
//    {
//    }
//
//    inline operator T() const
//    {
//        return m_address;
//    }
//
//private:
//    T m_address;
//};

//template<typename T>
//class RelocVirtualFunc
//{
//};
//
//template<typename C, typename R, typename... Args>
//class RelocVirtualFunc<R (C::*)(Args...)> : public RelocFuncBase<R (*)(C*, Args...)>
//{
//    using RelocFuncBase<R (*)(C*, Args...)>::RelocFuncBase;
//};


/**
 * @brief Represent a native struct, use this to relocate its address at runtime.
 * @tparam T The type.
 */
template<typename T>
class RelocFundamental : private RelocBase
{
public:
    RelocFundamental(uintptr_t aOffset)
        : m_address(aOffset + GetImageBase())
    {
        m_pointer = reinterpret_cast<T*>(malloc(sizeof(T)));
        memset(m_pointer, 0, sizeof(T));
        // assign m_address to vft
        *(uintptr_t*)m_pointer = m_address;
    }

    ~RelocFundamental() {
        free(m_pointer);
    }

    inline operator T*() const
    {
        return m_pointer;
    }

    inline T* operator->() const
    {
        return m_pointer;
    }

private:
    uintptr_t m_address;
    T * m_pointer;
};

/**
 * @brief Represent a native pointer, use this to relocate its address at runtime.
 * @tparam T The type.
 */
template<typename T>
class RelocPtr : private RelocBase
{
public:
    RelocPtr(uintptr_t aOffset)
        : m_address(reinterpret_cast<T*>(aOffset + GetImageBase()))
    {
    }

    inline operator T() const
    {
        return *m_address;
    }

    inline T* GetAddr() const
    {
        return m_address;
    }

private:
    T* m_address;
};

/**
 * @brief Represent a native virtual table, use this to relocate its address at runtime.
 * @tparam T The type.
 */
class RelocVtbl : private RelocBase
{
public:
    RelocVtbl(uintptr_t aOffset)
        : m_address(reinterpret_cast<uintptr_t*>(aOffset + GetImageBase()))
    {
    }

    inline operator uintptr_t*() const
    {
        return m_address;
    }

private:
    uintptr_t* m_address;
};

class UniversalRelocBase
{
public:
    static uintptr_t Resolve(uint32_t aHash);

private:
    using QueryFunc_t = void (*)(PluginInfo*);
    using ResolveFunc_t = std::uintptr_t (*)(std::uint32_t);

    static HMODULE GetRED4extModule();

    static ResolveFunc_t InitializeAddressResolverFunction();
    static ResolveFunc_t GetAddressResolverFunction();

    static HMODULE GetCurrentModuleHandle();
    static std::filesystem::path GetCurrentModulePath();

    static QueryFunc_t GetCurrentPluginQueryFunction();
    static bool QueryCurrentPlugin(PluginInfo& aPluginInfo);

    static void ShowErrorAndTerminateProcess(std::wstring_view aMsg, std::uint32_t aLastError,
                                             bool aQueryPluginInfo = true);
};

/**
 * @brief Represent a native function, use this to relocate its address at runtime.
 * @tparam T The type.
 */
template<typename T>
class UniversalRelocFunc : private UniversalRelocBase
{
public:
    UniversalRelocFunc(uint32_t aHash)
        : m_address(reinterpret_cast<T>(Resolve(aHash)))
    {
    }

    UniversalRelocFunc(uint32_t aVftHash, uintptr_t aSubOffset)
        : m_address(*reinterpret_cast<T*>(Resolve(aVftHash) + aSubOffset))
    {
    }

    inline operator T() const
    {
        return m_address;
    }

private:
    T m_address;
};

/**
 * @brief Represent a native pointer, use this to relocate its address at runtime.
 * @tparam T The type.
 */
template<typename T>
class UniversalRelocPtr : private UniversalRelocBase
{
public:
    UniversalRelocPtr(uint32_t aHash)
        : m_address(reinterpret_cast<T*>(Resolve(aHash)))
    {
    }

    inline operator T() const
    {
        return *m_address;
    }

    inline T* GetAddr() const
    {
        return m_address;
    }

private:
    T* m_address;
};

template<typename T>
class UniRelocFunc
{
};

template<typename R, typename... Args>
class UniRelocFunc<R (*)(Args...)> : public UniversalRelocFunc<R (*)(Args...)>
{
    using UniversalRelocFunc<R (*)(Args...)>::UniversalRelocFunc;
};

template<typename C, typename R, typename... Args>
class UniRelocFunc<R (C::*)(Args...)> : public UniversalRelocFunc<R (*)(C*, Args...)>
{
    using UniversalRelocFunc<R (*)(C*, Args...)>::UniversalRelocFunc;
};

/**
 * @brief Represent a native virtual table, use this to relocate its address at runtime.
 * @tparam T The type.
 */
class UniversalRelocVtbl : private UniversalRelocBase
{
public:
    UniversalRelocVtbl(uint32_t aHash)
        : m_address(reinterpret_cast<uintptr_t*>(Resolve(aHash)))
    {
    }

    inline operator uintptr_t*() const
    {
        return m_address;
    }

private:
    uintptr_t* m_address;
};

} // namespace RED4ext

#ifdef RED4EXT_HEADER_ONLY
#include <RED4ext/Relocation-inl.hpp>
#endif
