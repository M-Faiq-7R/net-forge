#include <iostream>
#include "thread_handler.h"
#include <thread>

#include "utils.h"

void nigga(){
    std::thread t1(draw_line , 2);
    std::thread t2(draw_x_line , 3);
    t2.join();
    t1.join();
}

int main(){
    nigga();
    return 0;
}