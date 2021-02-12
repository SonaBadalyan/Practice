#ifndef BMW_RADIATOR_H
#define BMW_RADIATOR_H

#include "AbstractRadiator.hpp"

class BMWRadiator : public AbstractRadiator
{
    public:
        virtual const std::string radiator_function() const override
        {
            return "BMW radiator";
        }
};
#endif // BMW_RADIATOR_H