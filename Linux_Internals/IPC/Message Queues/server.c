/**
 * There are no direct connections between the programs
 * Communication betweeen programs is independent of time
 * work can be carried out by small, self contained programs
 * Communication can be driven by events
 * Applications can assign a priority to a message
 * Security
 * Data Integrity
 * Recovery support
 */

/**
 * **************************************************************
 * Key is unique that should be used in other processes
 * When the message is read from message queue, it will be removed from the message queue
   that is message in message queues is one time readable
 * Easy to
 */


#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdlib.h>

int main() {
    printf("IPC using Message Queues\n");
    int msqid;
    if ((msqid = msgget(111, IPC_CREAT | 0666)) == -1) {   // ret
        perror("msgget");
        exit(0);
    }

    int ret = msgsnd(msqid, "Hello Raja", 10, 0);
    if (ret == -1) {
        perror("msgsnd");
        exit(0);
    }

    printf("Send done\n");

}//