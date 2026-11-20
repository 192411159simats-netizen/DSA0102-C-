
#include <iostream>
using namespace std;

class Auditorium {
    int rows, seats;
    char **map;

public:
    Auditorium(int r, int s) : rows(r), seats(s) {
        map = new char*[rows];

        for (int i = 0; i < rows; i++) {
            map[i] = new char[seats];

            for (int j = 0; j < seats; j++)
                map[i][j] = 'O';
        }

        cout << "Auditorium Created" << endl;
    }

    void book(int r, int s) {
        if (r >= 0 && r < rows &&
            s >= 0 && s < seats) {
            map[r][s] = 'X';
            cout << "Seat Booked" << endl;
        }
        else
            cout << "Invalid Seat" << endl;
    }

    void cancel(int r, int s) {
        if (r >= 0 && r < rows &&
            s >= 0 && s < seats) {
            map[r][s] = 'O';
            cout << "Booking Cancelled" << endl;
        }
    }

    void display() {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < seats; j++)
                cout << map[i][j] << " ";
            cout << endl;
        }
    }

    ~Auditorium() {
        for (int i = 0; i < rows; i++)
            delete[] map[i];

        delete[] map;

        cout << "Auditorium Closed" << endl;
    }
};

int main() {
    Auditorium a(3, 4);

    a.book(0, 1);
    a.book(1, 2);

    a.display();

    a.cancel(0, 1);

    a.display();

    Auditorium *b = new Auditorium(2, 3);
    b->book(0, 0);
    delete b;

    return 0;
}
