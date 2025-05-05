#include "webclient.h"

int main()
{
    WebClient client((char*)"192.168.159.1",666);
    client.StartClient();
    std::cout<<"exit\n";
}
