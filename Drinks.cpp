#include "Drinks.h"
#include <stdexcept>

Drinks::Drinks(string name, double volume) {
    if (name.empty()) {
        throw std::invalid_argument("The name must not be empty");
    }
    if (volume < 0 || volume > 10) {
        throw std::invalid_argument("Invalid argument for volume");
    }
    name_ = name;
    volume_ = volume;
}

double Drinks::volume() const {
    return volume_;
}

AlcoDrinks::AlcoDrinks(string name, double volume, double alcoContent): Drinks(std::move(name), volume) {
    if (alcoContent <= 0 || alcoContent > 100) {
        throw std::invalid_argument("Invalid argument for alcohol content");
    }
    alcoContent_ = alcoContent;
}

string AlcoDrinks::name() const {
    return name_;
}

SoftDrinks::SoftDrinks(string name, double volume): Drinks(std::move(name), volume) {}

string SoftDrinks::name() const {
    return name_;
}