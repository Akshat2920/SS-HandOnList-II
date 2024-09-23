/*
============================================================================
Name : q30d
Author : Akshat Abhishek Lal
Description : Write a program to create a shared memory.
d. remove the shared memory
Date: 22th Sep, 2024.
============================================================================
*/
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main(void) {
  int key = ftok(".", 'b');
  int shmid = shmget(key, 1024, 0);

  int del = shmctl(shmid, IPC_RMID, NULL);
  if (del == -1) {
    perror("Shared Mem deletion failed.");
  } else {
    printf("Deleted Shared memory successfully\n");
  }
  return 0;
}
