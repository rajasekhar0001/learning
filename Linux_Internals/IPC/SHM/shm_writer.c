/**
 * shmget() -> to create shm, if exists return existing SHM shmid or shmid of created one
 * shmat() -> assigning process to SHM, returns base address of allocated memory
 * No system call -> for read or write, works on memory ( Multille times readble and writable)
 * shmdt() -> to deatch the process 
 * shmctl() -> to delete SHM if no process attached to it (this has to be done in reader file  or child processes)
 * All above are system calls
*/

#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdlib.h>
#include <string.h>


int main() {
    int shmid = shmget(0xa, 100, IPC_CREAT| 0666);
    if (shmid == -1) {
        perror("shmget");
        exit(1);
    }

    void *ptr = shmat(shmid, NULL, 0);

    if (ptr == (void *) -1) {
        perror("shmat");
        exit(0);
    } 

    strcpy((char*) ptr, "Hello Raja.. Writing to SHM");

    printf("Written to SHM\n");

    if (shmdt(ptr)==-1) {
        perror("shmdt");
        exit(0);
    }

}