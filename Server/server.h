#ifndef SERVER_H
#define SERVER_H


#include <iostream>
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include "socketClass.h"

using namespace std;
class Server : Socket
{
public:

    Server(int port);
    virtual ~Server();
    bool send_massage(const string s);
    string resv_massage ();
    void accept_client(Socket& s);
};

#endif // SERVER_H
