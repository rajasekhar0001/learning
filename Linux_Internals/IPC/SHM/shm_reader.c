#include <stdio.h>
#include <stdlib.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <unistd.h>

int main() {
    int shmid = shmget(0xa, 100, 0);
    if (shmid == -1) {
        perror("shmget");
        exit(0);
    }

    char *ptr = shmat(shmid, NULL, 0);
    if (ptr == (void*) -1) {
        perror("shmat");
        exit(0);
    }

    printf("IN reader: %s\n", ptr);
    if (shmdt(ptr) == -1) {
        perror("shmdt");
        exit(0);
    }
    
    // sleep(10);
    // while (1) {
    //    / }
    
    
    printf("Reading completed\n");
    shmctl(shmid, IPC_RMID, NULL); // destroys the SHM when number of processes attached to it are 0

    

}