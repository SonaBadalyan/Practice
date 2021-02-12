#ifndef ABSTRACT_RADIATOR_H
#define ABSTRACT_RADIATOR_H

#include <string>

class AbstractRadiator
{
    public:
        virtual ~AbstractRadiator(){};
        virtual const std::string radiator_function() const = 0;
};

#endif // ABSTRACT_RADIATOR_H