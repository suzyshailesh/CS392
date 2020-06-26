
/*
Susmitha Shailesh
I pledge my honor that I have abided by the Stevens Honor System.
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>
#include "cs392_signal.h"

//taken directly from powerpoint on canvas

void hdl(int sig, siginfo_t *siginfo, void *context){
	//handle SIGTSTP- print and continue
	if(sig == SIGTSTP){
		printf("Stop Signal Received\n");
	}
	//handle SIGINT- print and terminate
	else if(sig == SIGINT){
		printf("Termination Signal Recieved\n");
		exit(0);
	}
}

int signal_handle(){
	struct sigaction act;

	memset(&act, '\0', sizeof(act));

	//use the sa_sigaction field because the handles has two additional parameters
	act.sa_sigaction = &hdl;

	//tell sigaction() to use sa_sigaction instead of sa_handler
	act.sa_flags = SA_SIGINFO;

	//error checking
	if((sigaction(SIGINT, &act, NULL) < 0) || (sigaction(SIGTSTP, &act, NULL) < 0)){
		perror("error with sigaction \n");
		return 1;
	}

	return 0;
}