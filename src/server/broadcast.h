#ifndef BROADCAST_H
#define BROADCAST_H

#include <string>
#include <vector>

void broadcast_message(int sender_socket , std::string message , std::vector<int> sender_list);      // It will broadcast message to other clients connected to server . 


#endif