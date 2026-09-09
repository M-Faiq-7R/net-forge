#include <iostream>
#include "broadcast.h"
#include <string>
#include <vector>
#include <netinet/in.h>

void broadcast_message(int sender_socket , std::string message , std::vector<int> sender_list){
    for (int i = 0 ; i < sender_list.size() ; i++ ){
        if (sender_list[i] == sender_socket){
            continue;
        }else{
            if (send(sender_list[i] , message.c_str() , message.size() , 0) == -1){
                    std::cout << "Failed to send message to " << sender_list[i] <<std::endl;
                }
        }
    }
}