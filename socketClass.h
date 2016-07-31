#ifndef SOCKET_H
#define SOCKET_H

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <arpa/inet.h>
using namespace std;
const int MAXHOSTNAME = 200;
const int MAXCONNECTIONS = 1;
const int MAXRECV = 256;

class Socket
{
public:
    Socket();
    virtual ~Socket();

    bool create();
    bool bind( const int port);
    bool listen() const;
    bool accept( Socket& new_socket) const;

    bool connect (const string host, const int port);

    bool send (const string s) const;
    int recv (string& s) const;
    void set_non_blocking (const bool b);
    bool is_valid () const { return m_sock != -1; }

private:
    int m_sock;
    sockaddr_in m_addr;
};

#endif // SOCKET_H
