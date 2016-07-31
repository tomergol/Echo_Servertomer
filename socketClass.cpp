#include "socketClass.h"
#include <string>
#include "string.h"
#include <errno.h>
#include <fcntl.h>
#include <sys/socket.h>


Socket::Socket() :
    m_sock ( -1)
{
    memset( &m_addr, 0, sizeof(m_addr));
}
Socket::~Socket()
{
    if ( is_valid())
        ::close (m_sock);
}
bool Socket::create()
{
    m_sock = socket (AF_INET, SOCK_STREAM, 0);

    if(!is_valid())
        return false;

    int on = 1;
    if(setsockopt(m_sock, SOL_SOCKET, SO_REUSEADDR, (const char *) &on, sizeof(on)) == -1)
        return false;

    return true;
}

bool Socket::bind(const int port)
{
    if( !is_valid())
        return false;

    m_addr.sin_family = AF_INET;
    m_addr.sin_addr.s_addr = INADDR_ANY;
    m_addr.sin_port = htons (port);

    if(::bind(m_sock, (struct sockaddr *) &m_addr, sizeof(m_addr)) == -1)
        return false;
    return true;
}

bool Socket::listen() const
{
    if( !is_valid())
        return false;

    if(::listen(m_sock, MAXCONNECTIONS)== -1)
        return false;
    return true;
}

bool Socket::accept(Socket & new_socket) const
{
    int addr_lenghth = sizeof(m_addr);
    new_socket.m_sock = ::accept(m_sock, (sockaddr *) &m_addr, (socklen_t *) &addr_lenghth);

    if(new_socket.m_sock <= 0)
        return false;
    return true;
}
bool Socket::send(const string s) const
{

    if (::send(m_sock, s.c_str(), s.size(), MSG_NOSIGNAL) == -1)
        return false;
    else
        return true;
}

int Socket::recv (string& s) const
{
    char buf[MAXRECV + 1];
    s = "";
    memset(buf, 0, MAXRECV + 1);
    int status = ::recv(m_sock, buf, MAXRECV, 0);

    if(status <= 0)
        return 0;
    s = buf;
    return status;
}

bool Socket::connect(const string host, const int port)
{
    if( !is_valid())
        return false;
    m_addr.sin_family = AF_INET;
    m_addr.sin_port = htons (port);
    inet_pton(AF_INET, host.c_str(), &m_addr.sin_addr);
    if(errno == EAFNOSUPPORT)
        return false;
    if(::connect(m_sock, (sockaddr *) &m_addr, sizeof(m_addr)))
        return true;
    return false;
}

void Socket::set_non_blocking(const bool b)
{
    int opts;

    opts = fcntl(m_sock, F_GETFL);
    if (opts < 0)
        return;
    if(b)
        opts = ( opts | O_NONBLOCK);
    else
        opts = (opts | ~O_NONBLOCK);
    fcntl( m_sock,F_SETFL,opts);
}
