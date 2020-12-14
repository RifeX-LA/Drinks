#ifndef DRINKS_ALCODRINKS_H
#define DRINKS_ALCODRINKS_H

#include <string>
#include "Drinks.h"
using std::string;

enum class Raw {barley, wheat, ginger, rice, corn};
enum class BeerColor {light, dark};

enum class Aging {VS, Superior, SOP, VSOP, EO};

enum class BySugarContent {dry, semiDry, sweet};
enum class WineColor {white, red, orange, pink};

class Beer: public AlcoDrinks {
public:
    Beer(string name, double volume, double alcoContent, Raw raw, BeerColor color);
    double alcoContent() const override;
    const char* raw() const;
    string color() const;
    virtual ~Beer() {}
private:
    Raw raw_;
    BeerColor color_;
    static const char* raws[];
};

class Cognac: public AlcoDrinks {
public:
    Cognac(string name, double volume, double alcoContent, Aging aging);
    double alcoContent() const override;
    const char* aging() const;
    virtual ~Cognac() {}
private:
    Aging aging_;
    static const char* age[];
};

class Wine: public AlcoDrinks {
public:
    Wine(string name, double volume, double alcoContent, BySugarContent, WineColor color);
    double alcoContent() const override;
    string sugar() const;
    const char* color() const;
    virtual ~Wine() {}
private:
    BySugarContent sugar_;
    WineColor color_;
    static const char* wineColor[];
};


#endif //DRINKS_ALCODRINKS_H