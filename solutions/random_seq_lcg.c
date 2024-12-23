/*
This script implements a simple linear congruential pseudo-random number generator (LCG). The LCG uses defined constant values (such as a multiplier, addend, and modulus) to generate a sequence of random integers within a specified range. 

The script defines two functions: 

1. `drandom()`: This function calculates the next random number in the sequence using previously defined constants and the last generated random number. It then scales this number to the pre-established range and returns it.

2. `seed(double low_in, double hi_in)`: This function takes two inputs representing the lower and upper bounds for the desired randomness range. It sets the range such that the lower input is assigned to `random_low` and the higher input is assigned to `random_hi`. If the inputs are provided in reverse order, the function correctly swaps them. It then seeds the random number generator by initializing `random_last` with a calculated value.
*/

//**********************************************************
// Pseudo random number generator:
//     double drandom
//     void seed (lower_limit, higher_limit)
//**********************************************************
//
// A simple linear congruential random number generator
// (Numerical Recipies chapter 7, 1st ed.) with parameters
// from the table on page 198j.
//
//  Uses a linear congruential generator to return a value between
//  0 and 1, then scales and shifts it to fill the desired range.  This
//  range is set when the random number generator seed is called.
// 
// USAGE:
//
//      pseudo random sequence is seeded with a range
//
//            void seed(lower_limit, higher_limit)
//   
//      and then subsequent calls to the random number generator generates values
//      in the sequence:
//
//            double random()
//
// History: 
//      Written by Tim Mattson, 9/2007.

#include "random_seq_lcg.h"

long MULTIPLIER  = 1366;
long ADDEND      = 150889;
long PMOD        = 714025;
long random_last = 0;
double random_low, random_hi;

double drandom()
{
    long random_next;
    double ret_val;

// 
// compute an integer random number from zero to mod
//
    random_next = (MULTIPLIER  * random_last + ADDEND)% PMOD;
    random_last = random_next;

//
// shift into preset range
//
    ret_val = ((double)random_next/(double)PMOD)*(random_hi-random_low)+random_low;
    return ret_val;
}
//
// set the seed and the range
//
void seed(double low_in, double hi_in)
{
   if(low_in < hi_in)
   { 
      random_low = low_in;
      random_hi  = hi_in;
   }
   else
   {
      random_low = hi_in;
      random_hi  = low_in;
   }
   random_last = PMOD/ADDEND;  // just pick something

}
//**********************************************************
// end of pseudo random generator code.
//**********************************************************
