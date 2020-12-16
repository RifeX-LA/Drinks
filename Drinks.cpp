#include "Drinks.h"
#include <stdexcept>

Drinks::Drinks(const string& name, double size) {
    rename(name);
    resize(size);
}

void Drinks::rename(const string& name) {
    if (name.empty()) {
        throw std::invalid_argument("The name must not be empty");
    }
    name_ = name;
}

double Drinks::size() const {
    return size_;
}

void Drinks::resize(double size) {
    if (size < 0 || size > 10) {
        throw std::invalid_argument("Invalid argument for size");
    }
    size_ = size;
}

AlcoDrinks::AlcoDrinks(const string& name, double size, double proof): Drinks(name, size) {
    if (proof <= 0 || proof > 200) {
        throw std::invalid_argument("Invalid argument for proof");
    }
    proof_ = proof;
}

string AlcoDrinks::name() const {
    return name_;
}

SoftDrinks::SoftDrinks(const string& name, double size): Drinks(name, size) {}

string SoftDrinks::name() const {
    return name_;
}

//************** ALCOHOL DRINKS **************//

const string Beer::raws[] = {"barley", "wheat", "ginger", "rice", "corn"};
const string Cognac::agings[] = {"VS", "Superior", "SOP", "VSOP", "EO"};
const string Wine::wineColors[] = {"white", "red", "orange", "pink"};

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

string Cognac::aging() const {
    return agings[static_cast<int>(aging_)];
}

Wine::Wine(const string& name, double size, double proof, Sweetness sweetness, WineColor color): AlcoDrinks(name, size, proof) {
    sweetness_ = sweetness;
    color_ = color;
}

double Wine::proof() const {
    return proof_;
}

string Wine::color() const {
    return wineColors[static_cast<int>(color_)];
}

string Wine::sweetness() const {
    switch (sweetness_) {
        case Sweetness::dry: return "dry";
        case Sweetness::semiDry: return "semi-dry";
        case Sweetness::sweet: return "sweet";
        default: return "";
    }
}

//************** SOFT DRINKS **************//

const string Lemonade::LemonadeTypes[] = {"classic", "coconut", "tropic", "berry", "crimson", "apple"};

Milk::Milk(const string& name, double size, int shelfLife, double fat): SoftDrinks(name, size) {
    if (shelfLife <= 0 || shelfLife > 60) {
        throw std::invalid_argument("Invalid argument for shelf life");
    }
    if (fat <= 0 || fat > 10) {
        throw std::invalid_argument("Invalid argument for fat");
    }
    shelfLife_ = shelfLife;
    fat_ = fat;
}

int Milk::shelfLife() const {
    return shelfLife_;
}

double Milk::fat() const {
    return fat_;
}

Mineral::Mineral(const string& name, double size, Carbonation carbonation, Mineralization mineraliz): SoftDrinks(name, size) {
    carbonation_ = carbonation;
    mineraliz_ = mineraliz;
}

string Mineral::carbonation() const {
    switch (carbonation_) {
        case Carbonation::still: return "still";
        case Carbonation::slightly: return "slightly";
        case Carbonation::strongly: return "strongly";
        default: return "";
    }
}

string Mineral::mineraliz() const {
    switch (mineraliz_) {
        case Mineralization::insipid: return "insipid";
        case Mineralization::slightly: return "slightly";
        case Mineralization::low: return "low";
        case Mineralization::medium: return "medium";
        case Mineralization::highly: return "highly";
        default: return "";
    }
}

Lemonade::Lemonade(const string& name, double size, Carbonation carbonation, LemonadeType type): SoftDrinks(name, size) {
    carbonation_ = carbonation;
    type_ = type;
}

string Lemonade::carbonation() const {
    switch (carbonation_) {
        case Carbonation::still: return "still";
        case Carbonation::slightly: return "slightly";
        case Carbonation::strongly: return "strongly";
        default: return "";
    }
}

string Lemonade::type() const {
    return LemonadeTypes[static_cast<int>(type_)];
}