#ifndef BMW_BATTERY_H
#define BMW_BATTERY_H

#include "AbstractBattery.hpp"

class BMWBattery : public AbstractBattery
{
    virtual const std::string battery_function() const override
    {
        return "BMW battery";
    };

};

#endif // BMW_BATTERY_H