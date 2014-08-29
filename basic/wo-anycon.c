/*
Consider the statement 
result = a ? b : c; 
Implement the above statement without using any conditional statements.
*/

/*
This is a clever answer!

I think a && (result = b, 1) || (result = c) should do though.

Explanation of the syntax:

Basic idea: (result = b, 1) always evaluates to "1". 
Just a clever way to set "result = b" 
while making sure the whole expression always evaluates to "1" even when value of b is 0.

Now the explanation is simple:
1. when a != 0, only (result = b, 1) gets executed effectively setting result to b.
2. when a == 0, no matter what, (result = b, 1) and (result = c, 0) 
gets evaluated in that order effectively setting result to c.
*/


a && (result = b, 1) || (result = c, 0)

This is solution for C++:

result = a * b + !a * c;


