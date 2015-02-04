Exercise 16
==========
<http://c.learncodethehardway.org/book/ex16.html>

valgrind --leak-check=full ./ex16


info assert

    #include <assert.h>        
    void assert (int EXPRESSION)

Verify the programmer's belief that EXPRESSION is nonzero at this
point in the program.

If 'NDEBUG' is not defined, 'assert' tests the value of EXPRESSION.
If it is false (zero), 'assert' aborts the program (note Aborting
a Program::) after printing a message of the form:

    FILE:LINENUM: FUNCTION: Assertion `EXPRESSION' failed.
    
man strdup

    #include <string.h>
    char *strdup(const char *s);
The strdup() function returns a pointer to a new  string  which  is  a
duplicate of the string s.  Memory for the new string is obtained with
malloc(3), and can be freed with free(3).


Watch out for them frees and NULLs.

