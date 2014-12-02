SIMD Benchmarks
===============
*Run on a mid-2014 rMBP Intel i5-4278u 2.6 GHz dual-core Haswell CPU.  
OS: Windows 8.1 running on VMWare Fusion 7.  
Compiled with VC++ 2012: x64 mode, /Arch:AVX  

All Matrices are 4x4 floats.  
Each operation timed over 10000 runs with random single-precision float values.  
Timing in unsigned __int64 CPU clock cycle via __rdtsc()  
*


###Matrix * Matrix  
```
Reference:  
SSE:  
AVX2:  
FMA3:  
```