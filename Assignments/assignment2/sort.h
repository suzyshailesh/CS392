
/*
Susmitha Shailesh
I pledge my honor that I have abided by the Stevens Honor System.
*/

#ifndef SORT_HEADERFILE_H
#define SORT_HEADERFILE_H

char* open_file(char * path);
long int* str_to_int(int int_count, char* file_contents);
void swap(long int *num1, long int *num2);
long int* sort(int int_count, long int* int_arr);
int print_to_file(char* path, int int_count, long int* int_arr);
int main(int argc, char ** argv);

#endif