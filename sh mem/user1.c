#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
#define SHMSZ  27
main() {
char c;
int shmid;
key_t key;
char *shm, *s;
/* We'll name our shared memory segment "56 8".
*/
key = 5678;
/*
* Create the segment.
*/
if ((shmid = shmget(key, SHMSZ , IPC_CREAT | 0666)) < 0) {
exit(1);
printf("shmget error");}
/*
* Now we attach the segment to our data space.
*/
if ((shm = shmat(shmid, NULL, 0)) == (char *) -1) {
printf("shmat error");
exit(1);
}

s = shm;
for (; ; ){
	*s = getchar();
	s++;
}




}
