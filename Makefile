CC = g++

all:
	g++ -std=c++0x -pthread socketServer.cpp -o socketServer

clean:
	rm -f *~ *.o socketServer


