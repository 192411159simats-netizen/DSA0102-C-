#include <iostream>
using namespace std;

class Number {
    int x;

public:
    Number(int a) {
        x = a;
    }

    friend int sum(Number, Number);
};

inline int sum(Number a, Number b) {
    return a.x + b.x;
}

int main() {
    Number a(10), b(20);

    cout << "Sum: " << sum(a, b);

    return 0;
}