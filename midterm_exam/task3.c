
/*
Susmitha Shailesh
I pledge my honor that I have abided by the Stevens Honor System.
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>


struct cs392_struct{
	int course;
	int student;
	char  semester;
	char string[24];
};


void cs392_read_datastructure(struct cs392_struct * cs_ds, char * fpath){

	/* Please write down your code here  */
	//open input file and store in fptr
	FILE *fptr;
	fptr = fopen(fpath, "r+");

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

	//declare temporary variables for each expected input value
	struct cs392_struct temp;
	int temp_course = 0;
	int temp_student = 0;
	char temp_semester;
	char temp_string[24];

	i = 0;


	//store first int from file_contents in temp_course
	while(!isspace(file_contents[i])){
		temp_course = (temp_course*10) + (file_contents[i]-48);
		i++;
	}

	i++;

	//store second int from file_contents in temp_student
	while(!isspace(file_contents[i])){
		temp_student = (temp_student*10) + (file_contents[i]-48);
		i++;
	}

	i++;

	//store char from file_contents in temp_semester
	while(!isspace(file_contents[i])){
		temp_semester = file_contents[i];
		i++;
	}

	i++;

	//store string from file_contents in temp_string
	int j = 0;
	while(i < strlen(file_contents)){
		temp_string[j] = file_contents[i];
		i++;
		j++;
	}
	//make sure rest of temp_string is empty
	while(j < strlen(temp_string)){
		temp_string[j] = '\0';
		printf("%c", temp_string[j]);
		j++;
	}
	
	//set all values of cs_ds to corresponding temp value
	cs_ds->course = temp_course;
	cs_ds->student = temp_student;
	cs_ds->semester = temp_semester;
	strcpy(cs_ds->string,temp_string);

	//free memory allocated for file_contents
	free(file_contents);
	//close input file
	//error check to make sure stream operation was successful
	if(fclose(fptr) == EOF){
		printf("Stream Error\n");
		exit(1);
	}

	return;

}


int main(int argc, char ** argv){


	int index = 0; 

	struct cs392_struct test, res; 

	int course[5] = {123, 345, 456, 789, 868};
	int student[5] = {987,675, 234, 432, 656};
	char semester[5] = {'A', 'B', 'C', 'D', 'E'};
	char string[5][24]= {"This", "Is", "The", "Mid", "Term"};


	for(index = 0; index < 5; index++){
		
		FILE * fp = fopen("/tmp/ds", "w");

		fprintf(fp, "%d %d %c %s",  course[index], student[index], semester[index],string[index]);
		
		fclose(fp);

		memset(&test, 0, sizeof(struct cs392_struct));
		memset(&res, 0, sizeof(struct cs392_struct));
		
		res.course = course[index];
		res.student = student[index]; 
		res.semester = semester[index];
		strcpy(res.string, string[index]);
		
		cs392_read_datastructure(&test, "/tmp/ds");		

		printf("	Test case %d:\n", index);

		if ( memcmp(&res, &test, sizeof(struct cs392_struct)) == 0)
			printf("	=== Result: PASSED === \n\n");
		else
			printf("	=== Result: FAILED === \n\n");	
	
	}


	return 0;
}


