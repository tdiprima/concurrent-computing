/*
This program utilizes OpenMP to create multiple threads that execute in parallel. Each thread retrieves its unique thread identification number (tid). If the tid is equal to a defined PARENT_TID value (which is 0 here), the number of running threads will be printed out. For all threads with tid not equal to the PARENT_TID, these threads print a hello world message along with their individual tid. The program finally returns an exit success status.

https://gist.githubusercontent.com/romeroyonatan/6a380e189cee4b1290700cbc5259c837/raw/e8acb2c18a5f757768193559bb8618ff30aeedbc/hello-openmp.c
Compile with: gcc -fopenmp hello-openmp.c
*/
#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define PARENT_TID 0

int main() {
  int tid;
  #pragma omp parallel
  {
    tid = omp_get_thread_num();
    if(tid == PARENT_TID)
      printf("Parent: %d threads running\n", omp_get_num_threads());
    else
      printf("Thread# %d: Hello world\n", tid);
  }
  return EXIT_SUCCESS;
}
