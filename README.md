SIMD Benchmarks
===============
*Tested on my 2014 rMBP with an Intel i5-4278u 2.6 GHz dual-core Haswell CPU.*  
*OS: Windows 8.1 running on VMWare Fusion 7.*  
*Compiled with VC++ 2012: x64 mode, `/Arch:AVX`*  
*Timing in CPU clock cycles via `__rdtsc()`*  

*Each operation's time is averaged over 10000 runs with 4x4 matrices of randomized single-precision floats.*  

####Matrix * Matrix  
```
Reference: 115.0047 cycles  
      SSE:  70.5265 cycles  
  AVX_XMM:  
  AVX_YMM:  
AVX2/FMA3:  
```
