SIMD Benchmarks
===============
*Tested on my 2014 rMBP with an Intel i5-4278u 2.6 GHz dual-core Haswell CPU.*  
*OS: Windows 8.1 running on VMWare Fusion 7.*  
*Compiled with VC++ 2012: x64 mode, `/Arch:AVX`*  
*Timing in CPU clock cycles via `__rdtsc()`. (Could've used the QPF/QPC API to control for clock frequency.)*  

Each operation's time is the average of 10000 runs using 4x4 matrices or 4D Vectors of random single-precision floats. Seperate calculations performed for AVX 128-bit (XMM) and 256-bit (YMM) registers. The AVX2/FMA3 instruction set (fused multiply-add) **requires an Intel Haswell CPU**. All operations are fairly heavily optimized (RVO, temporary elimination, etc). SIMD matrix multiplication uses the linear combination method.

Intel Intrinsics Guide: https://software.intel.com/sites/landingpage/IntrinsicsGuide/

####Matrix * Matrix  
```
Reference: 115.0047 cycles  
      SSE:  70.5265 cycles  
  AVX_XMM:  
  AVX_YMM:  
AVX2/FMA3:  
```

####Vector Normalization  
```
Reference:  
      SSE:  
  AVX_XMM:  
  AVX_YMM:  
AVX2/FMA3:  
```
