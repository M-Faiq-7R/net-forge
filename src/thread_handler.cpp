#include <iostream>
#include "thread_handler.h"
#include <thread>
#include <cstring>
#include <netinet/in.h>
#include <vector>


void handle_client(int client_socket){
    // Sending message to client
        std::string message = "Hello Client! ";
        if(send(client_socket , message.c_str() , message.size() , 0) == -1){
            std::cout << "Failed to send message" << std::endl;
        }
        

        // Recieving message from client
        while (true){
            char c_message[1024];
            int byte_received = recv(client_socket, c_message , sizeof(c_message) -1 , 0);
            if (byte_received > 0){
                c_message[byte_received] = '\0';
                std::cout << "Client : " << c_message << std::endl;
                std::string message = "Message Recieved by Server!";
                if (send(client_socket , message.c_str() , message.size() , 0) == -1){
                    std::cout << "Failed to send message" << std::endl;
                    break;
                }
            }
            else if(byte_received == 0){
                std::cout << "Client closed its connection." << std::endl;
                break;
            }
            else{
                std::cout << "Error : " << strerror(errno) << std::endl;
                break;
            }
        }
}



