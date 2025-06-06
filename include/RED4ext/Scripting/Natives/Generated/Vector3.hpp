#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <RED4ext/Scripting/Natives/Vector3.hpp>

namespace RED4ext
{
RED4EXT_ASSERT_SIZE(Vector3, 0xC);
} // namespace RED4ext

/*
#include <cstdint>
#include <RED4ext/Common.hpp>
//#include <RED4ext/Scripting/Natives/Generated/Vector4.hpp>

namespace RED4ext
{
struct alignas(0x4) Vector3
{
    static constexpr const char* NAME = "Vector3";
    static constexpr const char* ALIAS = NAME;

    float X; // 00
    float Y; // 04
    float Z; // 08

    Vector3() : Vector3(0.0, 0.0, 0.0) {

    }

    Vector3(float x, float y, float z) : X(x), Y(y), Z(z) {

    }

    Vector3& operator+=(const Vector3& rhs) {
        this->X += rhs.X;
        this->Y += rhs.Y;
        this->Z += rhs.Z;
        return *this;
    }

    Vector3 operator+(const Vector3& rhs) const {
        return Vector3(this->X + rhs.X, this->Y + rhs.Y, this->Z + rhs.Z);
    }

    Vector3 operator-() {
        return Vector3(-this->X, -this->Y, -this->Z);
    }
};
RED4EXT_ASSERT_SIZE(Vector3, 0xC);
} // namespace RED4ext
*/

// clang-format on
