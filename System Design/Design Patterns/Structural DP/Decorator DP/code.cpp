#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Coffee {
public:
    virtual string getDescription() const = 0;
    virtual double getCost() const = 0;
    virtual ~Coffee() {}
};

class SimpleCoffee : public Coffee {
public:    
    string getDescription() const override {
        return "Simple Coffee";
    }
    double getCost() const override {
        return 2.0;
    }
};

class Espresso : public Coffee {
public:    
    string getDescription() const override {
        return "Espresso";
    }
    double getCost() const override {
        return 3.0;
    }
};


class CoffeeDecorator : public Coffee {
protected:
    unique_ptr<Coffee> coffee;
public:    
    CoffeeDecorator(unique_ptr<Coffee> c) : coffee(move(c)) {}
    string getDescription() const override {
        return coffee->getDescription();
    }
    double getCost() const override {
        return coffee->getCost();
    }
};


class MilkDecorator : public CoffeeDecorator {
public:

    MilkDecorator(unique_ptr<Coffee> c) : CoffeeDecorator(move(c)) {}
    string getDescription() const override {
        return coffee->getDescription() + ", Milk";
    }
    double getCost() const override {
        return coffee->getCost() + 0.5;
    }
};  

class SugarDecorator : public CoffeeDecorator {
public:
    SugarDecorator(unique_ptr<Coffee> c) : CoffeeDecorator(move(c)) {}
    string getDescription() const override {
        return coffee->getDescription() + ", Sugar";
    }
    double getCost() const override {
        return coffee->getCost() + 0.2;
    }
};

int main() {
    cout << "Decorator Design Pattern in C++" << endl;
    unique_ptr<Coffee> coffee = make_unique<SimpleCoffee>();
    cout << coffee->getDescription() << " costs $" << coffee->getCost() << endl;


    coffee = make_unique<MilkDecorator>(move(coffee));
    cout << coffee->getDescription() << " costs $" << coffee->getCost() << endl;    

    coffee = make_unique<SugarDecorator>(move(coffee));
    cout << coffee->getDescription() << " costs $" << coffee->getCost() << endl;

    // Coffee* coffee = new SimpleCoffee();
    // cout << coffee->getDescription() << " costs $" << coffee->getCost() << endl;

    // coffee = new MilkDecorator(unique_ptr<Coffee>(coffee));
    // cout << coffee->getDescription() << " costs $" << coffee->getCost() << endl;        

    // coffee = new SugarDecorator(unique_ptr<Coffee>(coffee));
    // cout << coffee->getDescription() << " costs $" << coffee->getCost() << endl;

    return 0;

}