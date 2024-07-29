// 멀티스레드
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#define numP 4
#define numSample 10000000

double sum = 0.0;
void *monte(void *pthd)
{
    long tid = (long)pthd;
    unsigned int rtime;
    int i;
    double x, y, hap;

    rtime = (unsigned int)time(NULL) + tid;

    for(i = 0; i < numSample / numP; i++){
        x = (double)rand_r(&rtime) / RAND_MAX;
        y = (double)rand_r(&rtime) / RAND_MAX;

        if((x * x + y * y) <= 1.0){
            hap += 1.0;
        }
    }
    sum += hap;

    pthread_exit(NULL);
}

int main()
{
    pthread_t tid[numP];
    int rc;
    long t;
    void *status;

    for(t = 0; t < numP; t++){
        rc = pthread_create(&tid[t], NULL, monte, (void *)t);
        if(rc){
            printf("ERROR: RETURN CODE FROM pthread_create() is %d\n", rc);
            exit(-1);
        }
    }

    for(t = 0; t < numP; t++){
        rc = pthread_join(tid[t], &status);
        if(rc){
            printf("ERROR: RETURN CODE FROM pthread_join() is %d\n", rc);
            exit(-1);
        }
    }

    double pi = 4.0 * sum / numSample;
    printf("%f", pi);
    pthread_exit(NULL);
}
