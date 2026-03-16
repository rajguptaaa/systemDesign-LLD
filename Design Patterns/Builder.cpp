/*
#Builder
The Builder Pattern separates the construction of a complex object from its representation,
allowing the same construction process to create different representations.
Use it when an object has many optional parameters.
*/

#include<iostream>
using namespace std;

// Step 1 — Product
class Computer {
public:
    string cpu;
    string ram;
    string storage;
    bool gpu;

    void show() {
        cout << "CPU: " << cpu << endl;
        cout << "RAM: " << ram << endl;
        cout << "Storage: " << storage << endl;
        cout << "GPU: " << (gpu ? "Yes" : "No") << endl;
    }
};

// Step 2 — Builder Interface
class ComputerBuilder {
public:
    virtual void buildCPU() = 0;
    virtual void buildRAM() = 0;
    virtual void buildStorage() = 0;
    virtual void buildGPU() = 0;

    virtual Computer* getComputer() = 0;
};

//Step 3 - oncrete Builder
class GamingComputerBuilder : public ComputerBuilder {
    Computer* computer;
public:
    GamingComputerBuilder() {
        computer = new Computer();
    }
    void buildCPU() override {
        computer->cpu = "Intel i9";
    }
    void buildRAM() override {
        computer->ram = "32GB";
    }
    void buildStorage() override {
        computer->storage = "2TB SSD";
    }
    void buildGPU() override {
        computer->gpu = true;
    }
    Computer* getComputer() override {
        return computer;
    }
};

// Step 4 — Director
class Director {
public:
    void construct(ComputerBuilder* builder) {

        builder->buildCPU();
        builder->buildRAM();
        builder->buildStorage();
        builder->buildGPU();
    }
};

//Client Code
int main() {

    Director director;

    GamingComputerBuilder builder;

    director.construct(&builder);

    Computer* pc = builder.getComputer();

    pc->show();
}

/*
Key Characteristics
Feature	Description
Step-by-step construction	Build object gradually
Flexible creation	Optional components
Cleaner constructors	Avoids many parameters
Reusable build process	Same steps, different objects

Use Builder when:
Object has many optional fields
Construction requires multiple steps
You want immutable objects
Avoid large constructors

Builder pattern constructs complex objects step by step and 
separates the construction logic from the final representation.
*/