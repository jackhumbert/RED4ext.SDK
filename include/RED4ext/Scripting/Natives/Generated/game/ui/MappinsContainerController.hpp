#pragma once

// clang-format off

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
#include <RED4ext/Handle.hpp>
#include <cstdint>

namespace RED4ext
{
namespace game::mappins
{
struct RuntimeMappin;
struct QuestMappin;
struct PointOfInterestMappin;
struct IMappin;

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
    ink::WidgetPath spawnContainerPath; // 178

//     void* binkSystem;
//     void* questSystem;
//     uint64_t gpsQuestPathWidget[3]; // 198
//     uint64_t gpsPlayerTrackedPathWidget[3]; // 1B0
//     Handle<void> controllerSubtype; // 1C8
//     DynArray<void*> unk1C0; // 1D8

//     WeakHandle<game::mappins::QuestMappin> questMappin; // 1E8
//     DynArray<Vector4> questMappinPoints; // 1F8
//     uint64_t hasQuestMappin; // 208
//     WeakHandle<game::mappins::IMappin> poiMappin; // 210
//     DynArray<Vector4> poiMappinPoints; // 220
//     uint64_t hasPoiMappin; // 230
//     uint64_t unk220; // 240
//     volatile signed __int8 needsUpdateMaybe; // 248
//     Handle<void> callback; // 250
//     Handle<void> callback2; // 260
//     Handle<void> callback3; // 270
//     Handle<void> callback4; // 280
//     uint32_t psmVision; // 288
//     uint32_t psmCombat; // 28C
//     uint32_t psmZone; // 290
//     GameplayTier tier; // 294
//     uint32_t braindance;
//     uint32_t unk284;
//     void* unk288[4];
//     volatile signed __int8 mappinsNeedUpdatingMaybe;
//     DynArray<Handle<game::mappins::RuntimeMappin>> mappins;
//     Handle<void> insert;
// };
// RED4EXT_ASSERT_SIZE(MappinsContainerController, 0x2E8);
// RED4EXT_ASSERT_OFFSET(MappinsContainerController, questMappinPoints, 0x1E0 + 0x18);
// RED4EXT_ASSERT_OFFSET(MappinsContainerController, poiMappinPoints, 0x208 + 0x18);

    uint8_t unk188[0x198 - 0x188]; // 188
    ink::LinePatternWidgetReference gpsQuestPathWidget; // 198
    ink::LinePatternWidgetReference gpsPlayerTrackedPathWidget; // 1B0
    ink::LinePatternWidgetReference gpsDelamainPathWidget; // 1C8
    ink::LinePatternWidgetReference autodrivePathWidget; // 1E0
    uint8_t unk1F8[0x2E0 - 0x1F8]; // 1F8
    game::PSMVision psmVision; // 2E0
    game::PSMCombat psmCombat; // 2E4
    game::PSMZones psmZone; // 2E8
    GameplayTier tier; // 2EC
    uint8_t unk2F0[0x340 - 0x2F0]; // 2F0
};
RED4EXT_ASSERT_SIZE(MappinsContainerController, 0x340);
} // namespace game::ui
using gameuiMappinsContainerController = game::ui::MappinsContainerController;
using MappinsContainerController = game::ui::MappinsContainerController;
} // namespace RED4ext

// clang-format on
