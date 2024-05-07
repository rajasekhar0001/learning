#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

long tid;
long tid_g;

void *add(void *data) {

    printf("%ld    %ld   %ld\n", tid, pthread_self(), tid_g);
    for (int i=0;i < 20;i++) {
        printf("Inside thread\n");
    }
}

int main() {
    pthread_t t1;
    tid_g = t1;

    pthread_create(&t1, NULL, add, NULL);

    tid = t1;
    printf("Main thread\n");

    pthread_join(t1, NULL);  // check with and without
    printf("Outside cof created thread\n");


}