
#include "Singleton.hpp"

Singleton* Singleton::singleton = nullptr;
std::mutex Singleton::mutex;

Singleton* Singleton::get_instance(const std::string& name)
{
    std::unique_lock<std::mutex> lock(Singleton::mutex);
    if (singleton == nullptr)
        singleton = new Singleton(name);

    return singleton;
}

void Singleton::delete_instance()
{  
    std::unique_lock<std::mutex> lock(Singleton::mutex);
    if (singleton != nullptr)
        delete singleton;
}