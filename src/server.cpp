#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>

void draw_line(int i=1){
    for(int j =0; j<i; j++){
        std::cout << "===================================================================" << std::endl;
    }
}



int main() {
    draw_line();
    std::cout << "Netforge Initiated ... \nServer waiting for connections ..." << std::endl;
    draw_line(2);

    // Creating a socket
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    std::cout << "Socket created successfully -> " << server_socket << std::endl;
    
    // Additional socket info
    sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(8080);
    server_address.sin_addr.s_addr = INADDR_ANY ;

    std::cout << "Socket info :: " << std::endl;
    std::cout << "Socket family :: " << server_address.sin_family << std::endl;
    std::cout << "Socket port :: " << server_address.sin_port << std::endl      
              << "Socket address :: " << server_address.sin_addr.s_addr << std::endl;


    draw_line(2);         
    return 0;
}

