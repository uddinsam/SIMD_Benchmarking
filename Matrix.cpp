#include "Matrix.h"

//Default ctor
Matrix::Matrix()
	:m0(0.0f), m1(0.0f), m2(0.0f), m3(0.0f),
	 m4(0.0f), m5(0.0f), m6(0.0f), m7(0.0f),
	 m8(0.0f), m9(0.0f), m10(0.0f), m11(0.0f),
	 m12(0.0f), m13(0.0f), m14(0.0f), m15(0.0f)
{}

//Overload ctor from floats
Matrix::Matrix(const float m_0, const float m_1, const float m_2, const float m_3,
               const float m_4, const float m_5, const float m_6, const float m_7,
               const float m_8, const float m_9, const float m_10, const float m_11,
               const float m_12, const float m_13, const float m_14, const float m_15)
{
    this->m0 = m_0;
    this->m1 = m_1;
    this->m2 = m_2;
    this->m3 = m_3;

    this->m4 = m_4;
    this->m5 = m_5;
    this->m6 = m_6;
    this->m7 = m_7;

    this->m8 = m_8;
    this->m9 = m_9;
    this->m10 = m_10;
    this->m11 = m_11;

    this->m12 = m_12;
    this->m13 = m_13;
    this->m14 = m_14;
    this->m15 = m_15;
}

//Copy ctor
Matrix::Matrix(const Matrix& t)
	:r0(t.r0), r1(t.r1), r2(t.r2), r3(t.r3)
{}

//Overload ctor from __m128s
Matrix::Matrix(const __m128& m_0, const __m128& m_1, const __m128& m_2, const __m128& m_3) {
	this->r0 = m_0;
	this->r1 = m_1;
	this->r2 = m_2;
	this->r3 = m_3;
}

//Assignment operator
void Matrix::operator = (const Matrix& tmp) {
	this->r0 = tmp.r0;
	this->r1 = tmp.r1;
	this->r2 = tmp.r2;
	this->r3 = tmp.r3;
}

//Dtor
Matrix::~Matrix()
{}

//Statically construct a Matrix with random floats
Matrix Matrix::randMatrix() {
    return Matrix(static_cast<float>(rand()), static_cast<float>(rand()), static_cast<float>(rand()), static_cast<float>(rand()),
                  static_cast<float>(rand()), static_cast<float>(rand()), static_cast<float>(rand()), static_cast<float>(rand()),
                  static_cast<float>(rand()), static_cast<float>(rand()), static_cast<float>(rand()), static_cast<float>(rand()),
                  static_cast<float>(rand()), static_cast<float>(rand()), static_cast<float>(rand()), static_cast<float>(rand())
                  );
}



