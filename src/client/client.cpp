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
    if (client_socket < 0){
        std::cout << "Failed to create Client Socket. " << std::endl;
        std::cout << "Error : " << strerror(errno) << std::endl;
        return 0;
    }else{
        std::cout << "Client socket created Successfully ..." << std::endl;
    }
    
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
        return 0;
    }

    // Receiving message from server
    char s_message[1024];
    int byte_received = recv(client_socket, s_message , sizeof(s_message) -1 , 0);
    if (byte_received > 0){
        s_message[byte_received] = '\0';
        std::cout << "Server : " << s_message << std::endl;
    }else if(byte_received == 0){
        std::cout << "Server closed its connection." << std::endl;
    }else{
        std::cout << "Error : " << strerror(errno) << std::endl;
        return 0;
    }
    
    // Sending message back to server
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
                break;
            }else{
                if(send(client_socket , c_message.c_str() , c_message.size() , 0) == -1){
                    std::cout << "Failed to send message to server " << std::endl;
                    break;
                }else{

                }
            }

            char confirmation_message[1024];
            int byte_received_r = recv(client_socket, confirmation_message , sizeof(confirmation_message) -1 , 0);
            if (byte_received_r > 0){
                confirmation_message[byte_received_r] = '\0';
                std::cout << "Server : " << confirmation_message << std::endl;
            }else if(byte_received == 0){
                std::cout << "Server closed its connection." << std::endl;
            }else{
                std::cout << "Error : " << strerror(errno) << std::endl;
                return 0;
            }
        }
    }
    return 0;
}