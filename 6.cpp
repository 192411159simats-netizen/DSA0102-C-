
#include <iostream>
#include <string>
using namespace std;

// Abstract Base Class
class Vehicle {
protected:
    string regNo;
    double rate;
    bool rented = false;

public:
    Vehicle(string r, double d) : regNo(r), rate(d) {}

    virtual double charge(int days) const = 0;

    void rent(int days) {
        if (!rented) {
            rented = true;
            cout << regNo << " Rental Amount: "
                 << charge(days) << endl;
        }
        else
            cout << "Already Rented" << endl;
    }

    void returnVehicle(int lateDays) {
        if (rented) {
            cout << regNo << " Late Charge: "
                 << lateDays * rate * 1.5 << endl;
            rented = false;
        }
        else
            cout << "Vehicle Not Rented" << endl;
    }

    virtual void display() const {
        cout << "Registration: " << regNo
             << " Daily Rate: " << rate << endl;
    }

    virtual ~Vehicle() {}
};

// Bicycle
class Bicycle : public Vehicle {
public:
    Bicycle(string r, double d) : Vehicle(r, d) {}

    double charge(int days) const override {
        return rate * days;
    }
};

// Two Wheeler
class TwoWheeler : public Vehicle {
    double fuel;

public:
    TwoWheeler(string r, double d, double f)
        : Vehicle(r, d), fuel(f) {}

    double charge(int days) const override {
        return rate * days + fuel * 10;
    }
};

// Car
class Car : public Vehicle {
    int seats;

public:
    Car(string r, double d, int s)
        : Vehicle(r, d), seats(s) {}

    double charge(int days) const override {
        return rate * days;
    }

    void display() const override {
        Vehicle::display();
        cout << "Seats: " << seats << endl;
    }
};

// Electric Car
class ElectricCar : public Vehicle {
    double battery, units;

public:
    ElectricCar(string r, double d, double b, double u)
        : Vehicle(r, d), battery(b), units(u) {}

    double charge(int days) const override {
        return rate * days + units * 8;
    }

    void display() const override {
        Vehicle::display();
        cout << "Battery: " << battery << " kWh" << endl;
    }
};

// New Vehicle Type: Electric Bus
class ElectricBus : public Vehicle {
    int seats;
    double units;

public:
    ElectricBus(string r, double d, int s, double u)
        : Vehicle(r, d), seats(s), units(u) {}

    double charge(int days) const override {
        return rate * days + units * 8;
    }

    void display() const override {
        Vehicle::display();
        cout << "Bus Seats: " << seats << endl;
    }
};

int main() {
    Vehicle *fleet[5];

    fleet[0] = new Bicycle("B101", 100);
    fleet[1] = new TwoWheeler("T101", 200, 2);
    fleet[2] = new Car("C101", 1000, 5);
    fleet[3] = new ElectricCar("E101", 1500, 60, 10);
    fleet[4] = new ElectricBus("EB101", 3000, 40, 20);

    cout << "VEHICLE RENTAL SYSTEM\n\n";

    for (int i = 0; i < 5; i++) {
        fleet[i]->display();
        fleet[i]->rent(2);
        cout << endl;
    }

    cout << "RETURN VEHICLES\n\n";

    for (int i = 0; i < 5; i++) {
        fleet[i]->returnVehicle(1);
        delete fleet[i];
    }

    return 0;
}
