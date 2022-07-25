#include <RED4ext/Scripting/Natives/Generated/ent/Entity.hpp>

#define Entity_CopyComponentsToStorageAddr 0x1039020
/// @pattern 40 56 48 83 EC 20 48 89 5C 24 30 48 83 C2 50 49 83 78 18 00 49 8B F0 48 89 6C 24 38 48 8B E9 48
using Entity_CopyComponentsToStorage = __int64 __fastcall(RED4ext::ent::Entity *a1, RED4ext::ent::EntityDefinition *a2, __int64 *a3);

uintptr_t RED4ext::ent::Entity::CopyComponentsToStorage(void* definition, void* a2)
{
    RED4ext::Reloc<Entity_CopyComponentsToStorage>(Entity_CopyComponentsToStorageAddr);
}
