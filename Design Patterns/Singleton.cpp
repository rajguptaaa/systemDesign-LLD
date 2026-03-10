/*
Rules:
1. Constructor private
2. Static instance inside class
3. Public method to access instance
*/

// 1.Basic
/*
#include <iostream>
using namespace std;

class Singleton {
private:
    static Singleton* instance;
    Singleton() { }   // private constructor
public:
    static Singleton* getInstance() {
        if (instance == nullptr) {
            instance = new Singleton();
        }
        return instance;
    }
};
Singleton* Singleton::instance = nullptr;
int main() {
    Singleton* s1 = Singleton::getInstance();
    Singleton* s2 = Singleton::getInstance();

    cout << (s1 == s2);   // prints 1 (same instance)
}
*/

/*
Explanation
1. instance → static pointer shared across program
2. constructor → private (no direct object creation)
3. getInstance() → returns the single object
*/

// 2.Problem Not Thread safe
//If two threads call getInstance() simultaneously, two objects may be created.
//use mytex lock
/*
#include <mutex>
class Singleton {
private:
    static Singleton* instance;
    static std::mutex mtx;

    Singleton() {}
public:
    static Singleton* getInstance() {
        std::lock_guard<std::mutex> lock(mtx);

        if (instance == nullptr) {
            instance = new Singleton();
        }
        return instance;
    }
};
Singleton* Singleton::instance = nullptr;
std::mutex Singleton::mtx;
*/

//Best
class Singleton {
private:
    static Singleton instance;
    Singleton() {}

public:
    static Singleton& getInstance(){
        return instance;
    }
};
Singleton& s = Singleton::getInstance();

/*
Thread-safe (since C++11)
No manual memory management
Lazy initialization
*/

// Singleton ensures only one instance of a class exists and provides global access to it.
/*
Example	                    Why Singleton
Logger	                    one logging system
Configuration Manager	    single config source
Database connection pool	shared resource
Cache	                    central storage
*/