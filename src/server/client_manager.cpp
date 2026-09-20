#include "client_manager.h"
#include <unordered_map>
#include <string>
#include <arpa/inet.h>
#include "logger.h"

struct Client_Info{
    int socket ;
    std::string ip;
    int port;
    std::string connection_time;
};

std::unordered_map<int , Client_Info> clients;


void cManage(ClientAction x){
    if(x == ClientAction::Add){
        // If Client is being Added
    }else if(x == ClientAction::Remove){
        // If Client is being Removed
    }else{

    }
}

void make_client_details(int socket , sockaddr_in client_address){
    char ip[INET_ADDRSTRLEN];
    int port = ntohs(client_address.sin_port);
    inet_ntop(AF_INET, &client_address.sin_addr , ip , INET_ADDRSTRLEN);

    Client_Info clientInfo;
    clientInfo.socket = socket;
    clientInfo.ip = ip;
    clientInfo.port = port;
    clientInfo.connection_time = get_time();

    clients[socket] = clientInfo;

}