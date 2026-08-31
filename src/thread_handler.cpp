#include <iostream>
#include "thread_handler.h"
#include <thread>
#include <cstring>
#include <netinet/in.h>
#include <vector>
#include <algorithm>

std::vector<int> connected_sockets;  // Vector list created to keep record of all connected sockets.

void remove_client_socket(int client_socket , std::vector<int> connected_client_sockets){
    auto it = std::find(connected_sockets.begin(), connected_sockets.end() , client_socket);   // this will move through whole vector and then {it} will be the index of desired number
    if (it != connected_sockets.end()){
        connected_sockets.erase(it);
    }
}

void handle_client(int client_socket){
    // Sending message to client
        std::string message = "Hello Client! ";
        connected_sockets.push_back(client_socket);   // Append Client socket at the end of the vector
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
                remove_client_socket(client_socket , connected_sockets);
                break;
            }
            else{
                std::cout << "Error : " << strerror(errno) << std::endl;
                break;
            }
        }
}



