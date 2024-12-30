/*
This program is a parallelized implementation of the Monte Carlo simulation method to estimate the value of pi. It generates random points in a square and counts how many of those fall inside a unit circle. Since the ratio of the areas of the circle and the square approximates pi/4, the program multiplies this ratio by 4 to get an estimate of pi. It also calculates and prints the number of trials (random points generated), the estimated value of pi, and the execution time.
*/

#include <stdio.h>
#include <omp.h>
#include "random.h"


static long num_trials = 1000000;

int main ()
{
   long i;  long Ncirc = 0;
   double pi, x, y, test, time;
   double r = 1.0;   // radius of circle. Side of squrare is 2*r 

   time = omp_get_wtime();
   #pragma omp parallel
   {

      #pragma omp single
          printf(" %d threads ",omp_get_num_threads());

      seed(-r, r);  
      #pragma omp for reduction(+:Ncirc) private(x,y,test)
      for(i=0;i<num_trials; i++)
      {
         x = drandom(); 
         y = drandom();

         test = x*x + y*y;

         if (test <= r*r) Ncirc++;
       }
    }

    pi = 4.0 * ((double)Ncirc/(double)num_trials);

    printf("\n %ld trials, pi is %lf ",num_trials, pi);
    printf(" in %lf seconds\n",omp_get_wtime()-time);

    return 0;
}
