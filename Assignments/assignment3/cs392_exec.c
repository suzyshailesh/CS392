
/*
Susmitha Shailesh
I pledge my honor that I have abided by the Stevens Honor System.
*/

#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<string.h>
#include<unistd.h>
#include<signal.h>
#include "cs392_exec.h"

char ** command_one;
int command_one_size = 1;
char ** command_two;
int command_two_size = 0;
int piped = 0;
int pipe_index = 0;

int fill_comm_arrays(char * command){
	//allocate memory for command_one
	command_one = malloc(256 * sizeof(char*));
	
	//find number of words in command_one
	int i = 0;
	while(command[i] != '\0'){
		if(command[i] == ' '){
			command_one_size++;
		}
		i++;
	}

	//allocate memory for every index of command_one
	for(int i = 0; i < command_one_size; i++){
		command_one[i] = malloc(command_one_size*sizeof(char));
	}

	//separate command by spaces
	char* temp = strtok(command, " ");
	int j;
	//store command in command_one
	for(j = 0; temp!= NULL; j++){
		strcpy(command_one[j], temp);
		temp = strtok(NULL, " ");
	}
	command_one[j] = NULL;
}

int fill_pipe(char * command){
	//allocate memory for command_one and command_two
	command_one = malloc(256 * sizeof(char*));
	command_two = malloc(256 * sizeof(char*));
	
	//find number of words in command_one
	int i = 0;
	while(i < pipe_index){
		if(command[i] == ' '){
			command_one_size++;
		}
		i++;
	}
	i++;
	//find number of words in command_two
	while(command[i] != '\0' ){
		if(command[i] == ' '){
			command_two_size++;
		}
		i++;
	}

	//allocate memory for every index of command_one
	for(int i = 0; i < command_one_size; i++){
		command_one[i] = malloc(command_one_size*sizeof(char));
	}
	//allocate memory for every index of command_two
	for(int i = 0; i < command_two_size; i++){
		command_two[i] = malloc(command_two_size*sizeof(char));
	}
	
	//store each individual command in pipe_commands array
	char* temp = strtok(command, "|");
	char* pipe_commands[2];

	for(int j = 1; temp!= NULL; j++){
		pipe_commands[j] = temp;
		temp = strtok(NULL, "|");
	}

	char* first_command = strtok(pipe_commands[0], " ");
	int k;
	//store first command in command_one
	for(k = 0; first_command!= NULL; k++){
		strcpy(command_one[k], first_command);
		first_command = strtok(NULL, " ");
	}
	command_one[k] = NULL;

	char* second_command = strtok(pipe_commands[1], " ");
	int l;
	//store second command in command_two
	for(l = 1; second_command!= NULL; k++){
		strcpy(command_two[l], second_command);
		second_command = strtok(NULL, " ");
	}
	command_two[l] = NULL;

}

void cleanup(){
	//clear up all allocated storage
	for (int i = 0; i < command_one_size; i++) {
		free(command_one[i]);
	}
	for (int i = 0; i < command_two_size; i++) {
		free(command_two[i]);
	}
	free(command_one);
	free(command_two);
}

void run_command(){
	pid_t pid;

	//check for exit command
	if (strncmp(command_one[0], "exit", 4) == 0) { 
		cleanup();
		exit(0);
	} 
	else{
		//run command
		pid = fork();

		if(pid < 0){ //error checking
			printf("error with fork\n");
			cleanup();
			exit(1);
		}
		else if(pid == 0){ //child process
			//run command and error checking
			if (execvp(command_one[0], command_one) < 0) { 
				printf("error with command.");
			    cleanup();
				exit(1);
			}
		}
		else{ //parent process
			//wait for child process to finish
			wait(&pid);
		}
	}

	//free allocated storage
	cleanup();
}

void run_pipe(){
	///taken directly from powerpoint on canvas

	int pipefd[2]; 

	//make a pipe
	pipe(pipefd);

	//run first command
	int pid1 = fork();

	if(pid1 == 0){ //child process
		//replace standard input with input part of pipe
		dup2(pipefd[1], 1); 
		//close unused half of pipe
		close(pipefd[0]);
		//execute command
		if (execvp(command_one[0], command_one) < 0) { 
				printf("error with command.");
			    cleanup();
				exit(1);
		}
	}
	else if(pid1 < 0){ //error checking
		printf("error with fork\n");
		exit(1);	
	}

	//run second command
	int pid2 = fork();

	if(pid2 == 0){ //child process
		//replace standard output with output part of pipe
		dup2(pipefd[0], 0);
		//close unused half of pipe
		close(pipefd[1]);
		//execute command
		if (execvp(command_two[0], command_two) < 0) { 
				printf("error with command.");
			    cleanup();
				exit(1);
		}
	}
	else if(pid1 < 0){ //error checking
		printf("error with fork\n");
		exit(1);	
	}

	//close pipes
	close(pipefd[0]);
	close(pipefd[1]);

	//free allocated storage
	cleanup();

}

void execute_command(char * command){
	//check if command is concatenated through pipe
	int i = 0;
	while(command[i] != '\0'){
		if(command[i] == '|'){
			piped = 1; 
			pipe_index = i;
			break;
		}
		i++;
	}

	//if there is no pipe, fill command_one with the single command
	if(piped == 0){
		fill_comm_arrays(command);
	}
	//if there is a pipe, fill command_one and command_two with the respective commands
	else{
		fill_pipe(command);
	}

	//run single command
	if(piped == 1){
		run_pipe();
	}
	//run commands concatenated with pipe
	else{
		run_command();
	}

}
