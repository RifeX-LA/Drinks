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

//************** ALCOHOL DRINKS **************//

enum class Raw {barley, wheat, ginger, rice, corn};
enum class BeerColor {light, dark};

enum class Aging {VS, Superior, SOP, VSOP, EO};

enum class Sweetness {dry, semiDry, sweet};
enum class WineColor {white, red, orange, pink};

class Beer: public AlcoDrinks {
public:
    Beer(const string& name, double size, double proof, Raw raw, BeerColor color);
    double proof() const override;
    string raw() const;
    string color() const;
    virtual ~Beer() {}
private:
    Raw raw_;
    BeerColor color_;
    static const string raws[];
};

class Cognac: public AlcoDrinks {
public:
    Cognac(const string& name, double size, double proof, Aging aging);
    double proof() const override;
    const string aging() const;
    virtual ~Cognac() {}
private:
    Aging aging_;
    static const string agings[];
};

class Wine: public AlcoDrinks {
public:
    Wine(const string& name, double size, double proof, Sweetness, WineColor color);
    double proof() const override;
    string sweetness() const;
    const string color() const;
    virtual ~Wine() {}
private:
    Sweetness sweetness_;
    WineColor color_;
    static const string wineColor[];
};

//************** SOFT DRINKS **************//

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
    const string type() const;
    virtual ~Limonade() {}
private:
    Carbonation carbonation_;
    LimonadeType type_;
    static const string limonade[];
};


#endif //DRINKS_DRINKS_H