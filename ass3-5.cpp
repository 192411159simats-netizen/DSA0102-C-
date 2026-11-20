
#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;

class Time {
    int seconds;

public:
    Time(int s = 0) : seconds(s) {}

    Time& operator++() {
        ++seconds;
        return *this;
    }

    Time operator++(int) {
        Time temp = *this;
        seconds++;
        return temp;
    }

    bool operator==(Time t) {
        return seconds == t.seconds;
    }

    bool operator<(Time t) {
        return seconds < t.seconds;
    }

    void display() {
        cout << seconds / 3600 << ":"
             << (seconds / 60) % 60 << ":"
             << seconds % 60 << endl;
    }
};

class Playlist {
    vector<string> tracks;

public:
    Playlist() {
        tracks = {"Song 1", "Song 2", "Song 3"};
    }

    string& operator[](int i) {
        if (i < 0 || i >= tracks.size())
            throw out_of_range("Invalid Index");
        return tracks[i];
    }

    const string& operator[](int i) const {
        if (i < 0 || i >= tracks.size())
            throw out_of_range("Invalid Index");
        return tracks[i];
    }
};

int main() {
    Time t(3600);

    Time a = t++;
    Time b = ++t;

    cout << "a = ";
    a.display();

    cout << "b = ";
    b.display();

    cout << "Current Time = ";
    t.display();

    Playlist p;

    cout << p[0] << endl;
    cout << p[1] << endl;

    return 0;
}
