#ifndef TESLA_FACTORY_H
#define TESLA_FACTORY_H

#include "AbstractCarFactory.hpp"
#include "TeslaEngine.hpp"
#include "TeslaBattery.hpp"
#include "TeslaRadiator.hpp"

class TeslaFactory : public AbstractCarFactory
{
    public:
        virtual AbstractEngine* create_engine() const override
        {
            return new TeslaEngine();
        }

        virtual AbstractBattery* create_battery() const override
        {
            return new TeslaBattery();
        }

        virtual AbstractRadiator* create_radiator() const override
        {
            return new TeslaRadiator();
        }
};

#endif // TESLA_FACTORY_H