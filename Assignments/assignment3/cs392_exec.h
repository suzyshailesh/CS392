
/*
Susmitha Shailesh
I pledge my honor that I have abided by the Stevens Honor System.
*/

#ifndef CS392_EXEC_H
#define CS392_EXEC_H

#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<string.h>
#include<unistd.h>
#include<signal.h>

int fill_comm_arrays(char*);
int fill_pipe(char*);
void cleanup();
void run_command();
void run_pipe();
void execute_command(char*);

#endif