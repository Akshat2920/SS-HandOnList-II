/*
============================================================================
Name : q31_b.c
Author : Akshat Abhishek Lal
Description : Write a program to create a semaphore and initialize value to the
semaphore.
b. create a counting semaphore
Date: 22th Sep, 2024.
============================================================================
*/
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/sem.h>

int main(void) {
  union semun {
    int val;
    struct semid_ds *buf;
    unsigned short int *array;
  };
  int key = ftok(".", 'c');
  union semun arg;
  int semid = semget(key, 1, IPC_CREAT | 0744);
  arg.val = 2; // COUNTING SEMAPHORE
  semctl(semid, 0, SETVAL, arg);

  return 0;
}
