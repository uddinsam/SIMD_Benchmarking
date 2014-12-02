#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctime>
#include <cstdlib>

#include "Timer.h"
#include "Matrix.h"


int main() {

srand( static_cast<unsigned int>(time(0)) );

timer::initTimer();
timer matrix_mult_reference;
timer matrix_mult_SSE;
timer matrix_mult_AVX2;
timer matrix_mult_FMA3;
timer tmp;

unsigned __int64 time = __rdtsc();
Matrix tmp1 = Matrix::randMatrix();
Matrix tmp2 = Matrix::randMatrix();
unsigned __int64 delta_time = __rdtsc() - time;

unsigned __int64 timeM = __rdtsc();
Matrix tmp3 = tmp1 * tmp2;
unsigned __int64 delta_timeM = __rdtsc() - timeM;

printf("Creation of two random float Matrices: %f cycles\n", (double)delta_time);
printf("SSE Multiplication: %f cycles\n", (double)delta_timeM);

}