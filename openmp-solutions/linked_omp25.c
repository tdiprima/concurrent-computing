/*
This C program is designed for parallel processing of linked lists using OpenMP.

The linked list nodes are defined in the struct 'node', which includes integer data, the fibonacci sequence result corresponding to the data, and a pointer to the next node. 

The program consists of the following core functions:

1. 'fib': a recursive function that calculates the nth number in the Fibonacci sequence.
2. 'processwork': a function that takes a node as input and assigns the nth Fibonacci number to 'fibdata' corresponding to 'data' in the node.
3. 'init_list': initializes a linked list with N nodes; node data starts at FS and increment by 1 for each following node.

The 'main' function first initializes a linked list and then processes each node in two different methods:

- The first method processes the list in serial where each node's 'fibdata' is calculated and updated.
- The second method in contrast, is a parallel computation. It saves pointers of all nodes in parr[] and using OpenMP's 'omp parallel' directive, divides the processing of nodes amongst multiple threads.

Both computation times of serial and parallel methods are recorded and compared using 'omp_get_wtime' at beginning and end of each computation execution.

Finally, the program frees the memory allocated for each node in the linked list and concludes by printing the time consumed by the parallel computation method.
*/
#include <stdlib.h>
#include <stdio.h>
#include "omp.h"

#define N 5
#define FS 38
#define NMAX 10

struct node {
   int data;
   int fibdata;
   struct node* next;
};

int fib(int n) {
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
   int n;
   n = p->data;
   p->fibdata = fib(n);
}

struct node* init_list(struct node* p) {
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

int main(int argc, char *argv[]) {
     double start, end;
     struct node *p=NULL;
     struct node *temp=NULL;
     struct node *head=NULL;
     struct node *parr[NMAX]; 
     int i, count=0;
     
     printf("Process linked list\n");
     printf("  Each linked list node will be processed by function 'processwork()'\n");
     printf("  Each ll node will compute %d fibonacci numbers beginning with %d\n",N,FS);      
 
     p = init_list(p);
     head = p;


     start = omp_get_wtime();
     {
        while (p != NULL) {
		   processwork(p);
		   p = p->next;
        }
     }

     end = omp_get_wtime();

     printf("serial Compute Time: %f seconds\n", end - start);


     p = head;

     start = omp_get_wtime();
     {
        // count number of items in the list.  Strictly speaking this isn't 
        // needed since we know there are N elements in the list.  But in 
        // most cases you don't know this and need to count nodes. 
        while (p != NULL) {
	  	   p = p->next;
               count++;
        }
      
        // traverse the list and collect pointers into an array.
        p = head;
        for(i=0; i<count; i++) {
               parr[i] = p;
               p = p->next;
        }
       
        // do the work in parallel 
        #pragma omp parallel 
        {
           #pragma omp single
               printf(" %d threads \n",omp_get_num_threads());
           #pragma omp for schedule(static,1)
           for(i=0; i<count; i++)
		   processwork(parr[i]);
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

