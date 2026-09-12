#include <string>
#include <vector>
#include <iostream>
#include <netinet/in.h>


void broadcast_message(int client_socket){
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