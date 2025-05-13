# Constants and Strings

### Constants

a constant is a value that may not be changed during the program’s execution.  
Named constants are constant values that are associated with an identifier. These are also sometimes called symbolic constants.  
Literal constants are constant values that are not associated with an identifier.  
To declare a constant variable, we place the const keyword (called a “const qualifier”) adjacent to the object’s type  
Const variables must be initialized when you define them, and then that value can not be changed via assignment  
there is typically little point in returning const objects by value, because they are temporary copies that will be destroyed anyway. Returning a const value can also impede certain kinds of compiler optimizations (involving move semantics), which can result in lower performance.  

### Literals

Literals are values that are inserted directly into the code  
Just like objects have a type, all literals have a type. The type of a literal is deduced from the literal’s value. For example, a literal that is a whole number (e.g. 5) is deduced to be of type int.  
If the default type of a literal is not as desired, you can change the type of a literal by adding a suffix.  
By default, floating point literals have a type of double. To make them float literals instead, the f (or F) suffix should be used  

```cpp
int main()
{
    std::cout << 5.0 << '\n';  // 5.0 (no suffix) is type double (by default)
    std::cout << 5.0f << '\n'; // 5.0f is type float

    return 0;
}
```

### String

a string is a collection of sequential characters used to represent text (such as names, words, and sentences).  
This is the reason the string "Hello, world!" has type const char[14] rather than const char[13] -- the hidden null terminator counts as a character.  
Unlike C-style string literals, std::string and std::string_view literals create temporary objects. These temporary objects must be used immediately, as they are destroyed at the end of the full expression in which they are created.  

### Magic Number

A magic number is a literal (usually a number) that either has an unclear meaning or may need to be changed later.  

A constexpr variable is always a compile-time constant. As a result, a constexpr variable must be initialized with a constant expression, otherwise a compilation error will result.  
const means that the value of an object cannot be changed after initialization. The value of the initializer may be known at compile-time or runtime. The const object can be evaluated at runtime.  
constexpr means that the object can be used in a constant expression. The value of the initializer must be known at compile-time. The constexpr object can be evaluated at runtime or compile-time.  

A constexpr function is a function that can be called in a constant expression. A constexpr function must evaluate at compile-time when the constant expression it is part of must evaluate at compile time (e.g. in the initializer of a constexpr variable). Otherwise, a constexpr function may be evaluated at either compile-time (if eligible) or runtime. To be eligible for compile-time execution, all arguments must be constant expressions.  

### Strings

The easiest way to work with strings and string objects in C++ is via the std::string type, which lives in the <string> header.  

```cpp
#include <string> // allows use of std::string

int main()
{
    std::string name {}; // empty string

    return 0;
}
```

To read a full line of input into a string, you’re better off using the std::getline() function instead. std::getline() requires two arguments: the first is std::cin, and the second is your string variable.  

### std::ws

```cpp
#include <iostream>
#include <string>

int main()
{
    std::cout << "Pick 1 or 2: ";
    int choice{};
    std::cin >> choice;

    std::cout << "Now enter your name: ";
    std::string name{};
    std::getline(std::cin, name); // note: no std::ws here

    std::cout << "Hello, " << name << ", you picked " << choice << '\n';

    return 0;
}
```

When you enter a value using operator>>, std::cin not only captures the value, it also captures the newline character ('\n') that occurs when you hit the enter key. So when we type 2 and then hit enter, std::cin captures the string "2\n" as input. It then extracts the value 2 to variable choice, leaving the newline character behind for later. Then, when std::getline() goes to extract text to name, it sees "\n" is already waiting in std::cin, and figures we must have previously entered an empty string! Definitely not what was intended.  

If using std::getline() to read strings, use std::cin >> std::ws input manipulator to ignore leading whitespace. This needs to be done for each std::getline() call, as std::ws is not preserved across calls.  

Whenever a std::string is initialized, a copy of the string used to initialize it is made. Making copies of strings is expensive, so care should be taken to minimize the number of copies made.  
std::string supports a capability called move semantics, which allows an object that will be destroyed at the end of the function to instead be returned by value without making a copy.  

