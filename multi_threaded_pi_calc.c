/*
This program is a multi-threaded calculation of Pi using the rectangle method. It first defines a number of rectangles to be used in the calculation, which is 100000000, and the number of threads to be used is set to 2.

In the main() function, it initializes an equally sized array of sums for each thread to work on.

It then calculates the width of each rectangle (step) by diving 1 by the number of rectangles. This is used in the calculation of the area of each rectangle.

It sets the number of threads to be used by the OpenMP library and gets the start time of the calculation.

The parallelized region begins with declaring private variables for each thread, which include the thread's ID, the total number of threads, and the x-position of the rectangle that it's currently working on.

Each thread then goes into a for loop, working on every nth step where n is the total number of threads, thereby dividing the work amongst the threads. 

During each iteration of the loop, it calculates the area of the rectangle and adds it to its sum. 

Once the parallelized section finishes, the program adds up all the partial sums, which gives the total area under the curve, i.e., the value of Pi.

Finally, it calculates the run time by subtracting the start time from the current time and prints out the value of Pi, the time taken, and the number of threads used.
*/
#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

static long num_steps = 100000000;
double step;
#define NUM_THREADS 2

int main() {
    int i, nthreads;
    double pi, *sum;

    // Dynamically allocate memory for the sum array
    sum = (double *)malloc(NUM_THREADS * sizeof(double));
    if (sum == NULL) {
        fprintf(stderr, "Error allocating memory for sum array\n");
        return 1;
    }

    step = 1.0 / (double)num_steps;
    double start_time, run_time;

    omp_set_num_threads(NUM_THREADS);
    start_time = omp_get_wtime();

#pragma omp parallel
    {
        int id, nthrds;
        double x;

        id = omp_get_thread_num();
        nthrds = omp_get_num_threads();

#pragma omp single
        nthreads = nthrds; // Set nthreads once in a single thread

        for (i = id, sum[id] = 0.0; i < num_steps; i += nthrds) {
            x = (i + 0.5) * step;
            sum[id] += 4.0 / (1.0 + x * x);
        }
    }

    // Sum up results from all threads
    for (i = 0, pi = 0.0; i < nthreads; i++) {
        pi += sum[i] * step;
    }

    run_time = omp_get_wtime() - start_time;
    printf("\nPi is approximately %.15f\n", pi);
    printf("Computed in %.6f seconds using %d threads.\n", run_time, nthreads);

    // Free allocated memory
    free(sum);

    return 0;
}
