#ifndef FORD_ENGINE_H
#define FORD_ENGINE_H

#include "AbstractEngine.hpp"

class FordEngine : public AbstractEngine
{
    virtual const std::string engine_function() const override
    {
        return "Ford engine";
    }
};

#endif // FORD_ENGINE_H