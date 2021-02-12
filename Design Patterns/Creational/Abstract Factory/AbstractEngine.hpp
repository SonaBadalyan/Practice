#ifndef ABSTRACR_ENGINE_H
#define ABSTRACR_ENGINE_H

#include <string>

class AbstractEngine
{
    public:
        virtual ~AbstractEngine(){};
        virtual const std::string engine_function() const = 0;
};

#endif // ABSTRACR_ENGINE_H