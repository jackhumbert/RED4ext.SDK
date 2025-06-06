#pragma once

#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/WorldTransform.hpp>
#include <RED4ext/Scripting/Natives/Generated/ent/IMoverComponent.hpp>
#include <RED4ext/Scripting/Natives/Vector3.hpp>
#include <RED4ext/Scripting/Natives/Vector4.hpp>
#include <cstdint>

namespace RED4ext
{
namespace move
{
struct Component : ent::IMoverComponent
{
    static constexpr const char* NAME = "moveComponent";
    static constexpr const char* ALIAS = NAME;

    uint64_t unk90;
    uint64_t unk98;
    uint64_t unkA0;
    uint64_t unkA8;
    uint64_t unkB0[17];
    uint64_t unk138;
    uint64_t unk140[6];
    uint64_t unk170;
    uint64_t unk178;
    uint64_t unk180;
    uint64_t unk188;
    RED4ext::Transform unk190;
    uint8_t unk1B0;
    uint8_t unk1B1;
    uint8_t unk1B2;
    uint8_t unk1B3;
    uint8_t unk1B4;
    uint8_t unk1B5;
    uint8_t unk1B6;
    uint8_t unk1B7;
    uint64_t unk1B8[1];
    RED4ext::WorldTransform worldTransform; // 1C0
    uint64_t unk1E0;
    Vector4 position; // 1E8
    uint8_t unk1F8;
    uint8_t unk1F9;
    uint8_t unk1FA;
    uint8_t unk1FB;
    uint8_t unk1FC;
    uint8_t unk1FD;
    uint8_t unk1FE;
    uint8_t unk1FF;
    uint64_t unk200;
    uint64_t unk208;
    uint64_t unk210;
    uint64_t unk218;
    Vector3 speed; // 220
    float deltaFrame; // 22C
    uint64_t unk230[12];
    uint64_t unk290;
    uint64_t unk298;
    float unk2A0;
    float unk2A4;
    float unk2A8;
    float unk2AC;
    float unk2B0;
    float unk2B4;
    float unk2B8;
    float unk2BC;

};
RED4EXT_ASSERT_SIZE(Component, 0x2C0);
RED4EXT_ASSERT_OFFSET(Component, worldTransform, 0x1C0);
RED4EXT_ASSERT_OFFSET(Component, position, 0x1E8);
RED4EXT_ASSERT_OFFSET(Component, speed, 0x220);
RED4EXT_ASSERT_OFFSET(Component, deltaFrame, 0x22C);
} // namespace move
using moveComponent = move::Component;
} // namespace RED4ext
