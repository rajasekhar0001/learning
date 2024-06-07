/**
 * ftok() is used to generate a unique key
 * which takes some existing file/ folder( existing one) as an argument and some project_id (which should be non zero)
 */

#include <iostream>
#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/msg.h>

using namespace std;

int main() {
    key_t  ret = ftok("server.c", 0);

    perror("ftok");

    cout << ret << endl;
}