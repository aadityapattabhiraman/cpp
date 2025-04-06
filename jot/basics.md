# C++ Basics

A statement is a type of instruction that causes the program to perform some action.  
A function is a collection of statements that get executed sequentially (in order, from top to bottom)  
In programming, the name of a function (or object, type, template, etc…) is called its identifier.  
Computers have an additional type of character, called a “control character”. These are characters that have special meaning to the computer system, but either aren’t intended to be displayed, or display as something other than a single visible symbol. Examples of well-known control characters include “escape” (which doesn’t display anything), “tab” (which displays as some number of spaces), and “backspace” (which erases the previous character).  

### Comments

The `//` symbol begins a C++ single-line comment, which tells the compiler to ignore everything from the `//` symbol to the end of the line.  
The `/*` and `*/` pair of symbols denotes a C-style multi-line comment. Everything in between the symbols is ignored.  

### Objects

An object represents a region of storage (typically RAM or a CPU register) that can hold a value.  
An object with a name is called a variable.  
The process of reserving storage for an object’s use is called allocation. Once allocation has occurred, the object has been created and can be used.  
A data type (more commonly just called a type) determines what kind of value (e.g. a number, a letter, text, etc…) the object will store.  

### Assignment

Assignment copies the value on the right-hand side of the = operator to the variable on the left-hand side of the operator. This is called copy-assignment.  
When an initial value is provided inside parenthesis, this is called direct-initialization.  
The modern way to initialize objects in C++ is to use a form of initialization that makes use of curly braces. This is called list-initialization (or uniform initialization or brace initialization).  
List-initialization disallows narrowing conversions  
When a variable is initialized using an empty set of braces, a special form of list-initialization called value-initialization takes place  
C++17 introduced the `[[maybe_unused]]` attribute, which allows us to tell the compiler that we’re okay with a variable being unused. The compiler will not generate unused variable warnings for such variables.  

### iostream

`std::cout` is buffered  
Using std::endl is often inefficient, as it actually does two jobs: it outputs a newline (moving the cursor to the next line of the console), and it flushes the buffer (which is slow).  
`std::cin` is buffered  
