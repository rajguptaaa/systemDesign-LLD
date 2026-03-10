/*
The Abstract Factory Pattern provides an interface for creating 
families of related objects without specifying their concrete classes.
It is essentially a factory of factories.


Suppose you are building a cross-platform UI toolkit.

You have components:
Button
Checkbox

For each OS:
WindowsButton
WindowsCheckbox
&
MacButton
MacCheckbox

If you use only Factory Method Pattern, you would need many factories:
WindowsButtonFactory
WindowsCheckboxFactory
MacButtonFactory
MacCheckboxFactory


Core Idea:
Each factory creates a set of related products.
Example:
WindowsFactory
   → WindowsButton
   → WindowsCheckbox
MacFactory
   → MacButton
   → MacCheckbox
This ensures compatible objects are created together.
*/


#include<iostream>
using namespace std;

// 1. Abstract Products
class Button {
public:
    virtual void paint() = 0;
    virtual ~Button() {}
};
class Checkbox {
public:
    virtual void paint() = 0;
    virtual ~Checkbox() {}
};

//2. Concrete Products
class WindowsButton : public Button {
public:
    void paint() override {
        cout << "Windows Button\n";
    }
};
class MacButton : public Button {
public:
    void paint() override {
        cout << "Mac Button\n";
    }
};
class WindowsCheckbox : public Checkbox {
public:
    void paint() override {
        cout << "Windows Checkbox\n";
    }
};
class MacCheckbox : public Checkbox {
public:
    void paint() override {
        cout << "Mac Checkbox\n";
    }
};

//3. Abstract Factory
class GUIFactory {
public:
    virtual Button* createButton() = 0;
    virtual Checkbox* createCheckbox() = 0;
};


//4. Concrete Factories
class WindowsFactory : public GUIFactory {
public:
    Button* createButton() override {
        return new WindowsButton();
    }

    Checkbox* createCheckbox() override {
        return new WindowsCheckbox();
    }
};
class MacFactory : public GUIFactory {
public:
    Button* createButton() override {
        return new MacButton();
    }

    Checkbox* createCheckbox() override {
        return new MacCheckbox();
    }
};

//5. Client Code 
int main() {

    GUIFactory* factory;

    string os = "windows";

    if(os == "windows")
        factory = new WindowsFactory();
    else
        factory = new MacFactory();

    Button* btn = factory->createButton();
    Checkbox* cb = factory->createCheckbox();

    btn->paint();
    cb->paint();
}

/*
Used heavily in:
GUI frameworks
Cross-platform systems
Game engines
Theme systems

Abstract Factory provides an interface for creating families of related 
objects without specifying their concrete classes. It ensures that related 
objects are created together.


Simple Factory → one factory
Factory Method → many factories
Abstract Factory → factory of families
*/