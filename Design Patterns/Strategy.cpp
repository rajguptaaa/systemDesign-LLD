#include<iostream>
using namespace std;

/*
It Defines a family of algorithms, encapulates each one and make them interchangeable at runtime
it allows behaviour to change without modifiying the client code.
*/

//Strategy Interface
class PaymentStrategy {
public:
    virtual void pay(int amount) = 0;
    virtual ~PaymentStrategy() {}
};

//Concrete Strategy
class CreditCardPayment : public PaymentStrategy {
public:
    void pay(int amount) override {
        cout << "Paid " << amount << " using Credit Card\n";
    }
};

class UpiPayment : public PaymentStrategy {
public:
    void pay(int amount) override {
        cout << "Paid " << amount << " using UPI\n";
    }
};

class PaypalPayment : public PaymentStrategy {
public:
    void pay(int amount) override {
        cout << "Paid " << amount << " using PayPal\n";
    }
};

//Context
class PaymentContext {
    PaymentStrategy* strategy;
public:
    void setStrategy(PaymentStrategy* s) {
        strategy = s;
    }
    void pay(int amount) {
        strategy->pay(amount);
    }
};

//Client code
int main() {
    PaymentContext context;

    CreditCardPayment credit;
    UpiPayment upi;
    PaypalPayment paypal;

    context.setStrategy(&credit);
    context.pay(1000);

    context.setStrategy(&upi);
    context.pay(500);

    context.setStrategy(&paypal);
    context.pay(3000);
}