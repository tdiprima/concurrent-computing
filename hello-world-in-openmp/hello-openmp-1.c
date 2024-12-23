/*
This C program makes use of the OpenMP library for parallel programming. It spawns 
a group of threads and each thread executes concurrently, printing a message that 
includes the thread's id, which is retrieved by the function omp_get_thread_num(). 
Since the output depends on the thread scheduling by the OS, the order in which the 
messages are printed may vary between different execution runs. Therefore, the output 
of this program will be a series of "hello(id) world(id)" messages, with 'id' being 
the id of the thread, printed in no guaranteed order.

Dec 4, 2016
gcc hello-openmp-1.c -o hello -fopenmp
./hello

https://curc.readthedocs.io/en/latest/programming/OpenMP-C.html
*/
#include <stdio.h>
#include "omp.h"

int main()
{
  #pragma omp parallel
  {
    //int ID = 0;
    int ID = omp_get_thread_num();
    printf("hello(%d) ", ID);
    printf("world(%d)\n", ID);
  }
}
