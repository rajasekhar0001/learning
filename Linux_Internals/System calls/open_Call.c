/**
 * open() -> Used to open file in specific mode
 * it mimics fopen()
*/

#include <sys/types.h>

#include <sys/stat.h>
#include <fcntl.h>              // SYstem  calls present in this header file

#include <stdio.h>
#include <errno.h>      // Useful when system calls fail to execute to know reason behind it

int main() {
        // int fd = open("file.txt", O_RDONLY);        // OPEN file in readonly mode uisng system call

        // int fd = open("file.txt", O_WRONLY);

        int fd = open("file.txt", O_CREAT | O_WRONLY, 0666);    // Used to create file if not found in write mode
        // * 0666 -> octal value which specifies permissions for the file which is going to be created if not exist
        /**
         * O_CREAT -> used to create file if not exist
        */


        int fd1 = open("file1.txt", O_CREAT | O_EXCL | O_WRONLY, 0666);

        /**
         * O_EXCL -> If file already exist errno is set to say "File Exists"
        */

        // vALIDATE  open() is failed or not
        if (fd1 == -1) {
                // if (errno == EACCES)
                //         printf("Access denied\n");
                // else if (errno == ENOENT)
                //         printf("File not exist\n");
                perror("open"); // used to print error based on errorno set while executing system call
                return -1;

        }
        else
                printf("FIle opened successfully\n");



}