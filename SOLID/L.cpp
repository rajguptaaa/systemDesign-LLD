// # Liskov Substituion Principle
#include <iostream>
using namespace std;

//BAD
/*
class Bird {
public:
    virtual void fly() {
        cout << "Bird flying\n";
    }
};

class Penguin : public Bird {
public:
    void fly() {
        throw "Penguins can't fly";
    }
};
*/
class Bird {};

class FlyingBird : public Bird {
public:
    virtual void fly() {
        cout << "Flying\n";
    }
};

class Sparrow : public FlyingBird {};
class Penguin : public Bird {};

//Child classes must not break the behavior expected from parent classes.