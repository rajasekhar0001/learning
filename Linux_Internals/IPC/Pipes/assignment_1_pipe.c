/*
WAP to create two child process which will execute command (with or without options) 
passed through command-line arguments. First child will pass output to second child as 
input.
 Pre-requisites:- 
• Knowledge about system calls, How to read and understand ‘man pages’.
• Good knowledge about processes and IPC.
• Working of pipe & dup system calls.
Objective: -
• To understand working of pipe between two process.
Requirements: -
1. Create two child process and execute commands passed from command-line 
arguments 
2. Each command is separated by a '|' (pipe) character. 
3. First child execute first command (with or without options) and pass o/p to next.
4. Second child executes second command (after '|') will reads I/p from first cmd. 
5. Parent will wait for both child process to finish .
Sample execution: -
1. ./pipe (No arguments)
Error: No arguments passed
Usage: ./pipe <command 1> | <command 2>
2. ./pipe ls 
Error: Insufficient arguments passed
Usage: ./pipe <command 1> | <command 2>
3. ./pipe ls '|' wc
5 5 25
4. ./pipe ls ­l ­a '|' wc ­l ­w
10 15
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>


int main(int argc, char *argv[]) {
    if (argc == 1) {
        printf("No arguments passed\n");
        exit(0);
    }
    else if (argc < 3) {
        printf("Insuffucient arguments passed\n");
        exit(0);
    }
    int pipefd[2];
    if (pipe(pipefd) == -1) {
        perror("pipe");
        exit(0);
    }
    int ret = fork();
    
    if (ret == 0) {
        // Child process to handle first command
        
        char *cmd[argc];
        int i=1;
        for (i=1;i<argc && (strcmp(argv[i], "|") != 0);i++) {
            // strncpy(cmd[i-1], argv[i], strlen(argv[i]));  -> dont use in case of pointers
            cmd[i-1] = argv[i];
        }
        cmd[i-1] = NULL;
        printf("CMD-1: ");
        for (int i=0;cmd[i] != NULL;i++) {
            printf("%s ", cmd[i]);
        }
        printf("\n");

        close (pipefd[0]); // Closing pipe read descriptor
        dup2(pipefd[1], 1); // Replacing stdout decriptor with pipefd write descriptor
        if (execvp(cmd[0], cmd)==-1) {
            perror("execvp");
        }  
    }
    else if (ret > 0) {
        int ret1 = fork();
        if (ret1 == 0) {
            close (pipefd[1]); // Closing pipe write descriptor
            char *cmd[argc] ;
            int i;
            for (int i=2;i<argc;i++) {
                if (strcmp("|", argv[i]) == 0) {
                    int j;i++;
                    for (j=0;j<argc && i < argc;j++) {
                        // strcpy(cmd[j], argv[i]);
                        cmd[j] = argv[i];
                        i++;
                    }
                    cmd[j]= NULL;
                    break;
                }
            }
            printf("CMD-2: ");
            for (int i=0;cmd[i]!= NULL;i++) {
                printf("%s ", cmd[i]);
            }
            printf("\n");

            dup2(pipefd[0], 0); // Replacing stdin file descriptor with pipefd[0] (pipe read end)
            execvp(cmd[0], cmd);
            perror("child execvp");
        }
    }

}