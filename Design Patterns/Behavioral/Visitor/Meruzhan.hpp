#ifndef MERUZHAN_H
#define MERUZHAN_H

#include "Customer.hpp"
#include <string>

class Meruzhan : public Customer
{
    public:
        virtual void accept(Visitor *visitor) const override
        {
            visitor->visit_meruzhan(this);
        }

        const std::string get_name() const
        {
            return "Meruzhan";
        }

};

#endif // MERUZHAN_H