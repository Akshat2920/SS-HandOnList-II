/*
============================================================================
Name : q3.c
Author : Akshat Abhishek Lal
Description : Write a program to set (any one) system resource limit. Use setrlimit system call.
Date: 22th Sep, 2024.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/resource.h>

int main() {
    struct rlimit rl;
    if (getrlimit(RLIMIT_CPU, &rl) == 0) {
        printf("Current CPU limit: %ld seconds\n", rl.rlim_cur);
    } else {
        perror("getrlimit failed");
        return 1;
    }

    rl.rlim_cur = 10;  
    rl.rlim_max = 20;  

    if (setrlimit(RLIMIT_CPU, &rl) != 0) {
        perror("setrlimit failed");
        return 1;
    }

    printf("New CPU limit set to 10 seconds (soft), 20 seconds (hard)\n");

    while (1) {
   
    }

    return 0;
}
/* SAMPLE OUTPUT
Current CPU limit: -1 seconds
New CPU limit set to 10 seconds (soft), 20 seconds (hard)
CPU time limit exceeded (core dumped)
*/
