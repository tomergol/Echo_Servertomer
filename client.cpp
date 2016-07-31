#include "client.h"
#include "stdlib.h"
Client::Client()
{
    Socket::create();
}
Client::~Client()
{

}

bool Client::connect_server(string host = "127.0.0.1", int port = 3939)
{
    if(Socket::connect(host,port));
        return true;
    return false;
}

bool Client::send_Massage(string data)
{
    if(! Socket::send(data))
        return false;
    return true;
}
string Client::resvv_massage ()
{
    string buff;
    Socket::recv(buff);

    return buff;
}


