/* 
This C program utilizes the OpenMP library to parallelize tasks to multiple threads. The pragma directive tells the compiler to execute the following block of code in parallel. Each thread then fetches its unique identifier number (thread number) using the omp_get_thread_num function, and prints out the phrases "hello(thread_num)" and "world(thread_num)". The output order is non-deterministic as it depends on how system's thread scheduler assigns threads to processors. 
*/
#include <stdio.h>
#include <omp.h> // define types & functions that openmp uses

int main()
{
    #pragma omp parallel // Says: Give me a bunch of threads.
    {
        int ID = omp_get_thread_num();
        printf("hello(%d) ", ID);
        printf("world(%d)\n", ID);
    }
}
