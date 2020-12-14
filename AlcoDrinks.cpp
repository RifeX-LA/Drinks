#include "AlcoDrinks.h"

const char* Beer::raws[] = {"barley", "wheat", "ginger", "rice", "corn"};
const char* Cognac::age[] = {"VS", "Superior", "SOP", "VSOP", "EO"};
const char* Wine::wineColor[] = {"white", "red", "orange", "pink"};

Beer::Beer(string name, double volume, double alcoContent, Raw raw, BeerColor color): AlcoDrinks(std::move(name), volume, alcoContent) {
    raw_ = raw;
    color_ = color;
}

double Beer::alcoContent() const {
    return alcoContent_;
}

const char *Beer::raw() const {
    return raws[static_cast<int>(raw_)];
}

string Beer::color() const {
    if (color_ == BeerColor::light) {
        return "light";
    }
    return "dark";
}

Cognac::Cognac(string name, double volume, double alcoContent, Aging aging): AlcoDrinks(std::move(name), volume, alcoContent) {
    aging_ = aging;
}

double Cognac::alcoContent() const {
    return alcoContent_;
}

const char *Cognac::aging() const {
    return age[static_cast<int>(aging_)];
}

Wine::Wine(string name, double volume, double alcoContent, BySugarContent sugar, WineColor color): AlcoDrinks(std::move(name), volume, alcoContent) {
    sugar_ = sugar;
    color_ = color;
}

double Wine::alcoContent() const {
    return alcoContent_;
}

const char* Wine::color() const {
    return wineColor[static_cast<int>(color_)];
}

string Wine::sugar() const {
    switch (sugar_) {
        case BySugarContent::dry: return "dry";
        case BySugarContent::semiDry: return "semi-dry";
        case BySugarContent::sweet: return "sweet";
    }
}