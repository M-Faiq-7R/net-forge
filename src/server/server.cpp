#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <cerrno>
#include <cstring>
#include <thread>
#include "startup.h"
#include "thread_handler.h"
#include "utils.h"
#include "logger.h"


int main(){
    int server_socket = initialize_server(); // It will initialzie server with default 5

    while (true){
        draw_line();
        // Listening for TCP connections
        

        // Accepting Clients TCP connection request
        sockaddr_in client_address;
        socklen_t client_address_length = sizeof(client_address);
        int client_socket =  accept(server_socket , (struct sockaddr*)&client_address , &client_address_length);  // Parameters of accept are : (server_socket, client_address, client_address_length)
        if (client_socket == -1){
            std::cout << "Failed to connect to client " << std::endl;
            return 0;
        }else{
            std::cout << "Connection Accepted! " << std::endl;
            log_info(client_socket, "Connection Accepted! ");
            draw_line();
            std::thread t1(handle_client , client_socket);
            t1.detach();
        
        }
        
    }
    draw_line(2);
    
    
    return 0;

}

