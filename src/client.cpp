#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string>
#include <cerrno>
#include <cstring>

int main(){
    std::string ip_addr = "127.0.0.1";  // IPv4 to which client will connect

    int client_socket = socket(AF_INET , SOCK_STREAM, 0);
    std::cout << "Client socket created Successfully ..." << std::endl;

    // Assigning addrs to clients socket
    sockaddr_in server_address ;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(8080); 
    
    // Turns human read-able ip into binary(linux read-able)
    int server_ipv4_binary_address_conversion_status = inet_pton(AF_INET, ip_addr.c_str() , &server_address.sin_addr);

    // Connecting with the server
    int connection_status = connect(client_socket , (struct sockaddr*)&server_address , sizeof(server_address) );
    if (connection_status == 0){
        std::cout << "Connected to Server!" << std::endl;
        
        
    }else{
        std::cout << "Failed to connect to server!" << std::endl;
        std::cout << "Error : " << strerror(errno) << std::endl;
    }

    // Receiving message from server
    char message[1024];
    int byte_received = recv(client_socket, message , sizeof(message) -1 , 0);
    message[byte_received] = '\0';
    std::cout << "Server : " << message << std::endl;

    return 0;
}