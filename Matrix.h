#include <immintrin.h>
#include <cstdlib>

class Matrix {
public:
    Matrix();
    Matrix(const float m0, const float m1, const float m2, const float m3,
           const float m4, const float m5, const float m6, const float m7,
           const float m8, const float m9, const float m10, const float m11,
           const float m12, const float m13, const float m14, const float m15
           );
    Matrix(const __m128& m_0, const __m128& m_1, const __m128& m_2, const __m128& m_3);
    Matrix(const Matrix& tmp);
    ~Matrix();

    static Matrix randMatrix();
    void operator= (const Matrix& tmp);
    //Matrix operator* (const Matrix& tmp);

    inline Matrix Matrix::ref_mul(const Matrix& rhs) {

        return Matrix((this->m0*rhs.m0) + (this->m1*rhs.m4) + (this->m2*rhs.m8) + (this->m3*rhs.m12),
                      (this->m0*rhs.m1) + (this->m1*rhs.m5) + (this->m2*rhs.m9) + (this->m3*rhs.m13),
                      (this->m0*rhs.m2) + (this->m1*rhs.m6) + (this->m2*rhs.m10) + (this->m3*rhs.m14),
                      (this->m0*rhs.m3) + (this->m1*rhs.m7) + (this->m2*rhs.m11) + (this->m3*rhs.m15),
                  
                      (this->m4*rhs.m0) + (this->m5*rhs.m4) + (this->m6*rhs.m8) + (this->m7*rhs.m12),
                      (this->m4*rhs.m1) + (this->m5*rhs.m5) + (this->m6*rhs.m9) + (this->m7*rhs.m13),
                      (this->m4*rhs.m2) + (this->m5*rhs.m6) + (this->m6*rhs.m10) + (this->m7*rhs.m14),
                      (this->m4*rhs.m3) + (this->m5*rhs.m7) + (this->m6*rhs.m11) + (this->m7*rhs.m15),

                      (this->m8*rhs.m0) + (this->m9*rhs.m4) + (this->m10*rhs.m8) + (this->m11*rhs.m12),
                      (this->m8*rhs.m1) + (this->m9*rhs.m5) + (this->m10*rhs.m9) + (this->m11*rhs.m13),
                      (this->m8*rhs.m2) + (this->m9*rhs.m6) + (this->m10*rhs.m10) + (this->m11*rhs.m14),
                      (this->m8*rhs.m3) + (this->m9*rhs.m7) + (this->m10*rhs.m11) + (this->m11*rhs.m15),

                      (this->m12*rhs.m0) + (this->m13*rhs.m4) + (this->m14*rhs.m8) + (this->m15*rhs.m12),
                      (this->m12*rhs.m1) + (this->m13*rhs.m5) + (this->m14*rhs.m9) + (this->m15*rhs.m13),
                      (this->m12*rhs.m2) + (this->m13*rhs.m6) + (this->m14*rhs.m10) + (this->m15*rhs.m14),
                      (this->m12*rhs.m3) + (this->m13*rhs.m7) + (this->m14 *rhs.m11) + (this->m15*rhs.m15)
                     );
    }


    inline Matrix Matrix::sse_mul(const Matrix& rhs) {

        return Matrix(_mm_add_ps(_mm_add_ps(_mm_add_ps(_mm_mul_ps(_mm_set1_ps(this->r0.m128_f32[0]), rhs.r0), _mm_mul_ps(_mm_set1_ps(this->r0.m128_f32[1]), rhs.r1)), _mm_mul_ps(_mm_set1_ps(this->r0.m128_f32[2]), rhs.r2)), _mm_mul_ps(_mm_set1_ps(this->r0.m128_f32[3]), rhs.r3)),
                      _mm_add_ps(_mm_add_ps(_mm_add_ps(_mm_mul_ps(_mm_set1_ps(this->r1.m128_f32[0]), rhs.r0), _mm_mul_ps(_mm_set1_ps(this->r1.m128_f32[1]), rhs.r1)), _mm_mul_ps(_mm_set1_ps(this->r1.m128_f32[2]), rhs.r2)), _mm_mul_ps(_mm_set1_ps(this->r1.m128_f32[3]), rhs.r3)), 
                      _mm_add_ps(_mm_add_ps(_mm_add_ps(_mm_mul_ps(_mm_set1_ps(this->r2.m128_f32[0]), rhs.r0), _mm_mul_ps(_mm_set1_ps(this->r2.m128_f32[1]), rhs.r1)), _mm_mul_ps(_mm_set1_ps(this->r2.m128_f32[2]), rhs.r2)), _mm_mul_ps(_mm_set1_ps(this->r2.m128_f32[3]), rhs.r3)), 
                      _mm_add_ps(_mm_add_ps(_mm_add_ps(_mm_mul_ps(_mm_set1_ps(this->r3.m128_f32[0]), rhs.r0), _mm_mul_ps(_mm_set1_ps(this->r3.m128_f32[1]), rhs.r1)), _mm_mul_ps(_mm_set1_ps(this->r3.m128_f32[2]), rhs.r2)), _mm_mul_ps(_mm_set1_ps(this->r3.m128_f32[3]), rhs.r3))
                     );
    }


private:
    union {
        struct {
            __declspec(align(16)) __m128 r0;
            __declspec(align(16)) __m128 r1;
            __declspec(align(16)) __m128 r2;
            __declspec(align(16)) __m128 r3;
        };

        struct {
            float m0;
            float m1;
            float m2;
            float m3;

            float m4;
            float m5;
            float m6;
            float m7;

            float m8;
            float m9;
            float m10;
            float m11;

            float m12;
            float m13;
            float m14;
            float m15;
        };
    };
};