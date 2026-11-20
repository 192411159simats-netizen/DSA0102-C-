
#include <iostream>
#include <iomanip>
using namespace std;

class Money {
    long long paise;

public:
    Money(long long r = 0, int p = 0) {
        paise = r * 100 + p;
    }

    Money operator+(Money m) {
        Money t;
        t.paise = paise + m.paise;
        return t;
    }

    Money operator-(Money m) {
        Money t;
        t.paise = paise - m.paise;
        return t;
    }

    Money& operator+=(Money m) {
        paise += m.paise;
        return *this;
    }

    bool operator==(Money m) {
        return paise == m.paise;
    }

    bool operator<(Money m) {
        return paise < m.paise;
    }

    friend ostream& operator<<(ostream& out, Money m) {
        out << "Rs " << (m.paise < 0 ? "-" : "")
            << abs(m.paise / 100) << "."
            << setw(2) << setfill('0')
            << abs(m.paise % 100);
        return out;
    }

    friend istream& operator>>(istream& in, Money& m) {
        long long r;
        int p;
        in >> r >> p;
        m.paise = r * 100 + p;
        return in;
    }
};

int main() {
    Money a(120, 75), b(79, 25);

    Money c = a + b;

    cout << c << endl;
    cout << boolalpha << (c == Money(200)) << endl;

    Money x(0, 75), y(0, 50);
    cout << x + y << endl;

    return 0;
}
