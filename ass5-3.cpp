#include <iostream>
#include <vector>
#include <chrono>
#include <stdexcept>
using namespace std;
using namespace chrono;

class Bill {
public:
    virtual double total() const = 0;
    virtual ~Bill() = default;
};

class OPBill : public Bill {
    double consultation, tests;

public:
    OPBill(double c, double t) : consultation(c), tests(t) {}

    double total() const override {
        return consultation + tests;
    }
};

class IPBill : public Bill {
    double days, rate, surgery;

public:
    IPBill(double d, double r, double s)
        : days(d), rate(r), surgery(s) {}

    double total() const override {
        return days * rate + surgery;
    }
};

struct SimpleBill {
    int type;
    double a, b, c;
};

double switchTotal(const SimpleBill& bill) {
    switch (bill.type) {
        case 1: return bill.a + bill.b;
        case 2: return bill.a * bill.b + bill.c;
        default: return 0;
    }
}

void benchmark(int n) {
    vector<OPBill> op;
    vector<IPBill> ip;
    vector<Bill*> bills;
    vector<SimpleBill> simple;

    op.reserve(n / 2);
    ip.reserve(n / 2);
    bills.reserve(n);
    simple.reserve(n);

    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            op.emplace_back(500, 1200);
            bills.push_back(&op.back());
            simple.push_back({1, 500, 1200, 0});
        } else {
            ip.emplace_back(3, 2500, 40000);
            bills.push_back(&ip.back());
            simple.push_back({2, 3, 2500, 40000});
        }
    }

    double sum1 = 0, sum2 = 0;

    auto start = steady_clock::now();

    for (Bill* b : bills)
        sum1 += b->total();

    auto end = steady_clock::now();
    cout << n << " bills - Virtual time: "
         << duration<double, milli>(end - start).count() << " ms\n";

    start = steady_clock::now();

    for (const auto& b : simple)
        sum2 += switchTotal(b);

    end = steady_clock::now();
    cout << n << " bills - Switch time: "
         << duration<double, milli>(end - start).count() << " ms\n";

    cout << "Totals equal: " << (sum1 == sum2 ? "Yes" : "No") << "\n\n";
}

bool validReturn(double amount) {
    return amount >= 0 && amount <= 1000000;
}

bool validException(double amount) {
    try {
        if (amount < 0)
            throw invalid_argument("negative");

        if (amount > 1000000)
            throw out_of_range("too large");

        return true;
    }
    catch (const exception&) {
        return false;
    }
}

int main() {
    benchmark(1000);
    benchmark(1000000);
    benchmark(10000000);

    const int n = 1000000;

    for (int percent : {0, 1, 50}) {
        int invalid = n * percent / 100;

        auto start = steady_clock::now();

        for (int i = 0; i < n; i++) {
            double amount = (i < invalid) ? -5 : 500;
            validReturn(amount);
        }

        auto end = steady_clock::now();
        cout << percent << "% invalid - Return code: "
             << duration<double, milli>(end - start).count()
             << " ms\n";

        start = steady_clock::now();

        for (int i = 0; i < n; i++) {
            double amount = (i < invalid) ? -5 : 500;
            validException(amount);
        }

        end = steady_clock::now();
        cout << percent << "% invalid - Exceptions: "
             << duration<double, milli>(end - start).count()
             << " ms\n\n";
    }

    return 0;
}