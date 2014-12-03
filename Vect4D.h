#include "immintrin.h"
#include <cstdlib>

class Vect4D {
public:
    Vect4D();
	Vect4D(const float tx, const float ty, const float tz, const float tw);
	Vect4D(const __m128& tmp);
	Vect4D(const Vect4D& tmp);
	void operator= (const Vect4D& tmp);
	~Vect4D();

    static Vect4D randVect4D();

	void ref_norm();
    void sse_norm();
    void avx_128_norm();
    void fma3_norm();

    
private:
    union {
        __declspec(align(16)) __m128 m;

        struct {
            float x;
            float y;
            float z;
            float w;
        };
    };
};
