/*
**  This program performs a straightforward producer/consumer operation with an array of random numbers.
**  It first declares a set of constants for generating the random numbers and an array of double precision floating point numbers.
**  The program includes two primary functions - fill_rand and Sum_array.
**  - fill_rand function is the 'producer'. It populates the array with randomly generated numbers based on defined constants.
**  - Sum_array function is the 'consumer'. It sums all the elements of that array.
**  In the main function, it allocates memory for the array, captures the start time, and then calls the producer and consumer functions.
**  After the sum is performed, it calculates the elapsed runtime, and then prints the runtime and the sum of the array elements.
**  If run on an APPLE system, the program uses the stdlib.h library to perform memory allocation; otherwise, it uses the malloc.h library. 
*/
/*
**  PROGRAM: A simple serial producer/consumer program
**
**  One function generates (i.e. produces) an array of random values.  
**  A second functions consumes that array and sums it.
**
**  HISTORY: Written by Tim Mattson, April 2007.
*/
#include <omp.h>
#ifdef APPLE
#include <stdlib.h>
#else
#include <malloc.h>
#endif
#include <stdio.h>

#define N        10000

/* Some random number constants from numerical recipies */
#define SEED       2531
#define RAND_MULT  1366
#define RAND_ADD   150889
#define RAND_MOD   714025
int randy = SEED;

/* function to fill an array with random numbers */
void fill_rand(int length, double *a)
{
   int i; 
   for (i=0;i<length;i++) {
     randy = (RAND_MULT * randy + RAND_ADD) % RAND_MOD;
     *(a+i) = ((double) randy)/((double) RAND_MOD);
   }   
}

/* function to sum the elements of an array */
double Sum_array(int length, double *a)
{
   int i;  double sum = 0.0;
   for (i=0;i<length;i++)  sum += *(a+i);  
   return sum; 
}
  
int main()
{
  double *A, sum, runtime;
  int flag = 0;

  A = (double *)malloc(N*sizeof(double));

  runtime = omp_get_wtime();

  fill_rand(N, A);        // Producer: fill an array of data

  sum = Sum_array(N, A);  // Consumer: sum the array
   
  runtime = omp_get_wtime() - runtime;

  printf(" In %f seconds, The sum is %f \n",runtime,sum);
}
 
