
 /*
Susmitha Shailesh
I pledge my honor that I have abided by the Stevens Honor System.
*/

#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include "cs392_log.h"
#define BUFLEN 1024 

int tcp_server(int port){
	char buf[BUFLEN]; //buffer for message
    int serversock, clientsock;
 
    struct sockaddr_in echoclient, echoserver; //create structs

    serversock = socket(AF_INET, SOCK_STREAM, 0); //create socket
 
 	//error checking
    if( serversock == -1){
    	perror("socket");
    	exit(1);
    }
 	
 	memset(&echoserver, 0, sizeof(echoserver)); //Clear struct
    echoserver.sin_family = AF_INET; //Internet/IP
    echoserver.sin_addr.s_addr = htons(INADDR_ANY); //IP address
    echoserver.sin_port = htons(port); //server port
 
 	//bind network address to socket
   if( bind(serversock, (struct sockaddr *) &echoserver, sizeof(echoserver)) == -1){
   		perror("bind");
   		exit(1);
   }
 	
 	//wait for clientsock
    listen(serversock, 10);
 
 	//continuously wait for client connection
    while(1)
    {
    	int x = sizeof(echoclient);
    	clientsock = accept(serversock, (struct sockaddr*) &echoclient, &x); //accept connection from client

	    memset(buf, 0, 100);	

	    cs392_socket_log(port); //log IP and port information

	    //recieve message from client
	    //and error checking
		if(recv(clientsock, buf, BUFLEN, 0) == -1){
			perror("recv");
			exit(1);
		}	
		
		//send message back to client
		//and error checking
		if(send(clientsock, buf, BUFLEN, 0) == -1){
			perror("send");
			exit(1);
		}

		close(clientsock); //close socket
 	
    }

    close(serversock); //close socket
    return 0;
}
 
int main(int argc, char *argv[]){

	//error checking
	if(argc != 2){
		perror("Incorrect number of arguments");
		exit(1);
	}

 	int port = atoi(argv[1]); //store port number

 	tcp_server(port); //call method to connect to client
 
    
 	return 0;
}
