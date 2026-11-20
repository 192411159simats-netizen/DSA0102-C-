
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Cart {
    string items[10];
    double prices[10];
    int n = 0;
    double discount = 0;

public:
    Cart& add(string item, double price) {
        if (n < 10) {
            items[n] = item;
            prices[n] = price;
            n++;
        }
        return *this;
    }

    Cart& setDiscount(double discount) {
        this->discount = discount;
        return *this;
    }

    double total() const {
        double t = 0;

        for (int i = 0; i < n; i++)
            t += prices[i];

        return t * (100 - discount) / 100;
    }

    void display() const {
        cout << "Total: " << total() << endl;
    }
};

int main() {
    // 1. Direct object
    Cart c1;
    c1.add("Rice", 60).add("Dal", 120);

    // 2. Pointer to object
    Cart *p = &c1;
    p->add("Oil", 180);

    // 3. Reference to object
    Cart &r = c1;
    r.setDiscount(10);

    // 4. Dynamic object
    Cart *d = new Cart;
    d->add("Milk", 50);
    d->display();
    delete d;

    cout << fixed << setprecision(2);
    cout << "Cart Total: " << c1.total() << endl;

    // Array of pointers
    Cart c2, c3;
    c2.add("Book", 100);
    c3.add("Pen", 50).add("Bag", 500);

    Cart *carts[3] = {&c1, &c2, &c3};

    int maxIndex = 0;

    for (int i = 1; i < 3; i++) {
        if (carts[i]->total() > carts[maxIndex]->total())
            maxIndex = i;
    }

    cout << "Highest Cart Total: "
         << carts[maxIndex]->total() << endl;

    return 0;
}
