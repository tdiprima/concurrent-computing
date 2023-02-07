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
