
/*
Susmitha Shailesh
I pledge my honor that I have abided by the Stevens Honor System.
*/

#include<stdio.h>
#include<string.h>


int compare(char * str1, char * str2){
//strcmp
	char char1 = str1[0];
	char char2 = str2[0];

	int i = 0;
	//compare each char of the strings
	while(str1[i] != '\0'){
		if(str2[i] == '\0'){
		//return 1 if str2 ends and str1 does not
			return 1;
		}
		if(str2[i] > str1[i]){
		//return -1 if str1 < str2
			return -1;
		}
		if(str1[i] > str2[i]){
		//return 1 if str1> str2
			return 1;
		}
		i++;
	}

	if (str2[i] != '\0'){
	//return -1 if str1 ends and str2 does not
		return -1;
	} 

	//return 0 if strings are the same
    return 0;
}

void cs392_str_sort(char ** strlist, int number){
//bubble sort
	int i, j;  
    for (int i = 0; i < number - 1; i++){      
	    for (int j = 0; j < number - i - 1; j++){
	    	//bubble largest number up to the top
	        if (compare(strlist[j], strlist[j+1]) > 0){ 
	        	//swap numbers if value in left index > value in right index
	            char * temp = strlist[j];  
    			strlist[j] = strlist[j+1];  
    			strlist[j+1] = temp;
	        }
	    }
	}

}

int main(int argc, char ** argv){

	printf("CS_392 midterm task 2: \n");

	printf("        Test case 1:\n");

	char *strlist[5] = {"String1", "STring1", "String1extended", "String", "StRING1"};
	
	cs392_str_sort(strlist, 5);

	printf("	Correct results are: STring1, StRING1, String, String1, String1extended\n");
	printf("	Your results are: %s, %s, %s, %s, %s\n", strlist[0], strlist[1], strlist[2], strlist[3], strlist[4]);

	if(strcmp(strlist[0], "STring1") == 0 && strcmp(strlist[1], "StRING1") == 0 && strcmp(strlist[2], "String") == 0 && strcmp(strlist[3], "String1") == 0 && strcmp(strlist[4], "String1extended") == 0)
			printf("	=== Result: PASSED === \n\n");
		else
			printf("	=== Result: FAILED === \n\n");	

	char *strlist1[5] = {"string2", "s@ing2", "stringA", "sTRING2", "@tring2"};
	
	cs392_str_sort(strlist1, 5);

	printf("	Correct results are: @tring2, s@ing2, sTRING2, string2, stringA\n");
	printf("	Your results are: %s, %s, %s, %s, %s\n", strlist1[0], strlist1[1], strlist1[2], strlist1[3], strlist1[4]);

	if(strcmp(strlist1[0], "@tring2") == 0 && strcmp(strlist1[1], "s@ing2") == 0 && strcmp(strlist1[2], "sTRING2") == 0 && strcmp(strlist1[3], "string2") == 0 && strcmp(strlist1[4], "stringA") == 0)
			printf("	=== Result: PASSED === \n\n");
		else
			printf("	=== Result: FAILED === \n\n");	

	return 0;
}


