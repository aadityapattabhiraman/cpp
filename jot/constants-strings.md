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

