/*
============================================================================
Name : q8c.c
Author : Akshat Abhishek Lal
Description : 8. Write a separate program using signal system call to catch the following signals.
c. SIGFPE
Date: 22th Sep, 2024.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/time.h>

void signal_handler(int signal_num) {
    if(signal_num == SIGFPE){
        printf("Caught SIGFPE: Floating point exception\n");
        exit(1);
    }
}
int main() {
    signal(SIGFPE, signal_handler);
    int a = 0;
    int b = 10/b;
    while(1){
      pause();
    }
    return 0;
}
/* SAMPLE OUTPUT
Caught SIGFPE: Floating point exception
*/
