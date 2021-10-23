#include <iostream>
#include <future>
#include <thread>

void foo()
{
    auto id = "S";
    std::cout << id << std::endl;
}

void th1()
{
    return foo();
}

void th2()
{
    return foo();
}

int main()
{
    std::future<void> thread1(std::async(th1));

    th2();

    
    return 0;
}

