alls: server.o he.o
	 gcc server.o he.o -o target_bin -lpthread
all: client.o he.o
	gcc client.o he.o -o target_out -lpthread
server.o: src/server.c he.o header/he.h
	 gcc -I/home/inxs/tcp/header/ -c src/server.c -lpthread
client.o: src/client.c he.o header/he.h
	 gcc -I/home/inxs/tcp/header/ -c src/client.c -lpthread
he.o: src/he.c header/he.h
	 gcc -I/home/inxs/tcp/header/ -c src/he.c -lpthread
clear:	   
	 rm -rf *.o
	 rm target_bin

