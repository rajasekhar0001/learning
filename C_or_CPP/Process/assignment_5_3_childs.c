/*
 WAP to create three child processes from same parent.
 Pre-requisites:- 
• Knowledge about system calls, How to read and understand ‘man pages’.
• Good knowledge about processes.
• Working of fork & wait system calls.
Objective: -
• To understand how to use fork system calls.
Requirements: -
1. Create three child process from same parent.
2. Parent has to wait for all three child process.
3. Print exit status of each child when they terminates.
Sample execution: -
1. ./three_child
Child 1 with pid 2020 created
Child 2 with pid 2021 created
Child 3 with pid 2022 created
Child 2020 is terminated with code 0
Child 2021 is terminated with code 0
Child 2022 is terminated with code 0
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {

    int ret = fork();
    if (ret == 0) {
        printf("Child - 1:    PID : %d    PPID: %d\n", getpid(), getppid());
    }
    else if (ret > 0) {
        int ret1 = fork() ;
        if (ret1 == 0) {
            printf("Child-2:   PID : %d    PPID : %d\n", getpid(), getppid());
        }
        else if (ret1 > 0) {
            int ret2 = fork();
            if (ret2 == 0) {
                printf("Child -3     PID: %d     PPID : %d\n", getpid(), getppid());
            }
            else if (ret2 > 0) {
                int status;
                int ret;
                ret = wait(&status);
                printf("Child with PID: %d is terminated with exit status: %d\n", ret, status);
                ret = wait(&status);
                printf("Child with PID: %d is terminated with exit status: %d\n", ret, status);

                ret = wait(&status);
                printf("Child with PID: %d is terminated with exit status: %d\n", ret, status);

            }
        }

    }
    

}