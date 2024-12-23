/*
This program calculates the numerical value of the integral of function 4/(1+x*x) from 0 to 1, which is equivalent to the value of pi. It performs this calculation with varying numbers of parallel threads, from 1 to 4, by dividing iterations of the loop among the threads. In each iteration, it calculates the summation of function 4/(1+x*x) and then multiplies the sum  by the step size to get the pi value. It uses the OpenMP library for parallel computing, wherein the number of threads and the time are reported for each subset of threads used. The program also prints out the runtime for each set of threads. Originally written by Tim Mattson in 1999, this parallelization of the computation allows for faster processing with the use of multiple CPU threads.
*/
/*

This program will numerically compute the integral of

                  4/(1+x*x) 
				  
from 0 to 1.  The value of this integral is pi -- which 
is great since it gives us an easy way to check the answer.

The program was parallelized using OpenMP by adding just
four lines 

(1) A line to include omp.h -- the include file that 
contains OpenMP's function prototypes and constants.

(2) A pragma that tells OpenMP to create a team of threads

(3) A pragma to cause one of the threads to print the
number of threads being used by the program.

(4) A pragma to split up loop iterations among the team
of threads.  This pragma includes 2 clauses to (1) create a 
private variable and (2) to cause the threads to compute their
sums locally and then combine their local sums into a 
single global value.

History: Written by Tim Mattson, 11/99.

*/
#include <stdio.h>
#include <omp.h>
static long num_steps = 100000000;
double step;
int main ()
{
	  int i;
	  double x, pi, sum = 0.0;
	  double start_time, run_time;

	  step = 1.0/(double) num_steps;
	 for (i=1;i<=4;i++){
          sum = 0.0;
          omp_set_num_threads(i);
	  start_time = omp_get_wtime();
#pragma omp parallel  
{
#pragma omp single
	  printf(" num_threads = %d",omp_get_num_threads());

#pragma omp for reduction(+:sum)
	  for (i=1;i<= num_steps; i++){
		  x = (i-0.5)*step;
		  sum = sum + 4.0/(1.0+x*x);
	  }
}
	  pi = step * sum;
	  run_time = omp_get_wtime() - start_time;
	  printf("\n pi is %f in %f seconds and %d threads\n",pi,run_time,i);
}
}	  





