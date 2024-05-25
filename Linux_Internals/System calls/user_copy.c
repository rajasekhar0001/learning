#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

int main(int argc, char *argv[]) {

    // printf("%d\n", argc);

    if (argc < 3 || argc > 4) {
        printf("Please pass the arguments");
        return 0;
    }
    int permissions = 0;

    char *src, *dest;
    if (argc == 4 && strcmp("-p", argv[1])== 0) {
        struct stat st;
        stat(argv[2], &st);
        mode_t mode;
        mode = st.st_mode;
        if (mode & S_IRUSR)
            permissions |= S_IRUSR;
        if (mode & S_IWUSR)
            permissions  |= S_IWUSR;
        if (mode & S_IXUSR)
            permissions |= S_IXUSR;
        if (mode & S_IRGRP)
            permissions |= S_IRGRP;
        if (mode & S_IWGRP)
            permissions |= S_IWGRP;
        if (mode & S_IXGRP)
            permissions  |= S_IXGRP;
        if (mode & S_IROTH)
            permissions |= S_IROTH;
        if (mode & S_IWOTH)
            permissions |= S_IWOTH;
        if ( mode & S_IXOTH)
            permissions |= S_IXOTH;
        printf("%o\n", permissions);
        src = argv[2];
                dest = argv[3];
    }
        else {
                src = argv[1];
                dest = argv[2];
                // default permissions
        }

        int fd_rd = open(src, O_RDONLY);
        // printf("%d  %s\n", fd_rd, argv[1]);
        if (fd_rd == -1)
        {
            perror(src);
            return 0;
        }
        int fd_wr = open(dest, O_CREAT | O_WRONLY, permissions);

                if(permissions != 0) {
                        chmod (dest, permissions);
                        perror("chmod");
                }
        // printf("%s   %d\n", argv[2],fd_wr);
        if (fd_wr == -1) {
            perror(dest);
            return 0;
        }
        char buff[20];
        while (read(fd_rd, buff, 20) > 0) {
            write(fd_wr, buff, 20);
        }
        close(fd_rd);
        close(fd_wr);

}