#ifndef FORD_FACTORY_H
#define FORD_FACTORY_H

#include "AbstractCarFactory.hpp"
#include "FordEngine.hpp"
#include "FordBattery.hpp"
#include "FordRadiator.hpp"

class FordFactory : public AbstractCarFactory
{
    public:
        virtual AbstractEngine* create_engine() const override
        {
            return new FordEngine();
        }

        virtual AbstractBattery* create_battery() const override
        {
            return new FordBattery();
        }

        virtual AbstractRadiator* create_radiator() const override
        {
            return new FordRadiator();
        }
};

#endif // FORD_FACTORY_H