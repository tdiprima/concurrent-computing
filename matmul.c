/*
**  SUMMARY: This program performs matrix multiplication of two constant matrices 'A' and 'B', and stores the product in matrix 'C'. It first allocates memory for these matrices, then initializes them. 'A' and 'B' are populated with preset constant values while 'C' is initialized with zeros. Afterwards, the multiplication process takes place and the run time is recorded. The performance in terms of million floating point operations per second (mflops) is then calculated and displayed. Finally, the program validates the multiplication by comparing the error square (errsq) with a predefined tolerance (TOL). Depending on the result, a success message or the error value is printed.
**/
/*
**  PROGRAM: Matrix Multiply
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

int main(int argc, char **argv)
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

	/* Do the matrix product */

	start_time = omp_get_wtime(); 
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
