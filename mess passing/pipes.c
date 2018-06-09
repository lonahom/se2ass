#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<sys/types.h>

int main() {
    int parent_pipe[2];
    int child_pipe[2];
    char buff[50];

    

    
    int pid = fork();
    
    if (pid == 0) {
        
        const char child[]="A message from Child to parent.\n";
        int in, out;
        in = child_pipe[0];
        out = parent_pipe[1];
	read(in,buff,50);
        printf("Parent: %s",buff);
        write(out, child, strlen(child) + 1);
        
    }
    else {
        
        char parent[5];
	printf("Write a message from Parent to child\n");
	//scanf("%s",&parent[0]);
        int in, out;
        in = parent_pipe[0];
        out = child_pipe[1];
	write(out, parent, strlen(parent) + 1);
        read(in, buff, 50);
        printf("Child: %s", buff);
        
    }
}
