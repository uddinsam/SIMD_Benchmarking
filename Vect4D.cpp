#include <math.h>
#include <assert.h>

#include "Vect4D.h"

//Default ctor
Vect4D::Vect4D()
	:x(0.0f), y(0.0f), z(0.0f), w(0.0f)
{}

//Overload ctor
Vect4D::Vect4D(const float tx, const float ty, const float tz, const float tw)
	:x(tx), y(ty), z(tz), w(tw)
{}

//Copy ctor
Vect4D::Vect4D(const Vect4D& tmp) 
	:x(tmp.x), y(tmp.y), z(tmp.z), w(tmp.w)
{}

//Overload ctor taking a __m128
Vect4D::Vect4D(const __m128& m128) 
	:m(m128)
{}

//Assignment operator
void Vect4D::operator = (const Vect4D& tmp) {
	this->m = tmp.m;
}

//Dtor
Vect4D::~Vect4D()
{}

//Statically construct a random Vect4D
Vect4D Vect4D::randVect4D() {
    return Vect4D(static_cast<float>(rand()),
                  static_cast<float>(rand()),
                  static_cast<float>(rand()),
                  static_cast<float>(rand())
                  );
}

//Reference Vector normalization
void Vect4D::ref_norm() {
    float mag = sqrtf(x*x + y*y + z*z + w*w);

    this->x /= mag;
    this->y /= mag;
    this->z /= mag;
    this->w /= mag;
}

//multiply this->m by the reciprocal sqrt intrinsic of: (this->m)^2 via _mm_dp_ps written into all four registers (0xFF)
void Vect4D::sse_norm() {
	this->m = _mm_mul_ps(this->m, _mm_rsqrt_ps(_mm_dp_ps(this->m, this->m, 0xFF)));
}
