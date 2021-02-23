#ifndef SANTA_H
#define SANTA_H

#include <iostream>
#include "Visitor.hpp"
#include "Mary.hpp"
#include "Bob.hpp"

class Santa : public Visitor
{
    public:
        virtual void visit_bob(const Bob* bob) const
        {
            std::cout << "OOH YES! Santa visited " << bob->get_name() << " and bring Christmas to him!" << std::endl;
        }

        virtual void visit_mary(const Mary* mary) const
        {
            std::cout << "OOH YES! Santa visited " << mary->get_name() << " and bring Christmas to her!" << std::endl;

        }

};
#endif // SANTA