#pragma once

// This file is generated by Jack

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/Transform.hpp>
#include <RED4ext/Scripting/Natives/Generated/Vector3.hpp>
#include <RED4ext/Scripting/Natives/Generated/vehicle/BaseObject.hpp>

namespace RED4ext
{
namespace physics { 
struct VehiclePhysicsInsert2
{
    static constexpr const char* NAME = "physicsVehiclePhysicsInsert2";
    static constexpr const char* ALIAS = NAME;

    RED4ext::Vector3 position2;
    float unk0C[7];
    RED4ext::Vector3 position3;
    float unk34[2];
    uint32_t unk3C;
    void* unk40;
    void* unk48;
    RED4ext::Vector3 unk50;
    RED4ext::Vector3 unk5C;
    float unk68[14];
    CName physMaterial;
    int32_t unkA8[3];
    float relatedToInAir;
    float unkB8[2];
    RED4ext::Vector4 unkC0;
    RED4ext::Vector4 unkD0;
    RED4ext::Vector4 unkE0;
    RED4ext::Vector4 unkF0;
    RED4ext::Vector4 unk100;
    RED4ext::Vector4 unk110;
    RED4ext::Vector4 unk120;
    float unk130[2];
    float unk138;
    float unk13C[4];
    uint8_t unk14C;
    uint8_t unk14D;
    uint16_t unk14E;
    RED4ext::Vector4 position;
    RED4ext::Vector4 PID;
};
RED4EXT_ASSERT_SIZE(VehiclePhysicsInsert2, 0x170);
} // namespace physics
} // namespace RED4ext
