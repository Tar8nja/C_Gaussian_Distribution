#include "../include/gaussian.h"

unsigned int doublefactorial(unsigned int n)
{
    if (n == 0 || n==1)
      return 1;
    return n*doublefactorial(n-2);
}
  


float get_gaussian_dsitribution_value(float mu, float sigma, unsigned int precision){
    float cumulative_probability = 0.f;
    float x = (float)rand()/RAND_MAX;
    // x = (x)/sigma;
    for(unsigned int i = 0; i < precision; i++){
        cumulative_probability += expf( 0.5f*powf( x/sigma, 2.f))*powf(x, (float)(i*2 + 1))/(float)(doublefactorial(i*2 + 1));
    }
    cumulative_probability = cumulative_probability*ONE_OVER_SQRT_TWO_PI;
    cumulative_probability *= rand()%2 == 0 ? 1.f : -1.f;
    return cumulative_probability + mu;
}