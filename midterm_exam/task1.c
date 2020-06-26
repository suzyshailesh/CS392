
/*
Susmitha Shailesh
I pledge my honor that I have abided by the Stevens Honor System.
*/

#include<stdio.h>
#include<string.h>

void cs392_reversestr(char * str){

	//find size of str
	int size = strlen(str);
	int half_size = size/2;

	for(int i = 0; i < half_size; i++){
		//swap corresponding chars from the front and end of str, working towards the center
		char temp = str[i];
		str[i] = str[size - i - 1];
		str[size - i - 1] = temp;
	}

}


int main(int argc, char ** argv){

	int index; 
	char src[128];
	char dst[128];

	printf("CS_392 midterm task 1: \n");

	index = 1; 

	while(index <= 5){

		printf("	Test case %d:\n", index);

		memset(src, 0, 128);
		memset(dst, 0, 128);

		strcpy(src, argv[index]);
		strcpy(dst, argv[index+5]);

		cs392_reversestr(src);
		
		printf("	Original string: \"%s\"; Reversed string: \"%s\"; \n", argv[index], src);	

		if(strcmp(src, dst) == 0 )	
			printf("	=== Result: PASSED === \n\n");
		else
			printf("	=== Result: FAILED === \n\n");	

		index += 1;
	}

	return 0;
}


