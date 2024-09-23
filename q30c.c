/*
============================================================================
Name : q30c.c
Author : Akshat Abhishek Lal
Description : Write a program to create a shared memory.
c. detach the shared memory
Date: 22th Sep, 2024.
============================================================================
*/
#include <stdio.h>
#include <sys/shm.h>

int main(void) {
  int key = ftok(".", 'b');
  int shmid = shmget(key, 1024, 0);
  char *data = shmat(shmid, (void *)0, 0);
  int del = shmdt(data);
  if (del == -1) {
    perror("Shared Mem detach failed.");
  } else {
    printf("Detached Shared memory successfully\n");
  }
  return 0;
}
