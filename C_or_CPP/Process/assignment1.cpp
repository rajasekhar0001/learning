// not solved 
#include <iostream>
#include <stdlib.h>
#include <unistd.h>

using namespace std;

int status = 0;

int main() {
    static int c_pid = 0;

    // cout << "Before\n";
    int ret = fork();   // creates child process
    if (ret ==0) {
        // child process
        cout << "Child process is runnnig\n";
        c_pid = getpid();
        cout << "c_pid : " << c_pid << endl;
        FILE *fptr = fopen("pid.txt", "w");

        if (fptr == NULL)
            perror("fopen");
        else {
            fprintf(fptr, "%d", c_pid);
        }
        sleep(4); // child sleeping
        // char *str = "/proc/";
    }
    else if (ret > 0) {
        // parent process
        cout << "Parent process is running\n";
        string path;
        FILE *fptr = fopen("pid.txt", "r");
        char *str;
        sleep(4);
        fread(str, 5, 1, fptr);
        printf("c_pid in parent : %s\n", str);
            // path = "/proc/" + to_string(c_pid) + "/status"; 
        
        cout << "path : " << path << endl;
    }
    else {
        perror("fork");
    }
    cout << ">.............................\n";
    
}

