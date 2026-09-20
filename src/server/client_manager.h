#ifndef CLIENT_MANAGER_H
#define CLIENT_MANAGER_H

#include <netinet/in.h>

enum class ClientAction{
    Add,
    Remove
};

void cManage(ClientAction x);
void make_client_details(int socket , sockaddr_in client_address);

#endif