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
    }
    int fd = open("myfifo", O_RDONLY);
    if (fd == -1) 
    {
        perror("open");
        exit(0);
    }
    char buf[25];
    read(fd, buf, 25);

    printf("Read from pipe: %s\n", buf);
    close(fd);

}