#include <iostream>
#include "AlcoDrinks.h"
#include "SoftDrinks.h"

int main() {

    Beer b("Beer", 1.21, 50, Raw::barley, BeerColor::dark);
    Wine w("Wine", 1, 20, BySugarContent::sweet, WineColor::red);
    Limonade l("Coca-cola", 5, Carbonation::still, LimonadeKind::apple);
    std::cout << l.carbonation();
    return 0;
}