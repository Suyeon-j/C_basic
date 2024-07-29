//싱글스레드
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define numSample 1000000000

double monte()
{
    int i;
    double x, y, hap = 0.0;
    unsigned int rtime;
    
    rtime = (unsigned int)time(NULL);

    for (i = 0; i < numSample; i++) {
        x = (double)rand_r(&rtime) / RAND_MAX;
        y = (double)rand_r(&rtime) / RAND_MAX;

        if((x * x + y * y) <= 1.0){
            hap += 1.0;
        }
    }

    double pi = 4.0 * hap / numSample;

    return pi;
}

int main()
{
    double pi = monte();
    printf("%f", pi);

    return 0;
}
