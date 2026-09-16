#include <iostream>
#include "startup.h"
#include "broadcast.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string>
#include <cerrno>
#include <cstring>
#include <thread>
#include "client_operation_manager.h"


int main(){
    int client_socket =initialize_client();
    
    // Sending message back to server
    while (true){
        std::string c_message;
        std::cout << "> ";
        std::getline(std::cin , c_message);
        if (c_message.empty()){
            continue;
        }
        else{
            if (c_message == "exit"){
                std::cout << "Exiting this application" << std::endl;
                break;
            }else{
                if(send(client_socket , c_message.c_str() , c_message.size() , 0) == -1){
                    std::cout << "Failed to send message to server " << std::endl;
                    break;
                }else{
                    send_data(client_socket);
                }
            }
            rcv_data(client_socket);
        }
    }
    return 0;
}