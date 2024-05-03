/*
WAP to implement ls -l | grep “patern” | wc -l where pattern passed through command line arguments.
 Pre-requisites:- 
• Knowledge about system calls, How to read and understand ‘man pages’.
• Good knowledge about processes and IPC.
• Working of pipe & dup system calls.
Objective: -
• To understand working of multiple pipes between multiple process.
Requirements: -
1. Create three child process and execute commands passed from command-line 
arguments 
2. Each command is separated by a '|' (pipe) character. 
3. First child execute first command (ls -l) and pass output to next command.
4. Second child executes second command (grep pattern) where pattern passed from
command-line arguments.
5. Third child executes wc -l
Sample execution: -
1. ./three_pipes (No arguments)
Error: No arguments passed
Usage: ./three_pipes <command 1> | <command 2>
2. ./pipe ls -­l '|' grep 
Error: Insufficient arguments passed
Usage: ./pipe <command 1> | <command 2>
3. ./pipe ls ­-l '|' grep “pattern” | wc -­l
5 5 25
*/

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, char* argv[]) {
    if (argc < 5) {
        printf("Insufficient arguments\n");
        exit(0);
    }
    int pipefd1[2]; // Pipe between 1st and 2nd commands
    int pipefd2[2]; // pipe between 2nd and 3rd commands
    if (pipe(pipefd1)==-1) {
        perror("pipe-1");
    }
    if (pipe(pipefd2)==-1) {
        perror("pipe-2");
    }

    int ret1 = fork();
    if (ret1 == 0) {    // extract command 1
        int i=0;
        char *cmd[argc];
        for (i=1; i<argc && strcmp(argv[i], "|")!=0;i++) {
            cmd[i-1] = argv[i];
        }
        cmd[i-1] = NULL;

        printf("CMD 1: ");
        for (int i=0;cmd[i]!= NULL; i++) {
            printf("%s ", cmd[i]);
        }
        printf("\n");

        close(pipefd1[0]); // Closing read end of pipe-1
        dup2(pipefd1[1], 1);
        execvp(cmd[0], cmd);
        perror("execcp-1");
    }
    else if (ret1 > 0) {
        wait(NULL);
        int pipefd3[2];
        if (pipe(pipefd3) == -1) {
            perror("pipe-3");
        }
        int ret2 = fork();
        if (ret2 == 0) {    // Extract command 2
            int i=1;
            char *cmd[argc];
            int pipeCount = 0;
            int j=0;
            for (i=1;i< argc;i++) {
                if (strcmp("|", argv[i]) == 0) {
                    pipeCount++;
                    continue;
                }
                if (pipeCount == 1) {
                    cmd[j++] = argv[i];
                }
                if (pipeCount > 1) {
                    break;
                }
            }
            cmd[j] = NULL;
            printf("CMD 2: ");
            for (j=0;cmd[j]!= NULL;j++) {
                printf("%s ", cmd[j]);
            }
            printf("\n");
            // close(pipefd1[1]); // Closing the write end of pipe1
            dup2(pipefd1[0], 0);
            // close(pipefd3[0]); // Cosing the read end of pipe2
            dup2(pipefd1[1], 1);
            execvp(cmd[0], cmd);
            perror("execvp-2");
        }
        else if (ret2 > 0) {
            int status;
            waitpid(ret2, &status, 0);
            printf("Before\n");
            wait(NULL);
            printf("After\n");
            int ret3 = fork();
            if (ret3 == 0) {  // Extract command 3
                // printf("Child 3\n");
                int i=0;
                char *cmd[argc];
                int j=0;
                int pipeCount = 0;
                for (i=1;i<argc;i++) {
                    if (strcmp("|", argv[i])==0)
                    {
                        pipeCount++;
                        continue;
                    }
                    if (pipeCount==2) {
                        cmd[j++] = argv[i];
                    }
                    if (pipeCount > 2) {
                        break;
                    }
                }
                cmd[j] = NULL;

                printf("CMD 3: ");
                for (i=0;cmd[i] != NULL;i++) {
                    printf("%s  ", cmd[i]);
                }
                printf("\n");
                printf("Done commands\n");
                close(pipefd1[1]); // Closing the write end of pipe2
                dup2(pipefd1[0], 0);
                execvp(cmd[0], cmd);
                perror("execvp-3");
            }
            else if (ret3 > 0) {
                int status;
                waitpid(ret3, &status, 0);
                printf("Execution completed\n");
            }
        }
    }
}