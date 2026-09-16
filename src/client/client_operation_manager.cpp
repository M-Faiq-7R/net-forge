#include <iostream>
#include <cstring>
#include <netinet/in.h>
#include "client_operation_manager.h"

void rcv_data(int client_socket){
    char confirmation_message[1024];
            int byte_received_r = recv(client_socket, confirmation_message , sizeof(confirmation_message) -1 , 0);
            if (byte_received_r > 0){
                confirmation_message[byte_received_r] = '\0';
                std::cout << "Server : " << confirmation_message << std::endl;
            }else if(byte_received_r == 0){
                std::cout << "Server closed its connection." << std::endl;
            }else{
                std::cout << "Error : " << strerror(errno) << std::endl;
            }
}

void send_data(int client_socket){
    char c_message[1024];
        int byte_received = recv(client_socket, c_message , sizeof(c_message) -1 , 0);
        if (byte_received > 0){
            c_message[byte_received] = '\0';
            std::cout << "Client : " << c_message << std::endl;
            std::string message = "Message Recieved by Client!";
            if (send(client_socket , message.c_str() , message.size() , 0) == -1){
                std::cout << "Failed to send message" << std::endl;
            }
        }
}

void handle_client_input(int client_socket){
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
        }
}
}