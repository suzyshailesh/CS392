
/*
Susmitha Shailesh
I pledge my honor that I have abided by the Stevens Honor System.
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "cs392_log.h"

int cs392_socket_log(int port){
	
	//open file
	FILE *fptr;
	fptr = fopen("cs392_socket.log", "a");

	//error checking
	if(fptr == NULL){
		printf("Error opening file.\n");
		exit(1);
	}
	//log info
	else{
		fprintf(fptr, "IP Address: 127.0.0.1, Port: %d\n", port);
	}

	//close file
	fclose(fptr);	

	return 0;
}