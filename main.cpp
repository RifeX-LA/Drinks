#include <iostream>
#include "Drinks.h"

int main() {
    try {
        Beer beer("Alaskan", 1.2, 50, Raw::corn, BeerColor::dark);
        Wine wine("Merlot", 1.7, 20, Sweetness::sweet, WineColor::red);
        Cognac cognac("Hennessy", 1.5, 30, Aging::SOP);
        Milk milk("Freshz", 1, 5, 3);
        Mineral mineral("Darida", 2.5, Carbonation::strongly, Mineralization::highly);
        Lemonade lemonade("Coca-cola", 5, Carbonation::still, LemonadeType::apple);

        milk.rename("True taste");
        wine.resize(2);

        std::cout << "Name: " << beer.name() << ", size: " << beer.size() << "l, proof: " << beer.proof() << ", raw: "
                  << beer.raw() << ", color: " << beer.color() << '\n';

        std::cout << "Name: " << wine.name() << ", size: " << wine.size() << "l, proof: " << wine.proof()
                  << ", sweetness: "
                  << wine.sweetness() << ", color: " << wine.color() << '\n';

        std::cout << "Name: " << cognac.name() << ", size: " << cognac.size() << "l, proof: " << cognac.proof()
                  << ", aging: "
                  << cognac.aging() << '\n';

        std::cout << "Name: " << milk.name() << ", size: " << milk.size() << "l, shelf life: " << milk.shelfLife()
                  << "d, fat: "
                  << milk.fat() << "%\n";

        std::cout << "Name: " << mineral.name() << ", size: " << mineral.size() << "l, carbonation: "
                  << mineral.carbonation()
                  << ", mineralization: " << mineral.mineraliz() << '\n';

        std::cout << "Name: " << lemonade.name() << ", size: " << lemonade.size() << "l, carbonation: "
                  << lemonade.carbonation()
                  << ", lemonade type: " << lemonade.type() << '\n';
    }
    catch (std::exception &e) {
        std::cerr << e.what();
    }

    return 0;
}