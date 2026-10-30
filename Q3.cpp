#include <iostream>
using namespace std;

int add(int a, int b = 5) {
    return a + b;
}

double add(double a, double b) {
    return a + b;
}

int main() {
    cout << add(10) << endl;
    cout << add(10, 20) << endl;
    cout << add(2.5, 3.5) << endl;

    return 0;
}