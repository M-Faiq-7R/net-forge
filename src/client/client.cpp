#include <iostream>
#include "startup.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string>
#include <cerrno>
#include <cstring>

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

                }
            }

            char confirmation_message[1024];
            int byte_received_r = recv(client_socket, confirmation_message , sizeof(confirmation_message) -1 , 0);
            if (byte_received_r > 0){
                confirmation_message[byte_received_r] = '\0';
                std::cout << "Server : " << confirmation_message << std::endl;
            }else if(byte_received_r == 0){
                std::cout << "Server closed its connection." << std::endl;
            }else{
                std::cout << "Error : " << strerror(errno) << std::endl;
                return 0;
            }
        }
    }
    return 0;
}