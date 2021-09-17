#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>

using namespace std;

int main() {

    fstream f;
    f.open("straight_line.txt", ios::in);

    if (f.is_open()) {
        string line;
        while (getline(f, line)) {
            cout << line << endl;
            usleep(100000); //for 50ms delay use 50,000, currently 0.1seconds
        }
        f.close();
    } else {
        cout << "Could not open file..." << endl;
    }
}