/*
============================================================================
Name : q30a.c
Author : Akshat Abhishek Lal
Description : Write a program to create a shared memory.
a. write some data to the shared memory
Date: 22th Sep, 2024.
============================================================================
*/
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main(void) {
  char *data;
  int key = ftok(".", 'b');
  int shmid = shmget(key, 1024, IPC_CREAT | 0744);
  data = shmat(shmid, (void *)0, 0);
  scanf("%[^\n]%*c", data);
  return 0;
}
