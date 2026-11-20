
#include <iostream>
#include <cmath>
using namespace std;

class Complex {
    double real, imag;

public:
    Complex() : real(0), imag(0) {}

    Complex(double r) : real(r), imag(0) {}

    Complex(double r, double i) : real(r), imag(i) {}

    Complex operator+(Complex c) {
        return Complex(real + c.real, imag + c.imag);
    }

    Complex operator-(Complex c) {
        return Complex(real - c.real, imag - c.imag);
    }

    Complex operator*(Complex c) {
        return Complex(real*c.real - imag*c.imag,
                       real*c.imag + imag*c.real);
    }

    Complex operator/(Complex c) {
        double d = c.real*c.real + c.imag*c.imag;

        if (d == 0)
            throw runtime_error("Division by zero");

        return Complex((real*c.real + imag*c.imag)/d,
                       (imag*c.real - real*c.imag)/d);
    }

    bool operator==(Complex c) {
        return real == c.real && imag == c.imag;
    }

    double magnitude() {
        return sqrt(real*real + imag*imag);
    }

    friend ostream& operator<<(ostream& out, Complex c) {
        out << c.real;

        if (c.imag >= 0)
            out << " + " << c.imag << "j";
        else
            out << " - " << -c.imag << "j";

        return out;
    }
};

int main() {
    try {
        double R = 10, L = 0.1, C = 0.001, w = 100;

        Complex resistor(R, 0);
        Complex inductor(0, w * L);
        Complex capacitor(0, -1 / (w * C));

        Complex series = resistor + inductor + capacitor;

        cout << "Series Impedance: " << series << endl;
        cout << "Magnitude: " << series.magnitude() << endl;

        Complex parallel = (resistor * inductor) /
                           (resistor + inductor);

        cout << "Parallel Impedance: " << parallel << endl;
        cout << "Magnitude: " << parallel.magnitude() << endl;

        Complex a(10, 5), b(0, 0);
        Complex result = a / b;
    }
    catch (runtime_error &e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}
