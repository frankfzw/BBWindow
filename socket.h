#ifndef SOCKET_H
#define SOCKET_H

#include <string>

//version for windows
#include <winsock.h>
// Need to link with Ws2_32.lib, Mswsock.lib, and Advapi32.lib
#pragma comment (lib, "Ws2_32.lib")
#pragma comment (lib, "Mswsock.lib")
#pragma comment (lib, "AdvApi32.lib")

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

//version for windows
class MsgSender
{
private:
    SOCKET fd;
    int port;
    struct sockaddr_in addr;
public:
    MsgSender();
    ~MsgSender();

    /*version for windows
     * return 0 if bind successfully
     * else reutrn -1
     */
    int bindSocket(std::string ip, int port);

    /*version for windows
     * return 0 if send successfully
     * else reutrn -1
     */
    int sendMessage(std::string msg);

    /*version for windows
     * return 0 if send successfully
     * else reutrn -1
     */
    void clear();
};



#endif // SOCKET_H
