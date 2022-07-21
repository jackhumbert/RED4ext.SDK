#pragma once

// This file is generated from the Game's Reflection data

#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/Vector4.hpp>
#include <RED4ext/Scripting/Natives/Generated/GameplayTier.hpp>
#include <RED4ext/Scripting/Natives/Generated/Vector4.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/PSMCombat.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/PSMVision.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/PSMZones.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/ui/ProjectedHUDGameController.hpp>
#include <RED4ext/Scripting/Natives/Generated/ink/LinePatternWidgetReference.hpp>
#include <RED4ext/Scripting/Natives/Generated/ink/WidgetPath.hpp>
#include <cstdint>

namespace RED4ext
{
namespace game::mappins
{
struct RuntimeMappin;
struct QuestMappin;
struct PointOfInterestMappin;

} // namespace game::mappins
namespace game::ui
{
struct MappinsContainerController : game::ui::ProjectedHUDGameController
{
    static constexpr const char* NAME = "gameuiMappinsContainerController";
    static constexpr const char* ALIAS = "MappinsContainerController";

    // uint8_t unk148[0x160 - 0x148]; // 148
    // ink::WidgetPath spawnContainerPath; // 160
    // uint8_t unk170[0x180 - 0x170]; // 170
    // ink::LinePatternWidgetReference gpsQuestPathWidget; // 180
    // ink::LinePatternWidgetReference gpsPlayerTrackedPathWidget; // 198
    // uint8_t unk1B0[0x270 - 0x1B0]; // 1B0
    // game::PSMVision psmVision; // 270
    // game::PSMCombat psmCombat; // 274
    // game::PSMZones psmZone; // 278
    // GameplayTier tier; // 27C
    // uint8_t unk280[0x2D0 - 0x280]; // 280

    uint64_t unk148[3];
    ink::WidgetPath spawnContainerPath;
    void* binkSystem;
    void* questSystem;
    uint64_t gpsQuestPathWidget[3];
    uint64_t gpsPlayerTrackedPathWidget[3];
    Handle<void> controllerSubtype;
    DynArray<void*> unk1C0;

    WeakHandle<game::mappins::QuestMappin> questMappin;
    DynArray<Vector4> questMappinPoints;
    uint64_t hasQuestMappin;
    WeakHandle<game::mappins::IMappin> poiMappin;
    DynArray<Vector4> poiMappinPoints;
    uint64_t hasPoiMappin;
    uint64_t unk220;
    volatile signed __int8 needsUpdateMaybe;
    Handle<void> callback;
    Handle<void> callback2;
    Handle<void> callback3;
    Handle<void> callback4;
    uint32_t psmVision;
    uint32_t psmCombat;
    uint32_t psmZone;
    GameplayTier tier;
    uint32_t braindance;
    uint32_t unk284;
    void* unk288[4];
    volatile signed __int8 mappinsNeedUpdatingMaybe;
    DynArray<Handle<game::mappins::RuntimeMappin>> mappins;
    Handle<void> insert;
};
RED4EXT_ASSERT_SIZE(MappinsContainerController, 0x2D0);
RED4EXT_ASSERT_OFFSET(MappinsContainerController, questMappinPoints, 0x1E0);
RED4EXT_ASSERT_OFFSET(MappinsContainerController, poiMappinPoints, 0x208);
} // namespace game::ui
using MappinsContainerController = game::ui::MappinsContainerController;
} // namespace RED4ext
