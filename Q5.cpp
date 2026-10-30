#include <iostream>
using namespace std;

class Ticket {
public:
    static int count;
    int seat;

    Ticket() {
        seat = ++count;
    }

    void display() {
        cout << "Seat: " << seat << endl;
    }
};

int Ticket::count = 0;

int main() {
    Ticket t[3];

    for (int i = 0; i < 3; i++)
        t[i].display();

    cout << "Total: " << Ticket::count;

    return 0;
}