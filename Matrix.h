#include <immintrin.h>

class Matrix {
public:
    Matrix();
    Matrix(const float m0, const float m1, const float m2, const float m3,
           const float m4, const float m5, const float m6, const float m7,
           const float m8, const float m9, const float m10, const float m11,
           const float m12, const float m13, const float m14, const float m15
           );
    Matrix(const __m128& m_0, const __m128& m_1, const __m128& m_2, const __m128& m_3);
    Matrix(Matrix& tmp);
    ~Matrix();
		
    void operator= (const Matrix& tmp);
    const Matrix operator* (const Matrix& tmp);


private:
    union {
        __m128 r0;
        __m128 r1;
        __m128 r2;
        __m128 r3;

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