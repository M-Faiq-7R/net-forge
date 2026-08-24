#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string>

int main(){
    std::string ip_addr = "127.0.0.1";

    int client_socket = socket(AF_INET , SOCK_STREAM, 0);
    std::cout << "Client socket created Successfully ..." << std::endl;

    sockaddr_in server_address ;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(8080); 
    
    inet_pton(AF_INET, ip_addr.c_str() , &server_address.sin_addr);


    return 0;
}