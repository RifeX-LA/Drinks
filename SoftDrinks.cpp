#include <stdexcept>
#include <utility>
#include "SoftDrinks.h"

const char* Limonade::limonade[] = {"classic", "coconut", "tropic", "berry", "crimson", "apple"};

Milk::Milk(const string& name, double size, int shelfLife, double fat): SoftDrinks(name, size) {
    if (shelfLife < 0 || shelfLife > 60) {
        throw std::invalid_argument("Invalid argument for shelf life");
    }
    if (fat < 0 || fat > 15) {
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
    }
}

string Mineral::mineraliz() const {
    switch (mineraliz_) {
        case Mineralization::insipid: return "insipid";
        case Mineralization::slightly: return "slightly";
        case Mineralization::low: return "low";
        case Mineralization::medium: return "medium";
        case Mineralization::highly: return "highly";
    }
}

Limonade::Limonade(const string& name, double size, Carbonation carbonation, LimonadeType type): SoftDrinks(name, size) {
    carbonation_ = carbonation;
    type_ = type;
}

string Limonade::carbonation() const {
    switch (carbonation_) {
        case Carbonation::still: return "still";
        case Carbonation::slightly: return "slightly";
        case Carbonation::strongly: return "strongly";
    }
}

const char *Limonade::type() const {
    return limonade[static_cast<int>(type_)];
}
