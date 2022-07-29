#pragma once

#ifdef RED4EXT_STATIC_LIB
#include <RED4ext/Scripting/Natives/entEntity.hpp>
#endif

namespace RED4ext
{
namespace ent
{
#define Entity_CopyComponentsToStorageAddr 0x1039020
/// @pattern 40 56 48 83 EC 20 48 89 5C 24 30 48 83 C2 50 49 83 78 18 00 49 8B F0 48 89 6C 24 38 48 8B E9 48
using Entity_CopyComponentsToStorage = __int64 __fastcall(Entity *a1, EntityDefinition *a2, __int64 *a3);

RED4EXT_INLINE uintptr_t Entity::CopyComponentsToStorage(void* definition, void* a2)
{
    RED4ext::Reloc<Entity_CopyComponentsToStorage>(Entity_CopyComponentsToStorageAddr);
}

RED4EXT_INLINE Vector2 * __fastcall Entity::sub_120(Vector2 * a1, Vector2 * a2) {
    a1->X = a2->Y;
    a1->Y = a2->X * a2->Y;
    return a1;
}

RED4EXT_INLINE bool __fastcall Entity::sub_130() {
    return this->flags & Flags::Unk1;
}

RED4EXT_INLINE void Entity::sub_138()
{
    RelocVirtualFunc<decltype(&Entity::sub_138)> call(VFT_RVA, 0x138);
    return (this->*call)();
}

RED4EXT_INLINE uint64_t Entity::SetupEntityAndComponents(EntityDefinition* definition)
{
    RelocFunc<decltype(&Entity::SetupEntityAndComponents)> call(16977024);
    return call(this, definition);
}

} // namespace ent
} // namespace RED4ext