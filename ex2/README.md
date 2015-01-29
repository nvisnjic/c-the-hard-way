Exercise 2
==========
<http://c.learncodethehardway.org/book/ex2.html>


Only tabs in Makefile. Be smart, be consistent!

all: {name}


Read up on info make!

info pages navigation:
space, backspace (delete) - scroll down, scroll up
n, p, u, t - next, previous, up, top
tab - next hyperlink in file
h - help

EC: GCC
==============
There's a LOT of options here. man gcc, good luck.

-Wall <- gimme all the warning messages, quite handy for embedded C
-g    <- make debugging info in native system language, GDB can work with this

EC: Useful make snippets
===============

make -d   <- debugging information with rule application trace
make -p   <- print out whole make database, useful to trace variable values


In make, we use rules to define what the hell we want it to do, apart from
implicite rules, these are explicit rules we define.

In general, a rule looks like this:

     TARGETS : PREREQUISITES
             RECIPE
             ...

or like this:

     TARGETS : PREREQUISITES ; RECIPE
             RECIPE
             MORE RECIPE STUFF
             ...


Here is an example of a rule:

     foo.o : foo.c defs.h       # module for twiddling the frobs
                  cc -c -g foo.c


It tells make to rebuild foo (TARGETS) if foo.c and/or defs.h (PREREQUISITES) are out of date, using cc/gcc to compile the file (RECIPE).

