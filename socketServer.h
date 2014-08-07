#ifndef SOCKET_SERVER_H
#define SOCKET_SERVER_H

#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <queue>
#include <mutex>
#include <unistd.h> 
#include <pthread.h>

#define COMMANDSIZE 64

//control signal
#define CARFORWARD "a"
#define CARBACK "b"
#define CARLEFT "c"
#define CARRIGHT "d"
#define CAMERAUP "e"
#define CAMERADOWN "f"
#define CAMERALEFT "g"
#define CAMERARIGHT "h"

class MsgServer
{
private:
	int fd;
	int port;
    std::string ip;
	struct sockaddr_in addr;
	std::queue<char> commBuf;
	std::mutex mu;
	pthread_t pid;


public:
	MsgServer();
	~MsgServer();

	/*version for linux
     * return 0 if bind successfully
     * else reutrn -1
     */
    int bindSocket();

    int getCmd();

    void clear();

    int setIP(std::string ip, int port);

};

#endif