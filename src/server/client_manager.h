#ifndef CLIENT_MANAGER_H
#define CLIENT_MANAGER_H

#include <netinet/in.h>
#include <unordered_map>

enum class ClientAction{
    Add,
    Remove
};

struct Client_Info{
    int socket ;
    std::string ip;
    int port;
    std::string connection_time;
};

std::unordered_map<int , Client_Info> clients;

void cManage(ClientAction x , int socket);
void make_client_details(int socket , sockaddr_in client_address);

#endif