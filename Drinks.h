#ifndef DRINKS_DRINKS_H
#define DRINKS_DRINKS_H


#include <string>
using std::string;

class Drinks {
public:
    Drinks(string name, double volume);
    virtual string name() const = 0;
    virtual double volume() const;
    virtual ~Drinks() {}
protected:
    string name_;
    double volume_;
};

class AlcoDrinks: public Drinks {
public:
    AlcoDrinks(string name, double volume, double alcoContent);
    string name() const override;
    virtual ~AlcoDrinks() {}
protected:
    double alcoContent_;
};

class SoftDrinks: public Drinks {
public:
    SoftDrinks(string name, double volume);
    string name() const override;
    virtual ~SoftDrinks() {}
};


#endif //DRINKS_DRINKS_H