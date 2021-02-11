#include <iostream>
#include <thread>

#include "Singleton.hpp"

int main()
{
    std::thread thread1([](){ 
        Singleton* singleton = Singleton::get_instance("singleton");
        std::cout << singleton->get_name() << std::endl;
        });
   
    std::thread thread2([](){
        Singleton* singleton1 = Singleton::get_instance("singleton1");
        std::cout << singleton1->get_name() << std::endl;
    });
    

    return 0;
}