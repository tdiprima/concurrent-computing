/*
This C program demonstrates parallel processing using OpenMP to calculate Fibonacci numbers.
It first initiates a linked list where each node consists of an integer and a placeholder for the corresponding Fibonacci number.
The program generates a number of integers starting from a predefined number (FS) and calculates the Fibonacci numbers for them. 
It uses a recursive function to calculate the Fibonacci number for each integer in the linked list.
Each linked list node will be processed by function 'processwork()' that calculates Fibonacci number of the 'data' in the list and saves it in 'fibdata'.
The total number of Fibonacci numbers calculated is defined by the macro N. 
The program makes an efficient use of parallel computations, starting a new task for each Fibonacci calculation, thus possibly utilizing multiple processors to execute tasks in parallel.
The execution time is track using OpenMP's omp_get_wtime() function.
Finally, the program deallocates the linked list memory, prints all the calculated Fibonacci numbers along with their computation time.
*/
#include <omp.h>
#include <stdlib.h>
#include <stdio.h>


#ifndef N
#define N 5
#endif
#ifndef FS
#define FS 38
#endif

struct node {
   int data;
   int fibdata;
   struct node* next;
};

struct node* init_list(struct node* p);
void processwork(struct node* p); 
int fib(int n); 

int fib(int n) 
{
   int x, y;
   if (n < 2) {
      return (n);
   } else {
      x = fib(n - 1);
      y = fib(n - 2);
	  return (x + y);
   }
}

void processwork(struct node* p) 
{
   int n, temp;
   n = p->data;
   temp = fib(n);

   p->fibdata = temp;

}

struct node* init_list(struct node* p) 
{
    int i;
    struct node* head = NULL;
    struct node* temp = NULL;
    
    head = malloc(sizeof(struct node));
    p = head;
    p->data = FS;
    p->fibdata = 0;
    for (i=0; i< N; i++) {
       temp  = malloc(sizeof(struct node));
       p->next = temp;
       p = temp;
       p->data = FS + i + 1;
       p->fibdata = i+1;
    }
    p->next = NULL;
    return head;
}

int main() 
{
     double start, end;
     struct node *p=NULL;
     struct node *temp=NULL;
     struct node *head=NULL;

     printf("Process linked list\n");
     printf("  Each linked list node will be processed by function 'processwork()'\n");
     printf("  Each ll node will compute %d fibonacci numbers beginning with %d\n",N,FS);      

     p = init_list(p);
     head = p;

     start = omp_get_wtime();

	#pragma omp parallel 
	{
            #pragma omp master
                  printf("Threads:      %d\n", omp_get_num_threads());

		#pragma omp single
		{
			p=head;
			while (p) {
				#pragma omp task firstprivate(p) //first private is required
				{
					processwork(p);
				}
			  p = p->next;
		   }
		}
	}

     end = omp_get_wtime();
     p = head;
	 while (p != NULL) {
        printf("%d : %d\n",p->data, p->fibdata);
        temp = p->next;
        free (p);
        p = temp;
     }  
	 free (p);

     printf("Compute Time: %f seconds\n", end - start);

     return 0;
}

