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

## Functions

A nested function is illegal in CPP

### Status code
Main function return value 0 when ran normally  

Values:
* 0
* EXIT_SUCCESS
* EXIT_FAILURE

This provides a mechanism for any program lanuching another program to determine whether the launched program ran successfully or not.  
Failure to return from a value-returning function will cause undefined behaviour.  
Function main will implicitly return 0 if no return statement is provided.  
Function can return only a single value.

### Void function
Cant be used in a expresion that requires a value  
Returning a value from a void function is a compiiler error.  

### Function Parameters and arguments
Function parameter is a variable used in the header of the function  
Argument is a value that is passed from the caller to the function.  

Why functions are used:
* Organization
* Reusablity
* Testing
* Extensiblity
* Abstraction

## Files

### Programs with multiple code files
While compiling the program, one needs to include all the relevant files on the compiler line.  
Example:
`g++ main.cpp add.cpp -o main`  
Add forward declaration in main.cpp  

## Preprocessor
The preprocessor makes various changes to the code temporaarily in-memory or using temporary files.  
The preprocessor replaces the `#include` directive with the contents of the included file.

### Macros
A macro is a rule that defines how input text is converted into replacement output text.  

2 types of macros:
* function-like(unsafe can be done using a normal function)
* object-like
`#define IDENTIFIER`  
`#define IDENTIFIER substition_text`  

* Object like macro with substitution text
* Obejct like macro without substitution text

Obejct like macros without substitution text are generally considered acceptable to use.  

