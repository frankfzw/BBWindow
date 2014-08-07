#include "socket.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>

//version of linux
MsgSender::MsgSender()
{
    fd = -1;
    port = -1;
    memset(&addr, 0, sizeof(addr));
}

MsgSender::~MsgSender()
{
    close(fd);
}

int MsgSender::bindSocket(std::string ip, int port)
{



    fd = socket(AF_INET, SOCK_DGRAM, 0);
    if (fd == -1)
    {
        printf("bind error!\n");
        return -1;
    }

    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(ip.c_str());
    addr.sin_port = htons(port);
    this->port = port;
    return 0;
}

int MsgSender::sendMessage(std::string msg)
{
    if (fd == -1)
    {
        printf("Error: socket is not inited\n");
        return -1;
    }

    size_t len = sizeof(addr);
    if (sendto(fd, &msg[0], msg.length(), 0, (struct sockaddr*)&addr, len) == -1)
    {
        printf("Error: sending message error\n");
        return -1;
    }

    return 0;
}

void MsgSender::clear()
{
    if (fd == -1)
        return;

    close(fd);
    fd = -1;
    port = -1;
    memset(&addr, 0, sizeof(addr));

}
