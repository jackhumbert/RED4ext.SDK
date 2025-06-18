#pragma once

#ifdef RED4EXT_STATIC_LIB
#include <RED4ext/Scripting/Natives/Generated/ent/Entity.hpp>
#endif

namespace RED4ext
{
namespace ent
{

RED4EXT_INLINE uintptr_t Entity::CopyComponentsToStorage(EntityDefinition* definition, void* a2)
{
    static UniRelocFunc<decltype(&Entity::CopyComponentsToStorage)> func(VFT, 0x1A8);
    return func(this, definition, a2);
}
    
RED4EXT_INLINE float __fastcall Entity::sub_110() {
    return 1.0;
}

RED4EXT_INLINE Vector2 * __fastcall Entity::sub_118(Vector2 * a1, Vector2 * a2) {
    a1->X = a2->Y;
    a1->Y = a2->X * a2->Y;
    return a1;
}

RED4EXT_INLINE uint8_t __fastcall Entity::sub_120() {
    return false;
}

RED4EXT_INLINE uint8_t __fastcall Entity::sub_128() {
    return 1;
}

// RED4EXT_INLINE bool __fastcall Entity::sub_130() {
//     UniversalRelocFunc<decltype(&Entity::sub_130)> call(VFT, 0x128);
//     return call(this);
// }

RED4EXT_INLINE void Entity::sub_130()
{
    static UniRelocFunc<decltype(&Entity::sub_130)> func(VFT, 0x130);
    func(this);
}


// 1.61 RVA: 0x1046140
// 1.61hf1 RVA: 0x1046F30
//RED4EXT_INLINE uint64_t Entity::SetupEntityAndComponents(EntityDefinition* definition)
//{
//    UniversalRelocFunc<decltype(&Entity::SetupEntityAndComponents)> call(0x1046F30);
//    return call(this, definition);
//}

} // namespace ent
} // namespace RED4ext
