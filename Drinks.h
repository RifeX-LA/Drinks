#ifndef DRINKS_DRINKS_H
#define DRINKS_DRINKS_H
#include <string>
using std::string;

class Drinks {
public:
    Drinks(string name, double volume);
    virtual string name() const = 0;
    virtual double volume() const = 0;
    virtual ~Drinks() {}
protected:
    string name_;
    double volume_;
};

class AlcoDrinks: public Drinks {
public:
    AlcoDrinks(string name, double volume, double alcoContent);
    string name() const override;
    double volume() const override;
    virtual double alcoContent() const = 0;
    virtual ~AlcoDrinks() {}
protected:
    double alcoContent_;
};

class SoftDrinks: public Drinks {
public:
    SoftDrinks(string name, double volume);
    string name() const override;
    double volume() const override;
    virtual ~SoftDrinks() {}
};


#endif //DRINKS_DRINKS_H