
#include <iostream>
#include <cstring>
using namespace std;

class Text {
    char *str;

public:
    Text(const char *s = "") {
        str = new char[strlen(s) + 1];
        strcpy(str, s);
    }

    // Copy constructor
    Text(const Text &t) {
        str = new char[strlen(t.str) + 1];
        strcpy(str, t.str);
    }

    // Assignment operator
    Text& operator=(const Text &t) {
        if (this != &t) {
            char *temp = new char[strlen(t.str) + 1];
            strcpy(temp, t.str);

            delete[] str;
            str = temp;
        }
        return *this;
    }

    // Concatenation
    Text operator+(const Text &t) {
        char *temp = new char[strlen(str) + strlen(t.str) + 1];

        strcpy(temp, str);
        strcat(temp, t.str);

        Text result(temp);
        delete[] temp;

        return result;
    }

    bool operator==(const Text &t) const {
        return strcmp(str, t.str) == 0;
    }

    bool operator!=(const Text &t) const {
        return !(*this == t);
    }

    friend ostream& operator<<(ostream &out, const Text &t) {
        out << t.str;
        return out;
    }

    ~Text() {
        delete[] str;
    }
};

int main() {
    Text a("Hello ");
    Text b("World");

    Text c = a + b;

    cout << "Text 1: " << a << endl;
    cout << "Text 2: " << b << endl;
    cout << "Combined: " << c << endl;

    Text d = c;

    if (c == d)
        cout << "Both texts are equal" << endl;

    if (a != b)
        cout << "Both texts are different" << endl;

    c = c;

    return 0;
}
