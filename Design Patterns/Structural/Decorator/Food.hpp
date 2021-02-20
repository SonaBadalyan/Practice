#ifndef FOOD_H
#define FOOD_H
#include <string>

class Food
{
    public:
    virtual std::string prepare_food() = 0;
    virtual double food_price() = 0;
};

#endif // FOOD_H