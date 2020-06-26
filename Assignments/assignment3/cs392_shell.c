
/*
Susmitha Shailesh
I pledge my honor that I have abided by the Stevens Honor System.
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<errno.h>
#include "cs392_exec.h"
#include "cs392_log.h"
#include "cs392_signal.h"

int main(){

	//allocate memory for input command
	char * command = malloc(256 * sizeof(char));

	while(1){
		//start interface
		printf("cs392_shell $:");
		fflush(stdout);

		//handle SIGTSTP and SIGINT
		signal_handle();

		//read in input command
		if(read(0, command, 255) < 0){
			//handle signals
			if( errno == EINTR){
				continue;
			}
			//error checking
			else{
				printf("Error reading input.");
				exit(1);
			}
		}

		//ensure last char in command is a '\0'
		int i = 0;
		while(command[i] != '\n'){
			i++;
		}
		command[i] = '\0';

		//execute command
		execute_command(command);


		//log command
		log_command(command);

	}

	return 0;
} 