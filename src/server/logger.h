#ifndef LOGGER_H
#define LOGGER_H

#include <string>
#include "client_manager.h"


void log_info(int socket, std::string info);
std::string get_time();
void log_info(Client_Info info);

#endif