#include <iostream>
using namespace std;

class Account {
    int balance, transactions[5], count = 0;

public:
    Account(int b) {
        balance = b;
    }

    void deposit(int amount) {
        balance += amount;
        if (count < 5)
            transactions[count++] = amount;
    }

    void display() {
        cout << "Balance: " << balance << endl;
        cout << "Transactions: ";

        for (int i = 0; i < count; i++)
            cout << transactions[i] << " ";
    }
};

int main() {
    Account a(1000);

    a.deposit(200);
    a.deposit(300);
    a.display();

    return 0;
}