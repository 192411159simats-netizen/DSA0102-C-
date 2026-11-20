
#include <iostream>
#include <string>
using namespace std;

class Book {
    string title, author;
    int copies;

public:
    Book() : Book("Unknown", "Unknown", 0) {}

    Book(string t) : Book(t, "Unknown", 1) {}

    Book(string t, string a, int c)
        : title(t), author(a), copies(c >= 0 ? c : 0) {}

    void display() {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Copies: " << copies << endl;
        cout << endl;
    }
};

int main() {
    Book b1;
    Book b2("C++ Programming");
    Book b3("Java", "James", 5);

    b1.display();
    b2.display();
    b3.display();

    return 0;
}
