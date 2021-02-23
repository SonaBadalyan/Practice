#ifndef MARY_H
#define MARY_H

#include "Customer.hpp"
#include <string>

class Mary : public Customer
{
    public: 
        virtual void accept(Visitor *visitor) const override
        {
            visitor->visit_mary(this);
        }

        const std::string get_name() const
        {
            return "Mary";
        }
};

#endif // MARY_H