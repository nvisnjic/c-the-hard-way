Exercise 15
==========
<http://c.learncodethehardway.org/book/ex15.html>


Pointer fun.

Lexicon:

    type *ptr
    "a pointer of type named ptr"
    
    *ptr
    "the value of whatever ptr is pointed at"
    
    *(ptr + i)
    "the value of (whatever ptr is pointed at plus i)"
    
    &thing
    "the address of thing"
    
    type *ptr = &thing
    "a pointer of type named ptr set to the address of thing"
    
    ptr++
    "increment where ptr points" 


When to use pointers:

* Ask the OS for a chunk of memory and use a pointer to work with it. This includes strings and something you haven't seen yet, structs.
* Passing large blocks of memory (like large structs) to functions with a pointer so you don't have to pass the whole thing to them.
* Taking the address of a function so you can use it as a dynamic callback.
* Complex scanning of chunks of memory such as converting bytes off a network socket into data structures or parsing files.

