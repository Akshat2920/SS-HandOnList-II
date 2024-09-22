/*
============================================================================
Name : q6.c
Author : Akshat Abhishek Lal
Description : Write a simple program to create three threads.
Date: 22th Sep, 2024.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void* thread_function(void* arg) {
    return NULL;
}
int main() {
    pthread_t threads[3];
    int thread_ids[3];
    for (int i = 0; i < 3; i++) {
        thread_ids[i] = i + 1;
        if (pthread_create(&threads[i], NULL, thread_function, &thread_ids[i]) != 0) {
            perror("Failed to create thread");
            return 1;
        }
        else
          printf("Threads %d created successfully\n", i+1);
    }
    return 0;
}
/* SAMPLE OUTPUT
Threads 1 created successfully
Threads 2 created successfully
Threads 3 created successfully
*/
