
//Susmitha Shailesh
//I pledge my honor that I have abided by the Stevens Honor System.

/*
	This programs uses multiple threads to read data and process data from files.
	
	The main function will start three threads which all run the "cs392_thread_run" function. We have implemented the main function to start the threads, wait for the threads, and compare the results. 

	You need to implement the "cs392_thread_run" function. The argument to this function is a path to a file.
 
		* You need to open the file and process each line as follows: 
		  ** If the line is “+item1”, please increase the global variable “item1_counter” by 1. If the line is “-item1”, please decrease “item1_counter” by 1.
	  	  ** If the line is “+item2”, please increase “item2_counter” by 1. If the line is “-item2”, please decrease “item2_counter” by 1.
	  	  ** If the line is “+item3”, please increase “item3_counter” by 1. If the line is “-item3”, please decrease “item3_counter” by 1.
		  ** Pay attention, you may read the "\n" character when you read a line. If so, you need to ignore that byte when you do string comparison. 

		* When you change any of the above three global variables, you need to use the mutex called "mlock" (it has been defined and initialized)

		* You will need to use "pthread_exit" to terminage the execution of "cs392_thread_run".

*/

#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>


int item1_counter = 0;
int item2_counter = 0;
int item3_counter = 0;

pthread_t tid[3];
int counter;
pthread_mutex_t mlock;


void * cs392_thread_run(void* filepath){
	//open input file and store in fptr
	FILE *fptr;
	fptr = fopen(filepath, "r+");

	//error check to make sure input file exists
	if(fptr == NULL){
		printf("File does not exist.\n");
		exit(1);
	}

	//allocate memory for the line of the input file
	char* line;
	line = (char*) malloc(7 * sizeof(char));

	//while end of file has not been reached
	while(fscanf(fptr, "%s", line) == 1){

		//lock mutex
		pthread_mutex_lock(&mlock);

		//check input line and do corresponding command 
		if(strcmp(line, "+item1") == 0){
			item1_counter++;
		}
		else if(strcmp(line, "-item1") == 0){
			item1_counter--;
		}
		else if(strcmp(line, "+item2") == 0){
			item2_counter++;
		}
		else if(strcmp(line, "-item2") == 0){
			item2_counter--;
		}
		else if(strcmp(line, "+item3") == 0){
			item3_counter++;
		}
		else if(strcmp(line, "-item3") == 0){
			item3_counter--;
		}

		//unlock mutex
		pthread_mutex_unlock(&mlock);

	}

	//free memory allocated for line
	free(line);
	//close file and error checking
	if(fclose(fptr) == EOF){
		printf("Stream Error\n");
		exit(1);
	}

}


int main(int argc, char **argv){

	int i = 0;

	int err1, err2, err3;


		if (pthread_mutex_init(&mlock, NULL) != 0){
			printf("Cannot init mutex lock\n");
			return 1;
		}

	err1 = pthread_create(&(tid[0]), NULL, cs392_thread_run, "./item_file1.txt");
	err2 = pthread_create(&(tid[1]), NULL, cs392_thread_run, "./item_file2.txt");
	err3 = pthread_create(&(tid[2]), NULL, cs392_thread_run, "./item_file3.txt");

	if (err1 || err2 || err3)
		printf("Cannot creat new threads\n");

	for(i = 0; i < 3; i++)
		pthread_join(tid[i], NULL);

	pthread_mutex_destroy(&mlock);

	
	printf("========= Results of test cases for task 3 ========= \n");

	if(item1_counter == 10055)
		printf(" 	========= Congrats! You passed test case 1\n");
	else 
		printf(" 	========= Sorry! You failed test case 1. Expected results %d; Your result %d\n", 10055, item1_counter);

	if(item2_counter == 4884)
		printf(" 	========= Congrats! You passed test case 2\n");
	else 
		printf(" 	========= Sorry! You failed test case 2. Expected results %d; Your result %d\n", 4884, item2_counter);

	if(item3_counter == 4995)
		printf(" 	========= Congrats! You passed test case 3\n");
	else 
		printf(" 	========= Sorry! You failed test case 3. Expected results %d; Your result %d\n", 4995, item3_counter);

	return 0;
}
