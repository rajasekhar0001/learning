/**
 * mkfifo  -> library function
 * mknod  -> system call
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main() {

    if (mkfifo("myfifo", 0666) == -1) { // to create fifo pipe
        perror("mkfifo");
        // printf("mkfifo : %d\n", )
        // return -1;
    }
    int fd = open("myfifo", O_WRONLY);
    if (fd == -1) 
    {
        perror("open");
        exit(0);
    }
    write(fd, "Write into a FIFO", 18);
    close(fd);
    printf("Write operation successful\n");

}