/*
 * This is a parallelized "Hello World" program using the MPI (Message Passing Interface) library.
 * The program is intended for running on a distributed system (such as a cluster) where each process
 * contributes to print a greeting message "Hello World" along with the process number and the hostname.
 * It begins by initializing the MPI environment using MPI_Init, and determines the rank of the
 * process calling it using MPI_Comm_rank. The rank is stored in the 'node' variable.
 * The program then fetches and prints out the hostname of the current machine using gethostname function,
 * and the rank of the process in the printf statement. The program concludes by finalizing the MPI 
 * environment using MPI_Finalize before it exits.
 */
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
