// Dec 4, 2016
// gcc hello-openmp-1.c -o hello
// ./hello
// https://curc.readthedocs.io/en/latest/programming/OpenMP-C.html
#include <stdio.h>
#include "omp.h"
// #include <omp.h>
// #include "/usr/local/opt/libomp/include/omp.h"

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
