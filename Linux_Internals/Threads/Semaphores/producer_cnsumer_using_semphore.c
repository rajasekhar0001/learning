/**
 * Producer
 * Consumer
 * we will be using two threads
 * and two semaphores, one is to know avaliablity (use it if available), one is to increase availabity 
 * 
*/

#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

// It indicates that some thing is there for consumser to consume
sem_t use;  // Initialize with 0

// It indicates that there is space to produce something more
sem_t fill; // Initialize with 10

void *producer(void *data) {
    int limit = 10;
    while (limit-- > 0)
    {
        sem_wait(&fill);
        int num;
        sem_getvalue(&fill, &num);
        printf("Produced :  %d\n", num);
        sem_post(&use);
        // sleep(1);
    }
}

void *consumer(void* data) {
    int limit =10;
    while (limit-- > 0)
    {
        sem_wait(&use);

        int num;
        sem_getvalue(&use, &num);
        printf("Consumed :  %d\n", num);
        sem_post(&fill);
        // sleep(1);
    }
}

int main() {
    pthread_t tid1, tid2;
    sem_init(&use, 0, 0);
    sem_init(&fill, 0, 10);

    printf("Thread_ids before  tid1: %ld    tid2: %ld\n", tid1, tid2);
    pthread_create(&tid1, NULL, producer, NULL);
    pthread_create(&tid2, NULL, consumer, NULL);

    printf("Thread_ids between  tid1: %ld    tid2: %ld\n", tid1, tid2);

    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);

    sem_destroy(&fill);
    sem_destroy(&use);

    printf("Thread_ids  tid1: %ld    tid2: %ld\n", tid1, tid2);
    
}
