
/*

Susmitha Shailesh
I pledge my honor that I have abided by the Stevens Honor System.

commands I used:
gcc -O0 -c cs392_sum.c
gcc -shared -o libcs392_sum.so cs392_sum.0
gcc -O0 -c main.c
gcc -O0 -o main main.o libcs392_sum.so
./main

*/


int cs392_sum(int op1, int op2){
	return op1 + op2;
}

