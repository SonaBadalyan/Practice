#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "Visitor.hpp"

class Customer
{
    public:
        virtual void accept(Visitor *visitor) const = 0;
        virtual ~Customer() {}
};

#endif // CUSTOMER_H