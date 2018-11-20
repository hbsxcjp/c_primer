#include <cctype>
#include <iostream>
#include <iterator>
#include <stdexcept>
#include <string>
#include <vector>

using std::begin;
using std::cin;
using std::cout;
using std::end;
using std::endl;
using std::runtime_error;
using std::string;
using std::toupper;
using std::vector;

void c5_23() {
    int i, j;
    cin >> i >> j;
    cout << i / j << endl; // j==0,出错
}

void c5_24() {
    int i, j;
    cin >> i >> j;
    if (j == 0)
        throw runtime_error("Find error!");
    cout << i / j << endl;
}

void c5_25() {
    int i, j;
    while (cin >> i >> j) {
        try {
            if (j == 0)
                throw runtime_error("Find error!");
            cout << i / j << endl;
        } catch (runtime_error err) {            
            cout << err.what() << "\nTry Again? Enter y or n" << endl;
            char c;
            cin >> c;
            if (!cin || c == 'n')
                break;
        }
    }
}

int main() {
    // c5_23();
    // c5_24();
    c5_25();

    return 0;
}