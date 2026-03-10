// # Open/Closed Principle
#include <iostream>
using namespace std;

// Bad design
/*
class Payment
{
public:
    void pay(string type)
    {
        if (type == "credit")
        {
            cout << "Credit card payment\n";
        }
        else if (type == "paypal")
        {
            cout << "Paypal payment\n";
        }
    }
};
*/

// better
class Payment
{
public:
    virtual void pay() = 0;
};

class CreditCard : public Payment
{
public:
    void pay()
    {
        cout << "Credit card payment\n";
    }
};
class PayPal : public Payment
{
public:
    void pay()
    {
        cout << "Paypal payment\n";
    }
};

int main()
{
    Payment *p = new CreditCard();
    p->pay();
}


//OCP says classes should be extendable without 
// modifying existing implementation.