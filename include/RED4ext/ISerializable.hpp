#pragma once

#include <cstdint>

#include <RED4ext/Common.hpp>
#include <RED4ext/Handle.hpp>

namespace RED4ext
{
namespace Memory
{
struct IAllocator;
}

struct CClass;
struct BaseStream;
struct CString;

struct PostLoadParams
{
    bool disablePreInitialization; // 00
    uint8_t pad01[0x8 - 0x1];      // 01
};
RED4EXT_ASSERT_SIZE(PostLoadParams, 0x8);

struct ISerializable
{
    //static constexpr const char* NAME = "ISerializable";
    //static constexpr const char* ALIAS = NAME;

    /// @pattern
    ///     /vft(ISerializable_GetNativeType)                                           // GetNativeType
    ///     /vft(ISerializable_GetNativeType)                                           // GetType
    ///     /vft                                                                        // GetAllocator
    ///     /vft                                                                        // dstr
    ///     /vft(null)                                                                  // sub_20
    ///     /vft(null)                                                                  // sub_28
    ///     /vft                                                                        // sub_30
    ///     /vft(null)                                                                  // sub_38
    ///     /vft(ISerializable_OnSerialize)                                             // sub_40
    ///     /vft(ISerializable_OnSerializeToText)                                       // sub_48
    ///     /vft(ISerializable_OnSerializeFromText)                                     // sub_50
    /// @segment rdata
    /// @nth 0/0
    static constexpr const uintptr_t VFT = ISerializable_VFT_Addr;

    // static const CClass* CLASS = reinterpret_cast<CClass *>(reinterpret_cast<uintptr_t>(GetModuleHandle(nullptr)) + ISerializable_Class_Addr);

    // 1.52 RVA: 0x1AB240 / 1749568
    /// @pattern 40 53 48 83 EC 20 48 8D 05 7B DA EC 02 48 8B D9 48 89 01 33 C0 48 89 41 08 48 89 41 10 48 89 41
    //ISerializable() = default;

    ISerializable();

    // 1.6  RVA: 0x1AFD70 / 1768816
    /// @pattern 40 53 48 83 EC 50 4C 8B C2 48 8B D9 48 85 D2 0F 84 C5 00 00 00 48 8B 42 10 0F 57 C0 66 0F 7F 44
    void __fastcall SetOwner(ISerializable *owner);

    /// @pattern /mov(ISerializable_Class_p) /retn
    /// @noimpl 1
    virtual CClass* GetNativeType() = 0;                                                // 00 GetNativeClass
    virtual CClass* GetType();                                                          // 08 GetClass
    virtual Memory::IAllocator* GetAllocator();                                         // 10 GetInnerTypeMemoryPool
    virtual ~ISerializable() = default;                                                 // 18 ~Type
    virtual void sub_20(Handle<ISerializable>* a1);                                     // 20
    virtual void PostLoad(const PostLoadParams& aParams);                               // 28 OnPostLoad
    virtual bool sub_30();                                                              // 30 OnPropertyPreChange
    virtual void sub_38();                                                              // 38 OnPropertyPostChange
    virtual bool sub_40(BaseStream* aStream);                                           // 40 OnSerialize
    virtual bool sub_48(int64_t a1);                                                    // 48 OnSerializeToText
    virtual bool sub_50(int64_t a1);                                                    // 50 OnSerializeFromText
    virtual bool sub_58();                                                              // 58 
    virtual bool sub_60();                                                              // 60 OnPropertyTypeMismatch
    virtual bool sub_68();                                                              // 68 
    virtual bool sub_70();                                                              // 70 
    virtual int64_t sub_78(int64_t a1, int64_t a2, uint8_t a3, int64_t a4, int64_t a5); // 78 CreateView
    virtual bool sub_80();                                                              // 80 
    virtual void sub_88();                                                              // 88 GetCustomEditableProperties
    virtual bool sub_90();                                                              // 90 ReadCustomEditableProperties
    virtual bool sub_98();                                                              // 98 WriteCustomEditableProperties
    virtual void* sub_A0();                                                             // A0 GetBaseObjectData
    virtual CClass* sub_A8();                                                           // A8 GetEmbodiment
    virtual void sub_B0(void* a1);                                                      // B0 GetEditorObject
    virtual CString sub_B8();                                                           // B8 GetFriendlyName
    virtual void* sub_C0(void* a1);                                                     // C0 FindParent<CResource>
    virtual void* sub_C8(void* a1);                                                     // C8
    virtual bool CanBeDestructed();                                                     // D0

    bool IsOfClass(const CClass* cls);
    operator const WeakHandle<ISerializable>&() const noexcept;
    operator Handle<ISerializable>() noexcept;

    [[nodiscard]] const char* ToString();

    WeakHandle<ISerializable> ref;   // 00 - Initialized in Handle ctor
    WeakHandle<ISerializable> unk18; // 18 - Owner/parent
    uint64_t unk28;                  // 28 - Incremental ID set in ISerializable ctor, can be zero. Global incremental ID, used in serialization

};
RED4EXT_ASSERT_SIZE(ISerializable, 0x30);
} // namespace RED4ext

/**
 * @brief Adds default implementation for generated/imported class.
 * Allows ISerializable class to be used without Handle<> and RTTI construction.
 * Some ISerializables are used as structs, without initilializing ref counter.
 */
#ifndef RED4EXT_IMPL_NATIVE_TYPE
#define RED4EXT_IMPL_NATIVE_TYPE()                                                                                     \
    CClass* GetNativeType() override                                                                                   \
    {                                                                                                                  \
        return CRTTISystem::Get()->GetClass(NAME);                                                                     \
    }
#endif

#ifdef RED4EXT_HEADER_ONLY
#include <RED4ext/ISerializable-inl.hpp>
#endif
