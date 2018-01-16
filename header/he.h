#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <errno.h>
#define PORT 4950
#define BUFSIZE 1024
void send_recv(int i, int sockfd);
void connect_request(int *sockfd, struct sockaddr_in *server_addr);
void send_to_all(int j, int i, int sockfd, int nbytes_recvd, char *recv_buf, fd_set *master);
void send_recv2(int i, fd_set *master, int sockfd, int fdmax);
void connection_accept(fd_set *master, int *fdmax, int sockfd, struct sockaddr_in *client_addr);
void connect_request2(int *sockfd, struct sockaddr_in *my_addr);
