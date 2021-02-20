#include <iostream>
#include "VeganFood.hpp"
#include "Food.hpp"
#include "NonVeganFood.hpp"
#include "ChineeseFood.hpp"

int main()
{
    std::cout << "========= Food Menu ============ \n";
    std::cout << "           1. Vegetarian Food.   \n";
    std::cout << "           2. Non-Vegetarian Food.\n";
    std::cout << "           3. Chineese Food.         \n";
    
    int choice;
    std::cin >> choice;

    switch (choice)
    {
    case 1 :
    {
        VeganFood *vf = new VeganFood();
        std::cout << vf->prepare_food() << std::endl;
        std::cout << vf->food_price() << std::endl;
        break;
    }
    case 2 :
    {
        Food *nvf = new NonVeganFood(new VeganFood());
        std::cout << nvf->prepare_food() << std::endl;
        std::cout << nvf->food_price() << std::endl;
        break;
    }
    case 3 :
    {
        Food *cf = new ChineeseFood(new VeganFood());
        std::cout << cf->prepare_food() << std::endl;
        std::cout << cf->food_price() << std::endl;
        break;
    }
    }

    return 0;
}