#ifndef FORD_RADIATOR_H
#define FORD_RADIATOR_H

#include "AbstractRadiator.hpp"

class FordRadiator : public AbstractRadiator
{
    public:
        virtual const std::string radiator_function() const override
        {
            return "Ford radiator";
        }
};

#endif // FORD_RADIATOR_H