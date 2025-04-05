# Compiler Flags

-std=c++23
-ggdb
-O2 -DNDEBUG


### Optimization settings

-O0 is the recommended optimization level for debug builds, as it disables optimization. This is the default setting
-O2 is the recommended optimization level for release builds, as it applies optimizations that should be beneficial for all programs.
-O3 adds additional optimizations that may or may not perform better than -O2 depending on the specific program. Once your program is written, you can try compiling your release build with -O3 instead of -O2 and measure to see which is faster.
