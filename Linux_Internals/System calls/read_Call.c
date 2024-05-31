/**
 * read() -> used to read from the file -> system call
 * it mimics fread()
 * 
 * size_t fread(void *buf, size_T size, size_t nmemb, FILE *fptr);
 * 
 * ssize_t read(int fd, void *buf, size_t count);  // retuns no. of bytes it read from fd
 *  * count ->  indicate no. of bytes
 *  * fd -> fd points to file pointer
*/


#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>     // Macros related to mode of file opening
#include <unistd.h>  // for read function call

#include <stdio.h>
#include <errno.h>

int main() {
    int fd = open("file.txt", O_RDONLY);
    if (fd == -1)
        {
            perror("open");
            return -1;
        }
    char buf[20];
    int count;
    while ((count = read(fd, buf, 20)) != 0) {
        printf("%d  -> %s\n",count,  buf);
    }
}