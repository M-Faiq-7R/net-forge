#include <iostream>
#include <cstring>
#include <netinet/in.h>
#include "client_operation_manager.h"
#include <atomic>

std::atomic<bool> running = true;

void rcv_data(int client_socket){
    while (true){
        char confirmation_message[1024];
            int byte_received_r = recv(client_socket, confirmation_message , sizeof(confirmation_message) -1 , 0);
            if (byte_received_r > 0){
                confirmation_message[byte_received_r] = '\0';
                std::cout << "Server : " << confirmation_message << std::endl;
                running = true;
            }else if(byte_received_r == 0){
                std::cout << "Server closed its connection." << std::endl;
                running = false;
                break;
            }else{
                std::cout << "Error : " << strerror(errno) << std::endl;
                running = false;
                break;
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
                running = false;
                break;
            }else{
                if(send(client_socket , c_message.c_str() , c_message.size() , 0) == -1){
                    std::cout << "Failed to send message to server " << std::endl;
                    running = false;
                    break;
                }
            }
        }
}
}

bool run_status(){
    return running;
}

