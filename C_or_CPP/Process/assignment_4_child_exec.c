/*
WAP to create a child process which will execute command passed through command line arguments.
 Pre-requisites:- 
• Knowledge about system calls, How to read and understand ‘man pages’.
• Good knowledge about processes.
• Working of fork, wait and exec system calls.
Objective: -
• To understand how to use exec system calls.
Requirements: -
1. Create child and execute a command passed from command-line arguments.
2. If no arguments passed print a usage message.
3. In case any wrong command passed, print an error message.
4. After child terminates print the exit status of child process
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
// #include <sys/types.h>
// #include <sys/stat.h>


int main(int argc, char *argv[]) {


    int ret = fork();

    if (ret == 0) {
        printf("This is a Child process with PID : %d\n", getpid());

        // int i=0;
        // while (i++ < 5) {
        //     printf("Child PID : %d    PPID:  %d\n", getpid(), getppid());
        //     sleep(1);
        // }

        sleep(10);

        if (argc <= 1) {
            printf("No arguments passed\n");
        }
        else {
            argv[argc] = NULL;
            execvp(argv[1], &argv[1]); // If this statement is true this process will not execute further lines
            // Returns -1 only if exec function fails to execute
            perror("execvp");
        }
        printf("Child terminated\n");
    }
    else if( ret > 0) {
        printf("Parent process: Child PID: %d\n", ret);

        int status;
        wait(&status);

        if (WIFEXITED(status)) {
            printf("Child terminated with exit status : %d\n", EEXITSTATUS(status));
        }

        // Below loop block is  the alternative method but dont use that


        // while (1) {
        //     char str[30] = {0};
        //     strcat(str, "/proc/");
        //     char pid[7];
        //     sprintf(pid, "%d", ret);
        //     strcat(str, pid);
        //     strcat(str, "/status");
        //     int fd = open (str, O_RDONLY);
        //     if (fd == -1) {
        //         printf("path : %s\n", str);
        //         printf("Child is exited with status : %d\n", );

        //         break;
        //     }
        // }
        printf("Prent is terminated\n");
    }

}