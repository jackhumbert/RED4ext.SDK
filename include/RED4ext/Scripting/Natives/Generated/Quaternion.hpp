#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <xmmintrin.h> //SSE
#include <emmintrin.h> //SSE 2
#include <smmintrin.h> // SSE4.1
#include <immintrin.h> //avx2

#include <RED4ext/Scripting/Natives/Quaternion.hpp>

namespace RED4ext
{
RED4EXT_ASSERT_SIZE(Quaternion, 0x10);
} // namespace RED4ext

/*

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/Vector3.hpp>
#include <RED4ext/Scripting/Natives/Generated/Vector4.hpp>

namespace RED4ext
{
struct EulerAngles;
struct Matrix;
struct __declspec(align(0x10)) Quaternion
{
    static constexpr const char* NAME = "Quaternion";
    static constexpr const char* ALIAS = NAME;

    float i; // 00
    float j; // 04
    float k; // 08
    float r; // 0C

    // 1.6 RVA: 0x65C450 / 6669392
    /// @pattern 48 83 EC 58 F3 0F 10 51 0C F3 0F 10 59 04 0F 28 C2 0F 29 74 24 40 0F 28 CB F3 0F 59 C2 0F 28 F3
    float __fastcall GetYaw();

    // 1.6 RVA: 0x5582F0 / 5604080
    /// @pattern 48 8B C4 48 89 58 08 57 48 81 EC B0 00 00 00 F3 0F 10 21 48 8B FA 44 0F 29 40 D8 48 8B D9 44 0F
    EulerAngles * __fastcall ToEulerAngles(EulerAngles *a2);

    // 1.6 RVA: 0x481830 / 4724784
    /// @pattern 48 83 EC 28 0F 10 21 48 8B C2 41 0F 10 28 0F 28 DC 0F 59 DC C7 42 0C 00 00 00 00 0F 29 74 24 10
    //Vector4 *__fastcall sub_7FF75B961830(RED4ext::Vector4 *a2, RED4ext::Transform *a3);
    
    Quaternion() : Quaternion(0.0, 0.0, 0.0, 1.0) {

    }

    Quaternion(float i, float j, float k, float r) {
        this->i = i;
        this->j = j;
        this->k = k;
        this->r = r;
    }

    Quaternion(__m128 m) {
        this->i = m.m128_f32[0];
        this->j = m.m128_f32[1];
        this->k = m.m128_f32[2];
        this->r = m.m128_f32[3];
    }

    Quaternion(Vector3 complex, float real) : Quaternion(complex.X, complex.Y, complex.Z, real) {

    }

    operator __m128() const {
        return *(__m128*)(this);
    }

    Vector3 complex() const {
        return Vector3(this->i, this->j, this->k);
    }

    float real() const {
        return this->r;
    }

    Quaternion conjugate(void) const {
      return Quaternion(-complex(), real());
    }

    Quaternion operator+(const Quaternion& q) const {
        return _mm_add_ps(*this, q);
    }

    Quaternion operator-(const Quaternion& q) const {
        return _mm_sub_ps(*this, q);
    }

    // 1.6 RVA: 0x1C7A80 / 1866368
    /// @pattern 48 83 EC 68 F3 41 0F 10 28 48 8B C2 F3 0F 10 61 0C 0F 28 C5 0F 29 74 24 50 F3 0F 10 71 04 0F 29
    // Quaternion *__fastcall AssignMultiply(Quaternion *a, Quaternion *b);

    Quaternion operator*(const Quaternion& b) const {
        auto a = *this;
        auto aOut = Quaternion();
        aOut.i = b.i * a.r + b.r * a.i + b.k * a.j - b.j * a.k;
        aOut.j = b.j * a.r + b.r * a.j + b.i * a.k - b.k * a.i;
        aOut.k = b.k * a.r + b.r * a.k + b.j * a.i - b.i * a.j;
        aOut.r = b.r * a.r - b.i * a.i - b.j * a.j - b.k * a.k;
        return aOut;
    }

    Vector3 operator*(const Vector3& r) const {
        return (((*this) * Quaternion(r, 0.0)) * conjugate()).complex();
    }

    //Vector4 operator*(const Vector4& w) const {
    //    Vector4 aOut;
    //    __m128 v10, v11, v12, v13, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v30;
    //    float v14, v15;

    //    v10 = w;
    //    v11 = *this;
    //    v12 = v11;
    //    v13 = _mm_mul_ps(v11, v11);
    //    v14 = _mm_shuffle_ps(v13, v13, _MM_SHUFFLE(1, 1, 1, 1)).m128_f32[0];
    //    v15 = _mm_shuffle_ps(v13, v13, _MM_SHUFFLE(2, 2, 2, 2)).m128_f32[0] + _mm_shuffle_ps(v13, v13, _MM_SHUFFLE(3, 3, 3, 3)).m128_f32[0];
    //    v16 = _mm_shuffle_ps(v13, v13, 0);
    //    v16.m128_f32[0] = v16.m128_f32[0] + v14;
    //    v17 = {0};
    //    v18 = _mm_shuffle_ps(v10, v10, _MM_SHUFFLE(3, 1, 0, 2));
    //    v16.m128_f32[0] = sqrtf(v16.m128_f32[0] + v15);
    //    v19 = _mm_shuffle_ps(v16, v16, _MM_SHUFFLE(0, 0, 0, 0));
    //    v20 = _mm_cmpeq_ss(v19, v17);
    //    v21 = _mm_andnot_ps(_mm_shuffle_ps(v20, v20, 0), _mm_mul_ps(_mm_div_ps(Vector4(1.0, 1.0, 1.0, 1.0), v19), v12));
    //    v22 = _mm_shuffle_ps(v21, v21, _MM_SHUFFLE(3, 0, 2, 1));
    //    v23 = _mm_shuffle_ps(v22, v22, _MM_SHUFFLE(3, 0, 2, 1));
    //    v30 = _mm_sub_ps(_mm_mul_ps(v18, v22), _mm_mul_ps(_mm_shuffle_ps(v18, v18, _MM_SHUFFLE(3, 1, 0, 2)), v23));
    //    v30.m128_f32[3] = 1.0;
    //    v24 = _mm_add_ps(v30, v30);
    //    v25 = _mm_shuffle_ps(v24, v24, _MM_SHUFFLE(3, 1, 0, 2));
    //    v26 = _mm_shuffle_ps(v21, v21, _MM_SHUFFLE(3, 3, 3, 3));
    //    v30 = _mm_sub_ps(_mm_mul_ps(v25, v22), _mm_mul_ps(_mm_shuffle_ps(v25, v25, _MM_SHUFFLE(3, 1, 0, 2)), v23));
    //    v30.m128_f32[3] = 1.0;
    //    v27 = _mm_add_ps(_mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v26, v26, 0), v24), v10), v30);

    //    aOut.X = v27.m128_i32[0];
    //    aOut.Y = _mm_shuffle_ps(v27, v27, _MM_SHUFFLE(1, 1, 1, 1)).m128_u32[0];
    //    aOut.Z = _mm_shuffle_ps(v27, v27, _MM_SHUFFLE(2, 2, 2, 2)).m128_u32[0];
    //    aOut.W = 0.0;

	   // return aOut;
    //}

    // 1.6 RVA: 0x1C9A30 / 1874480
    /// @pattern 4C 8B DC 48 81 EC B8 00 00 00 0F 10 21 41 0F 29 73 E8 0F 28 DC 0F 59 DC C7 44 24 0C 00 00 00 00
    Matrix *__fastcall ToMatrix(Matrix * matrix);

};
RED4EXT_ASSERT_SIZE(Quaternion, 0x10);
} // namespace RED4ext
*/

// clang-format on
