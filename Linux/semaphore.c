#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

sem_t sem;
int data = 0;

void *func(void *dummy)
{
    int i ;

    for( i = 0; I < 4; i ++ ) {
       sem_wait(&sem);
       printf(“%d\n”, data);
}

Return NULL;
}

Int main(int argc, char **argv)
{
     int i;
     pthread_t tid;

     if (sem_init($sem, 0, 1) < 0) {
       return -1;
     }
    pthread_create(&tid, NULL, func, NULL);
    sem_wait(&sem);

    for( i =0; i < 5; i ++) {
      sleep(1);
      data += i;
      sem_post(&sem);
}
    pthread_join(tid, NULL);
    printf(“%d\n”, data);
    sem_destory(&sem);
}
