
/*
Susmitha Shailesh
I pledge my honor that I have abided by the Stevens Honor System.
*/

#include<sys/wait.h> 
#include <unistd.h> 
#include <stdio.h> 
#include<stdlib.h> 

int main(){
	pid_t pid = fork();

	if(pid < 0){
		perror("error\n");
		return -1;
	}
	else if(pid == 0){
		printf("hello from child\n");
		exit(0);
	}
	else{
		printf("%d\n", pid);
		wait(&pid);
		while(1){
			sleep(5);
			printf("hello from parent\n");
		}
	}

	return 1;
}