#include <stdio.h>
#include <sys/msg.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 512

struct msgbuf{
    long mtype;
    char mtext[SIZE];
};


int main( void )
{
    key_t key = ftok("text" , 65);
    int qid = msgget(key , IPC_CREAT|0666);
    struct msgbuf msg;
    
    msgrcv( qid , &msg , SIZE , 0 , IPC_NOWAIT);
    printf("Recieved: %s\n", msg.mtext);
    	   

    return 0;
}
