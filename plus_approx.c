/* Author: Dominic van der Zypen
 * Goal: compute average Hamming distance between a+b
 * and the approximation a+b "=" a ^ b ^ ((a & b) << 1);
 * for a, b bytes = unsigned char
 *
 * Compile: gcc plus_approx.c -o out . Run: ./out
 */

#include <stdio.h>
#include <stdlib.h>

unsigned char popcount(unsigned int a)
  // == Hamming weight == number of 1 in binary rep of a.
  // popcount(a ^ b) is Hamming distance of a,b
{
  unsigned char count = 0;
  while (a)
  {
    if (a & 1) { count++; } // increment count if rightmost bit == 1
    a = a >> 1;
  }
  return count;
}
// ----------------------------
unsigned int almostplus(unsigned int a, unsigned int b)
  // approximation of + 
{
  return (a ^ b) ^ ((a & b) << 1);
}
// ----------------------------
void hamming_distance_orig_vs_new() 
  // calculate the average Hamming distance of a+b to almost_plus OLD
  // and the average Hamming distance of a+b to almost_plus NEW
{
  unsigned int a,b,d,maximum;
  unsigned int sum, sum_orig, sum_new;
      // sum = a+b, sum_orig = orig approx, sum_new = new approx.
  unsigned int sum_diff_orig = 0;
  unsigned int loops = 0;
  maximum = (1 << 13);

  a = 0;
  while (a < maximum) 
  {
    b = a;
    while (b < maximum)	  
    {
      sum = a + b;
      sum_orig = almostplus(a,b);
      sum_diff_orig += popcount(sum ^ sum_orig); // Hamming distance of sum to sum_orig
      b++;
      loops++;
    }
    a++;
  }
  printf("Number of runs: %d\n", loops);
  printf("Total sum of Hamming distance of + to almost + (orig): %d\n", sum_diff_orig);
}
// ----------------------------
int main()
{
  hamming_distance_orig_vs_new();
  return 0;
}
