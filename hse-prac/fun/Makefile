server: socket.o server.o
	g++ socket.o server.o -o server

client: socket.o client.o
	g++ socket.o client.o -o client

socket.o: 
	g++ socket.cpp -c -std=c++11

server.o:
	g++ server.cpp -c -std=c++11

client.o:
	g++ client.cpp -c -std=c++11

all:
	make server
	make client
