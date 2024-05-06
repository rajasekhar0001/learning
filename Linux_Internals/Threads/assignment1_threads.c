/*
AP to print the factorial of a given number using multithreads
 Pre-requisites:-
• Knowledge about multi-thread process, How to read and understand ‘man pages’.
• Good knowledge about pthread library functions.
Objective: -
• To understand working and flow of multithread programs.
Requirements: -
1. Modify the factorial template code using multiple threads.
2. Create at-least 3 threads and share the work among threads equally .
3. Create and join threads using separate loops .
4. You may have to change the argument structure.
5. Declare all integer variables as unsigned long int (For max values).
Sample execution: -
1. ./factorial
Enter the number
10
factorial of 10 is 3628800
*/

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

typedef struct {
    unsigned long start, end;
    unsigned long result;
} fact;

void *find_factorial(void * data) {

    fact *d = (fact *) data;
    for (unsigned long i=d->start;i<=d->end;i++ ) {
        d->result *= i;
    }

}

int main( ) {
    pthread_t tid1, tid2, tid3;

    int num = 10;

    fact part1 = {1, num/3, 1};
    fact part2 = {num/3 +1, num- (num/ 3), 1};
    fact part3 = {num - (num/3) +1, num,  1};

    pthread_create(&tid1, NULL, find_factorial, &part1);
    pthread_create(&tid2, NULL, find_factorial, &part2);
    pthread_create(&tid3, NULL, find_factorial, &part3);

    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);
    pthread_join(tid3, NULL);

    printf("Result : %ld\n", part1.result*part2.result*part3.result);

}