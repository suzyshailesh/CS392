#include<stdio.h>
#include<string.h>

void cs392_strswap(char * src, char * dst){

	/* Please write down your code here
	 *
	 * You can assume both src and dst are big enough to hold the data of each other
	 * No API is allowed to use here 
	 * No additional array or dynamic memory is allowed to use here
	 * Please write down your pledge of honor system as comment 
	 *
	 * */




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
		strcpy(dst, argv[index+1]);

		cs392_strswap(src, dst);
		
		printf("	Original src: \"%s\"; Original dst: \"%s\"; Swapped src \"%s\"; Swapped dst \"%s\"\n", argv[index], argv[index+1], src, dst);	

		if(strcmp(src, argv[index+1]) == 0 && strcmp(dst, argv[index]) == 0)	
			printf("	=== Result: PASSED === \n\n");
		else
			printf("	=== Result: FAILED === \n\n");	

		index += 2;
	}

	return 0;
}


