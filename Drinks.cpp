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