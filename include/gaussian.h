#ifndef GAUSSIAN_H
#define GAUSSIAN_H

#include <math.h>
#include <stdlib.h>
#include <time.h>

#define ONE_OVER_SQRT_TWO_PI 0.3989422804f

unsigned int doublefactorial(unsigned int n);
float get_gaussian_dsitribution_value(float mu, float sigma, unsigned int precision);



#endif