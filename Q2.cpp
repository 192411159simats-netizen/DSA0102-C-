#include <iostream>
using namespace std;

int& largest(int a[], int n) {
    int max = 0;

    for (int i = 1; i < n; i++)
        if (a[i] > a[max])
            max = i;

    return a[max];
}

int main() {
    int a[] = {10, 25, 15, 20};

    cout << "Largest: " << largest(a, 4) << endl;

    largest(a, 4) = 30;

    cout << "Updated: " << largest(a, 4);

    return 0;
}