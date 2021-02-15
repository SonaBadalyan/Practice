#ifndef GRINCH_H
#define GRINCH_H

#include <iostream>
#include "Visitor.hpp"
#include "Sona.hpp"
#include "Meruzhan.hpp"

class Grinch : public Visitor
{
    public:
        virtual void visit_meruzhan(const Meruzhan* morexik) const
        {
            std::cout << "OHH NOO! Grinch visited " << morexik->get_name() << " and stole Christmas from him!" << std::endl;
        }
        
        virtual void visit_sona(const Sona* xelarik) const
        {
            std::cout << "OHH NOO! Grinch visited " << xelarik->get_name() << " and stole Christmas from her!" << std::endl;
        }

};

#endif // GRINCH_H