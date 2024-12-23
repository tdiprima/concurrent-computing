/*
** This program performs parallelized matrix multiplication using OpenMP. It multiplies two matrices A and B (of size `ORDER x ORDER`), both initially filled with predefined constants `AVAL` and `BVAL` respectively. The multiplication result is stored in matrix C. 
**
** The matrices are not explicitly two-dimensional, but are modeled as one-dimensional arrays for which an offset is calculated to navigate through them.
** 
** Additionally, the program measures the time taken to perform the multiplication, as well as the MFLOPs (Million Floating-Point Operations Per Second) it achieved, and reports these statistics.
**
** The program also performs an error check comparing the difference between the computed values in matrix C and the expected value. If the total difference is larger than a predefined tolerance `TOL`, it reports an error.
*/
/*
**  PROGRAM: Parallel Matrix Multiply (using OpenMP)
**
**  PURPOSE: This is a simple matrix multiply program. 
**           It will compute the product
**
**                C  = A * B
**
**           A and B are set to constant matrices so we
**           can make a quick test of the multiplication.
**
**  USAGE:   Right now, I hardwire the martix dimensions. 
**           later, I'll take them from the command line.
**  
**  HISTORY: Written by Tim Mattson, Nov 1999.
*/
#ifdef APPLE
#include <stdlib.h>
#else
#include <malloc.h>
#endif
#include <stdio.h>
#include <omp.h>

#define ORDER 1000
#define AVAL 3.0
#define BVAL 5.0
#define TOL  0.001

int main(int argc, char *argv[])
{
	int Ndim, Pdim, Mdim;   /* A[N][P], B[P][M], C[N][M] */
	int i,j,k;
	
	double *A, *B, *C, cval, tmp, err, errsq;
      double dN, mflops;
	double start_time, run_time;


	Ndim = ORDER;
	Pdim = ORDER;
	Mdim = ORDER;

	A = (double *)malloc(Ndim*Pdim*sizeof(double));
      B = (double *)malloc(Pdim*Mdim*sizeof(double));
      C = (double *)malloc(Ndim*Mdim*sizeof(double));

	/* Initialize matrices */

	for (i=0; i<Ndim; i++)
		for (j=0; j<Pdim; j++)
			*(A+(i*Ndim+j)) = AVAL;

	for (i=0; i<Pdim; i++)
		for (j=0; j<Mdim; j++)
			*(B+(i*Pdim+j)) = BVAL;

	for (i=0; i<Ndim; i++)
		for (j=0; j<Mdim; j++)
			*(C+(i*Ndim+j)) = 0.0;
	
		start_time = omp_get_wtime();

	/* Do the matrix product */

#pragma omp parallel for private(tmp, i, j, k)  
	for (i=0; i<Ndim; i++){
		for (j=0; j<Mdim; j++){
 
                        tmp = 0.0;

			for(k=0;k<Pdim;k++){
				/* C(i,j) = sum(over k) A(i,k) * B(k,j) */
				tmp += *(A+(i*Ndim+k)) *  *(B+(k*Pdim+j));
			}
			*(C+(i*Ndim+j)) = tmp;
		}
	}
	/* Check the answer */

	run_time = omp_get_wtime() - start_time;

	printf(" Order %d multiplication in %f seconds \n", ORDER, run_time);
      printf(" %d threads\n",omp_get_max_threads());
      dN = (double)ORDER;
      mflops = 2.0 * dN * dN * dN/(1000000.0* run_time);

      printf(" Order %d multiplication at %f mflops\n", ORDER, mflops);

	cval = Pdim * AVAL * BVAL;
	errsq = 0.0;
	for (i=0; i<Ndim; i++){
		for (j=0; j<Mdim; j++){
			err = *(C+i*Ndim+j) - cval;
		    errsq += err * err;
		}
	}

	if (errsq > TOL) 
		printf("\n Errors in multiplication: %f",errsq);
	else
		printf("\n Hey, it worked");

	printf("\n all done \n");
}
