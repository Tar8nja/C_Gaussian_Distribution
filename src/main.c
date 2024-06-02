#include <stdio.h>
#include "../include/gaussian.h"

int main(){

    float mu = 0.f;
    float sigma = 1.f;
    unsigned int precision = 3;
    unsigned long N = 100000;
    unsigned long resolution = 100;

    printf("Enter the average of the normal distribution: ");
    scanf("%f", &mu);
    printf("Enter the standard deviation of the normal distribution (0.1-5.0): ");
    scanf("%f", &sigma);
    printf("Enter the precission wanted for the calculations (3-100): ");
    scanf("%u", &precision);
    printf("Enter the times that you want to get a number (0-100000): ");
    scanf("%lu", &N);
    printf("Enter the resolution of the graphical representation (10-500): ");
    scanf("%lu", &resolution);


    srand(time(NULL));

    float vals[N];
    float min = __FLT_MAX__;
    float max = __FLT_MIN__;
    for(unsigned long i = 0; i < N; i++){
        vals[i] = get_gaussian_dsitribution_value(mu, sigma, precision);
        if(vals[i] < min) min = vals[i];
        else if(vals[i] > max) max = vals[i];

        // prlongf("%8.7f\n", );
    }
    float step = (float)(max-min)/resolution;
    unsigned long ocurrencies[resolution];

    for(unsigned long i = 0; i < resolution; i++){
        ocurrencies[i] = 0;
    }

    float iterator = min;
    for(unsigned long i = 0; i < N; i++){
        iterator = min + step;
        for(unsigned long j = 0; j < resolution; j++ ){
            if(vals[i] > iterator){
                iterator += step;
            }
            else if(vals[i] <= iterator){
                ocurrencies[j] += 1;
                break;
            }
        }
    }

    unsigned long find_max = 0;
    for(unsigned long i = 0; i < resolution; i++){
        if(find_max < ocurrencies[i]) find_max = ocurrencies[i];
    }

    unsigned long total = 0;
    for(unsigned long i = 0; i < resolution; i++){
        printf("MIN: %.5E\tMAX: %.5E\t", (min + i*step), (min + (i+1)*step));
        printf("%10lu - ", ocurrencies[i]);
        for(unsigned long j = 0; j < (unsigned long)(50.f*(float)ocurrencies[i]/find_max ); j++){
            printf("#");
        }
        printf("\n");

        total += ocurrencies[i];
    }
    printf("Total: %lu\n", total);

    return 0;
}