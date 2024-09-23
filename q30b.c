/*
============================================================================
Name : q30b.c
Author : Akshat Abhishek Lal
Description : Write a program to create a shared memory.
b. attach with O_RDONLY and check whether you are able to overwrite.
Date: 22th Sep, 2024.
============================================================================
*/
#include <stdio.h>
#include <sys/shm.h>

int main(void) {
  int key = ftok(".", 'b');
  int shmid = shmget(key, 1024, 0);
  char *data = shmat(shmid, (void *)0, SHM_RDONLY);
  scanf("%[^\n]%*c", data);
  printf("Text in shared mem: %s", data);
  return 0;
}

// OUTPUT:
/*We are getting segmentation fault error
 * as we are trying to access read only memory.
 */
