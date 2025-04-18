# Functions and files

### Functions

A function is a reusable sequence of statements designed to do a particular job.  
A function call tells the CPU to interrupt the current function and execute another function. The CPU essentially “puts a bookmark” at the current point of execution, executes the function named in the function call, and then returns to the point it bookmarked and resumes execution.  
A function whose definition is placed inside another function is a nested function. Unlike some other programming languages, in C++, functions cannot be nested.  
main() is required to return an int.  
Explicit function calls to main() are disallowed.  

The C++ standard only defines the meaning of 3 status codes: 0, EXIT_SUCCESS, and EXIT_FAILURE. 0 and EXIT_SUCCESS both mean the program executed successfully. EXIT_FAILURE means the program did not execute successfully.  
#include <cstdlib> // for EXIT_SUCCESS and EXIT_FAILURE  

A value-returning function that does not return a value will produce undefined behavior  

### Void Dunctions

Returning a value from a void function is a compile error  
Void functions can’t be used in expression that require a value  
Void functions don’t need a return statement  

### Parameters and arguments

A function parameter is a variable used in the header of a function.  
An argument is a value that is passed from the caller to the function when a function call is made  
When a function is called, all of the parameters of the function are created as variables, and the value of each of the arguments is copied into the matching parameter (using copy initialization). This process is called pass by value. Function parameters that utilize pass by value are called value parameters.  

In certain cases, you will encounter functions that have parameters that are not used in the body of the function. These are called unreferenced parameters.  
In a function definition, the name of a function parameter is optional. Therefore, in cases where a function parameter needs to exist but is not used in the body of the function, you can simply omit the name. A parameter without a name is called an unnamed parameter  

A forward declaration allows us to tell the compiler about the existence of an identifier before actually defining the identifier.  

### ODR (One Definition Rule)

Within a file, each function, variable, type, or template in a given scope can only have one definition. Definitions occurring in different scopes (e.g. local variables defined inside different functions, or functions defined inside different namespaces) do not violate this rule.  
Within a program, each function or variable in a given scope can only have one definition. This rule exists because programs can have more than one file. Functions and variables not visible to the linker are excluded from this rule  
Types, templates, inline functions, and inline variables are allowed to have duplicate definitions in different files, so long as each definition is identical.  

### Multiple files

From the command line, you can create the additional file yourself, using your favorite editor, and give it a name. When you compile your program, you’ll need to include all of the relevant code files on the compile line. For example: g++ main.cpp add.cpp -o main, where main.cpp and add.cpp are the names of your code files, and main is the name of the output file.  
place the definition of function add before function main, or satisfy the compiler with a forward declaration. In this case, because function add is in another file, the reordering option isn’t possible.  

A namespace provides another type of scope region (called namespace scope) that allows you to declare or define names inside of it for the purpose of disambiguation. The names declared in a namespace are isolated from names declared in other scopes, allowing such names to exist without conflict.  

### Conditional Compilation

The conditional compilation preprocessor directives allow you to specify under what conditions something will or won’t compile. There are quite a few different conditional compilation directives, but we’ll only cover a few that are used the most often: #ifdef, #ifndef, and #endif.  

The #ifdef preprocessor directive allows the preprocessor to check whether an identifier has been previously defined via #define. If so, the code between the #ifdef and matching #endif is compiled. If not, the code is ignored.  

#ifndef is the opposite of #ifdef, in that it allows you to check whether an identifier has NOT been #defined yet.  

One more common use of conditional compilation involves using #if 0 to exclude a block of code from being compiled (as if it were inside a comment block)  

### Header files

Header files usually have a .h extension, but you will occasionally see them with a .hpp extension or no extension at all.  
Conventionally, header files are used to propagate a bunch of related forward declarations into a code file.  

int add(int x, int y); // function prototype for add.h -- don't forget the semicolon!  
#include "add.h" // Insert contents of add.h at this point.  Note use of double quotes here.  

When we use double-quotes, we’re telling the preprocessor that this is a header file that we wrote. The preprocessor will first search for the header file in the current directory. If it can’t find a matching header there, it will then search the include directories.  
When we use angled brackets, we’re telling the preprocessor that this is a header file we didn’t write ourselves. The preprocessor will search for the header only in the directories specified by the include directories.  

### Header Guards

The good news is that we can avoid the above problem via a mechanism called a header guard (also called an include guard). Header guards are conditional compilation directives that take the following form:  
#ifndef SOME_UNIQUE_NAME_HERE
#define SOME_UNIQUE_NAME_HERE

// your declarations (and certain types of definitions) here

#endif  
Some good suggestions are a naming convention of PROJECT_PATH_FILE_H, FILE_LARGE-RANDOM-NUMBER_H, or FILE_CREATION-DATE_H.  

#pragma once serves the same purpose as header guards: to avoid a header file from being included multiple times. With traditional header guards, the developer is responsible for guarding the header (by using preprocessor directives #ifndef, #define, and #endif). With #pragma once, we’re requesting that the compiler guard the header. How exactly it does this is an implementation-specific detail.  
There is one known case where #pragma once will typically fail. If a header file is copied so that it exists in multiple places on the file system, if somehow both copies of the header get included, header guards will successfully de-dupe the identical headers, but #pragma once won’t (because the compiler won’t realize they are actually identical content).  


