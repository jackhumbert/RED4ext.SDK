#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/IScriptable.hpp>
#include <RED4ext/Scripting/Natives/Generated/Vector4.hpp>
#include <RED4ext/Scripting/Natives/Generated/Vector3.hpp>
#include <RED4ext/Scripting/Natives/Generated/Quaternion.hpp>
#include <RED4ext/Scripting/Natives/Generated/Transform.hpp>
#include <RED4ext/Scripting/Natives/Generated/ent/Entity.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/data/Vehicle_Record.hpp>
#include <RED4ext/Scripting/Natives/Generated/vehicle/TPPCameraComponent.hpp>
// #include <RED4ext/Scripting/Natives/Generated/vehicle/BaseObject.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/FPPCameraComponent.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/CameraComponent.hpp>
#include <RED4ext/Scripting/Natives/vehicleCameraManager.hpp>

namespace RED4ext
{
namespace vehicle {
struct BaseObject;
struct TPPCameraComponent;
// struct __declspec(align(0x10)) CameraManager : IScriptable
// {
//     static constexpr const char* NAME = "vehicleCameraManager";
//     static constexpr const char* ALIAS = "VehicleCameraManager";
    // uint8_t unk40[0x3A0 - 0x40]; // 40
// };
RED4EXT_ASSERT_SIZE(CameraManager, 0x3A0);
} // namespace vehicle
using vehicleCameraManager = vehicle::CameraManager;
using VehicleCameraManager = vehicle::CameraManager;
} // namespace RED4ext

// clang-format on
