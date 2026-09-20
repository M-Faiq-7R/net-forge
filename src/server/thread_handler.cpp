#include <iostream>
#include "thread_handler.h"
#include "utils.h"
#include "broadcast.h"
#include "logger.h"
#include <thread>
#include <cstring>
#include <netinet/in.h>
#include <vector>
#include <algorithm>
#include <mutex>                 // Library added to use lockguard funtion
#include "client_manager.h"

std::vector<int> connected_sockets;  // Vector list created to keep record of all connected sockets.
std::mutex my_mutex ;

void remove_client_socket(int client_socket){
    auto it = std::find(connected_sockets.begin(), connected_sockets.end() , client_socket);   // this will move through whole vector and then {it} will be the index of desired number
    if (it != connected_sockets.end()){
        connected_sockets.erase(it);
        cManage(ClientAction::Remove);        // Sends data to client_manager.cpp
    }
}

void print_vector(std::vector<int> nigga){                                    // Optional function ; just for testing purposes
    for(int i = 0; i <= nigga.size() ; i++){
                        std::cout << i << "-----" ; 
                    }
}


void handle_client(int client_socket){
    // Sending message to client
        std::string message = "Hello Client! ";
        {   // This block only allows one thread to access and modify this vector at a time to avoid race condition
            std::lock_guard<std::mutex> lock(my_mutex);
            connected_sockets.push_back(client_socket);   // Append Client socket at the end of the vector
            cManage(ClientAction::Add);
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
                broadcast_message(client_socket , c_message , connected_sockets);       // Broadcast Message to other clients ; Sends data to broadcast.cpp to process
                if (send(client_socket , message.c_str() , message.size() , 0) == -1){
                    std::cout << "Failed to send message" << std::endl;
                    break;
                }
                log_info(client_socket, "Message Broadcasted! ");
            }
            else if(byte_received == 0){
                std::cout << "Client closed its connection." << std::endl;
                {   // This block only allows one thread to access and modify this vector at a time to avoid race condition
                    std::lock_guard<std::mutex> lock(my_mutex);
                    remove_client_socket(client_socket );        // Removing Disconnected Clients 
                    log_info(client_socket, "Connection Removed ! ");
                }
                break;
            }
            else{
                std::cout << "Error : " << strerror(errno) << std::endl;
                remove_client_socket(client_socket );
                log_info(client_socket, "Connection Removed ! ");
                break;
            }
        }
}




