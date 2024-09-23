/*
============================================================================
Name : q32
Author : Akshat Abhishek Lal
Description : Write a program to implement semaphore to protect any critical section.
a. rewrite the ticket number creation program using semaphore
b. protect shared memory from concurrent write access
c. protect multiple pseudo resources ( may be two) using counting semaphore
d. remove the created semaphore
Date: 22th Sep, 2024.
============================================================================
*/

#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

struct sembuf p = {0, -1, 0};
struct sembuf v = {0, 1, 0};

void change_ticket(int semid) {
  int fd, ticket;
  semop(semid, &p, 1); // lock
  fd = open("ticket.txt", O_RDWR | O_CREAT, 0644);
  if (fd < 0)
    perror("open");
  read(fd, &ticket, sizeof(int));
  printf("ticket no. :%d\n", ticket);
  ticket++;
  lseek(fd, 0, SEEK_SET);
  write(fd, &ticket, sizeof(int));
  close(fd);
  printf("updated ticket no:%d\n", ticket);
  semop(semid, &v, 1); // unlock
}

void access_shm(int semid) {
  int shmid;
  char *shm;
  key_t k2 = ftok(".", 'b');
  shmid = shmget(k2, 1024, IPC_CREAT | 0666);
  shm = (char *)shmat(shmid, NULL, 0);
  semop(shmid, &p, 1); // lock
  printf("writing to shared memory\n");
  sprintf(shm, "shm message 1");
  semop(shmid, &v, 1); // unlock
  shmdt(shm);          // detach
}
void protect(int semid) {
  semctl(semid, 0, SETVAL, 2); // allow two resources
  semop(semid, &p, 1);         // lock
  printf("using resource\n");
  sleep(1);
  semop(semid, &v, 1);
  printf("resource released\n");
}
void remove_sem(int semid) {
  semctl(semid, 0, IPC_RMID);
  printf("semaphore removed");
}
int main() {
  key_t k1 = ftok(".", 'a');
  int semid = semget(k1, 1, IPC_CREAT | 0666); // create sem
  semctl(semid, 0, SETVAL, 1); // init semaphore to 1 for mutual exclusion
  change_ticket(semid);
  access_shm(semid);
  protect(semid);
  remove_sem(semid);
}
/* SAMPLE OUTPUT
ticket no. :0
updated ticket no:1
writing to shared memory
using resource
resource released
semaphore removed
 */
