#include <iostream>
using namespace std;

void change(int a, int &b, int *c) {
    a++;
    b++;
    (*c)++;
}

int add(int a, int b = 10) {
    return a + b;
}

int main() {
    int a = 5, b = 5, c = 5;

    change(a, b, &c);

    cout << a << " " << b << " " << c << endl;
    cout << add(5) << endl;

    return 0;
}