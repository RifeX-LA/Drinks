#ifndef DRINKS_SOFTDRINKS_H
#define DRINKS_SOFTDRINKS_H

#include <string>
#include "Drinks.h"
using std::string;

enum class Carbonation {still, slightly, strongly};
enum class Mineralization {insipid, slightly, low, medium, highly};
enum class LimonadeKind {classic, coconut, tropic, berry, crimson, apple};

class Milk: public SoftDrinks {
public:
    int shelfLife() const;
    double fatContent() const;
private:
    int shelfLife_;
    double fatContent_;
};

class Mineral: public SoftDrinks {
public:
    string carbonation() const;
    string mineraliz() const;
private:
    Carbonation carbonation_;
    Mineralization mineraliz_;
};

class Limonade: public SoftDrinks {
public:
    string carbonation() const;
    string limonadeKind() const;
private:
    Carbonation carbonation_;
    LimonadeKind limonadeKind_;
};


#endif //DRINKS_SOFTDRINKS_H