/*
============================================================================
Name : q29.c
Author : Akshat Abhishek Lal
Description : Write a program to remove the message queue.
Date: 22th Sep, 2024.
============================================================================
*/
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/types.h>
#include <time.h>

int main() {
  int qid;
  printf("Enter message queue ID you want to remove :\n");
  scanf("%d", &qid);

  int ret = msgctl(qid, IPC_RMID, NULL);
  if (ret == -1) {
    perror("MSGCTL ERROR");
    return -1;
  } else {
    printf("Message queue with ID %d is removed !!\n", qid);
  }
  return 0;
}

// OUTPUT:
/*Enter message queue ID you want to remove :
1
Message queue with ID 1 is removed !!
 */
