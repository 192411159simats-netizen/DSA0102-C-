
#include <iostream>
#include <string>
using namespace std;

class Staff {
protected:
    string name;
    int id;
    double basic;

public:
    Staff(string n, int i, double b)
        : name(n), id(i), basic(b) {}

    virtual double pay() const = 0;

    virtual void display() const {
        cout << name << " " << id << " " << pay() << endl;
    }

    virtual ~Staff() {}
};

class Professor : public Staff {
    double research;

public:
    Professor(string n, int i, double b, double r)
        : Staff(n, i, b), research(r) {}

    double pay() const override {
        return basic + basic * 0.42 + research;
    }
};

class LabAssistant : public Staff {
public:
    LabAssistant(string n, int i, double b)
        : Staff(n, i, b) {}

    double pay() const override {
        return basic + basic * 0.42;
    }
};

class GuestFaculty : public Staff {
    double hours, rate;

public:
    GuestFaculty(string n, int i, double h, double r)
        : Staff(n, i, 0), hours(h), rate(r) {}

    double pay() const override {
        return hours * rate;
    }
};

int main() {
    Staff *s[3];

    s[0] = new Professor("Arun", 101, 30000, 5000);
    s[1] = new LabAssistant("Kumar", 102, 20000);
    s[2] = new GuestFaculty("Ravi", 103, 20, 500);

    for (int i = 0; i < 3; i++)
        s[i]->display();

    for (int i = 0; i < 3; i++)
        delete s[i];

    return 0;
}
