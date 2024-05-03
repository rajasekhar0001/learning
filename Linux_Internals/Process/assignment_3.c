/*
** Non_block_wait

WAP to avoid a child become zombie with out blocking the parent.
 Pre-requisites:- 
• Knowledge about system calls, How to read and understand ‘man pages’.
• Good knowledge about processes & zombie process.
• Working of fork & wait system call.
Objective: -
• To understand different states of a process.
Requirements: -
1. Create a child process avoid it become a zombie.
2. To avoid zombie we need to call wait(), but this block parent until child 
terminates.
3. So we need to use waitpid() with proper arguments (Read man page).
4. When child is working parent has to continuously print some message.
5. When ever child terminates parent has to print child terminated and print exit 
status of child process
*/


/*
int t = waitpid(ret, &status, WNOHANG);
    // WNOHANG flag used to for non-blocking purpose in parent process, if child is not stopped
    // returns immediately istead of blocking
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <sys/types.h>

int main() {

    int ret  = fork();
    if (ret == 0) {
        printf("Child s running\n");
        sleep(1);
        // for (int i=0;i<10000000;i++);
    }
    else if (ret > 0) {
        // ret stores the child PID as return value from fork()
        printf("ret value : %d\n", ret);
        int status;
        while(1) {
            printf("Parent is running\n");
            int t = waitpid(ret, &status, WNOHANG);
            // WNOHANG flag used to for non-blocking purpose in parent process, if child is not stopped
            // returns immediately istead of blocking
            if (t == ret) {
                printf("child with PID : %d exited successfully\n", ret);
                break;
            }
            printf("Wait pid: status : %d   %d\n", status, t);
            // sleep(1);
        }
        printf("Parent is terminated\n");
    }
}