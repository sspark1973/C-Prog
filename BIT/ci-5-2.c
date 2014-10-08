/*
5 2 Given a (decimal - e g  3.72) number that is passed in as a string, 
print the binary rep-resentation   

If the number can not be represented accurately in binary, 
print ¡°ERROR¡±
*/

/*
SOLUTION
First, let's start off by asking ourselves 
what a non-integer number in binary looks like.   

By analogy to a decimal number, 
the number n = 0.101 = 1 * (1/2^1) + 0 * (1/2^2) + 1 * (1/2^3)   

Printing the int part of n is straight-forward (see below).   
To print the decimal part, 
we can multiply by 2 and check if the 2*n is greater than or equal to one.   

This is essentially ¡°shifting¡±  the fractional sum.   
That is: 
	r = 2*n = 2*0.101 = 1*(1 / 2^0) + 0*(1 / 2^1) + 1*(1 / 2^2) = 1.01 

If r >= 1, then we know that n had a 1 right after the decimal point.   
By doing this continu- ously, we can check every digit.
*/



