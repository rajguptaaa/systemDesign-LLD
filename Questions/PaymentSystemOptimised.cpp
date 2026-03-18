#include<iostream>
using namespace std;

struct PaymentResult {
    bool success;
    string message;
    string transactionId;
};


// Payment interface (Strategy)
class Payment {
public:
    virtual PaymentResult processPayment(int amount) = 0;
    virtual ~Payment(){}
};


// PaymentService (handles retry + logging)
class PaymentService {
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

        int attempts = 3;

        for(int i = 1; i <= attempts; i++){

            cout << "Attempt " << i << "...\n";

            PaymentResult result = strategy->processPayment(amount);

            if(result.success){
                cout << "SUCCESS: " << result.message << endl;
                cout << "Transaction ID: " << result.transactionId << endl;
                return;
            } else {
                cout << "FAILED: " << result.message << endl;
            }
        }

        cout << "Payment failed after 3 attempts\n";
    }
};


// Concrete Payments
class CreditCardPayment : public Payment{
public:
    PaymentResult processPayment(int amount) override{
        return {true, "Paid using Credit Card", "TXN123"};
    }
};

class UpiPayment : public Payment{
public:
    PaymentResult processPayment(int amount) override{
        return {false, "UPI failed (network issue)", ""}; // simulate failure
    }
};

class PaypalPayment : public Payment{
public:
    PaymentResult processPayment(int amount) override{
        return {true, "Paid using PayPal", "TXN999"};
    }
};


// Factory (simple selector)
Payment* getPayment(string type){

    if(type == "credit")
        return new CreditCardPayment();

    if(type == "upi")
        return new UpiPayment();

    if(type == "paypal")
        return new PaypalPayment();

    return NULL;
}


// main
int main(){

    string type = "credit";  // try changing this

    Payment* p = getPayment(type);

    if(p == NULL){
        cout << "Invalid payment type\n";
        return 0;
    }

    PaymentService service;
    service.setStrategy(p);

    service.processPayment(500);
}