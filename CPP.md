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

## CPP BASICS

### Statements

Different kinds of statement:
* Declaration
* Jump
* Expression
* Compound
* Conditional
* Loops
* Try Blocks

Every CPP program should have a main function.  

### Comments

* Single Line Comments `//`
* Multi-line Comments `/*  */`

### Objects and variables

Direct memory access is discouraged, instead access memory indirectly using objects.
An object with a name is called a variable.

* Although the language allows, avoid creating multiple variables of the same type in a single statement. instead, define each variable in a separate statement on its own line.  

### Variable Assignment and Initialization

Variable Assignment `=`  
Variable Initialization
* Default `int a`
* Copy `int b = 5`
* Direct `int c (6)`
* Direct list initialization `int d{ 7 }`
* Value Initialization `int e {}`

Other forms of initialization
* Aggregate
* Reference
* Static, constant and dynamic
* Zero 

List initialization disallows narrow conversions  
`[[maybe_unused]]` does not throw warnings if something is unused

### iostream

* cout
* cin
* endl
* endl v/s \n

### Uninitialized variables and Undefined behaviour
