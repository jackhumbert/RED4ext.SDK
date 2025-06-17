#pragma once

#ifdef RED4EXT_STATIC_LIB
#include <RED4ext/Scripting/Natives/entIComponent.hpp>
#endif

namespace RED4ext
{
namespace ent
{

RED4EXT_INLINE bool IComponent::sub_110(CName propertyName, void* out) {
    UniversalRelocFunc<decltype(&IComponent::sub_110)> call(VFT, 0x110);
    return call(this, propertyName, out);
}

RED4EXT_INLINE bool IComponent::sub_118(CName propertyName, void* out) {
    UniversalRelocFunc<decltype(&IComponent::sub_118)> call(VFT, 0x118);
    return call(this, propertyName, out);
}

RED4EXT_INLINE Handle<game::PersistentState>* IComponent::sub_150(Handle<game::PersistentState>* a1) {
    UniversalRelocFunc<decltype(&IComponent::sub_150)> call(VFT, 0x150);
    return call(this, a1);
}

RED4EXT_INLINE bool IComponent::sub_158() {
    UniversalRelocFunc<decltype(&IComponent::sub_158)> call(VFT, 0x158);
    return call(this);
}

RED4EXT_INLINE bool IComponent::sub_160() {
    UniversalRelocFunc<decltype(&IComponent::sub_160)> call(VFT, 0x160);
    return call(this);
}

RED4EXT_INLINE uint64_t IComponent::Initialize(CompInit* a1) {
    UniversalRelocFunc<decltype(&IComponent::Initialize)> call(VFT, 0x170);
    return call(this, a1);
}

RED4EXT_INLINE void IComponent::Uninitialize(ScriptGameInstance* a1) {
    UniversalRelocFunc<decltype(&IComponent::Uninitialize)> call(VFT, 0x178);
    return call(this, a1);
}

RED4EXT_INLINE void IComponent::OnAttach(void* a1) {
    UniversalRelocFunc<decltype(&IComponent::OnAttach)> call(VFT, 0x180);
    return call(this, a1);
}

RED4EXT_INLINE bool IComponent::OnDetach(void *a1) {
    UniversalRelocFunc<decltype(&IComponent::OnDetach)> call(VFT, 0x190);
    return call(this, a1);
}

RED4EXT_INLINE uint64_t IComponent::OnRenderSelection(uint64_t a1) {
    UniversalRelocFunc<decltype(&IComponent::OnRenderSelection)> call(VFT, 0x1F8);
    return call(this, a1);
}

RED4EXT_INLINE const char * IComponent::GetBucketString() {
    UniversalRelocFunc<decltype(&IComponent::GetBucketString)> call(VFT, 0x220);
    return call(this);
}

RED4EXT_INLINE CClass* IComponent::GetReplicatedStateClass() {
    UniversalRelocFunc<decltype(&IComponent::GetReplicatedStateClass)> call(VFT, 0x228);
    return call(this);
}

} // namespace ent
} // namespace RED4ext
