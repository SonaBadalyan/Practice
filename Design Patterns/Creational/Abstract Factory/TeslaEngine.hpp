#ifndef TESLA_ENGINE_H
#define TESLA_ENGINE_H

#include "AbstractEngine.hpp"

class TeslaEngine : public AbstractEngine
{
    virtual const std::string engine_function() const override
    {
        return "Tesla engine";
    }
};

#endif // TESLA_ENGINE_H