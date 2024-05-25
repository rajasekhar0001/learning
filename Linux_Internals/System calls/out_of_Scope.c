#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <err.h>
#include <unistd.h> // for file related system calls

int main() {
    int s = close(0);
    // int s;
    printf("Hello Raja\n");
    printf("s  : %d\n",  s);
}
