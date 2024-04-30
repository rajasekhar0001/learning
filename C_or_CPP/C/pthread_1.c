#include <stdio.h>
#include <pthread.h>
int times = 100;
int count = 0;

pthread_mutex_t mutex;

void *fun () {

  pthread_mutex_lock(&mutex);
    // printf("Thread invocation\n");
  printf("Started in thread1\n");
  for(int i=0;i< 0xFFFFFFF;i++)
    ;

  printf("Ended in thread 1\n");
    // for(int i=0;i<times;i++)
    //   count++;
  pthread_mutex_unlock(&mutex);
    return NULL;
}

void * fun2() {
  pthread_mutex_lock(&mutex);
  printf("Started thread2\n");
  for(int i=0;i< 0xFFFFFFF;i++)
    ;

  printf("Ended in thread 2\n");

  pthread_mutex_unlock(&mutex);
}

int main() {
  pthread_mutex_init(&mutex, NULL);
    pthread_t th, th2;
    // printf("before thread  creation\n");
    int c = pthread_create(&th, NULL, fun, NULL);
  int c1 = pthread_create(&th2, NULL, fun2, NULL);
    pthread_join(th, NULL);
  pthread_join(th2, NULL);

  pthread_mutex_destroy(&mutex);

    // printf("value %d\n", count);
  
}