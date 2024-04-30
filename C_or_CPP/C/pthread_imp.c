#include <stdio.h>
#include <pthread.h>
#include <unistd.h>


void* printEven(void*);
void* printOdd(void*);
pthread_mutex_t mutex;
int num = 0;
int limit = 10;
// pthread_cond_t cond;

void * printEven(void *p) {
    
    for(;num< limit;) {
      pthread_mutex_lock(&mutex);
        // pthread_mutex_lock(&mutex);
        // pthread_cond_wait(&cond, &mutex);
        if (num % 2  ==0)  {
            printf("%d \n", num++);
            printf("%ld \n", pthread_self());
        }
        // else
          pthread_mutex_unlock(&mutex);
    }
    // pthread_mutex_unlock(&mutex);
    // return NULL;
}

void  * printOdd(void *p) {
        // pthread_mutex_lock(&mutex);

    for(;num< limit;) {
        // pthread_cond_wait(&cond, &mutex);
      pthread_mutex_lock(&mutex);
      if (num % 2  !=0)  {
          printf("%d \n", num++);
          printf("%ld \n", pthread_self());
      }
        // else 
            pthread_mutex_unlock(&mutex);
    }

    // return NULL;
}

int main() {

    pthread_t t1;
    pthread_t t2;
    pthread_mutex_init(&mutex, NULL);
    pthread_create(&t1, 0,printEven, 0);
    pthread_create(&t2, 0,printOdd, 0);


    // sleep(3);


    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    pthread_mutex_destroy(&mutex);


}