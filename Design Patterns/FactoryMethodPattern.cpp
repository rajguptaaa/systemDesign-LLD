/*
Intent
Define an interface for creating objects, but let subclasses decide which class to instantiate.
The factory method moves object creation to subclasses instead of using if-else logic.

Problems with simple factory method: 
Large if-else / switch
Factory must change when new types are added
Violates Open–Closed Principle


STEPS
Product → interface
ConcreteProduct
Creator → declares factory method
ConcreteCreator → implements factory method
*/

#include<iostream>
using namespace std;

class Vehicle {
public:
    virtual void drive() = 0;
    virtual ~Vehicle() {}
};

class Car : public Vehicle {
public:
    void drive() override {
        cout << "Driving Car\n";
    }
};
class Bike : public Vehicle {
public:
    void drive() override {
        cout << "Riding Bike\n";
    }
};

class VehicleFactory {
public:
    virtual Vehicle* createVehicle() = 0; //no if else instead use one more class to intantiate object
};

class CarFactory : public VehicleFactory {
public:
    Vehicle* createVehicle() override {
        return new Car();
    }
};

class BikeFactory : public VehicleFactory {
public:
    Vehicle* createVehicle() override {
        return new Bike();
    }
};

int main() {

    // VehicleFactory* factory = new CarFactory(); 
    // Vehicle* v = factory->createVehicle();
    // v->drive(); //Drivinf Car

    // VehicleFactory* factory = new BikeFactory();
    // Vehicle* v = factory->createVehicle();
    // v->drive(); //Riding Bike

    return 0;
}

/*
Key Difference from Simple Factory
Simple Factory         |     Factory Method
------------------------------------------------
1. One factory class   |    Multiple factories
2. Uses if-else	       |    Uses polymorphism
3. Harder to extend	   |    Open for extension
4. Not GoF	           |    GoF pattern


Factory Method defines an interface for creating an object but lets subclasses decide which 
class to instantiate. It replaces conditional object creation with polymorphism.
*/