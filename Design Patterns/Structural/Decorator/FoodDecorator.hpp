#ifndef FOOD_DECORATOR_H
#define FOOD_DECORATOR_H
#include "Food.hpp"

class FoodDecorator : public Food
{
    public:
    FoodDecorator(Food *food) : m_food(food) {}
    virtual std::string prepare_food() override
    {
        return m_food->prepare_food();
    }

    virtual double food_price() override
    {
        return m_food->food_price();
    }

    private:
    Food *m_food;

};
#endif // FOOD_DECORATOR_H