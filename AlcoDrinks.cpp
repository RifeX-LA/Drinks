#include "AlcoDrinks.h"

#include <utility>

const char* Beer::raws[] = {"barley", "wheat", "ginger", "rice", "corn"};

const char* Beer::raw() const {
    return raws[static_cast<int>(raw_)];
}

Beer::Beer(string name, double volume, double alcoContent, Raw raw, BeerColor color): AlcoDrinks(std::move(name), volume, alcoContent) {
    raw_ = raw;
    color_ = color;
}

Cognac::Cognac(string name, double volume, double alcoContent, Aging aging): AlcoDrinks(std::move(name), volume, alcoContent) {
    aging_ = aging;
}

Wine::Wine(string name, double volume, double alcoContent, SugarContent sugar, WineColor color): AlcoDrinks(std::move(name), volume, alcoContent) {
    sugarContent_ = sugar;
    color_ = color;
}