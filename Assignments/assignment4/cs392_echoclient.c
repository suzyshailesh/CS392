
/*
Susmitha Shailesh
I pledge my honor that I have abided by the Stevens Honor System.
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<arpa/inet.h>
#include<sys/socket.h>
#include<unistd.h>
#define BUFFSIZE 1024

//Please implement your code below
int tcp_client(char *ip, int port, char * message){

	int sock;
	struct sockaddr_in echoserver; //create struct

	char buffer[BUFFSIZE]; //buffer for recieved message
	unsigned int echolen; //stores message length

	sock = socket(AF_INET, SOCK_STREAM, 0); //create socket

	//error checking
	if( sock == -1){
    	perror("socket");
    	exit(1);
    }

	memset(&echoserver, 0, sizeof(echoserver)); //Clear struct
	echoserver.sin_family = AF_INET; //Internet/IP
	echoserver.sin_addr.s_addr = inet_addr(ip); //IP address
	echoserver.sin_port = htons(port); //server port

	//connect to server
	connect(sock, (struct sockaddr *) &echoserver, sizeof(echoserver));

	echolen = strlen(message); //store length of message

	//send message to server
	//and error check
	if(send(sock, message, echolen, 0) == -1){
		perror("send");
		exit(1);
	}

	//recieve back message from server
	//and error check
	if(recv(sock, buffer, BUFFSIZE-1, 0) == -1){
		perror("recv");
		exit(1);
	} 

	printf("Echoed message: %s", buffer); //print message

	close(sock); //close connection

	return 0;
}

int main(int argc, char *argv[]){

	//error checking
	if(argc != 3){
		perror("Incorrect number of arguments");
		exit(1);
	}

	//store ip address
	char * ip; 
	strcpy(ip, argv[1]);

	//store port number 
	int port = atoi(argv[2]);  

	//store message 
	printf("Type message: ");
	char * message = malloc(1024 * sizeof(char)); //allocate memory for message
	if(fgets(message, 1024, stdin) == NULL){
			printf("Error reading input.");
			exit(1);
	}

	tcp_client(ip, port, message); //call method to connect to server

	free(message); //free space allocated for message
	return 0;

}