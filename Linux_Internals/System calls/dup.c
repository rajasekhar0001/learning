/**
 * dup() -> to write something in a file using file descriptor "1"
 * by closing stdout file descriptor uinsg close(1)
 * dup(3)  -> file descriptor is copied into the lowest unused file descriptor i.e., 1
*/


#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>

int main() {
    int fd = open("dup_file.txt", O_WRONLY);
    int stdout_fd = dup(1);; // duplicating the stdout file descriptor
    if (fd == -1) 
    {
        perror("open");
        return 0;
    }
    printf("File opened successfully\n");

    close(1);   // closed stdout file descriptor

    dup(fd);
    printf("Hello Raja\n");
    close(fd);      // closes the file descriptor which is original not duplicate
// duplicate file descriptor need to be closed

    // perror("close");
    close(1);  // closing the file descriptor which is being used file, which we opened in write mode
    dup(stdout_fd); // without this below printf() will not print anything

    printf("After reasssigning the duplicated  stdout file descriptor\n");


}