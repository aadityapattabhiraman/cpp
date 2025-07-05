# CPP

## Introduction

* Compiling using g++ `g++ -o HelloWorld HelloWorld.cpp`  
* I use `g++ hello.cpp -std=c++23 -O2 -DNDEBUG -pdeantic-errors -Werror`

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

### Conditional Compilation
Allows to specify under what conditions something will or wont compile.

Types:  
* #ifdef
Allows preprocessor to check whether a identifier has been defined via #define. If so, the code between #ifdef and matching #endif is compiled. Ignored otherwise.  
* #ifndef
Allows to check whether an identifier has not been defined yet.  
* #endif
completion for both ifdef and ifndef  
* if 0
exclude a block of code from being compiled.  
* if 1
always compiles  

Macro substitution does not occur when a macro identifier is used within another preprocessor command. Most forms of `#if` and `#elif` do macro substitution within the preprocessor command.  

### Scope of #define
Directives are only vaid from the point of definition to the end of the file in which they are defined. Directives defined in one file do not have any impact on the other files, unless they are included in another file.  

### Header Files
Used to propagate a bunch of related forward declarations into a code file.  

A header file consists of 2 parts:
* header guard
* content of the header file

If a header file is paired with a code file they should have the same base name

When the preprocessor processes `#include "add."` line, it includes the contents of add.h into the current file at that point. Because our add.h contains a forward declaration for the function add(), that forward declaration will be copied into main.cpp. The end result is a program that is functionally the same as the one where we manually added the forward declaration at the top of main.cpp.  

Do NOT `#include .cpp` files.  
When angled brackets are used, preprocessor knows that this is a header file we didn't write ourselves. The preprocessor will search for header files only in directories specified by `include directories`. When using double quotes we're telling the preprocessor that this is a header file that we wrote. It will first search the current directory, if it cant find then it will search `include directories`.  

`-I` option can be used to specify alternate include directory  
`g++ -o main -I./source/includes main.cpp`  

Each file should explicitly #include all the header files it needs to compile. Do not rel on headers included transitively from other headers.  

### Header Guards
Variables defined more than once can only have one definition, similarly function defined more than once can cause errors.  
To prevent duplicates of definition in the program especially while using header files header guards are used.

```
#ifndef UNIQUE
#definde UNIQUE
---
#endif
```
Using only the file names for header guards can cause problems, if a file requires both the includes will not used only the first header will be included.  
Header guards do not prevent a header from being includeed once into different code files  
`#pragma once` serves the same purpose as header guards. If a header file is copied so that it exists in multiple places on the system, if both copies of heade gets included, header guards will successfully de-dupe the identical headers, where as `#praga once` does not.  

Example:

`square.h`
```cpp
#ifndef SQUARE_H
#define SQUARE_H

int get_square_sides()
{
    return 4;
}
#endif
```

`wave.h`
```cpp
#ifndef WAVE_H
#define WAVE_H

#include "square.h"

#endif
```

`main.cpp`
```cpp
#include "square.h"
#include "wave.h"

int main()
{
    return 0;
}
```

Header guards prevent duplicate inclusions because the first time a guard is encountered, the macro isn't defined, so the guarded content is included. Past that point, the guard macro is defined, so any subsequent copies of the guarded content are excluded.  

## Data Types

### Integer overflow
Assigning 140 to 8 bit signed integer, causes overflow.  
If during the evaluation of an expression, the result is not mathematically defined or not in the range of representable values for its type, the behaviour is undefined.  

Unsigned integer causes "wraps around" or "modulo wrapping"

### Fixed width integers
same size on every architecture unlike normal integers.  
the 8-bit fixed-width integer types are often treated like chars instead of integer values (varies based on system). The 16-bit and wider integral types are not subject to this issue.  
Fixed-width integers actually dont define new types, they are just aliases for existing integral types with the desired size.

