#ifndef TESLA_BATTERY_H
#define TESLA_BATTERY_H

#include "AbstractBattery.hpp"

class TeslaBattery : public AbstractBattery
{
    public:
        virtual const std::string battery_function() const override
        {
            return "Tesla battery";
        }
};

#endif // TESLA_BATTERY_H