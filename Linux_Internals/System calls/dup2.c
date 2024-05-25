/**
 * dup2()  -> same as dup(), but it copies to the file descriptor index which is mentioned
*/


#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>

int main() {
    int fd = open("dup2_file.txt", O_WRONLY);
    int stdout_fd = dup(1); // duplicating the stdout file descriptor
    if (fd == -1) 
    {
        perror("open");
        return 0;
    }
    printf("File opened successfully\n");

    // close(1);   // closed stdout file descriptor

    dup2(fd, 1);    // fil descriptor fd copied to file descriptor position index '1' after closing file descriptor '1'

    printf("Hello Raja\n");

    close(fd);      // closes the file descriptor which is original not duplicate
// duplicate file descriptor need to be closed

    // perror("close");
    // close(1);  // closing the file descriptor which is being used  by file, which we opened in write mode4
    
    dup2(stdout_fd, 1); // closed fd at index '1' and copies stdout_fd at index '1'

    printf("After reasssigning the duplicated stdout file descriptor\n");


}