// This program creates multiple threads using the OpenMP library. It then prints out a "Hello World" message 
// from each thread, indicating the thread's number. The master thread (thread 0) alone gathers and stores 
// the total number of threads created. Finally, all threads join the master thread and terminate.
// https://raw.githubusercontent.com/parallella/parallella-examples/master/para-para/src/hello-openmp.c
#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[]) {
  
  int nthreads, tid;
  
  /* Create a thread and fork */
  #pragma omp parallel private(nthreads, tid)
  {
    /* Obtain thread number */
    tid = omp_get_thread_num();
    printf("Hello World from OpenMP thread = %d\n", tid);
    
    /* Only master thread does this */
    if (tid == 0) {
      nthreads = omp_get_num_threads();
      // printf("Number of threads = %d\n", nthreads);
    }  
  } /* All threads join master thread and disband */  
}
