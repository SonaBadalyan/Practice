#ifndef SANTA_H
#define SANTA_H

#include <iostream>
#include "Visitor.hpp"
#include "Sona.hpp"
#include "Meruzhan.hpp"

class Santa : public Visitor
{
    public:
        virtual void visit_meruzhan(const Meruzhan* morexik) const
        {
            std::cout << "OOH YES! Santa visited " << morexik->get_name() << " and bring Christmas to him!" << std::endl;
        }

        virtual void visit_sona(const Sona* xelarik) const
        {
            std::cout << "OOH YES! Santa visited " << xelarik->get_name() << " and bring Christmas to her!" << std::endl;

        }

};
#endif // SANTA