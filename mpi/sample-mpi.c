/**
 * The Parallel Hello World Program
 * Compile: mpicc -o sample-mpi sample-mpi.c
 * Run: ./sample-mpi
 * Run: mpirun -n 4 ./sample-mpi
 */
#include <stdio.h>
#include <mpi.h>

main(int argc, char **argv)
{
   int node;
   char hostname[256];

   MPI_Init(&argc,&argv);
   MPI_Comm_rank(MPI_COMM_WORLD, &node);

   gethostname(hostname,255);

   printf("Hello World from process %d on %s\n",node, hostname);

   MPI_Finalize();
}
