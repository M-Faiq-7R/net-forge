#include "startup.h"
#include <thread>
#include "client_operation_manager.h"


int main(){
    int client_socket =initialize_client();
    
    // Sending message back to server
    
    std::thread t1(handle_client_input,client_socket);
    t1.detach();
    std::thread t2 (rcv_data,client_socket);
    t2.detach();
        
    while (true){
        //
    }
    
    return 0;
}