#ifndef TESLA_RADIATOR_H
#define TESLA_RADIATOR_H

#include "AbstractRadiator.hpp"

class TeslaRadiator : public AbstractRadiator
{
    public:
        virtual const std::string radiator_function() const override
        {
            return "Tesla radiator";
        }

};

#endif // TESLA_RADIATOR_H