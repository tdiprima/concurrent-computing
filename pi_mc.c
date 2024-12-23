/*
 This program approximates the value of PI using a Monte Carlo method. It generates random coordinates as "darts" within a square, and checks how many of these coordinates also fall within a circle inscribed in that square. The ratio of the number of "darts" that fall within the circle to the total number of "darts" thrown approximates the ratio of the areas of the circle and the square, which is pi/4. This approximation, when multiplied by 4, gives an estimate for pi. 

 The radius of the circle and the side length of the square are set to 1. The number of trials (i.e., "darts thrown") is set by 'num_trials'. Random numbers for these trials are generated and signified by X and Y coordinates. If the sum of the squares of these coordinates is less than or equal to 1, the "dart" is considered to have landed inside the circle. 

 The total number of "darts" that fall within the circle is divided by the total number of "darts" thrown (i.e., 'num_trials') and this ratio is multiplied by 4 to calculate the approximation of pi. The result is printed to the console. 
*/
/*

NAME:
   Pi_mc:  PI Monte Carlo

Purpose:
   This program uses a Monte Carlo algorithm to compute PI as an
   example of how random number generators are used to solve problems.
   Note that if your goal is to find digits of pi, there are much 
   better algorithms you could use.

Usage:
   To keep the program as simple as possible, you must edit the file
   and change the value of num_trials to change the number of samples
   used.  Then compile and run the program.

Algorithm:
   The basic idea behind the algorithm is easy to visualize.  Draw a 
   square on a wall.  Inside the square, draw a circle.  Now randomly throw 
   darts at the wall.  some darts will land inside the square.  Of those, 
   some will fall inside the circle.   The probability of landing inside
   the circle or the square is proportional to their areas.

   We can use a random number generator to "throw the darts" and count
   how many "darts" fall inside the square and how many inside the 
   cicle.  Dividing these two numbers gives us the ratio of their areas
   and from that we can compute pi.

Algorithm details:
   To turn this into code, I need a bit more detail.  Assume the circle
   is centered inside the square.  the circle will have a radius of r and 
   each side of the square will be of area 2*r (i.e. the diameter of the
   circle).  

       A(circle) = pi * r^2
       A(square) = (2*r)*(2*r) = 4*r^2

       ratio = A(circle)/A(square) = pi/4

   Since the probability (P) of a dart falling inside a figure (i.e. the square 
   or the circle) is proportional to the area, we have

       ratio = P(circle)/P(square) = pi/4

   If I throw N darts as computed by random numbers evenly distributed 
   over the area of the square

      P(sqaure) = N/N    .... i.e. every dart lands in the square
      P(circle) = N(circle)/N

      ratio = (N(circle)/N)/(N/N)  = N(circle)/N

   Hence, to find the area, I compute N random "darts" and count how many fall
   inside the circle.  The equation for a circle is

      x^2 + y^2 = r^2 

   So I randomly compute "x" and "y" evenly distributed from -r to r and 
   count the "dart" as falling inside the cicle if

      x^2 + y^2 < or = r

Results:  
   Remember, our goal is to demonstrate a simple monte carlo algorithm, 
   not compute pi.  But just for the record, here are some results (Intel compiler
   version 10.0, Windows XP, core duo laptop)

       100        3.160000
       1000       3.148000
       10000      3.154000
       100000     3.139920
       1000000    3.141456
       10000000   3.141590
       100000000  3.141581

   As a point of reference, the first 7 digits of the true value of pi 
   is 3.141592 


History: 
   Written by Tim Mattson, 9/2007.

*/
#include <stdio.h>
#include <omp.h>
#include "random.h"

// 
// The monte carlo pi program
//

static long num_trials = 10000;

int main ()
{
long i;  long Ncirc = 0;
double pi, x, y, test;
double r = 1.0;   // radius of circle. Side of squrare is 2*r 

seed(-r, r);  // The circle and square are centered at the origin
#pragma omp parallel for private(x,y,test) reduction(+:Ncirc)
for(i=0;i<num_trials; i++)
{
    x = drandom(); 
    y = drandom();

    test = x*x + y*y;

    if (test <= r*r) Ncirc++;
    }

    pi = 4.0 * ((double)Ncirc/(double)num_trials);

    printf("\n %ld trials, pi is %lf \n",num_trials, pi);

    return 0;
}
