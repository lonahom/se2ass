#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
#include<unistd.h>
#define SHMSZ  27
main() {
int shmid;
key_t key;
char *shm, *s;
key = 5678;

if ((shmid = shmget(key, SHMSZ , 0666)) < 0) {
printf("shmget error");
exit(1);
}

if ((shm = shmat(shmid, NULL, 0)) == (char *) -1) {
printf("shmat error");
exit(1);
}

s = shm;
char * ss;
ss=shm;
while(*ss!=NULL){
	*ss=NULL;
	ss++;
}
while(1){
//printf("pointer %p new pointer %p\n",shm,s);
while(*s==NULL){}

	putchar(*s);
	s++;


//putchar('\n');
}


exit(0);

}
