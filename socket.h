#ifndef SOCKET_H
#define SOCKET_H

#include <string>

//version for linux
#include <sys/socket.h>
#include <arpa/inet.h>


#define BUFSIZE 512

//control signal
#define CARFORWARD "a"
#define CARBACK "b"
#define CARLEFT "c"
#define CARRIGHT "d"
#define CAMERAUP "e"
#define CAMERADOWN "f"
#define CAMERALEFT "g"
#define CAMERARIGHT "h"

//version for linux
class MsgSender
{
private:
    int fd;
    int port;
    struct sockaddr_in addr;
public:
    MsgSender();
    ~MsgSender();

    /*version for linux
     * return 0 if bind successfully
     * else reutrn -1
     */
    int bindSocket(std::string ip, int port);

    /*version for linux
     * return 0 if send successfully
     * else reutrn -1
     */
    int sendMessage(std::string msg);

    /*version for linux
     * return 0 if send successfully
     * else reutrn -1
     */
    void clear();
};



#endif // SOCKET_H
