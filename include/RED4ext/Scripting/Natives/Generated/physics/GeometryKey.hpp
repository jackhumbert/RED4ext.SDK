#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/NativeTypes.hpp>

namespace RED4ext
{
namespace physics { 

// enum class StaticCollisionShapeCategory : uint32_t {
//     Interior = 0,
//     Exterior = 1,
//     Architecture = 2,
//     Decoration = 3,
//     Other = 4
// };

// enum class QueryUseCase : uint16_t {
//     Default = 0,
//     ActionAnimation = 1,
//     AI = 2,
//     AnimationComponent = 3,
//     Audio = 4,
//     AudioHedgehog = 5,
//     Components = 6,
//     Debug = 7,
//     Gameplay = 8,
//     GeomDescription = 9,
//     LineOfSightTests = 10,
//     Navigation = 11,
//     Nodes = 12,
//     Ragdoll = 13,
//     Scripts = 14,
//     VehicleAI = 15,
//     Vehicles = 16,
//     VehicleChassis = 17,
//     VehiclesCrowd = 18,
//     VehicleWheel = 19,
//     VehicleStreamingHack = 20,
//     VehicleWater = 21,
//     WorldUI = 22,
//     GameEffects = 23,
//     GameProjectiles = 24
// };

// enum class PhysicalSystemOwner : uint8_t {
//     Unknown = 0,
//     BakedDestructionNode = 1,
//     ClothMeshNode = 2,
//     CollisionAreaNode = 3,
//     DecorationMeshNode = 4,
//     DynamicMeshNode = 5,
//     InstancedDestructibleNode = 6,
//     PhysicalDestructionNode = 7,
//     PhysicalTriggerNode = 8,
//     StaticMeshNode = 9,
//     TerrainCollisionNode = 10,
//     WaterPatchNode = 11,
//     WorldCollisionNode = 12,
//     BakedDestructionComponent = 13,
//     ClothComponent = 14,
//     ColliderComponent = 15,
//     PhysicalDestructionComponent = 16,
//     PhysicalMeshComponent = 17,
//     PhysicalSkinnedMeshComponent = 18,
//     PhysicalTriggerComponent = 19,
//     SimpleColliderComponent = 20,
//     SkinnedClothComponent = 21,
//     StateMachineComponent = 22,
//     VehicleChassisComponent = 23,
//     PhysicalParticleSystem = 24,
//     PhotoModeSystem = 25,
//     RagdollBinder = 26,
//     FoliageDestruction = 27,
//     EntityProxy = 28
// };

struct GeometryKey
{
    static constexpr const char* NAME = "physicsGeometryKey";
    static constexpr const char* ALIAS = NAME;

    // 0x0, key used to look-up physx object in a hashmap
    NativeArray<uint8_t, 12> ta;
    // 0xC, type of physx Entity, likely ShapeType
    // 3 PxConvexMesh
    // 4 PxTriangleMesh
    // 5 PxHeightField
    uint8_t pe;
    uint8_t unk0D[0x10 - 0xD]; // D
};
RED4EXT_ASSERT_SIZE(GeometryKey, 0x10);
} // namespace physics
using physicsGeometryKey = physics::GeometryKey;
} // namespace RED4ext

// clang-format on
