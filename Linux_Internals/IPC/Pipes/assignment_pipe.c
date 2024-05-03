/**
 * task: ls | wc
 * Use stdin and stdout file descriptors replacing with pipe descriptors
 * -> C1 -> execute "ls"
 * -> C2 -> execute "wc"
 * -> P -> wait for C1 and C2 to complete (reason)
 * reason -> To avoid children to become Zombie or Orphan
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <wait.h>

int main() {
    int pipefd[2];
    if (pipe(pipefd) == -1) {
        perror("pipe");
        exit(1);
    }
    int ret = fork();
    if (ret == 0) {
        // child process 1
        // ls 
        close(pipefd[0]);; // closing read end
        dup2(pipefd[1], 1); // replacing stdout file descriptor with pipe write end descriptor
        execlp("ls", "ls", NULL);

    }
    else if (ret > 0) {
        // parent process
        ret = fork();
        if (ret == 0) {
            // chiled process 2
            // wc
            close(pipefd[1]);
            dup2(pipefd[0], 0);
            execlp("wc", "wc", NULL);
        }
    }
    close(pipefd[0]);
    close(pipefd[1]);
    wait(NULL); // Wait for one of the child to complete
    wait(NULL); // Wait for other chid to complete
    printf("Parent terminated\n");

}