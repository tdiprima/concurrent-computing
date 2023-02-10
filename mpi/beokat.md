## Message Passing Interface (MPI)

Each parallel process has its own local memory, and data must be explicitly shared by passing messages between processes.

So MPI is a way of exchanging messages between multiple computers running a parallel program.

In parallel computing, multiple computers &ndash; or even multiple processor ***cores*** within the same computer &ndash; are called **nodes**.

### Video demo

[YouTube](https://youtu.be/X03Ck8TyckQ) 🚀

### sample-mpi.c

[sample-mpi.c](http://people.cs.ksu.edu/~mozes/beocat/sample-mpi.c)

```c
/*The Parallel Hello World Program*/
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
```

### sample-mpi.qsub

[sample-mpi.qsub](http://people.cs.ksu.edu/~mozes/beocat/sample-mpi.qsub)

```sh
#!/bin/bash
#First, lets tell the qsub command which resources we need
#lets start with memory (in this case I ask for 1 gigabyte)
#$ -l mem=1G

#Now we tell qsub how long we expect our work to take: 15 minutes (H:MM:SS)
#$ -l h_rt=0:15:00

# Now lets tell the system how many processors you want (8 in this case)
#$ -pe mpi-fill 8

# This line tells SGE to start-up the job in the directory we are currently in.
#$ -cwd

# Lets output a little useful information This will put something like "Starting the job at: Thu Jan 26 10:43:26 CST 2012" in your output file
echo -n "Starting the job at: "
date

# MPI applications are run with the mpirun command. Under the scheduler it will automatically determine and connect to the right processors and machines.
mpirun ./sample-mpi

# like before, this is just useful information
echo -n "Ending the job at: "
date
```

### What is Beocat?

[KSU](https://support.beocat.ksu.edu/BeocatDocs/index.php/Main_Page)

Beocat is the High-Performance Computing (HPC) cluster at Kansas State University
