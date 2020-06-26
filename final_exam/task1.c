

//Susmitha Shailesh
//I pledge my honor that I have abided by the Stevens Honor System.

/* 
 * This program implements a signal-handling program:
 * Functionality Description:

	This program will register a signal handler for sigint (SIGINT), using the sigaction interface (with the sa_sigaction field in the second argument to sigaction). When a sigint signal is received (by pressing ctrl + c), the handler will increase a "global variable" called "sigcount" by 1
	
	After the program starts, it will run an infinite loop, where each iteration will print a message and then sleep for 1 second. 

	You can press ctrl + c to trigger the sigint signal. After you do it for 3 times, the the loop will be broken and the program will terminate. 


 * Testing points:
 You are required to find out 10 errors in the following piece of code. You need to find at least 8 errors to get full score. 

 
HINT:

 Note that all the errors are marked with hints

 Please find syntax and grammar errors that prevent the building
 	Pay attention to compiler warnings (if all syntax and grammar errors are fixed, you will not see any compiler warnings)

 Please find the errors that mismatch the above functionality descriptions

 Please find the missing of error checking 

 Please find other errors based on the hints (you may need to change the locations of some code)


 To test this case, run "make -s task1"

 	After fixing all the errors, the program will run an infinite loop and after you press ctrl + c for 3 times, the program will terminate.
 
	In case you do not find all the errors and you cannot kill your program by ctrl + c, try ctrl + d and then run "pkill task1"

 *
 */

//include signal.h and stdlib.h
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

//make sigcount a global variable
int sigcount;


//add third argument
static void hdl (int sig, siginfo_t *siginfo, void *context){

	sigcount++;

	printf ("Received Signal, PID: %ld, UID: %ld\n", (long)siginfo->si_pid, (long)siginfo->si_uid);

}
 
int main (int argc, char **argv){
	
	struct sigaction act;
 
	//initialize act
	memset(&act, '\0', sizeof(act));


	/* Use the sa_sigaction field */
	act.sa_sigaction = hdl;
 
	/* Setup the flag to tell sigaction() to use the sa_sigaction field */
	act.sa_flags = SA_SIGINFO;


	//change first argument to SIGINT and add & to second argument
	int sigret = sigaction(SIGINT, &act, NULL); 
 	
	//error checking
	if(sigret < 0){
		perror("sigaction");
		return 1;
	}
	

	while(1){
		//change = to ==
		if(sigcount == 3){
			//change %s to %d to print int
			printf("You have hit ctrl+c for %d times. Program terminated\n", sigcount);
			exit(0);	
		}
		printf("Hello, please presse ctrl+c\n");
		sleep(1);
	}
		
	return 0;
}


