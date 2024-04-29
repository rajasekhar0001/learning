/*

Create a scenario to make zombie process become orphan, print status of each state.
 Pre-requisites:- 
• Knowledge about system calls, How to read and understand ‘man pages’.
• Good knowledge about processes, zombie and orphan.
• Working of fork system call.
Objective: -
• To understand different states of a process.
Requirements: -
1. Create a child process and print status that process is running
2. After some time print status that process is zombie state
3. After some time print zombie process cleared by init.
4. To print status use help of /proc/<pid>/status file.
For eg: if child pid is 1234, open file /proc/1234/status and print first 3 lines
5. If that file is not available means that process is cleared.
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <stdint.h>
#include <stddef.h>

int main() {
    printf("Starting of program\n");
    int pipefd[2]; // 0 -> to read and 1 -> to write
    if (pipe(pipefd) == -1) {
            perror("pipe");
        }
    int ret = fork();

    if (ret == 0) {
        // child process
        printf("Child running\n");
        int pid = getpid();
        char s_pid[5];
        sprintf(s_pid, "%d", pid);
     
        // To get the path where status of process is being stored
        
        printf("child PID : %d\n", getpid());
        printf("Path : %s\n", s_pid);
        write(pipefd[1], s_pid, strlen(s_pid));

        // int readfd = open(str, O_RDONLY);
        // if (readfd == -1) {
        //     perror("open");
        //     printf("Process is cleared earlier\n");
        //     exit(0);
        // }
        // char data[50];
        // read(readfd, data, 255);
        // int i=3;
        // while (i-- > 0) {
        //     printf("%s\n", data);
        // }
        sleep(2);

    }

    else if (ret > 0) {
        // parent process
        printf("Parent is running\n");
        const int len = 512;
        char s_pid[len] = {0};
        
        read(pipefd[0], s_pid,(size_t) len);

        printf("s_pid: %s\n", s_pid);
        char str[19] ={0};
        strcat (str, "/proc/");
        strcat(str, (char*)s_pid);
        strcat(str, "/status");
        
        printf("Path is parent :  %s\n", str); 
        int readfd;
        while ((readfd = open(str, O_RDONLY)) != -1) {
            char buf[100];
            read(readfd, buf, 100);
            printf("%s\n", buf);
            sleep(1);
        }

        printf("Process terminated\n");
    }
    else {
        perror("fork");
    }

}