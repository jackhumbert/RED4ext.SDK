#include <RED4ext/Scripting/Natives/Generated/world/NodeEditorData.hpp>
#include <RED4ext/Scripting/Natives/Generated/world/Prefab.hpp>
#include <RED4ext/Scripting/Natives/Generated/world/PrefabNode.hpp>
#include <RED4ext/Scripting/Natives/Generated/world/StreamingSector.hpp>
#include <RED4ext/Scripting/Natives/Generated/world/NodesGroup.hpp>
#include <RED4ext/Scripting/Natives/Generated/world/Node.hpp>
#include <RED4ext/Scripting/Natives/Generated/world/InstancedDestructibleMeshNode.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/data/Vehicle_Record.hpp>
#include <RED4ext/Scripting/Natives/Generated/ISerializable.hpp>
#include <RED4ext/Scripting/Functions.hpp>
#include <RED4ext/TweakDB.hpp>
using namespace RED4ext;

/// @pattern 48 89 5C 24 ? 57 48 81 EC ? ? ? ? 48 8B 02
/// @nth 1/9
using CBaseFunction_Execute = bool (CBaseFunction* self, CStack* aStack);

/// @pattern 48 89 5C 24 08 57 48 83 EC 20 49 8B D9
/// @nth 0/6
using CGlobalFunction_ctor = CGlobalFunction* (CGlobalFunction*, CName, CName, ScriptingFunction_t<void*>);

/// @pattern 48 89 5C 24 08 48 89 74 24 10 57 48 83 EC 20 48 8D 05 ? ? ? ? 48 C7 41 08 00 00 00 00
/// @nth 1/3
using CStack_ctor = CStack* (CStack*, ScriptInstance, CStackType*, uint32_t, CStackType*, int64_t);

/// @pattern 48 89 6C 24 20 57 41 54 41 56 48 83 EC ?
/// @nth 0/2
using DynArray_Realloc = void (DynArray<void*> * aThis, uint32_t aCapacity, uint32_t aElementSize, uint32_t aAlignment,
                               void (*a5)(int64_t, int64_t, int64_t, int64_t));

/// @pattern 40 53 48 83 EC 20 33 C0 C6 01 00
/// @nth 2/4
using CString_ctor = CString* (CString*, const char*);

/// @pattern 48 89 5C 24 08 ? 89 ? 24 18 57 48 83 EC 30 8B C2
using TweakDB_CreateRecord = void (TweakDB*, uint32_t aBaseMurmur3, TweakDBID aDBID);

/// @pattern 48 89 5C 24 10 57 48 83 EC 30 F6 41 70 0C 48 8B F9
using CClass_GetMaxAlignment = uint32_t (const CClass*);

/// @pattern 48 89 5C 24 18 56 48 83 EC 20 83 B9 F0 00 00 00 00
using CClass_GetProperty = CProperty* (CClass*, CName);

/// @pattern 40 56 41 56 48 83 EC ? 41 0F B6 F0
using CClass_AllocInstance = ScriptInstance (const CClass*, uint32_t, bool);

/// @pattern 48 89 4C 24 08 53 56 48 83 EC 58
using CClass_sub_D0 = bool (const CClass*);

/// @pattern 40 53 48 83 EC 20 48 83 79 38 00 48 8B D9 75
/// @nth 1/2
using IScriptable_GetValueHolder = void* (IScriptable*);

// jack's

/// @pattern 48 89 5C 24 08 57 48 83 EC 20 48 8B D9 ? ? ? ? ? 33 FF ? ? ? ? ? ? ? 48 89 03
/// @nth 1/10
using InitializeNodeEditorData = world::NodeEditorData* (world::NodeEditorData*);

/// @pattern 40 53 48 83 EC 20 65 48 8B 04 25 58 00 00 00 8B 0D 5B 60 04 04
using GetNodeEditorData = world::NodeEditorData* ();

/// @pattern 33 C0 C7 41 1C 00 00 80 3F 48 89 01 89 41 08 48 89 41 10 89 41 18 48 8B C1 C7 41 20 00 00 80 3F C7 41 24 00 00 80 3F C7 41 28 00 00 80 3F C3
using InitializeNodeTransform = world::NodeTransform* (world::NodeTransform*);

/// @pattern 48 89 5C 24  08 48 89 6C 24 10 48 89  74 24 18 57 48 83 EC 40  48 8B FA 48 8B D9 E8 01  03 00 00
using GetUsableGlobalName = CString* (uint64_t, CString*);

/// @pattern 48 89 5C 24 10 48 89 6C  24 18 56 57 41 56 48 83 EC 70 48 8B 99 18 02 00  00 49 8B E8 8B 81 24 02
using GetNodeEditorDataFromPrefab = world::NodeEditorData* (world::Prefab*, world::NodeEditorData*, CString*);

/// @pattern 40 53 48 83 EC 40 48 8B  D9 E8 C2 72 11 FF 81 BB DC 00 00 00 00 01 00 00  0F 86 FA 00 00 00 48 8D
using ukWorldInstancedDestructibleMeshNode = void (world::InstancedDestructibleMeshNode*);

/// @pattern 33 C0 4C 8B CA 48 89 02  4C 8B C1 48 89 42 08 48 8B 41 38 48 85 C0 74 2E  8B 00 85 C0 74 28 66 90
using GetNode = Handle<world::Node>* (world::NodeEditorData*, world::Node*);

// @pattern 48 8B C4 53 48 81 EC 20  01 00 00 48 83 79 30 00 48 8B D9 0F 84 86 01 00  00 48 8D 48 08 48 89 70
// using uk1PrefabNode = void ** (world::PrefabNode*);

/// @pattern 40 55 56 57 41 54 41 56  41 57 48 8D 6C 24 E8 48 81 EC 18 01 00 00 45 33  E4 4C 8B FA 44 89 65 60
using uk2PrefabNode = char** (world::PrefabNode*, char**);

/// @pattern 48 89 5C 24 08 57 48 83  EC 20 48 8B CA 48 8B FA E8 FB 8C 65 FF 48 8D 05  24 A9 64 02 48 8D 4C 24
using InitializeWorldStreamingSector = void (uint64_t, world::StreamingSector*);

/// @pattern 48 89 5C 24 18 55 56 57  48 8D AC 24 50 FF FF FF 48 81 EC B0 01 00 00 48  8B D9 48 8D 4D C0 E8 DD 1A 5F FF 48 8D 4C 24 30  E8 93 28 5F FF 48 8D 4C
using SetupVehicle_Record = void* (game::data::Vehicle_Record*);

/// @pattern 48 3B D1 75 03 B0 01 C3  48 8B 41 10 48 85 C0 0F 84 09 01 00 00 48 3B D0  74 EB 48 8B 48 10 48 85
using IsChildClass = bool (CClass*, CClass*);

/// @pattern 48 8B C4 48 89 58 08 57  48 81 EC 90 00 00 00 F3 0F 10 05 99 43 3B 01 0F  57 ED 0F 29 70 E8 49 8B
using VehicleTTPCalculatePitch = int64_t (vehicle::TPPCameraComponent*, Vector3*, Vector3, Matrix*);

/// @pattern 48 89 5C 24 18 55 56 57  41 56 41 57 48 8D AC 24 10 FF FF FF 48 81 EC F0  01 00 00 48 8B F1 48 8D
using RegisterCameraComponentScriptInterface = int64_t (game::data::Vehicle_Record*);