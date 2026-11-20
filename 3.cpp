
#include <iostream>
#include <string>
using namespace std;

class Address {
    string city;
    int pin;

public:
    Address(string c, int p) : city(c), pin(p) {
        cout << "Address Created" << endl;
    }

    string display() const {
        return city + "-" + to_string(pin);
    }

    ~Address() {
        cout << "Address Destroyed" << endl;
    }
};

class Course {
    string courseName;

public:
    Course(string c) : courseName(c) {
        cout << "Course Created" << endl;
    }

    ~Course() {
        cout << "Course Destroyed" << endl;
    }
};

class Person {
protected:
    string name;
    int age;
    Address home;

public:
    Person(string n, int a, string c, int p)
        : name(n), age(a), home(c, p) {
        cout << "Person Created" << endl;
    }

    ~Person() {
        cout << "Person Destroyed" << endl;
    }
};

class Student : virtual public Person {
    int regNo;
    Course course;

public:
    Student(string n, int a, string c, int p,
            int r, string co)
        : Person(n, a, c, p), regNo(r), course(co) {
        cout << "Student Created" << endl;
    }

    ~Student() {
        cout << "Student Destroyed" << endl;
    }

    void display() {
        cout << regNo << " " << name << " "
             << age << " " << home.display() << endl;
    }
};

class Staff : virtual public Person {
    double salary;

public:
    Staff(string n, int a, string c, int p, double s)
        : Person(n, a, c, p), salary(s) {
        cout << "Staff Created" << endl;
    }

    ~Staff() {
        cout << "Staff Destroyed" << endl;
    }
};

class TeachingAssistant : public Student, public Staff {
public:
    TeachingAssistant(string n, int a, string c, int p,
                      int r, string co, double s)
        : Person(n, a, c, p),
          Student(n, a, c, p, r, co),
          Staff(n, a, c, p, s) {
        cout << "TA Created" << endl;
    }

    ~TeachingAssistant() {
        cout << "TA Destroyed" << endl;
    }
};

int main() {
    cout << "Student Object" << endl;
    {
        Student s("Kavya", 19, "Salem", 636001,
                  101, "C++");
        s.display();
    }

    cout << "\nTeaching Assistant Object" << endl;
    {
        TeachingAssistant t("Arun", 22, "Chennai",
                            600001, 102, "Java", 30000);
    }

    return 0;
}
