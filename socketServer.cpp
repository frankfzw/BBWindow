#include "socketServer.h"




static void *listen(void *server)
{
	MsgServer *p = (MsgServer *)server;
	p->bindSocket();
}

MsgServer::MsgServer()
{
	fd = -1;
	memset(&addr, 0, sizeof(addr));
	pid = 0;

	while (!commBuf.empty())
		commBuf.pop();
}

MsgServer::~MsgServer()
{
	close(fd);
}

int MsgServer::bindSocket()
{
    if (fd != -1)
    {
        printf("socketd is binded\n");
        return -1;
    }

    if (port == -1)
    {
        printf("please set ip and port \n");
        return -1;
    }

	fd = socket(AF_INET, SOCK_DGRAM, 0);
	if (fd == -1)
	{
		printf("socket error\n");
		return -1;
	}

	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = inet_addr(ip.c_str());
	addr.sin_port = htons(port);

    struct sockaddr_in other;
	
	//bind socket
	if (bind(fd, (struct sockaddr*)&addr, sizeof(addr)) == -1)
	{
		printf("bind error\n");
		return -1;
	}
	
	while (1)
	{
		printf("Waiting ...\n");

		int len;
        socklen_t addrLen = sizeof(other);

		char buf[COMMANDSIZE];
		if (len = recvfrom(fd, buf, COMMANDSIZE, 0, (struct sockaddr*)&other, &addrLen) == -1)
		{
			printf("recv error\n");
			//return -1;
		}

		printf("Received packet from %s:%d\n", inet_ntoa(other.sin_addr), ntohs(other.sin_port));
        printf("Data: %c\n" , buf[0]);
		mu.lock();
		commBuf.push(buf[0]);
		mu.unlock();

	}

	return 0;
}

int MsgServer::getCmd()
{
    if (commBuf.empty())
        return -1;

    int ret = commBuf.front();
	mu.lock();
    commBuf.pop();
    mu.unlock();
	
    return ret;
}

void MsgServer::clear()
{
    if (pid != 0)
        pthread_cancel(pid);

    close(fd);

    fd = -1;
    memset(&addr, 0, sizeof(addr));
    pid = 0;

    while (!commBuf.empty())
        commBuf.pop();

    port = -1;
    ip = "";
}

int MsgServer::setIP(std::string ip, int port)
{
    clear();

    this->ip = ip;
    this->port = port;

    //create new thread
    int ret;
    ret = pthread_create(&pid, NULL, listen, (void *)this);

    if (ret < 0)
    {
        printf("pthread error\n");
        return -1;
    }

    printf("main thread exit\n");
    return 0;
}


//test
int main()
{
    MsgServer server;
    server.setIP("127.0.0.1", 6556);
    while(1)
    {
        sleep(1);
        printf("Waiting ...\n");
        printf("cmd %d\n", server.getCmd());
    }
    return 0;
}