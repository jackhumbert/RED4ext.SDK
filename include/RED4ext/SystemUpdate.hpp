#pragma once

#include <cstdint>

#include <RED4ext/Callback.hpp>
#include <RED4ext/Common.hpp>
#include <RED4ext/JobQueue.hpp>
#include <RED4ext/Scripting/Natives/Generated/UpdateBucketEnum.hpp>

namespace RED4ext
{
struct IUpdatableSystem;

// enum class UpdateTickGroup : unsigned char
// {
//     // TierSystem, MountingFacility, HitRepresentationSystem
//     // AIDirectorSystem, UpdateTime, Damage, TrafficSystemMovement
//     // Audio/FinishAsyncJob, Traffic_FrameStart, DebugCheatsSystem
//     // Navigation/Update, RuntimeSystemDestruction/WaitFractureCallbacks
//     // GameRules, RuntimeSystemNodeStreaming/ProcessNodes
//     // Multiplayer/UpdateTime, AnimationSystem_FrameBeginReset
//     // PlayerManager/Tick
//     FrameBegin = 0x0,
//     // Server/DeleteEntities
//     Multiplayer_UpdateStateSnapshots = 0x1,
//     // TrafficMovement/UpdateAvoidanceManager, Entities/UpdateState
//     EntityUpdateState = 0x2,
//     // EffectorSystem, vehicleMoveSystem, ApplyWind, VisionModeSystem
//     // TrafficSystemMovement_UpdateVehicles, PersistencySystem/HandlePSEvents
//     // WeatherSystem, TransformAnimator, PlayerSystem, FunctionalTests/OnPreWorldTick
//     // CorpseSystem_ExecuteTransaction, AnimationSystem_ExecuteTransaction
//     // ContainerManager/TickVisibility, ProjectileSystem/TickPreBuckets
//     PreBuckets = 0x3,
//     // Many are this
//     // ShootingAccuracySystem, TransformsHistorySystem
//     // EnvironmentDamageSystem, DeviceSystem/TickDeviceVisibility
//     // Audio, UI/RuntimeSystem/AudioHandlersUpdate
//     Buckets = 0x4,
//     // TransactionSystem, LightSystem, LootManager,
//     // ObjectCarrySystem, FootstepSystem, DelaySystem
//     // CooldownSystem, CombatQueriesSystem, InteractionManager
//     // DamageSystem/CallbackUpdate, WorkspotManager/PostBucketsTick
//     // PersistencySystem/UpdateCache, UpdateTriggers,
//     // WatchdogSystem/Log/FrameBegin, TrafficSystemMovement_UpdatePedestrians
//     // RuntimeSystemCamera/UpdateComponents, Corpses, Dismemberment/TickKick
//     // ContainerManager/Tick
//     PostBuckets = 0x5,
//     // ObjectPool, ItemFactory, CameraSystem, Traffic/Update, Dismemberment/TickFinish
//     CameraUpdate = 0x6,
//     // StatusEffectSystem, CameraSystem/PlayerAnim, UI/RuntimeSystem
//     // RuntimeSystemNodeStreaming/ProcessContent, PlayerManager/TickAim
//     PlayerAimUpdate = 0x7,
//     // gameFxSystem, gameEffectSystem, EffectAttachments, PhotoMode/AnimUpdate
//     // ProjectileSystem/TickPostCamera, TargetingSystem/TickKick
//     PostPlayerAimUpdate = 0x8,
//     // StimuliSystem, MinimapSystem, EntityStubHandlerProviderSystem
//     // EntityStubSystem, PopulationSystem/UpdateVisQueriesAfterPooling
//     // RuntimeSystemEffects/UpdateJobsKick, TargetingSystem/TickFinish
//     MappinsUpdate = 0x9,
//     // BlackboardSystem/FireCallbacks_SecondPass, RuntimeSystemEffects/UpdateJobsFinish
//     BlackboardCallbacks_SecondPass = 0xA,
//     // Audio, TrafficSystemMovement_Wait, AutoSaveSystem, EntityVisualController
//     // GOGRewards, UI/RuntimeSystem/FullscreenProcessing
//     // FlushPendingOccluders, AttachPendingProxies, EntityVisualController
//     // Telemetry, gameActivityCardsSystem, Physics/KickAndWaitSimulation
//     PreRenderUpdate = 0xB,
//     // Server/PreCaptureStateSnapshots
//     Multiplayer_CaptureStateSnapshots = 0xC,
//     Unknown = 0xD
// };

enum class UpdateTickGroup : uint8_t
{
    FrameBegin = 0,
    Multiplayer_UpdateStateSnapshots = 1,
    EntityUpdateState = 2,
    PreBuckets = 3,
    Buckets = 4,
    PostBuckets = 5,
    CameraUpdate = 6,
    PlayerAimUpdate = 7,
    PostPlayerAimUpdate = 8,
    MappinsUpdate = 9,
    BlackboardCallbacks_SecondPass = 10,
    PreRenderUpdate = 11,
    Multiplayer_CaptureStateSnapshots = 12,
    Unknown,
};

// enum class UpdateBucketEnum : uint8_t
// {
//     Vehicle = 0,
//     Character = 1,
//     AttachedObject = 2,
//     BucketCount = 3,
// };

enum class UpdateBucketMask : uint8_t
{
    Vehicle = 1 << static_cast<uint8_t>(UpdateBucketEnum::Vehicle),
    Character = 1 << static_cast<uint8_t>(UpdateBucketEnum::Character),
    AttachedObject = 1 << static_cast<uint8_t>(UpdateBucketEnum::AttachedObject),
    Everything = Vehicle | Character | AttachedObject,
};

enum class UpdateBucketStage : uint8_t
{
    Entities_PreTick = 0,
    Entities_ServiceEvents = 1,
    PrePhysicsTick = 2,
    UpdateTransformPrePhysics = 3,
    PhysicsFlushBufferedState = 4,
    PhysicsExecuteAsyncQueries = 5,
    PostPhysicsSyncResults = 6,
    UpdateTransformPostPhysics = 7,
    AnimationUpdate = 8,
    PostPhysicsTick = 9,
    Entities_PostTick = 10,
    Entities_PostServiceEvents = 11,
    Unknown,
};

struct FrameDetailedInfo
{
    float deltaTime;    // 00
    float timeDilation; // 04
    void* unk08;        // 08
    uint32_t unk10;     // 10
};
RED4EXT_ASSERT_SIZE(FrameDetailedInfo, 0x18);
RED4EXT_ASSERT_OFFSET(FrameDetailedInfo, timeDilation, 0x04);
RED4EXT_ASSERT_OFFSET(FrameDetailedInfo, unk10, 0x10);

struct FrameInfo
{
    float deltaTime;            // 00
    FrameDetailedInfo* details; // 08
    uint8_t unk10;              // 10
};
RED4EXT_ASSERT_SIZE(FrameInfo, 0x18);
RED4EXT_ASSERT_OFFSET(FrameDetailedInfo, deltaTime, 0x00);
RED4EXT_ASSERT_OFFSET(FrameDetailedInfo, unk10, 0x10);

using GroupUpdateCallback = Callback<void (*)(FrameInfo&, JobQueue&)>;
using BucketUpdateCallback = Callback<void (*)(UpdateBucketEnum, FrameInfo&, JobQueue&)>;

struct UpdateRegistrar
{
    void RegisterUpdate(UpdateTickGroup aGroup, IUpdatableSystem* aSystem, const char* aName,
                        GroupUpdateCallback&& aCallback);
    void RegisterUpdate(UpdateBucketMask aBuckets, UpdateBucketStage aStage, IUpdatableSystem* aSystem,
                        const char* aName, BucketUpdateCallback&& aCallback);
};
} // namespace RED4ext

#ifdef RED4EXT_HEADER_ONLY
#include <RED4ext/SystemUpdate-inl.hpp>
#endif
