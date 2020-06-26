
//Susmitha Shailesh
//I pledge my honor that I have abided by the Stevens Honor System.

#include <stdio.h>

int main() {
	// [1] Create an integer variable 
	int practice;

	// [2] Assign a constant value to that variable (whatever value you want)
	practice = 5;
	printf("The integer is: %d\n", practice);

	// [3] Create an integer pointer
	int *point;

	// [4] Make that pointer point to the integer variable 
	point = &practice;

	// [5] Change that integer variable to another constant value by dereferencing the pointer created in [3] (instead of directly changing that integer variable)
	*point = 10;

	// [6] Print the integer variable again. 
	printf("The integer is: %d\n", practice);
}