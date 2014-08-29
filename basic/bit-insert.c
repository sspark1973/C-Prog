/*
given two integers and two bit positions. 
Set the first integer between the two bit positions to be that of the second integer.
*/

int replace_bits(int a, int b, int x, int y) 
{ 
int mask = ((1 << (y - x + 1)) - 1) << x; 
// Clear a and replace with that of b 
return ((a & ~mask) | (b & mask)); 
}



start = start bit
end = end bit

first = first num
second = second num

mask = ((1 << st) - 1 ) | (~0 - ((1 << end) - 1));
(mask | first) | (second << st)

