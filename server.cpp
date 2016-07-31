#include "server.h"

Server::Server(int port)
{
    Socket::create();
    Socket::bind(port);
    Socket::listen();
}

Server::~Server()
{

}

bool Server::send_massage(const string s)
{
    return Socket::send(s);
}

string Server::resv_massage ()
{
    string buff;
    Socket::recv(buff);

    return buff;
}

bool Server::accept_client(Socket& s)
{
   return Server::accept(s);
}
