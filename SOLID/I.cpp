//# Interface Segregation Principle (ISP)
#include <iostream>
using namespace std;

//BAD
/*
class Worker {
public:
    virtual void work() = 0;
    virtual void eat() = 0;
};
class Robot : public Worker {
public:
    void work() {
        cout << "Robot working\n";
    }

    void eat() { } // meaningless
};
*/



//BETTER
class Workable {
public:
    virtual void work() = 0;
};

class Eatable {
public:
    virtual void eat() = 0;
};

//Split large interfaces into smaller specific ones.