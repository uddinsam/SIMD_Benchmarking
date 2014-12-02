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

tmp.ticRaw();
Matrix tmp1 = Matrix::randMatrix();
Matrix tmp2 = Matrix::randMatrix();
tmp.tocRaw();

unsigned __int64 time = tmp.timeInRawCycles();

while(1) {
    ;
}
}