/**
 * To understabd tricky return value of fork
 * fork()
 */
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    int ret = -1;
    printf("Parent PID: %d\n", getpid());
    printf("Before fork\n");
    ret = fork();
    /**
     * fork returns child process ID in parent process
     * fork returns 0 in child process
     */
    printf("PID: %d, ret: %d\n", getpid(), ret);
}