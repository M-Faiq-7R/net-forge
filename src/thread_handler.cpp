#include <iostream>
#include "thread_handler.h"
#include <thread>
#include <cstring>
#include <netinet/in.h>
#include <vector>

std::vector<int> connected_sockets;  // Vector list created to keep record of all connected sockets.

void handle_client(int client_socket){
    // Sending message to client
        std::string message = "Hello Client! ";
        connected_sockets.push_back(client_socket);   // Append Client socket at the end of the vector
        for(int i =0 ; i <= connected_sockets.size() ; i++){       // For testing purposes
            std::cout << connected_sockets[i] << " , ";      
        }
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
                // std::erase(connected_sockets , client_socket);
                break;
            }
            else{
                std::cout << "Error : " << strerror(errno) << std::endl;
                break;
            }
        }
}



