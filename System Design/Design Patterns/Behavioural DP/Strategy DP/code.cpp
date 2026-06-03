#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <algorithm>

using namespace std;



class PaymentStrategy {
    public:
        virtual void processPayment() = 0;
};

class CreditCardPayement : public PaymentStrategy {
    public:
    void processPayment() {
        cout << "credit card is used for payment\n";
    }
};

class UPIPayement : public PaymentStrategy {
    public:
    void processPayment() {
        cout << "UPI is used for payment\n";
    }
};

class PayPalPayement: public PaymentStrategy {
    public:
    void processPayment() {
        cout << "PayPal is used for payment\n";
    }
};

class PaymentProcessor {
    shared_ptr<PaymentStrategy> strategy;
    public:
    PaymentProcessor(shared_ptr<PaymentStrategy> ps) {
        strategy = ps;
    }
    void processPayment() {
        strategy->processPayment();
    }

    void setPaymentStrategy(shared_ptr<PaymentStrategy> ps) {
        strategy = ps;
    }
};




int main() {
    shared_ptr<PaymentStrategy> strategy1 = make_shared<CreditCardPayement>();

    // Set payment strategy as Credit Card
    shared_ptr<PaymentProcessor> paymentProcessor = make_shared<PaymentProcessor>(strategy1);

    paymentProcessor->processPayment();

    shared_ptr<PaymentStrategy> strategy2 = make_shared<UPIPayement>();
    // Set Payement strategy as UPI
    paymentProcessor->setPaymentStrategy(strategy2);

    paymentProcessor->processPayment();


    shared_ptr<PaymentStrategy> strategy3 = make_shared<PayPalPayement>();

    // set payment strategy as PayPal
    paymentProcessor->setPaymentStrategy(strategy3);

    paymentProcessor->processPayment();
}