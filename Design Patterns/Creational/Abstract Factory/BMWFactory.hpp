#ifndef BMW_FACTORY_H
#define BMW_FACTORY_H

#include "AbstractCarFactory.hpp"
#include "BMWEngine.hpp"
#include "BMWBattery.hpp"
#include "BMWRadiator.hpp"

class BMWFactory : public AbstractCarFactory
{
    public:
        virtual AbstractEngine* create_engine() const override
        {
            return new BMWEngine();
        }

        virtual AbstractBattery* create_battery() const override
        {
            return new BMWBattery();
        }

        virtual AbstractRadiator* create_radiator() const override
        {
            return new BMWRadiator();
        }
};
#endif // BMW_FACTORY_H