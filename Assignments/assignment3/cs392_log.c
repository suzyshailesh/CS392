
/*
Susmitha Shailesh
I pledge my honor that I have abided by the Stevens Honor System.
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "cs392_log.h"

int log_command(char * command){
	//open file
	FILE *fptr;
	fptr = fopen("cs392_shell.log", "a");

	//error checking
	if(fptr == NULL){
		printf("Error opening file.\n");
		exit(1);
	}
	//log command
	else{
		fprintf(fptr, "%s\n", command);
	}

	//close file
	fclose(fptr);

}
