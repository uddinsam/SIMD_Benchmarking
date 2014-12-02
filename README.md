SIMD Benchmarks
===============
*Tested on my 2014 rMBP with an Intel i5-4278u 2.6 GHz dual-core Haswell CPU.*  
*OS: Windows 8.1 running on VMWare Fusion 7.*  
*Compiled with VC++ 2012: x64 mode, `/Arch:AVX`*  

*All Matrices are 4x4 floats.*  
*Each operation's time is averaged over 10000 runs with random single-precision floats.*  
*Timing in CPU clock cycles via `__rdtsc()`*  


####Matrix * Matrix  
```
Reference:  
SSE:  
AVX_XMM:  
AVX_YMM:  
AVX2/FMA3:  
```