# Compiler Flags

### Mine

-std=c++23 -pedantic-errors -ggdb -Werror
-std=c++23 -pedantic-errors -DNDEBUG -O2

### Flags

-std=c++23
-ggdb
-O2 -DNDEBUG
-pedantic-errors 

### Optimization settings

-O0 is the recommended optimization level for debug builds, as it disables optimization. This is the default setting
-O2 is the recommended optimization level for release builds, as it applies optimizations that should be beneficial for all programs.
-O3 adds additional optimizations that may or may not perform better than -O2 depending on the specific program. Once your program is written, you can try compiling your release build with -O3 instead of -O2 and measure to see which is faster.

### Disable compiler extensions

You can disable compiler extensions by adding the -pedantic-errors flag to the compile command line.

### Header files in different directory

Using g++, you can use the -I option to specify an alternate include directory:
g++ -o main -I./source/includes main.cpp

There is no space after the -I. For a full path (rather than a relative path), remove the . after -I.

### Optimization

optimization is the process of modifying software to make it work more efficiently  
Some types of optimization are typically done by hand. A program called a profiler can be used to see how long various parts of the program are taking to run, and which are impacting overall performance. The programmer can then look for ways to alleviate those performance issues. Because hand-optimization is slow, programmers typically focuses on making high-level improvements that will have a large impact  
A program that optimizes another program is called an optimizer. Optimizers typically work at a low-level, looking for ways to improve statements or expressions by rewriting, reordering, or eliminating them  
Modern C++ compilers are optimizing compilers, meaning they are capable of automatically optimizing your programs as part of the compilation process. Just like the preprocessor, these optimizations do not modify your source code files -- rather, they are applied transparently as part of the compilation process.  
compilers typically support multiple optimization levels that determine whether they optimize, how aggressively they optimize, and what kind of optimizations they prioritize (e.g. speed vs size).  

### Asif rule

In C++, compilers are given a lot of leeway to optimize programs. The as-if rule says that the compiler can modify a program however it likes in order to produce more optimized code, so long as those modifications do not affect a program’s “observable behavior”.  

Modern C++ compilers are capable of fully or partially evaluating certain expressions at compile-time (rather than at runtime). When the compiler fully or partially evaluates an expression at compile-time, this is called compile-time evaluation.  

One of the original forms of compile-time evaluation is called “constant folding”. Constant folding is an optimization technique where the compiler replaces expressions that have literal operands with the result of the expression.  
Constant propagation is an optimization technique where the compiler replaces variables known to have constant values with their values. Using constant propagation, the compiler would realize that x always has the constant value 7, and replace any use of variable x with the value 7.  
Dead code elimination is an optimization technique where the compiler removes code that may be executed but has no effect on the program’s behavior.  

### Optimizations can make a program harder to debug

When the compiler optimizes a program, the result is that variables, expressions, statements, and function calls may be rearranged, modified, replaced, or removed entirely. Such changes can make it hard to debug a program effectively.  
At runtime, it can be hard to debug compiled code that no longer correlates very well with the original source code. For example, if you try to watch a variable that has been optimized out, the debugger won’t be able to locate the variable. If you try to step into a function that has been optimized away, the debugger will simply skip over it. So if you are debugging your code and the debugger is behaving strangely, this is the most likely reason.  
At compile-time, we have little visibility and few tools to help us understand what the compiler is even doing. If a variable or expression is replaced with a value, and that value is wrong, how do we even go about debugging the issue? This is an ongoing challenge.  
To help minimize such issues, debug builds will typically leave optimizations turned off, so that the compiled code will more closely match the source code.  
