#include <iostream>
#include <string>
using namespace std;

class Bill {
protected:
    string patient;

public:
    Bill(string p) : patient(p) {}
    virtual ~Bill() = default;

    virtual double total() const = 0;
    virtual string type() const = 0;

    void print() const {
        cout << type() << " " << patient
             << ": " << total() << '\n';
    }
};

class OutPatient : public Bill {
    double consultation, tests;

public:
    OutPatient(string p, double c, double t)
        : Bill(p), consultation(c), tests(t) {}

    double total() const override {
        return consultation + tests;
    }

    string type() const override {
        return "OutPatient";
    }
};

class InPatient : public Bill {
    int days;
    double rate, surgery;

public:
    InPatient(string p, int d, double r, double s)
        : Bill(p), days(d), rate(r), surgery(s) {}

    double total() const override {
        return days * rate + surgery;
    }

    string type() const override {
        return "InPatient";
    }
};

// New bill type
class DayCareBill : public Bill {
    double packagePrice;

public:
    DayCareBill(string p, double price)
        : Bill(p), packagePrice(price) {}

    double total() const override {
        return packagePrice;
    }

    string type() const override {
        return "DayCare";
    }
};

class Payer {
public:
    virtual double amountCovered(const Bill& b) const = 0;
    virtual ~Payer() = default;
};

class SelfPay : public Payer {
public:
    double amountCovered(const Bill& b) const override {
        return b.total();
    }
};

class Insurance : public Payer {
    double limit;

public:
    Insurance(double l) : limit(l) {}

    double amountCovered(const Bill& b) const override {
        return (b.total() < limit) ? b.total() : limit;
    }
};

// New payer type
class CorporatePayer : public Payer {
public:
    double amountCovered(const Bill& b) const override {
        return b.total() * 0.80;
    }
};

int main() {
    OutPatient op("Ravi", 500, 1200);
    InPatient ip("Meena", 3, 2500, 40000);
    DayCareBill dc("Arun", 15000);

    SelfPay self;
    Insurance insurance(30000);
    CorporatePayer corporate;

    Bill* bills[] = {&op, &ip, &dc};
    Payer* payers[] = {&self, &insurance, &corporate};

    for (Bill* b : bills) {
        b->print();

        for (Payer* p : payers) {
            cout << "Amount covered: "
                 << p->amountCovered(*b) << '\n';
        }

        cout << '\n';
    }

    return 0;
}