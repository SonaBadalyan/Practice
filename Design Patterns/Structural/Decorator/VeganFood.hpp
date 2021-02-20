#ifndef VEGAN_FOOD
#define VEGAN_FOOD
#include "Food.hpp"

class VeganFood : public Food
{
    public:
    virtual std::string prepare_food() override
    {
        return "Vegan food";
    }

    virtual double food_price() override
    {
        return 5.6;
    }
};

#endif // VEGAN_FOOD