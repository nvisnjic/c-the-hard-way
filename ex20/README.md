Exercise 20
==========
<http://c.learncodethehardway.org/book/ex20.html>

DEBUG macros are a good addition to the arsenal.


    debug("some message about the bug & number: &d", 42);

dbg.h will work just nicely.
Minor edits to formatting output.

    #define NDEBUG
is the swittch.

Makefile modification for different CFLAGS during compilation.
(a cleaner solution ought to exist thou)


Function names:
https://gcc.gnu.org/onlinedocs/gcc/Function-Names.html (for name)
https://gcc.gnu.org/onlinedocs/gcc/Return-Address.html (for stack address)

More detailed:
http://www.gnu.org/software/libc/manual/html_node/Backtraces.html


