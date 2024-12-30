#ifndef _RANDOM_SEQ_LCG_H_
#define _RANDOM_SEQ_LCG_H_

// Function declarations
double drandom(void);
void seed(double low_in, double hi_in);

// External variables
extern long MULTIPLIER;
extern long ADDEND;
extern long PMOD;
extern long random_last;
extern double random_low, random_hi;

#endif /* _RANDOM_SEQ_LCG_H_ */

