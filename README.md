SIMD Benchmarks
===============
Testing the relative performace of basic Matrix and Vector operations against their SIMD counterparts. Each operation's times are averaged over 10000 runs. 4x4 matrices or 4D Vectors of random single-precision floats are used. Seperate calculations performed for AVX 128-bit (XMM) and 256-bit (YMM) registers. The AVX2/FMA3 (128-bit) instruction set (fused multiply-add) **requires an Intel Haswell CPU**. All operations are fairly heavily optimized. SIMD matrix multiplication uses the linear combination method.

*Tested on a 2014 rMBP with an Intel i5-4278u 2.6 GHz dual-core Haswell CPU.*  
*OS: Windows 8.1 running on VMWare Fusion 7.*  
*Compiled with MSVC++ 2012: `x64 mode`, `/arch:AVX`, `/fp:Fast`*  
*Timing in CPU clock cycles via `__rdtsc()`. (Could also use the `QueryPerformanceCounter` API to control for clock frequency.)*  

Intel Intrinsics Guide: https://software.intel.com/sites/landingpage/IntrinsicsGuide/

####Matrix * Matrix  
```
Reference: 262.00 cycles  
      SSE:  37.00 cycles  
  AVX_128:  
  AVX_256:  
AVX2/FMA3:  62.00 cycles  
```

####Vector Normalization  
```
Reference: 34.00 cycles  
      SSE: 55.00 cycles  
  AVX_128:  
  AVX_256:  
AVX2/FMA3:  
```
