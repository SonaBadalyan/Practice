#ifndef BOB_H
#define BOB_H

#include "Customer.hpp"
#include <string>

class Bob : public Customer
{
    public:
        virtual void accept(Visitor *visitor) const override
        {
            visitor->visit_bob(this);
        }

        const std::string get_name() const
        {
            return "Bob";
        }

};

#endif // BOB_H