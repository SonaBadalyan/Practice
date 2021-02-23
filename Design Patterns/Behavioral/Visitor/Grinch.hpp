#ifndef GRINCH_H
#define GRINCH_H

#include <iostream>
#include "Visitor.hpp"
#include "Mary.hpp"
#include "Bob.hpp"

class Grinch : public Visitor
{
    public:
        virtual void visit_bob(const Bob* bob) const
        {
            std::cout << "OHH NOO! Grinch visited " << bob->get_name() << " and stole Christmas from him!" << std::endl;
        }
        
        virtual void visit_mary(const Mary* mary) const
        {
            std::cout << "OHH NOO! Grinch visited " << mary->get_name() << " and stole Christmas from her!" << std::endl;
        }

};

#endif // GRINCH_H