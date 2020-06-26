
/*
Susmitha Shailesh
I pledge my honor that I have abided by the Stevens Honor System.
*/

#ifndef CS392_SIGNAL_H
#define CS392_SIGNAL_H

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>

void hdl(int, siginfo_t*, void*);
int signal_handle();

#endif