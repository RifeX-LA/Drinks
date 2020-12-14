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
    Milk(string name, double volume, int shelfLife, double fatContent);
    int shelfLife() const;
    double fatContent() const;
    virtual ~Milk() {}
private:
    int shelfLife_;
    double fatContent_;
};

class Mineral: public SoftDrinks {
public:
    Mineral(string name, double volume, Carbonation carbonation, Mineralization mineraliz);
    string carbonation() const;
    string mineraliz() const;
    virtual ~Mineral() {}
private:
    Carbonation carbonation_;
    Mineralization mineraliz_;
};

class Limonade: public SoftDrinks {
public:
    Limonade(string name, double volume, Carbonation carbonation, LimonadeKind limonadeKind);
    string carbonation() const;
    const char* limonadeKind() const;
    virtual ~Limonade() {}
private:
    Carbonation carbonation_;
    LimonadeKind limonadeKind_;
    static const char* limonade[];
};


#endif //DRINKS_SOFTDRINKS_H