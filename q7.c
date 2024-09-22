/*
============================================================================
Name : q6.c
Author : Akshat Abhishek Lal
Description : Write a simple program to print the created thread ids.
Date: 22th Sep, 2024.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void* thread_function(void* arg) {
    int thread_id = *((int*)arg);
    printf("%d ", thread_id);
    return NULL;
}

int main() {
    pthread_t threads[3];
    int thread_ids[3];
    for (int i = 0; i < 3; i++) {
        thread_ids[i] = i + 1; // Assign an ID to each thread
        if (pthread_create(&threads[i], NULL, thread_function, &thread_ids[i]) != 0) {
            perror("Failed to create thread");
            return 1;
        }
    }
    printf("Thread ID : ");
    for (int i = 0; i < 3; i++) {
        pthread_join(threads[i], NULL);
    }
    return 0;
}
/* SAMPLE OUTPUT
Thread ID : 1 2 3
*/
