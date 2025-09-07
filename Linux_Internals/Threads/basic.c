#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

/**
    Any of the threads in the process calls exit(3), or the main thread performs a return from main().  This causes the
          termination of all threads in the process.
*/

long tid;
long tid_g;

void *add(void *data) {
    printf("%ld    %ld   %ld\n", tid, pthread_self(), tid_g);
    for (int i=0;i < 20;i++) {
        printf("Inside thread\n");
    }

    return NULL;
}

int main() {
    pthread_t t1;
    tid_g = t1;

    pthread_create(&t1, NULL, add, NULL); // returns 0 on success, error code on failure

    tid = t1;
    printf("Main thread\n");

    // Waits for t1 to complete its execution
    pthread_join(t1, NULL);  // check with and without
    printf("Outside cof created thread\n");
}