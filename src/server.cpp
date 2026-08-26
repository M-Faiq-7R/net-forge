#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include "utils.h"
#include <cerrno>
#include <cstring>



int main() {
    int backlogs = 5; // For listening TCP connections. It is no. of devices which can wait in qeue before forming a connection.


    draw_line();
    std::cout << "Netforge Initiating ... \n" << std::endl;
    draw_line(2);

    // Creating a socket
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    std::cout << "Socket created successfully -> " << server_socket << std::endl;
    
    // Additional socket info
    sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(8080);
    server_address.sin_addr.s_addr = INADDR_ANY ;

    std::cout << "Socket info := " << std::endl;
    std::cout << "Socket family :: " << server_address.sin_family << std::endl;
    std::cout << "Socket port :: " << server_address.sin_port << std::endl      
              << "Socket address :: " << server_address.sin_addr.s_addr << std::endl;

    // Binding the socket
    if (bind(server_socket, (struct sockaddr*)&server_address , sizeof(server_address))==0){
        std::cout << "Bind Created Successfully." << std::endl;
    }else{
        std::cout << "Failed to create Bind." << std::endl;
        std::cout << "Error : " << strerror(errno) << std::endl;
        return 0;
    }

    draw_line();
    // Listening for TCP connections
    if(listen(server_socket , backlogs) == 0){                                       // Listen doesn't actually communicates with client , instead it just waits for user request to form connection , we use accept() to form connection with client-server.
        std::cout << "Server listening ..." << std::endl;
    }else{
        std::cout << "Server Failed to listen ... " << std::endl;
        
    }

    // Accepting Clients TCP connection request
    sockaddr_in client_address;
    socklen_t client_address_length = sizeof(client_address);
    int client_socket =  accept(server_socket , (struct sockaddr*)&client_address , &client_address_length);  // Parameters of accept are : (server_socket, client_address, client_address_length)
    std::cout << "Connection Accepted! " << std::endl;

    draw_line();

    // Sending message to client
    std::string message = "Hello Client! ";
    
    send(client_socket , message.c_str() , message.size() , 0);
    // std::cout << "Message Sent!" <<  std::endl;

    // Recieving message from client
    char c_message[1024];
    int byte_received = recv(client_socket, c_message , sizeof(c_message) -1 , 0);
    if (byte_received > 0){
        c_message[byte_received] = '\0';
        std::cout << "Client : " << c_message << std::endl;
    }else if(byte_received == 0){
        std::cout << "Client closed its connection." << std::endl;
    }else{
        std::cout << "Error : " << strerror(errno) << std::endl;
        return 0;
    }

    draw_line(2);         
    return 0;
}

