#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <stdio.h>
#include <getopt.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char* argv[]) {
    int c;

   


    int options[3]= {0};
    int j=0;

    while ((c = getopt(argc, argv, "-lwc"))!= -1)
    // int c = getopt(argc, argv, "-l-w");
    {
        // printf("\n\n@@@@@   %d\n\n", c);
        if (c == 'l')
            options[0] = c;
        if (c == 'w')
            options[1] = c;
        if (c == 'c')
            options[2] = c;

    }
        
        {
                for (int i=1;i<argc;i++) {
                     int lineCount=0;
    int wordCount = 0;
                    int charCount=0;
                    if (strchr( argv[i], '-')== NULL) {
                        int fd = open(argv[i], O_RDONLY);
                        if (fd == -1) {
                            perror (strcat("open :: ", argv[i]));
                            continue;
                        }
                        char buff[20];int len=0;
                        while (((len = read(fd, &buff, 20)) > 0)) {
                            for (int i=0;i<strlen(buff);i++) {
                                if (buff[i] == '\n') {
                                    lineCount++;wordCount++;
                                }
                                if (buff[i] == ' ') {
                                    wordCount++;
                                }
                                charCount++;
                            }
                            buff[len] = '\0';
                        }
                        close(fd);


                         if (options[0] == 'l') {
                                printf("%d  ", lineCount);
                            }
                            if (options[1] == 'w') {
                                printf("%d  ", wordCount);
                            }

                            if (options[2] =='c') {
                                printf("%d ", charCount);
                            }
                    
                        printf("-->   %s\n", argv[i]);
                    
                    }   

                }
            }
}