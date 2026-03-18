//Payment System

/*
requirements:
    1. payment Methods
        CreditCard
        UPI
        PayPal
    2. Payment Processing Logic is changing so we can use Strategy Design Patter:
        - It allows behaviour change without modifying the client code.
        - It defines a family of algorithms, encapsulates each other and make them 
        interchangeable at runtime
*/
#include<iostream>
using namespace std;

class Payment{ //payment interface
public:
    virtual void processPayment(int amount) = 0;
    virtual ~Payment(){}
};

class PaymentService{ //create a service which will have a object of Payment
    Payment* strategy = NULL;
public:
    void setStrategy(Payment* s){
        strategy = s;
    }
    void processPayment(int amount){
        if(strategy == NULL){
            cout << "Payment method not set\n";
            return;
        }
        strategy->processPayment(amount);
    }
};

//concrete payments 
class CreditCardPayment : public Payment{
public:
    void processPayment(int amount) override{
        cout<<amount<<" paid with CreditCard\n";
    }
};

class UpiPayment : public Payment{
public:
    void processPayment(int amount) override{
        cout<<amount<<" paid with UPI\n";
    }
};

class PaypalPayment : public Payment{
public:
    void processPayment(int amount) override{
        cout<<amount<<" paid with PaypalPayment\n";
    }
};

//Factory Base
class PaymentFactory{
public:
    virtual Payment* createPayment() = 0;
};

//Concrete Factories
class CreditCardFactory : public PaymentFactory{
public:
    Payment* createPayment() override{
        return new CreditCardPayment();
    }
};

class UpiPaymentFactory : public PaymentFactory{
public:
    Payment* createPayment() override{
        return new UpiPayment();
    }
};

class PayPalPaymentFactory : public PaymentFactory{
public:
    Payment* createPayment() override{
        return new PaypalPayment();
    }
};

//Factory selector (so system works with input)
PaymentFactory* getFactory(string type){
    if(type == "credit")
        return new CreditCardFactory();
    if(type == "upi")
        return new UpiPaymentFactory();
    if(type == "paypal")
        return new PayPalPaymentFactory();
    return NULL;
}


int main(){
    string type = "upi";
    PaymentFactory* factory = getFactory(type);

    if(factory == NULL){
        cout << "Invalid payment type\n";
        return 0;
    }

    Payment* p = factory->createPayment(); //payment object


    PaymentService service; //use payment service3
    service.setStrategy(p);
    service.processPayment(500);
}

/*
Responsibility Separation
Component	|   Responsibility
-Payment	    -how to pay
-Factory	    -object creation
-Service	    -execution logic
*/