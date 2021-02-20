#ifndef CHINEESE_FOOD_H
#define CHINEESE_FOOD_H
#include "FoodDecorator.hpp"

class ChineeseFood : public FoodDecorator
{
    public:
    ChineeseFood(Food *food) :  FoodDecorator(food)
    {
    }
    
    virtual std::string prepare_food() override
    {
        return FoodDecorator::prepare_food() + " With Fried Rice and Manchurian  ";
    }

    virtual double food_price() override
    {
        return FoodDecorator::food_price() + 65.0;
    }

};

#endif // CHINEESE_FOOD_H
