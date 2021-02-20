#ifndef NON_VEGAN_FOOD_H
#define NON_VEGAN_FOOD_H
#include "FoodDecorator.hpp"

class NonVeganFood : public FoodDecorator
{
    public:
    NonVeganFood(Food *food) :  FoodDecorator(food)
    {
    }
    
    virtual std::string prepare_food() override
    {
        return FoodDecorator::prepare_food() + " With Roasted Chiken and Chiken Curry  ";
    }

    virtual double food_price() override
    {
        return FoodDecorator::food_price() + 150.5;
    }

};

#endif // NON_VEGAN_FOOD_H
