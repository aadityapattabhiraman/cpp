# CPP

## Introduction

* Compiling using g++ `g++ -o HelloWorld HelloWorld.cpp`  

### Configure Compiler

Add `-ggdb` for debug builds and `-O2 -DNDEBUG` for release builds.

The -O# option is used to control optimization settings.  
* `-O0` is recommended optimization for debug builds, as it disables optimization.  
* `-O2` is the recommended optimization for release builds, as it applies optimizations.
* `-O3` adds aditional optimizations that may or may not perform bettter than -O2 depending on the specific program. Once the program is complete, try compiling with `-O3` instead of `-O2` to see which one is faster.

Always Disable COMPILER EXTENSIONS using `-pedantic-errors`  

Best practise is to trweat all warnings as errors using `-Werror`  

Setting a language standard `-std=c++11`, `-std=c++14`, `-std=c++17`, `-std=c++23`  
