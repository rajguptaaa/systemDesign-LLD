#include<iostream>
using namespace std;

//Recipe
struct Recipe{
    int water;
    int milk;
    int coffee;
    int sugarSpoon;
};

//Beverage Interface
class Beverage{
public:
    virtual Recipe getRecipe() = 0;
    virtual string getName() = 0;
};

//Drinks
class Espresso : public Beverage{
public:
    Recipe getRecipe(){
        return {50, 0, 18, 0};
    }
    string getName(){
        return "Espresso";
    }
};

class Latte : public Beverage{
public:
    Recipe getRecipe(){
        return {30, 150, 18, 0};
    }
    string getName(){
        return "Latte";
    }
};

class RegularCoffee : public Beverage{
public:
    Recipe getRecipe(){
        return {50, 0, 18, 2};
    }
    string getName(){
        return "Regular Coffee";
    }
};


//Ingredient Manager
class IngredientManager{
    int water = 500;
    int milk = 500;
    int coffee = 200;
    int sugarSpoon = 50;
public:
    bool hasIngredients(Recipe r){
        return water >= r.water &&
                milk >= r.milk &&
                coffee >= r.coffee &&
                sugarSpoon >= r.sugarSpoon;
    }

    void useIngredients(Recipe r){
        water -= r.water;
        milk -= r.milk;
        coffee -= r.coffee;
        sugarSpoon -= r.sugarSpoon;
    }
};

//Factory
class BeverageFactory {
public:

    static Beverage* create(string type) {

        if(type == "espresso")
            return new Espresso();
        if(type == "latte")
            return new Latte();
        if(type == "regular")
            return new RegularCoffee();
        return NULL;
        
        //Every new drink → modify factory ❌
        //Violates Open–Closed Principle
        
    }
};



//Coffee Machine
class CoffeeMachine {
    IngredientManager manager;
public:
    void makeCoffee(string type) {
        Beverage* b = BeverageFactory::create(type);
        if(b == NULL) {
            cout << "Invalid drink\n";
            return;
        }
        Recipe r = b->getRecipe();
        if(!manager.hasIngredients(r)) {
            cout << "Not enough ingredients\n";
            return;
        }
        manager.useIngredients(r);
        cout << "Preparing " << b->getName() << endl;
    }
};

//main
int main() {
    CoffeeMachine machine;
    machine.makeCoffee("latte");
    machine.makeCoffee("espresso");
    machine.makeCoffee("regular");
}