#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctime>
#include <cstdlib>

#include "Timer.h"
#include "Matrix.h"


int main() {

srand( static_cast<unsigned int>(time(0)) );

timer matrix_mult_reference;
timer matrix_mult_SSE;
timer matrix_mult_AVX_128;
timer matrix_mult_AVX_256;
timer matrix_mult_AVX2_FMA3;


/*
 * Create two 10000-element arrays of Matrices. Testing will be each element i in op1 * op2 using each
 * type of instruction set. (i.e. op1[i] * op2[i])
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
unsigned __int64 timeREF = __rdtsc();
for (int i = 0; i < 10000; i++) {
    out_ref[i] = op1[i].ref_mul(op2[i]);
}
unsigned __int64 delta_timeREF = __rdtsc() - timeREF;
double ref_time = delta_timeREF/10000.0;
printf("REFERENCE Multiplication: %f cycles\n", ref_time);
delete[] out_ref;

/*
 * SSE Multiplication. 
 */
Matrix* out_sse = (Matrix *)_aligned_malloc(sizeof(Matrix)*10000, 16);
unsigned __int64 timeSSE = __rdtsc();
for (int i = 0; i < 10000; i++) {
    out_sse[i] = op1[i].sse_mul(op2[i]);
}
unsigned __int64 delta_timeSSE = __rdtsc() - timeSSE;
double sse_time = delta_timeSSE/10000.0;
printf("SSE Multiplication: %f cycles\n", sse_time);
delete[] out_sse;



delete[] op1;
delete[] op2;
}