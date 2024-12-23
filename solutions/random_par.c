/*
This code defines and implements a Parallel Pseudo Random Number Generator. It makes use of the OpenMP parallel region and the Leap Frog method to ensure the generation of non-overlapping sequences for each thread. The generator is initially seeded with a range, which is specified using a seed function.

The seed function also adjusts the multiplier and seeds to establish suitable initial conditions for various threads. The drandom function then generates a stream of random numbers within the defined preset range for every subsequent call.

The key elements used in the generation process are a modulus of 2^31-1 and a multiplier obtained from the Hoaglin Linear Congruential Generators (LCG). The addend is set to zero for simplicity.

The generator is designed to avoid false sharing and optimized to function within a multi-threaded environment to fit into cache-line size.
*/

//**********************************************************
// Parallel Pseudo random number generator:
//
// USAGE:
//
//  The pseudo random sequence is seeded with a range
//
//            void seed(lower_limit, higher_limit)
//   
//  and then subsequent calls to the random number generator 
//  generates values in the sequence:
//
//            double drandom()
//
//  A leap frog method is used to assure non-overlapping
//  sequences for each thread.
//
//  Note: these functions are to be called from inside the
//  the OpenMP parallel region that will use the sequence.
//
//  BACKGROUND:
//
//  We are using a modulus of 2^31-1 and a multiplier from 
//  the Hoaglin LCGs in the following article:
//
//    http://random.mat.sbg.ac.at/~charly/server/node3.html#lcg
//
//   we are using a zero addend just to make the leap frog 
//   algorithm easier to implement.
//
//  HISTORY:
//
//  9/2008: Written by Tim Mattson by cutting and pasting 
//  from a generator written by Larry Meadows
//
//***********************************************************
#include <omp.h>

static unsigned long long MULTIPLIER  = 764261123;
static unsigned long long PMOD        = 2147483647;
static unsigned long long mult_n;
double random_low, random_hi;

#define MAX_THREADS 128
static unsigned long long pseed[MAX_THREADS][4]; //[4] to padd to cache line
                                                 //size to avoid false sharing
unsigned long long random_last = 0;
#pragma omp threadprivate(random_last)


double drandom()
{
    unsigned long long random_next;
    double ret_val;

// 
// compute an integer random number from zero to mod
//
    random_next = (unsigned long long)((mult_n  * random_last)% PMOD);
    random_last = random_next;

//
// shift into preset range
//
    ret_val = ((double)random_next/(double)PMOD)*(random_hi-random_low)+random_low;
    return ret_val;
}

//
// set the seed, the multiplier and the range
//
void seed(double low_in, double hi_in)
{
   int i, id, nthreads;
   unsigned long long iseed;
   id = omp_get_thread_num();

   #pragma omp single
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
  
//
// The Leapfrog method ... adjust the multiplier so you stride through
// the sequence by increments of "nthreads" and adust seeds so each 
// thread starts with the right offset
//

      nthreads = omp_get_num_threads();
      iseed = PMOD/MULTIPLIER;     // just pick a reasonable seed
      pseed[0][0] = iseed;
      mult_n = MULTIPLIER;
      for (i = 1; i < nthreads; ++i)
      {
	iseed = (unsigned long long)((MULTIPLIER * iseed) % PMOD);
	pseed[i][0] = iseed;
	mult_n = (mult_n * MULTIPLIER) % PMOD;
      }

   }
   random_last = (unsigned long long) pseed[id][0];
}
