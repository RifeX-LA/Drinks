#include <iostream>
#include "Drinks.h"
#include "AlcoDrinks.h"

int main() {

    Beer b("fdaf", 1.21, 50, Raw::barley, BeerColor::dark);
    std::cout << b.volume();
    return 0;
}