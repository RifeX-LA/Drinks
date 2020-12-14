#include <stdexcept>
#include <utility>
#include "SoftDrinks.h"

const char* Limonade::limonade[] = {"classic", "coconut", "tropic", "berry", "crimson", "apple"};

Milk::Milk(string name, double volume, int shelfLife, double fatContent): SoftDrinks(std::move(name), volume) {
    if (shelfLife < 0 || shelfLife > 60) {
        throw std::invalid_argument("Invalid argument for shelf life");
    }
    if (shelfLife < 0 || shelfLife > 20) {
        throw std::invalid_argument("Invalid argument for fat content");
    }
    shelfLife_ = shelfLife;
    fatContent_ = fatContent;
}

int Milk::shelfLife() const {
    return shelfLife_;
}

double Milk::fatContent() const {
    return fatContent_;
}

Mineral::Mineral(string name, double volume, Carbonation carbonation, Mineralization mineraliz): SoftDrinks(std::move(name), volume) {
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

Limonade::Limonade(string name, double volume, Carbonation carbonation, LimonadeKind limonadeKind): SoftDrinks(std::move(name), volume) {
    carbonation_ = carbonation;
    limonadeKind_ = limonadeKind;
}

string Limonade::carbonation() const {
    switch (carbonation_) {
        case Carbonation::still: return "still";
        case Carbonation::slightly: return "slightly";
        case Carbonation::strongly: return "strongly";
    }
}

const char *Limonade::limonadeKind() const {
    return limonade[static_cast<int>(limonadeKind_)];
}
