
#include <iostream>
#include <string>
#include <stdexcept>
#include <new>
#include <cstddef>
using namespace std;

class ClaimError : public runtime_error {
public:
    using runtime_error::runtime_error;
};

class Test {
public:
    Test() {
        cout << "Object created\n";
    }

    ~Test() {
        cout << "Object destroyed\n";
    }
};

double approve(double billed, double cover) {
    if (billed < 0 || cover < 0)
        throw invalid_argument("negative amount");

    if (billed > cover)
        throw ClaimError("exceeds cover");

    return billed;
}

double settle(double billed, double cover) {
    try {
        return approve(billed, cover);
    }
    catch (const ClaimError& e) {
        cout << "audit: " << e.what() << '\n';
        throw;
    }
}

double packageRate(string code) {
    if (code == "OP")
        return 5000;
    if (code == "IP")
        return 20000;

    throw runtime_error("Unknown package");
}

int main() {
    // Test claims
    double cases[][2] = {
        {40000, 50000},
        {60000, 50000},
        {-1, 50000}
    };

    for (auto& c : cases) {
        try {
            double paid = settle(c[0], c[1]);
            cout << "approved " << paid << '\n';
        }
        catch (const ClaimError& e) {
            cout << "claim rejected: " << e.what() << '\n';
        }
        catch (const exception& e) {
            cout << "error: " << e.what() << '\n';
        }
    }

    // Test unknown package
    try {
        cout << packageRate("XYZ") << '\n';
    }
    catch (const exception& e) {
        cout << e.what() << '\n';
    }

    // Test invalid text
    try {
        string value = "hello";
        double amount = stod(value);
        cout << amount << '\n';
    }
    catch (const invalid_argument& e) {
        cout << "Invalid number entered\n";
    }

    // Test memory allocation failure
    try {
        size_t n;
        cout << "Enter array size: ";
        cin >> n;

        int* p = new int[n];
        delete[] p;
    }
    catch (const bad_alloc& e) {
        cout << "Memory allocation failed\n";
    }

    // Test object destruction and top-level catch
    try {
        Test obj;
        throw runtime_error("Test exception");
    }
    catch (...) {
        cout << "Exception caught safely\n";
    }

    cout << "Program continues\n";

    return 0;
}
