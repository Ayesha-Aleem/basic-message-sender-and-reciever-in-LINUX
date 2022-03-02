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
    char input[SIZE];
    while( 1 )
    {
    	printf("%s","Enter Message(good bye to exit): ");
    	gets(input);
    	    		
    	msg.mtype = 10;
    	strcpy( msg.mtext , input);
        	msgsnd(qid , &msg , sizeof(msg.mtext) , 0);
    	
    	if( strcmp( msg.mtext, "good bye") == 0)
    		break;
    }

    return 0;
}