### Floats
Prefer double over float unless size is a premium, s the lack of precision in a float will often lead to inaccuracies.  
Rounding errors make floating comparison risky  

### Type Conversion
When compiler does does type conversions without asking it is called implicit type conversions.  
`const_cast` and `reinterpret_cast` do not return temp objects, instead reinterpret the type of an existing value or object.  
In case of explicit type conversions, warnings are not given.  
`static_cast<int>(ch)`  

## Constants and Strings

### Constants
* Named Constants
* Literal Constants

Types of named Constant  
* Constant variables
* Object like macros with substitution text
* enumerate constants

Const Variable
`const double gravity { 9.8 };`  
const varibles must be initialized when you define them.  
Prefer constant variables over object-like macros with substitution text.  

A type qualifier is a keyword that is applied to a type that modifies how that type behaves.  
Types:  
* `const`
* `volatile`

### As-if rule
Compiler can modify a program however it likes in order to produce mre optimized code.  
When the compiler fully or partially evaluates an exppression at compile-time, this is called compile-time evaluation.  

* Constant folding is a optimization techinique where the compiler replaces expressions that have literal operands with the result of the expression.  
* Constant propagation is an optimization technique where the compiler replaces variables known to have constant values with their values. Using constant propagation, the compiler would realise that `x` alwways has constant value `7`, and replace any use of the variable `x` with value `7`.  
* Dead code elimination is an optimization technique where the compiler removes code that may be executed but has no effect on the program's behavior.  
Using const variables can help the compiler optimize things more effectively.  
*optimizations can make programs harder to debug*  

A common cases where a compiler time evaluatable expression:
* initializer of a constexpr variable
* A non-type template argument
* the defined length of a `std::array` or a C-style array.  

### Compile time programming
C++ language provides ways for us to be explicit about what parts of the code we want to execute at compile-time.  

Foundation to compile-time programming:
* Constexpr variables
* Constexpr functions
* Templates
* static_assert

### Constant Expression
Non-empty sequence of literals, constant variables, operators and function calls all of which must be evaluated at compile-time.

Constant expression can contain:
* Literal
* Most operators with constant expression operands
* Const integral variables with a constant expression initializer
* Constexpr variables
* Constexpr function calls with constant expression arguments
* Non-type template parameters
* enumerators
* Type traits
* Constexpr lambda expressions

```cpp
const int x { 3 + 4 }; // evaluated at compile time
int y { 3 + 4 }; // maybe evaluated at compile time
```

The compiler is only required to evaluate constant expressions at compile-time in contexts that require a constant expression. It may or may not do in other cases.  

### constexpr variables
A `const` variable with an integral type and a constant expression initializer can be used in a constant expression. All other `const` variables cannot be used in constant expressions.  

Use of `const` to create variables that can be used in constant expressions has a few challenges.
* `const` does not make it immiediately clear whether the variable is usable in constant expression or not.  
* use of `const` does not provide a way to inform the compiler that we require a variable that is usable in constant expression.  
* use of `const` to create a compile time constant variable does not extend to non-integral values.  

A `constexpr` variable is always a compile-time constant.  
Functions normally execute at runtime, the return value of a function is not constexpr even when the return expression is a constant expression.  

### constexpr funcitons
Function that can be called in a constant expression.  

### String
`std::string`  
`std::getline()`  
`std::getline(std::cin >> std::ws, var);`  
`std::ws`  
string copies is expensive.  
even intializing is expensive.  

### std::string_view
`std::string` being expensive to initialize or copy, `std::string_view` provides a read only access to an existing string without making a copy.  
A view is dependent on the object being viewed. If the object being viewed is modified or destroyed while the view is still being used, unexpected or undefined behavior will result.  
Way too much shit in this and I am not sure whether this would actually be useful to be, especially the number of footguns.  

## Operators

### Conditional Expression
`condition ? expression1 : expression2;`
condition is true expression1 is evaluated, else expression2 is evaluated
