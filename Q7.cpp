#include <iostream>
using namespace std;

class Buffer {
    int a[5], count = 0, next = 0;

public:
    void add(int x) {
        a[next] = x;
        next = (next + 1) % 5;

        if (count < 5)
            count++;
    }

    void display() {
        int start = (count == 5) ? next : 0;

        for (int i = 0; i < count; i++)
            cout << a[(start + i) % 5] << " ";
    }
};

int main() {
    Buffer b;

    for (int i = 1; i <= 7; i++)
        b.add(i);

    b.display();

    return 0;
}