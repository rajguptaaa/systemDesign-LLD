//# Dependency Inversion Principle (DIP)


//BAD
/*
class Keyboard {};

class Computer {
    Keyboard k;
};
*/

//Better
class InputDevice {
public:
    virtual void input() = 0;
};

class Keyboard : public InputDevice {
public:
    void input() {}
};

class Computer {
    InputDevice* device;

public:
    Computer(InputDevice* d) {
        device = d;
    }
};

//Depend on interfaces/abstract classes, not concrete implementations.