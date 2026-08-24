#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>

void draw_line(int i=1){
    for(int j =0; j<i; j++){
        std::cout << "===================================================================" << std::endl;
    }
}



int main() {
    int backlogs = 5; // For listening TCP connections. It is no. of devices which can wait in qeue before forming a connection.


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

    std::cout << "Socket info := " << std::endl;
    std::cout << "Socket family :: " << server_address.sin_family << std::endl;
    std::cout << "Socket port :: " << server_address.sin_port << std::endl      
              << "Socket address :: " << server_address.sin_addr.s_addr << std::endl;

    // Binding the socket
    if (bind(server_socket, (struct sockaddr*)&server_address , sizeof(server_address))==0){
        std::cout << "Bind Created Successfully." << std::endl;
    }else{
        std::cout << "Failed to create Bind." << std::endl;
    }

    // Listening for TCP connections
    if(listen(server_socket , backlogs) == 0){
        std::cout << "Server listening ..." << std::endl;
    }else{
        std::cout << "Server Failed to listen ... " << std::endl;
    }


    draw_line(2);         
    return 0;
}

