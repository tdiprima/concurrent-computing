/*
This code declares two functions. 

The `drandom` function, which returns a double, is intended to generate a random value. The specifics of the random generation are not provided here. 

The `seed` function is used to set the lower and upper bounds for the random number generation, with two double parameters (`low_in`, `hi_in`) indicating the lower and upper bounds respectively. 

Details of implementation are not included in these function declarations.
*/
#ifndef RANDOM_H
#define RANDOM_H

// Declare functions
double drandom(void);
void seed(double low_in, double hi_in);

// Declare external variables
extern long random_last;
extern double random_low, random_hi;

#endif
