/**
 * pipe
 * 
 * returns 0 on success and -1 on failure
*/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    int pipefd[2];

    /**
     * pipefd[0] -> file descriptor to read into pipe or refers to the read end of the pipe
     * pipefd[1] -> file descriptor to write from pipe or refers to the  write end of the pipe
    */
    if (pipe(pipefd)==-1) {
        perror("pipe");
        exit(0);
    }

    // int pid = fork();
    // if (pid > 0) {
        printf("Parent process\n");
        // write access
        // Consider parent to writie into pipe
        // remote read file descriptor
        close(pipefd[0]);
        write(pipefd[1], "Hello Welcome", 14);

    // }
    // else if (pid ==0) {
    //     printf("Child process\n");
    //     // read access
    //     // close the write file descriptor
    //     close(pipefd[1]);
    //     char buf[15];
    //     read(pipefd[0], buf, 15);
    //     printf("Buffer: %s\n", buf);

    // }
    // else {
    //     perror("fork");
    // }
}