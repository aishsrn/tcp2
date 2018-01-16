#include"he.h"
void send_recv(int i, int sockfd);
void connect_request(int *sockfd, struct sockaddr_in *server_addr);
void send_to_all(int j, int i, int sockfd, int nbytes_recvd, char *recv_buf, fd_set *master);
void send_recv2(int i, fd_set *master, int sockfd, int fdmax);
void connection_accept(fd_set *master, int *fdmax, int sockfd, struct sockaddr_in *client_addr);
void connect_request2(int *sockfd, struct sockaddr_in *my_addr);
int main()
{

	fd_set master;

	fd_set read_fds; 

	int fdmax, i;

	int sockfd= 0;

	struct sockaddr_in my_addr, client_addr;

	

	FD_ZERO(&master);

	FD_ZERO(&read_fds);

	connect_request2(&sockfd, &my_addr);

	FD_SET(sockfd, &master);

	

	fdmax = sockfd;

	while(1){

		read_fds = master;

		if(select(fdmax+1, &read_fds, NULL, NULL, NULL) == -1){

			perror("select");
 
			exit(4);

		}

		

		for (i = 0; i <= fdmax; i++){

			if (FD_ISSET(i, &read_fds)){

				if (i == sockfd)

					connection_accept(&master, &fdmax, sockfd, &client_addr);

				else

					send_recv2(i, &master, sockfd, fdmax);

			}

		}

	}

	return 0;

}
