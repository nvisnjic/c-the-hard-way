Exercise 17
==========
<http://c.learncodethehardway.org/book/ex17.html>


man strncpy 

If there is no terminating null byte in the  first  n  bytes  of  src,
strncpy()  produces an unterminated string in dest.  If buf has length
buflen, you can force termination using something like the following:

    strncpy(buf, str, buflen - 1);
    if (buflen > 0)
        buf[buflen - 1]= '\0';


