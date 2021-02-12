#ifndef BMW_ENGINE_H
#define BMW_ENGINE_H

#include "AbstractEngine.hpp"

class BMWEngine : public AbstractEngine
{
    virtual const std::string engine_function() const override 
    {
        return "BMW engine";
    }
};
#endif // BMW_ENGINE_H