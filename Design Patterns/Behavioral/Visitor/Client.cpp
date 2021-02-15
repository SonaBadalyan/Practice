#include <vector>
#include "Customer.hpp"
#include "Visitor.hpp"
#include "Santa.hpp"
#include "Grinch.hpp"
#include "Sona.hpp"
#include "Meruzhan.hpp"

void client_code(std::vector<const Customer*> customers, Visitor *visitor)
{
    for (auto const& customer : customers)
        customer->accept(visitor);
}

int main()
{
    std::vector<const Customer*> customers;
    customers.push_back(new Meruzhan);
    customers.push_back(new Sona);

    Santa *santa = new Santa;
    client_code(customers, santa);
    delete santa;

    Grinch *grinch = new Grinch;
    client_code(customers, grinch);
    delete grinch;

    for (auto customer : customers)
        delete customer;

    return 0;
}