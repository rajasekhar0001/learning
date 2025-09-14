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
#include <sys/wait.h>

int main()
{
    printf("Starting of program\n");
    int pipefd[2]; // 0 -> to read and 1 -> to write
    if (pipe(pipefd) == -1)
    {
        perror("pipe");
    }
    int ret = fork();

    if (ret == 0)
    {
        printf("Child process started\n");
        // child process
        int r = fork();
        if (r == 0)
        {
            printf("Grand child : PID : %d\n", getpid());
            printf("Grand Child running\n");
            int pid = getpid();
            char s_pid[5];
            sprintf(s_pid, "%d", pid);

            // To get the path where status of process is being stored

            // printf("Grand child PID : %d\n", getpid());
            // printf("Path : %s\n", s_pid);
            write(pipefd[1], s_pid, strlen(s_pid));
            for (long i = 0; i < 100000000; i++)
                ;
            sleep(100);
        }
        else if (r > 0)
        {
            printf("Parent is running\n");
            const int len = 512;
            char s_pid[len];

            read(pipefd[0], s_pid, (size_t)len);

            printf("s_pid: %s\n", s_pid);
            char str[30] = {0};
            strcat(str, "/proc/");
            strcat(str, (char *)s_pid);
            strcat(str, "/status");

            printf("Path in parent : %s\n", str);
            write(pipefd[1], str, sizeof(str)); // Writing path to parent process via virtual pipe
            int readfd;
            readfd = open(str, O_RDONLY);
            if (readfd == -1) {
                perror("open in Child");
            }
            else {
                int i = 0;
                while (i++ < 4)
                {
                    char buf[100];
                    read(readfd, buf, 100);
                    char *s = strstr(buf, "State");
                    // *(s+ 15) = '\0';
                    buf[(s -buf)+20] ='\0';
                    printf("%ld\n", s-buf);
                    printf("%s\n", buf);
                    sleep(1);
                    close(readfd);
                    // readfd = open(str, O_RDONLY);
                }
                close(readfd);
            }

            printf("Process terminated\n");
        }
    }

    else if (ret > 0)
    {
        int status;
        wait(&status);
        printf("wait exit status : %d\n", status);
        char buf[30];
        read(pipefd[0], buf, 30);
        printf("Path in Grand parent : %s\n", buf);
        int fd = open(buf, O_RDONLY);
        if (fd == -1)
        {
            perror("open");
            printf("Process is cleared by init\n");
        }
        printf("fd : %d\n", fd);
    }
    else
    {
        perror("fork");
    }
    printf("outside of all processes\n");
}