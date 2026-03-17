/*
LLD: Coffee Machine

Class design
Separation of responsibility
Extensibility (adding new drinks)

*/

/*
1. Requirements (Clarify First)

Assume:
Functional
Machine can make:
    Espresso
    Cappuccino
    Latte

Each drink has:
    fixed recipe (water, milk, coffee, sugar)

User selects a drink → machine prepares it

Non-Functional (important for interview)
    Easy to add new drinks
    No large if-else
    Clean separation of logic

2. High-Level Design
We will combine:
    Strategy Pattern → for drink preparation
    Factory Method Pattern → for drink creation
    (I will model beverages as a strategy, use a factory for object 
    creation, and a coffee machine class that orchestrates preparation 
    using ingredient management)
*/

#include<iostream>
using namespace std;

/*
CoffeeMachine
Beverage (interface)
   ├── Espresso
   ├── Latte
   └── Cappuccino
IngredientManager
BeverageFactory
*/

//Class Design

// Beverage Interface (Strategy)
class Beverage {
public:
    virtual void prepare() = 0;
    virtual ~Beverage() {}
};

//Concrete Beverages
class Espresso : public Beverage {
public:
    void prepare() override {
        cout << "Preparing Espresso\n";
    }
};

class Latte : public Beverage {
public:
    void prepare() override {
        cout << "Preparing Latte\n";
    }
};

class Cappuccino : public Beverage {
public:
    void prepare() override {
        cout << "Preparing Cappuccino\n";
    }
};

//Factory (Object Creation)
class BeverageFactory {
public:
    static Beverage* createBeverage(string type) {

        if(type == "espresso")
            return new Espresso();

        if(type == "latte")
            return new Latte();

        if(type == "cappuccino")
            return new Cappuccino();

        return nullptr;
    }
};

// CoffeeMachine (Main Class)
class CoffeeMachine {
public:
    void makeCoffee(string type) {

        Beverage* beverage = BeverageFactory::createBeverage(type);

        if(beverage == nullptr) {
            cout << "Invalid selection\n";
            return;
        }

        beverage->prepare();
    }
};

//Client Code
int main() {

    CoffeeMachine machine;

    machine.makeCoffee("latte");
    machine.makeCoffee("cappuccino");
}