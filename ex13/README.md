Exercise 13
==========
<http://c.learncodethehardway.org/book/ex13.html>

More basics.

CFLAGS="-std=c99" make ex13


Switch statement, essentially a lookup (jump) table.

* The compiler marks the place in the program where the switch-statement starts, let's call this location Y.
* It then evaluates the expression in switch(letter) to come up with a number. In this case the number will be the raw ASCII code of the letter in argv[1].
* The compiler has also translated each of the case blocks like case 'A': into a location in the program that is that far away. So the code under case 'A' is at Y+'A' in the program.
* It then does the math to figure out where Y+letter is located in the switch-statement, and if it's too far then it adjusts it to Y+default.
* Once it knows the location, the program "jumps" to that spot in the code, and then continues running. This is why you have break on some of the case blocks, but not others.
* If 'a' is entered, then it jumps to case 'a', there's no break so it "falls through" to the one right under it case 'A' which has code and a break.
* Finally it runs this code, hits the break then exits out of the switch-statement entirely.

