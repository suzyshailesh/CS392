/*
Susmitha Shailesh
I pledge my honor that I have abided by the Stevens Honor System.
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "sort.h"

char* open_file(char * path){
	//open input file and store in fptr
	FILE *fptr;
	fptr = fopen(path, "r+");

	//error check to make sure input file exists
	if(fptr == NULL){
		printf("File does not exist.\n");
		exit(1);
	}

	//move fptr to end of file
	//error check to make sure stream operation was successful
	if(fseek(fptr, 0, SEEK_END) != 0){
		printf("Stream Error\n");
		exit(1);
	}

	//find location of fptr, finds the length of file
	int file_len = ftell(fptr);

	//move fptr back to start of file
	//error check to make sure stream operation was successful
	if(fseek(fptr, 0, SEEK_SET) != 0){
		printf("Stream Error\n");
		exit(1);
	}

	//allocate memory for the contents of the input file
	char* file_contents;
	file_contents = (char*) malloc(file_len* sizeof(char));
	//store the contents of the input file in file_contents
	int i = 0;
	for(char c = getc(fptr); c != EOF; c = getc(fptr)){
		file_contents[i] = c;
		i++;
	}

	//close input file
	//error check to make sure stream operation was successful
	if(fclose(fptr) == EOF){
		printf("Stream Error\n");
		exit(1);
	}

	return file_contents;
}

long int* str_to_int(int int_count, char* file_contents){

	//allocate memory for array of ints
	long int* int_arr=(long int*)malloc(int_count*sizeof(long int));

	int j = 0;
	int_arr[j] = 0;
	//for each number, convert each digit from str to int and add to the end of existing digits in the number
	for(int i=0; i<strlen(file_contents); i++){
		if(file_contents[i] != '\n'){
			if(file_contents[i] != 13){
				int_arr[j]= (int_arr[j]*10) + (file_contents[i]-48);
			}
		}
		else{
		//when new line is reached, increment index of int_arr and start creating new number
			j++;
			int_arr[j] = 0;
		}
	}

	//free memory allocated for file_contents
	free(file_contents);

	return int_arr;
}

void swap(long int *num1, long int *num2){  
	//helper function for sort
	//swaps values in two array indices
    long int temp = *num1;  
    *num1 = *num2;  
    *num2 = temp;  
}  

long int* sort(int int_count, long int* int_arr){
	//bubble sort
	int i, j;  
    for (int i = 0; i < int_count-1; i++){      
	    for (int j = 0; j < int_count-i-1; j++){
	    	//bubble largest number up to the top
	    	//swap numbers if value in left index > value in right index
	        if (int_arr[j] > int_arr[j+1]){ 
	            swap(&int_arr[j], &int_arr[j+1]);
	        }
	    }
	}
}

int print_to_file(char* path, int int_count, long int* int_arr){
	//open output file and store in fptr
	FILE *fptr;
	fptr = fopen(path, "w");

	//error check to make sure output file exists
	if(fptr == NULL){
		printf("File does not exist.");
		exit(1);
	}

	//print each value in int_arr on separate line in output file
	//error check to make sure stream operation was successful
	for(int i = 0; i < int_count; i++){
		if(fprintf(fptr, "%ld", int_arr[i]) < 0){
			printf("Stream Error\n");
			exit(1);
		}
		fprintf(fptr, "%c", '\n');
	}

	//free memory allocated for int_arr
	free(int_arr);

	//close output file
	//error check to make sure stream operation was successful
	if(fclose(fptr) == EOF){
		printf("Stream Error\n");
		exit(1);
	}

	return 0;
}



int main(int argc, char ** argv){
	//make sure number of arguments is 3
	if(argc < 3){
		printf("Too few arguments.\n");
		exit(1);
	}
	else if (argc > 3){
		printf("Too many arguments.\n");
		exit(1);
	}

	//store input file and output file paths
	char* input_path = argv[1];
	char* output_path = argv[2];

	//store content of input file in file_contents
	char* file_contents = open_file(input_path);

	//count number of ints in file_contents, store in int_count
	int int_count = 1;
	for(int i = 0; i < strlen(file_contents); i++){
		if(file_contents[i] == '\n'){
			int_count = int_count + 1;
		}
	}

	//convert input from char array to int array
	long int* int_arr = str_to_int(int_count, file_contents);

	//sort inputted numbers in int_arr
	sort(int_count, int_arr);

	//print sorted numbers to output file
	print_to_file(output_path, int_count, int_arr);

	return 0;

}