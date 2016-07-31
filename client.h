#ifndef CLIENT
#define CLIENT

#include <iostream>
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include "socketClass.h"
#include <string>

using namespace std;

class Client : private Socket
{
public:
    Client();
    virtual ~Client();

    bool connect_server(string host, int port);
    bool send_Massage(string data);
    string resvv_massage();
};

#endif // CLIENT

