Exercise 22
==========
<http://c.learncodethehardway.org/book/ex22.html>

Watch that scope!

Overview of special var types:

*extern* - "the variable exists, but it's 
in another 'external' location". Typically  one .c file is
going to use a variable that's been defined in another .c file

*static (file)* - the variable will only be available and used in this .c file 
(kinda opposite of extern).

*static (function)* - a persistant variable that can hold value between function calls.
Only available within mentioned function.


"Pass by value" vs "Pass by reference" example
======================================

If the one that's being passed is changed, than it's pass by reference (eg.
address of variable AKA pointer (reference))


    void Modify(int p, int * q, int * o)
    {
        p = 27; // passed by value - only the local parameter is modified
        *q = 27; // passed by value or reference, check call site to determine which
        *o = 27; // passed by value or reference, check call site to determine which
    }
    int main()
    {
        int a = 1;
        int b = 1;
        int x = 1;
        int * c = &x;
        Modify(a, &b, c);   // a is passed by value
                            //b is passed by reference by creating a pointer,
        // c is a pointer passed by value
        // b and x are changed
        return(0);
    }

More detail: <http://en.wikipedia.org/wiki/Evaluation_strategy>
