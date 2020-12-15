#ifndef DRINKS_DRINKS_H
#define DRINKS_DRINKS_H


#include <string>

using std::string;

class Drinks {
public:
    Drinks(const string& name, double size);
    virtual string name() const = 0;
    void rename(const string& name);
    double size() const;
    void resize(double size);
    virtual ~Drinks() {}
protected:
    string name_;
    double size_;
};

class AlcoDrinks: public Drinks {
public:
    AlcoDrinks(const string& name, double size, double proof);
    string name() const override;
    virtual double proof() const = 0;
    virtual ~AlcoDrinks() {}
protected:
    double proof_;
};

class SoftDrinks: public Drinks {
public:
    SoftDrinks(const string& name, double size);
    string name() const override;
    virtual ~SoftDrinks() {}
};


#endif //DRINKS_DRINKS_H