#include <string>
#include <fstream>
#include <chrono>
#include <ctime>
#include <iomanip>
#include "logger.h"

std::string get_time(){
    auto now = std::chrono::system_clock::now();
    std::time_t current_time = std::chrono::system_clock::to_time_t(now);
    std::tm* local_time = std::localtime(&current_time);

    std::ostringstream time_stream;
    time_stream << std::put_time(local_time, "%Y-%m-%d %H:%M:%S");

    return time_stream.str();
}

void log_info(int socket, std::string info){
    std::string timestamp = get_time();
    std::ofstream file("system.log" , std::ios::app);
    file << '[' << timestamp << "]  " << info << "  | Socket : " << socket << std::endl;
    file.close();
}

