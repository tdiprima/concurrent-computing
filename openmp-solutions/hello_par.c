/*
This program uses the OpenMP library to create a parallel region of code. 

It sets the desired number of threads to 4 using the 'omp_set_num_threads()' function. Then, it defines a parallel region where each thread prints its ID along with the total number of threads using 'omp_get_thread_num()' and 'omp_get_num_threads()' respectively. 

Once done with the parallel region, the program prints a message to say it's finished and displays the initially desired number of threads. 

Please note that the actual number of threads can be less than the desired number depending on the system resources and the compiler's implementation of OpenMP.

This program is a basic demo of using OpenMP for multi-threaded programming in C.
*/
#include <stdio.h>
#include <omp.h>
 
int main ()  
{
   int nthreads = 4;
   omp_set_num_threads(nthreads);

   #pragma omp parallel
   {
      int id = omp_get_thread_num();

      printf("Hello World from thread = %d", id);
      printf(" with %d threads\n",omp_get_num_threads());
   }  

   printf("all done, with hopefully %d threads\n",nthreads);

}
