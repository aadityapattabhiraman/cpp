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
