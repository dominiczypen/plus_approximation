/* Author: Dominic van der Zypen
 * Goal: Check associativity for
 * the approximation a+b "=" a ^ b ^ ((a & b) << 1);
 * for a, b, c bytes = unsigned char
 *
 * Compile: gcc plus_approx_assoc.c -o out . Run: ./out
 */

#include <stdio.h>
#include <stdlib.h>

// ----------------------------
unsigned int ap(unsigned int a, unsigned int b)
  // approximation of + 
  // ap -> "almost plus" 
{
  return (a ^ b) ^ ((a & b) << 1);
}
// ----------------------------
void assoc_check() 
  // calculate the average Hamming distance of a+b to almost_plus OLD
  // and the average Hamming distance of a+b to almost_plus NEW
{
  unsigned char a,b,c,res1,res2,number_of_counterex;
  a = 0;
  number_of_counterex = 0;
  while (a < 0xff)
  {
    b = a;
    while (b < 0xff)	  
    {
      c = b;
      while ((c < 0xff) && (number_of_counterex < 0x0f))
      {
	res1 = ap(ap(a, b), c);
	res2 = ap(a, ap(b, c)); // if res1 == res2 -> associative
	if (res1 != res2)
	{
	  printf("Counterexample: %x, %x, %x, res1 == %x,  res2 == %x\n", 
			  a, b, c, res1, res2);
	  number_of_counterex++;
	}
	c++;
      }
      b++;
    }
    a++;
  }
}
// ----------------------------
int main()
{
  assoc_check();
  return 0;
}
