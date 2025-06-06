#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <RED4ext/Scripting/Natives/Vector4.hpp>

namespace RED4ext
{
RED4EXT_ASSERT_SIZE(Vector4, 0x10);
} // namespace RED4ext

/*
#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/Vector3.hpp>

//struct Vector3;

namespace RED4ext
{
struct __declspec(align(0x10)) Vector4
{
    static constexpr const char* NAME = "Vector4";
    static constexpr const char* ALIAS = NAME;

    float X; // 00
    float Y; // 04
    float Z; // 08
    float W; // 0C

    //Vector4(WorldPosition& v) {
    //    this->X = (v.x.Bits / 131072.0);
    //    this->Y = (v.y.Bits / 131072.0);
    //    this->Z = (v.z.Bits / 131072.0);
    //    this->W = 1.0;
    //}

    Vector4() : Vector4(0.0, 0.0, 0.0, 0.0) { }

    Vector4(float x, float y, float z, float w) : X(x), Y(y), Z(z), W(w) {

    }
    
    // Vector4(__m128 m) : X(m.m128_f32[0]), Y(m.m128_f32[1]), Z(m.m128_f32[2]), W(m.m128_f32[3]) {
    // }

    // operator __m128() const {
    //     return *(__m128*)(this);
    // }

    operator Vector3() const {
        return Vector3(this->X, this->Y, this->Z);
    }
    
    Vector4 operator+(const Vector4& rhs) {
        return Vector4(
            this->X + rhs.X, 
            this->Y + rhs.Y,
            this->Z + rhs.Z,
            this->W + rhs.W);
    }
    
    Vector4 operator+(const Vector3& rhs) {
        return Vector4(
            this->X + rhs.X, 
            this->Y + rhs.Y,
            this->Z + rhs.Z,
            this->W);
    }
    
    Vector4 operator*(const float& rhs) {
        return Vector4(
            this->X * rhs, 
            this->Y * rhs,
            this->Z * rhs,
            this->W * rhs);
    }
    
    Vector4 operator-(const Vector4& rhs) {
        return Vector4(
            this->X - rhs.X, 
            this->Y - rhs.Y,
            this->Z - rhs.Z,
            this->W - rhs.W);
    }

    Vector4& operator+=(const Vector4& v) {
        this->X += v.X;
        this->Y += v.Y;
        this->Z += v.Z;
        this->W += v.W;
        return *this;
    }
};
RED4EXT_ASSERT_SIZE(Vector4, 0x10);
} // namespace RED4ext
*/

// clang-format on
