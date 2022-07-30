#pragma once

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/NativeTypes.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/Object.hpp>
#include <RED4ext/Scripting/Natives/Generated/WorldTransform.hpp>
#include <RED4ext/Scripting/Natives/Generated/vehicle/ChassisComponent.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/OccupantSlotComponent.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/data/Vehicle_Record.hpp>
#include <RED4ext/Scripting/Natives/Generated/vehicle/Controller.hpp>
#include <RED4ext/Scripting/Natives/Generated/vehicle/CameraManager.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/interactions/Component.hpp>
#include <RED4ext/Scripting/Natives/Generated/AI/CAgent.hpp>
#include <RED4ext/Scripting/Natives/Generated/move/Component.hpp>

#include <RED4ext/Scripting/Natives/vehicleBaseObject.hpp>

namespace RED4ext
{
namespace vehicle
{

//#pragma pack(push, 1)
//struct BaseObject : game::Object
//{
    //static constexpr const char* NAME = "vehicleBaseObject";
    //static constexpr const char* ALIAS = "VehicleObject";
//};
//#pragma pack(pop)
RED4EXT_ASSERT_SIZE(BaseObject, 0x980);
RED4EXT_ASSERT_OFFSET(BaseObject, weapons, 0x940);
//char (*__kaboom)[sizeof(BaseObject)] = 1;
//char (*__kaboom)[offsetof(BaseObject, weapons)] = 1;
} // namespace vehicle
using VehicleObject = vehicle::BaseObject;
} // namespace RED4ext
