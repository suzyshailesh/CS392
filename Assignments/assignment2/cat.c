
/*
Susmitha Shailesh
I pledge my honor that I have abided by the Stevens Honor System.
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>


char* print_file_contents(char * path){
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


	fwrite(file_contents, file_len, 1, stdout);

	//close input file
	//error check to make sure stream operation was successful
	if(fclose(fptr) == EOF){
		printf("Stream Error\n");
		exit(1);
	}

	return file_contents;

}

int main(int argc, char ** argv){
	//make sure number of arguments is 2
	if(argc == 1){
		printf("Specify a path.\n");
		exit(1);
	}
	else if (argc > 2){
		printf("Too many arguments.\n");
		exit(1);
	}

	//store input file path in path
	char* path = argv[1];

	//print contents of input file to standard output
	print_file_contents(path);

	return 0;
}