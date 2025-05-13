# Data Types

Void is the easiest of the data types to explain. Basically, void means “no type”!

Void is our first example of an incomplete type. An incomplete type is a type that has been declared but not yet defined. The compiler knows about the existence of such types, but does not have enough information to determine how much memory to allocate for objects of that type. void is intentionally incomplete since it represents the lack of a type, and thus cannot be defined.  
Functions that do not return a value  

The sizeof operator is a unary operator that takes either a type or a variable, and returns the size of an object of that type (in bytes).  
sizeof does not include dynamically allocated memory used by an object.  

### Overflow

The C++20 standard makes this blanket statement: “If during the evaluation of an expression, the result is not mathematically defined or not in the range of representable values for its type, the behavior is undefined”. Colloquially, this is called overflow.  
