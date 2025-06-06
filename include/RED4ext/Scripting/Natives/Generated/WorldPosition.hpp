#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <RED4ext/Scripting/Natives/WorldPosition.hpp>

namespace RED4ext
{
RED4EXT_ASSERT_SIZE(WorldPosition, 0xC);
} // namespace RED4ext

/*
#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/FixedPoint.hpp>
#include <RED4ext/Scripting/Natives/Generated/Vector3.hpp>
#include <RED4ext/Scripting/Natives/Generated/Vector4.hpp>

namespace RED4ext
{
struct WorldPosition
{
    static constexpr const char* NAME = "WorldPosition";
    static constexpr const char* ALIAS = NAME;

    FixedPoint x; // 00
    FixedPoint y; // 04
    FixedPoint z; // 08

    WorldPosition() {
        this->x.Bits = 0;
        this->y.Bits = 0;
        this->z.Bits = 0;
    }

    WorldPosition(const Vector4& v) {
        this->x.Bits = (v.X * 131072);
        this->y.Bits = (v.Y * 131072);
        this->z.Bits = (v.Z * 131072);
    }

    WorldPosition& operator+=(const Vector3& v) {
        this->x.Bits += (v.X * 131072);
        this->y.Bits += (v.Y * 131072);
        this->z.Bits += (v.Z * 131072);

        return *this;
    }

    WorldPosition operator=(const Vector4& v) {
        return WorldPosition(v);
    }

    Vector3 * ToVector3() {
        auto v = new Vector3();
        v->X = this->x.Bits / 131072.0f;
        v->Y = this->y.Bits / 131072.0f;
        v->Z = this->z.Bits / 131072.0f;
        return v;
    }

    Vector4 * ToVector4() {
        auto v = new Vector4();
        v->X = this->x.Bits / 131072.0f;
        v->Y = this->y.Bits / 131072.0f;
        v->Z = this->z.Bits / 131072.0f;
        v->W = 1.0f;
        return v;
    }
};
RED4EXT_ASSERT_SIZE(WorldPosition, 0xC);
} // namespace RED4ext
*/

// clang-format on
