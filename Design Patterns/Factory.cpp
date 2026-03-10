#include<iostream>
using namespace std;

class Vehicle{
public:
    virtual void drive() = 0;
};

class Car : public Vehicle{
public:
    void drive(){
        cout<<"Driving a Car"<<endl;
    }
};

class Bike : public Vehicle{
public:
    void drive(){
        cout<<"Riding a Car"<<endl;
    }
};

class VehicleFactory{
public:
    static Vehicle* createVehicle(string type){
        if(type=="Car"){
            return new Car(); 
        }
        else if(type=="Bike"){
            return new Bike();
        }
        return nullptr;
    }
};

int main(){
    Vehicle* v1 = VehicleFactory::createVehicle("Car");
    v1->drive();
    Vehicle* v2 = VehicleFactory::createVehicle("Bike");
    v2->drive();
    return 0;
}

/*
* also known as Virtual COnstructor
Move Object creation into a factory class, the factory decides which class to instantiate, it promotes loose coupling
steps:
a. common interface, e.g. class Vehicle{};
b. concrete classes, e.g. class Car and Class Bike (child classes)
c. Factory class, e.g. class VehicleFactory(this class created new objects)
d. client code, Vehicle* v1 = VehicleFactory::createVehicle("Car"); (created the object using the factory)

Factory pattern provides an interface for creating objects without exposing the object 
creation logic to the client and refers to the newly created object using a common interface.
*/