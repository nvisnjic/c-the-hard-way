Exercise 18
==========
<http://c.learncodethehardway.org/book/ex18.html>


The format of a function pointer:

    int (*POINTER_NAME)(int a, int b)
    //eg.
    int (*tester)(int a, int b) = sorted_order;


A way to remember how to write one is to do this:

    Write a normal function declaration: int callme(int a, int b)
    Wrap function name with pointer syntax: int (*callme)(int a, int b)
    Change the name to the pointer name: int (*compare_cb)(int a, int b)

To pass function pointers on as parameters of other functions use typedef.

    // a typedef creates a fake type, in this
    // case for a function pointer
    typedef int (*compare_cb)(int a, int b);

    int *bubble_sort(int *numbers, int count, compare_cb cmp)
    { (...)


VIM hex view 

filter to hex -> :%!xdd
reverse filter to binary -> :%!xxd -r

[http://www.kevssite.com/2009/04/21/using-vi-as-a-hex-editor/](more info)


hte hex editor or dhex are good..
