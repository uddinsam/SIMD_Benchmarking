#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctime>
#include <cstdlib>

#include "Timer.h"
#include "Matrix.h"
#include "Vect4D.h"


int main() {

srand( static_cast<unsigned int>(time(0)) );

timer matrix_mult_reference;
timer matrix_mult_SSE;
timer matrix_mult_AVX_128;
timer matrix_mult_AVX_256;
timer matrix_mult_AVX2_FMA3;


/*
 * Create two 10000-element arrays of Matrices. Multiply each element i in op1 by op2 using each
 * type of instruction set. (i.e. op1[i] (*_mul) op2[i])
 */

Matrix* op1 = (Matrix *)_aligned_malloc(sizeof(Matrix)*10000, 16);
Matrix* op2 = (Matrix *)_aligned_malloc(sizeof(Matrix)*10000, 16);
for (int i = 0; i < 10000; i++) {
    op1[i] = Matrix::randMatrix();
    op2[i] = Matrix::randMatrix();
}

DWORD64 avg_time = MAXDWORD64;
DWORD64 time = 0; 
DWORD64 delta_time = 0;
DWORD64 accum = 0;
/*
 * REFERENCE Multiplication. 
 */
Matrix* out_ref = (Matrix *)_aligned_malloc(sizeof(Matrix)*10000, 16);

for (int i = 0; i < 10000; i++) {
    time = __rdtsc();
    out_ref[i] = op1[i].ref_mul(op2[i]);
    delta_time = __rdtsc() - time;
    accum += delta_time;
}

avg_time = accum/10000.0;

printf("REFERENCE Multiplication: %f cycles\n", (double)avg_time);
_aligned_free(out_ref);

/*
 * SSE Multiplication. 
 */
Matrix* out_sse = (Matrix *)_aligned_malloc(sizeof(Matrix)*10000, 16);
accum = 0;
for (int i = 0; i < 10000; i++) {   
    time = __rdtsc();
    out_sse[i] = op1[i].sse_mul(op2[i]);
    delta_time = __rdtsc() - time;
    accum += delta_time;
}

avg_time = accum/10000.0;
printf("SSE Multiplication: %f cycles\n", (double)avg_time);
_aligned_free(out_sse);

/*
 * FMA3 128-bit Multiplication.
 */
Matrix* out_fma3_128 = (Matrix *)_aligned_malloc(sizeof(Matrix)*10000, 16);
accum = 0;
for (int i = 0; i < 10000; i++) {
    time = __rdtsc();
    out_fma3_128[i] = op1[i].fma3_mul(op2[i]);
    delta_time = __rdtsc() - time;
    accum += delta_time;
}

avg_time = accum/10000.0;
printf("FMA3 128-bit Multiplication: %f cycles\n", (double)avg_time);
_aligned_free(out_fma3_128);

_aligned_free(op1);
_aligned_free(op2);

/*
 * Vector Normalization
 */

Vect4D* op_normalize = (Vect4D *) _aligned_malloc(sizeof(Vect4D)*10000, 16);
Vect4D* ref_normalize = (Vect4D *) _aligned_malloc(sizeof(Vect4D)*10000, 16);
Vect4D* sse_normalize = (Vect4D *) _aligned_malloc(sizeof(Vect4D)*10000, 16);
for (int i = 0; i < 10000; i++) {
    ref_normalize[i] = Vect4D::randVect4D();
    sse_normalize[i] = Vect4D::randVect4D();
}

/*
 * REFERENCE 4-D Vector Normalization.
 */
accum = 0;
for (int i = 0; i < 10000; i++) {
    time = __rdtsc();
    ref_normalize[i].ref_norm();
    delta_time = __rdtsc() - time;
    accum += delta_time;
}

avg_time = accum/10000.0;
printf("REFERENCE Normalization: %f cycles\n", (double)avg_time);

/*
 * SSE Normalization. 
 */

for (int i = 0; i < 10000; i++) {
    time = __rdtsc();
    sse_normalize[i].sse_norm();
    delta_time = __rdtsc() - time;
    accum += delta_time;
}

avg_time = accum/10000.0;
printf("SSE Normalization: %f cycles\n", (double)avg_time);





_aligned_free(op_normalize);
_aligned_free(ref_normalize);
_aligned_free(sse_normalize);


}