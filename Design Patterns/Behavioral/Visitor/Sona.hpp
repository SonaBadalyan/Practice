#ifndef SONA_H
#define SONA_H

#include "Customer.hpp"
#include <string>

class Sona : public Customer
{
    public: 
        virtual void accept(Visitor *visitor) const override
        {
            visitor->visit_sona(this);
        }

        const std::string get_name() const
        {
            return "Sona";
        }
};

#endif // SONA_H