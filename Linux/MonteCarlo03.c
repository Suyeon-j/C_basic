//멀티스레드
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#define numP 4
#define numSample 10000000

double sum = 0.0;

pthread_mutex_t mutex;

void *monte()
{
    unsigned int rtime;
    int i;
    double x, y, hap = 0.0;

    rtime = (unsigned int)time(NULL);

    for (i = 0; i < numSample / numP; i++) {
        x = (double)rand_r(&rtime) / RAND_MAX;
        y = (double)rand_r(&rtime) / RAND_MAX;

        if ((x * x + y * y) <= 1.0) {
            hap += 1.0;
        }
    }

    pthread_mutex_lock(&mutex);
    sum += hap;
    pthread_mutex_unlock(&mutex);

    pthread_exit(NULL);
}

int main()
{
    pthread_t tid[numP];
    int rc;
    long t;

    pthread_mutex_init(&mutex, NULL);

    for (t = 0; t < numP; t++) {
        rc = pthread_create(&tid[t], NULL, monte, NULL);
        if (rc) {
            printf("ERROR: RETURN CODE FROM pthread_create() is %d\n", rc);
            exit(-1);
        }
    }

    for (t = 0; t < numP; t++) {
        rc = pthread_join(tid[t], NULL);
        if (rc) {
            printf("ERROR: RETURN CODE FROM pthread_join() is %d\n", rc);
            exit(-1);
        }
    }

    pthread_mutex_destroy(&mutex);

    double pi = 4.0 * sum / numSample;
    printf("%f\n", pi);

    return 0;
}
