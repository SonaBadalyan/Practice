#include <iostream>
#include "AbstractCarFactory.hpp"
#include "TeslaFactory.hpp"
#include "BMWFactory.hpp"
#include "FordFactory.hpp"

void client_code(const AbstractCarFactory &car)
{
    const AbstractEngine* engine = car.create_engine();
    const AbstractBattery* battery = car.create_battery();
    const AbstractRadiator* radiator = car.create_radiator();
    std::cout << engine->engine_function() << std::endl;
    std::cout << battery->battery_function() << std::endl;
    std::cout << radiator->radiator_function() << std::endl;
    delete engine;
    delete battery;
    delete radiator;
}

int main ()
{
    std::cout << "Welcome to the car factory! Please select which model of car you want." << std::endl;
    std::cout << " Type 1 for Tesla car, 2 for BMW car, 3 for Ford car. " << std::endl;
    int carNo;
    std::cin >> carNo;

    switch (carNo)
    {
        case 1:
        {
            TeslaFactory* tesla = new TeslaFactory();
            client_code(*tesla);
            delete tesla;
            break;
        }
        case 2:
        {
            BMWFactory* bmw = new BMWFactory();
            client_code(*bmw);
            break;
        }
        case 3:
        {
            FordFactory* ford = new FordFactory();
            client_code(*ford);
            break;
        }
        default:
        {
            std::cout << "Wrong input!" << std::endl;
            break;
        }
    }

    return 0;
}