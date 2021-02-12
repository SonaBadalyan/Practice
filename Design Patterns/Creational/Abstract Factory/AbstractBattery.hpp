#ifndef ABSTRACT_BATTERY_H
#define ABSTRACT_BATTERY_H

#include <string>

class AbstractBattery
{
    public:
        virtual ~AbstractBattery(){};
        virtual const std::string battery_function() const = 0;
};

#endif // ABSTRACT_BATTERY_H