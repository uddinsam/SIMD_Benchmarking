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
unsigned __int64 time = __rdtsc();
Matrix* op1 = (Matrix *)_aligned_malloc(sizeof(Matrix)*10000, 16);
Matrix* op2 = (Matrix *)_aligned_malloc(sizeof(Matrix)*10000, 16);
for (int i = 0; i < 10000; i++) {
    op1[i] = Matrix::randMatrix();
    op2[i] = Matrix::randMatrix();
}
unsigned __int64 delta_timeCreate = __rdtsc() - time;
printf("Creation of 20000 random float Matrices: %f cycles\n", (double)delta_timeCreate);

/*
 * REFERENCE Multiplication. 
 */
Matrix* out_ref = (Matrix *)_aligned_malloc(sizeof(Matrix)*10000, 16);
DWORD64 best_timeREF = MAXDWORD64;
DWORD64 timeREF, delta_timeREF;
for (int i = 0; i < 10000; i++) {
    timeREF = __rdtsc();
    out_ref[i] = op1[i].ref_mul(op2[i]);
    delta_timeREF = __rdtsc() - timeREF;
    if (delta_timeREF < best_timeREF) {
        best_timeREF = delta_timeREF;
    }
}
printf("REFERENCE Multiplication: %f cycles\n", (double)best_timeREF);
_aligned_free(out_ref);

/*
 * SSE Multiplication. 
 */
Matrix* out_sse = (Matrix *)_aligned_malloc(sizeof(Matrix)*10000, 16);
DWORD64 best_timeSSE = MAXDWORD64;
DWORD64 timeSSE, delta_timeSSE;
for (int i = 0; i < 10000; i++) {
    timeSSE = __rdtsc();
    out_sse[i] = op1[i].sse_mul(op2[i]);
    delta_timeSSE = __rdtsc() - timeSSE;
    if (delta_timeSSE < best_timeSSE) {
        best_timeSSE = delta_timeSSE;
    }
}
printf("SSE Multiplication: %f cycles\n", (double)best_timeSSE);
_aligned_free(out_sse);

/*
 * FMA3 128-bit Multiplication.
 */
Matrix* out_fma3_128 = (Matrix *)_aligned_malloc(sizeof(Matrix)*10000, 16);
DWORD64 best_timeFMA3 = MAXDWORD64;
DWORD64 timeFMA3, delta_timeFMA3;
for (int i = 0; i < 10000; i++) {
    timeFMA3 = __rdtsc();
    out_fma3_128[i] = op1[i].fma3_mul(op2[i]);
    delta_timeFMA3 = __rdtsc() - timeFMA3;
    if (delta_timeFMA3 < best_timeFMA3) {
        best_timeFMA3 = delta_timeFMA3;
    }
}
printf("FMA3 128-bit Multiplication: %f cycles\n", (double)best_timeFMA3);
_aligned_free(out_fma3_128);

_aligned_free(op1);
_aligned_free(op2);

/*
 * Vector Normalization
 */


Vect4D* ref_normalize = (Vect4D *) _aligned_malloc(sizeof(Vect4D)*10000, 16);
_aligned_free(ref_normalize);
Vect4D* sse_normalize = (Vect4D *) _aligned_malloc(sizeof(Vect4D)*10000, 16);
_aligned_free(sse_normalize);

}