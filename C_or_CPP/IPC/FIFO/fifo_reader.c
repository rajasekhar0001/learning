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

    int fd = open("myfifo", O_RDONLY);
    if (fd == -1) 
    {
        perror("open");
        exit(0);
    }
    char buf[18];
    read(fd, buf, 18);

    
    close(fd);
    printf("Read from pipe: %s\n", buf);

}