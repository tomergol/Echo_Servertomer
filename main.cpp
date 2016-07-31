#include "server.h"

//int main(int argc, char *argv[])
int main()
{
    //QCoreApplication a(argc, argv);
    cout << "Start";

        Server s(3939);

        while(true)
        {
            Server new_sock();
            s.accept((Socket)new_sock);

                while(true)
                {
                    string data;
                    data = new_sock.resv_massage();
                    new_sock.send_massage(data);
                }

        }
    return 0;
    //  return a.exec();
}
