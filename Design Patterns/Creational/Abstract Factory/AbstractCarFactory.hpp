#ifndef ABSTRACT_CAR_FACTORY_H
#define ABSTRACT_CAR_FACTORY_H

#include "AbstractEngine.hpp"
#include "AbstractBattery.hpp"
#include "AbstractRadiator.hpp"

class AbstractCarFactory
{
    public:
        virtual AbstractEngine* create_engine() const = 0;
        virtual AbstractBattery* create_battery() const = 0;
        virtual AbstractRadiator* create_radiator() const = 0;
};

#endif // ABSTRACT_CAR_FACTORY_H