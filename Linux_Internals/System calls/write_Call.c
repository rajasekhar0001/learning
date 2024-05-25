/**
 * write() -> used to write to a file -> system call
 * it mimics fwrite()
 * 
 * size_t fwrite(void *buf, size_T size, size_t nmemb, FILE *fptr);
 * 
 * ssize_t write(int fd,c const void *buf, size_t count);  // retuns no. of bytes it written to fd
 * 
 *  * count ->  indicate no. of bytes
 *  * fd -> fd points to file pointer
*/


#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>     // Macros related to mode of file opening
#include <unistd.h>  // for write function call

#include <stdio.h>
#include <errno.h>

int main() {
    int fd = open("file.txt", O_WRONLY|O_TRUNC);
    if (fd == -1)
        {
            perror("open");
            return -1;
        }
    char buf[20] = "I love to code.............";
    int count;
    count = write(fd, buf, 20);
       
    printf("%d \n",count);

    close(fd);  //
    /**
     * used to close file descriptor
     * returns  0  -> on success
     *          1  -> on failure
    */
    
}