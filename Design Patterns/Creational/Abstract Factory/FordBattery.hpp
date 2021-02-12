#ifndef FORD_BATTERY_H
#define FORD_BATTERY_H

#include "AbstractBattery.hpp"

class FordBattery : public AbstractBattery
{
    virtual const std::string battery_function() const override
    {
        return "Ford battery";
    }
};

#endif // FORD_BATTERY_H