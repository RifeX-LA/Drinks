#ifndef DRINKS_ALCODRINKS_H
#define DRINKS_ALCODRINKS_H

#include <string>
#include "Drinks.h"
using std::string;

enum class Raw {barley, wheat, ginger, rice, corn};
enum class BeerColor {light, dark};

enum class Aging {VS, Superior, SOP, VSOP, EO};

enum class SugarContent {dry, semiDry, sweet};
enum class WineColor {white, red, orange, pink};

class Beer: public AlcoDrinks {
public:
    Beer(string name, double volume, double alcoContent, Raw raw, BeerColor color);
    double alcoContent() const override;
    const char* raw() const;
    string color() const;
    virtual ~Beer() {}
private:
    static const char* raws[];
    Raw raw_;
    BeerColor color_;
};

class Cognac: public AlcoDrinks {
public:
    Cognac(string name, double volume, double alcoContent, Aging aging);
    double alcoContent() const override;
    string aging() const;
    virtual ~Cognac() {}
private:
    Aging aging_;
};

class Wine: public AlcoDrinks {
public:
    Wine(string name, double volume, double alcoContent, SugarContent, WineColor color);
    double alcoContent() const override;
    string sugarContent() const;
    string color() const;
    virtual ~Wine() {}
private:
    SugarContent sugarContent_;
    WineColor color_;
};


#endif //DRINKS_ALCODRINKS_H