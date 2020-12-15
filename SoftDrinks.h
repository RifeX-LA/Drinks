#ifndef DRINKS_SOFTDRINKS_H
#define DRINKS_SOFTDRINKS_H

#include <string>
#include "Drinks.h"
using std::string;

enum class Carbonation {still, slightly, strongly};
enum class Mineralization {insipid, slightly, low, medium, highly};
enum class LimonadeType {classic, coconut, tropic, berry, crimson, apple};

class Milk: public SoftDrinks {
public:
    Milk(const string& name, double size, int shelfLife, double fat);
    int shelfLife() const;
    double fat() const;
    virtual ~Milk() {}
private:
    int shelfLife_;
    double fat_;
};

class Mineral: public SoftDrinks {
public:
    Mineral(const string& name, double size, Carbonation carbonation, Mineralization mineraliz);
    string carbonation() const;
    string mineraliz() const;
    virtual ~Mineral() {}
private:
    Carbonation carbonation_;
    Mineralization mineraliz_;
};

class Limonade: public SoftDrinks {
public:
    Limonade(const string& name, double size, Carbonation carbonation, LimonadeType type);
    string carbonation() const;
    const char* type() const;
    virtual ~Limonade() {}
private:
    Carbonation carbonation_;
    LimonadeType type_;
    static const char* limonade[];
};


#endif //DRINKS_SOFTDRINKS_H