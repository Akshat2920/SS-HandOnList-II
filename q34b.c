/*
============================================================================
Name : q34b.c
Author : Akshat Abhishek Lal
Description : 
    c. ITIMER_PROF
Date: 22th Sep, 2024.
============================================================================
*/
#include <arpa/inet.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#define PORT 8080
#define BACKLOG 5

void *handle_client(void *socket_fd) {
  int new_socket = *((int *)socket_fd);
  free(socket_fd);
  char buffer[1024] = {0};
  read(new_socket, buffer, 1024);
  printf("Client: %s\n", buffer);
  send(new_socket, "Hello from server", strlen("Hello from server"), 0);
  close(new_socket);
  return NULL;
}

int main() {
  int server_fd;
  struct sockaddr_in address;
  socklen_t addrlen = sizeof(address);
  server_fd = socket(AF_INET, SOCK_STREAM, 0);
  address.sin_family = AF_INET;
  address.sin_addr.s_addr = INADDR_ANY;
  address.sin_port = htons(PORT);
  if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
    perror("bind failed");
    exit(EXIT_FAILURE);
  }
  if (listen(server_fd, BACKLOG) < 0) {
    perror("listen failed");
    exit(EXIT_FAILURE);
  }
  while (1) {
    int *new_socket = malloc(sizeof(int));
    *new_socket = accept(server_fd, (struct sockaddr *)&address, &addrlen);
    if (*new_socket < 0) {
      perror("accept failed");
      free(new_socket);
      continue;
    }

    pthread_t thread_id;
    if (pthread_create(&thread_id, NULL, handle_client, (void *)new_socket) !=
        0) {
      perror("pthread_create failed");
      free(new_socket);
    }

    pthread_detach(thread_id); // Ensure the thread cleans up after finishing
  }

  return 0;
}
