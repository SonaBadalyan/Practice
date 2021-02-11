#include <iostream>
#include <thread>

#include "Singleton.hpp"

int main()
{
    Singleton* singleton;

    std::thread thread1([&singleton](){ 
        singleton = Singleton::get_instance("singleton");
        
        });
   
    std::thread thread2([&singleton](){
        singleton = Singleton::get_instance("singleton1");
        
    });
    
    thread1.join();
    thread2.join();
    
    std::cout << singleton->get_name() << std::endl;
    singleton->delete_instance();

    return 0;
}