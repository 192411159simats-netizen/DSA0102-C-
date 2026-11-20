
#include <iostream>
using namespace std;

class Account {
public:
    virtual double rate() const {
        return 3.5;
    }

    virtual void display() const {
        cout << "Account Interest: " << rate() << "%" << endl;
    }

    virtual ~Account() {
        cout << "Account Destroyed" << endl;
    }
};

class SeniorAccount : public Account {
    double *history;

public:
    SeniorAccount() {
        history = new double[100];
    }

    double rate() const override {
        return 4.0;
    }

    void display() const override {
        cout << "Senior Account Interest: "
             << rate() << "%" << endl;
    }

    ~SeniorAccount() override {
        delete[] history;
        cout << "Senior Account Destroyed" << endl;
    }
};

int main() {
    Account *accounts[2];

    accounts[0] = new Account();
    accounts[1] = new SeniorAccount();

    for (int i = 0; i < 2; i++)
        accounts[i]->display();

    cout << "\nDeleting Accounts" << endl;

    for (int i = 0; i < 2; i++)
        delete accounts[i];

    return 0;
}
