
//Susmitha Shailesh
//I pledge my honor that I have abided by the Stevens Honor System.
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int cs392_file_insert(char * path, int index, char * str){

	/* Please write down your code here
	 *
	 * You can use whatever API you want to use
	 * You can allocate whatever memory you want 
	 * Please do error handling checks 
	 * 
	 * Please write down your pledge of honor system as comment 
	 *
	 * */


	//open file and create file pointer
	FILE *fptr;
	fptr = fopen(path, "r+");

	//ERROR CHECKING
	//if file does exist
	if(fptr == NULL){
		printf("File does not exist.");
	}

	//find length of file
	fseek(fptr, 0, SEEK_END);
	int file_len = ftell(fptr);

	//if index exceeds file length
	if(index > file_len){
		printf("Index exceeds file length.");
	}

	//set file pointer back to beginning
	fseek(fptr, 0, SEEK_SET);

	//store first part of file before index
	char before[index]; 
	fgets(before, index + 1, fptr);

	//set file pointer to index
	fseek(fptr, index, SEEK_SET);

	//store second part of file after index
	char after[file_len - index];
	fgets(after, file_len + 1, fptr);

	//close and re-open file to clear all text and be able to write
	fclose(fptr);
	fptr = fopen(path, "w");

	//print first part, new string, and second part of file into file
	fprintf(fptr,"%s", before);
	fprintf(fptr,"%s", str);
	fprintf(fptr,"%s", after);

	//close file
	fclose(fptr);

	return 0;
}


int main(int argc, char ** argv){

	cs392_file_insert("cs392_task3_tmp.txt", 10, "@cs392 data inserted@");

	return 0;
}


