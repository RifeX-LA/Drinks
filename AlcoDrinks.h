#ifndef DRINKS_ALCODRINKS_H
#define DRINKS_ALCODRINKS_H

#include <string>
#include "Drinks.h"
using std::string;

enum class Raw {barley, wheat, ginger, rice, corn};
enum class BeerColor {light, dark};

enum class Aging {VS, Superior, SOP, VSOP, EO};

enum class Sweetness {dry, semiDry, sweet};
enum class WineColor {white, red, orange, pink};

class Beer: public AlcoDrinks {
public:
    Beer(const string& name, double size, double proof, Raw raw, BeerColor color);
    double proof() const override;
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
    Cognac(const string& name, double size, double proof, Aging aging);
    double proof() const override;
    const char* aging() const;
    virtual ~Cognac() {}
private:
    Aging aging_;
    static const char* agings[];
};

class Wine: public AlcoDrinks {
public:
    Wine(const string& name, double size, double proof, Sweetness, WineColor color);
    double proof() const override;
    string sweetness() const;
    const char* color() const;
    virtual ~Wine() {}
private:
    Sweetness sweetness_;
    WineColor color_;
    static const char* wineColor[];
};


#endif //DRINKS_ALCODRINKS_H