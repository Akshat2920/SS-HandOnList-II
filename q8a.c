/*
============================================================================
Name : q8a.c
Author : Akshat Abhishek Lal
Description : 8. Write a separate program using signal system call to catch the following signals.
a. SIGSEGV
Date: 22th Sep, 2024.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/time.h>

void signal_handler(int signal_num) {
    if(signal_num == SIGSEGV){
      printf("Caught SIGSEGV: Segmentation fault\n");  
      exit(1);
      }
}
int main() {
    signal(SIGSEGV, signal_handler);
    int arr[2];
    int *ptr = NULL;
    *ptr = 1;
    while(1){
      pause();
    }
    return 0;
}
/* SAMPLE OUTPUT
Caught SIGSEGV: Segmentation fault
*/
