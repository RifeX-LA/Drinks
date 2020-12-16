#include "AlcoDrinks.h"

const string Beer::raws[] = {"barley", "wheat", "ginger", "rice", "corn"};
const string Cognac::agings[] = {"VS", "Superior", "SOP", "VSOP", "EO"};
const string Wine::wineColor[] = {"white", "red", "orange", "pink"};

Beer::Beer(const string& name, double size, double proof, Raw raw, BeerColor color): AlcoDrinks(name, size, proof) {
    raw_ = raw;
    color_ = color;
}

double Beer::proof() const {
    return proof_;
}

string Beer::raw() const {
    return raws[static_cast<int>(raw_)];
}

string Beer::color() const {
    if (color_ == BeerColor::light) {
        return "light";
    }
    return "dark";
}

Cognac::Cognac(const string& name, double size, double proof, Aging aging): AlcoDrinks(name, size, proof) {
    aging_ = aging;
}

double Cognac::proof() const {
    return proof_;
}

const string Cognac::aging() const {
    return agings[static_cast<int>(aging_)];
}

Wine::Wine(const string& name, double size, double proof, Sweetness sweetness, WineColor color): AlcoDrinks(name, size, proof) {
    sweetness_ = sweetness;
    color_ = color;
}

double Wine::proof() const {
    return proof_;
}

const string Wine::color() const {
    return wineColor[static_cast<int>(color_)];
}

string Wine::sweetness() const {
    switch (sweetness_) {
        case Sweetness::dry: return "dry";
        case Sweetness::semiDry: return "semi-dry";
        case Sweetness::sweet: return "sweet";
    }
}